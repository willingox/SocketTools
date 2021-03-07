/*dqc tcp service
 *创建一个tcpserver，监听多个tcpwork，接受tcpwork过来的消息。
 * receive_message曹函数接收 tcpwork消息，删除树节点
 * acceptClient 增加树节点
 * receive_message_value 曹函数 接收tcpwork发升的数据，并发出消息sg_SendMessage
 */
#include "settcpserver.h"
#include <QtGui>
#include <QTimer>
#include <cglobal.h>
#include <QSqlQuery>


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>

QSetTcpServer::QSetTcpServer(QObject *parent) :
    QObject(parent)
{
    mp_tcpServer = new QTcpServer;
    connect(mp_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    treeItem = NULL;
    q_savedevinfo = new QSqlQuery(*db_mysql);
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    m_timer->setInterval(30000);
    m_timer->start(30000);
}

QSetTcpServer::~QSetTcpServer()
{
    foreach (QTcpWork *tcpWork, mp_client_list)
    {
        tcpWork->disconnect();
        delete(tcpWork);
    }
}

//dqc deal new connection message
void QSetTcpServer::onNewConnection()
{
    if (mp_tcpServer->hasPendingConnections())//Returns true if the server has a pending connection; otherwise returns false.
    {
        acceptClient(mp_tcpServer->nextPendingConnection());//Returns the next pending connection as a connected QTcpSocket object.
    }
}

//dqc new tcpwork created(one connection),and create new node follow treeitem of settcpserver
void QSetTcpServer::acceptClient(QTcpSocket *client)
{
    qDebug() << "QSetTcpServer::acceptClient(QTcpSocket *client)";
    QTcpWork *tcpWork = new QTcpWork;
    tcpWork->setTcpSocket(client);
    connect(tcpWork, SIGNAL(sg_SendMessage(int,QByteArray,QTcpWork*)), this, SLOT(receive_message(int,QByteArray,QTcpWork*)));
    connect(tcpWork, SIGNAL(sg_SendMessage(int,QString,QTcpWork*)), this, SLOT(receive_message(int,QString,QTcpWork*)));
    QString clientName = "connected "+client->peerAddress().toString() + tr(":") + QString::number(client->peerPort());
    emit sg_SendMessage(10, clientName,this);

    this->mp_client_list.append(tcpWork);
}

//dqc received message from tcpwork ， if disconnect，remove this tcpwork node
//dqc 20200814这里应该能收到接收的数据
void QSetTcpServer::receive_message(int type, QString message, QTcpWork *tcpWork)
{
    qDebug() << " QSetTcpServer::receive_message type:" << type << " message:" << message << " tcpWork:" << tcpWork;

    if (type == 1 && message == tr("连接中断"))
    {
        QString clientName =  "disconnected " + tcpWork->m_Client->peerAddress().toString() + tr(":") + QString::number(tcpWork->m_Client->peerPort());
        emit sg_SendMessage(10, clientName,this);
    }
}

void QSetTcpServer::receive_message(int type, QByteArray temp, QTcpWork *tcpWork)
{
    qDebug() << "QSetTcpServer::receive_message type:" << type << " message:" << temp << " tcpWork:" << tcpWork;

    if(type == 2)
    {
       // QByteArray text = QByteArray::fromHex("517420697320677265617421");
        //报头4：     C1 头 02类型  0c 00 数据区长度
        //数据区12 ： 0100 id  ff00 温度 ee02 湿度 01 报警标志 1102142300 时间
        //09校验
        int t1 = temp[2];
        int t2 = temp[3];
        int length = MAKEWORD(temp[2],temp[3]);
        int datacount = length/12;
        if(length < temp.length())
        {
            for(int isers=0;isers<datacount;isers++)
            {
                unsigned short id = MAKEWORD(temp[4+isers*12],temp[4+isers*12+1]);

                QString ss ="select * from devinfo where devid ="+QString::number(id,10);
                q_savedevinfo->exec(ss);
                int isize = q_savedevinfo->size();
                if(isize == 1)
                {
                    short temper = MAKEWORD(temp[4+isers*12+2],temp[4+isers*12+3]) ;
                    float ftemper = float(temper) / 10;
                    int   water = MAKEWORD(temp[4+isers*12+4],temp[4+isers*12+5]);
                    float fwater = float(water) / 10;

                   // 报警标志定义如下：
                   // bit7       bit6      bit5   bit4     bit3   bit2   bit1       bit0
                   // 低电压报警   设备故障     无   断电报警   无     无   湿度报警   温度报警
                  //warning	Temp>>=(Offset);          //  return Temp&0x01;

                    unsigned char warning = temp[4+isers*12+6];
                    bool bit0 = warning&0x01;
                    bool bit1 = (warning>>1)&0x01;
                    bool bit2 = (warning>>2)&0x01;
                    bool bit3 = (warning>>3)&0x01;
                    bool bit4 = (warning>>4)&0x01;
                    bool bit5 = (warning>>5)&0x01;
                    bool bit6 = (warning>>6)&0x01;
                    bool bit7 = (warning>>7)&0x01;

                    //int id = MAKEWORD(temp[4+isers*12],temp[4+isers*12+1]); 日期暂不解析
                    QString dt = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
                    QDateTime dtsource;// = QDateTime::currentDateTime();
                    int iyear = temp[4+isers*12+7]+2000;
                    int imonth = temp[4+isers*12+8];
                    int iday = temp[4+isers*12+9];
                    dtsource.date().setDate(iyear,imonth,iday);
                    int ihour = temp[4+isers*12+10];
                    int imin = temp[4+isers*12+11];
                    dtsource.time().setHMS(ihour,imin,0);

                    QByteArray dts = temp.mid(4+isers*12+7,5);

                    QString sqlstr="";
                   // QString strdts(dts);// = dts.toStdString();

                     //insert into t_tenmin (f_savetime,f_fjno,f_p,f_q,f_day_gen,f_month_gen,f_year_gen,f_windspeed,f_windstat) value(
                     //'2020-07-21 13:44:27','fj001',111,222,333,444,555,6.2,14);

                    //dqc 20200824 插入历史数据
                     sqlstr="insert into devdata (devtime,cursystime,devid,devtemper,devwater,devwarning,lowdianyawarningint,shebeiguzhang,beiyong1,duandiangaojing,beiyong2,beiyong3,shidugaojing,wendugaojing) value('";
                     QString sqlstr1="20"+dts.toHex()+"00','"+dt+"','"+QString::number(id,10)+"',"+QString::number(ftemper,10,3);
          //           sqlstr=sqlstr+dtsource.toString("yyyyMMddhhmmss")+"','"+dt+"','"+QString::number(id,10)+"',"+QString::number(ftemper,10,3);
                     sqlstr=sqlstr+sqlstr1+","+QString::number(fwater,10,3);
                     sqlstr=sqlstr+","+QString::number(warning,10);

                     sqlstr=sqlstr+","+QString::number(bit7,10);
                     sqlstr=sqlstr+","+QString::number(bit6,10);
                     sqlstr=sqlstr+","+QString::number(bit5,10);
                     sqlstr=sqlstr+","+QString::number(bit4,10);
                     sqlstr=sqlstr+","+QString::number(bit3,10);
                     sqlstr=sqlstr+","+QString::number(bit2,10);
                     sqlstr=sqlstr+","+QString::number(bit1,10);
                     sqlstr=sqlstr+","+QString::number(bit0,10)+")";
                     bool succe = q_savedevinfo->exec(sqlstr);  //query=QSqlQuery::QSqlQuery(m_db);//
                     if(!succe){
                         if (! db_mysql->open()) {
                                 QSqlError e = db_mysql->lastError();
                                 qDebug() << "QSqlError:" << e.text();

                             }
                         else
                         {
                              qDebug() << "QSql connected:" ;//调试打印
                              qDebug("QSql connected:!");//输出日志
                         }
                     }

                     qDebug()<<"sqlstr:"<<sqlstr;
                    //dqc 20200824 修改devinfo数据
                     //dqc 20200824 插入历史数据
                     sqlstr="update devinfo set ";
                     sqlstr=sqlstr + "devtime ='20"+dts.toHex()+"00',";
                     sqlstr=sqlstr + "cursystime ='"+dt+"',";
                     sqlstr=sqlstr + "devtemper ='"+QString::number(ftemper,10,3)+"',";
                     sqlstr=sqlstr + "devwater ='"+QString::number(fwater,10,3)+"',";
                     sqlstr=sqlstr + "devwarning ='"+QString::number(warning,10)+"',";
                     sqlstr=sqlstr + "lowdianyawarningint ='"+QString::number(bit7,10)+"',";
                     sqlstr=sqlstr + "shebeiguzhang ='"+QString::number(bit6,10)+"',";
                     sqlstr=sqlstr + "beiyong1 ='"+QString::number(bit5,10)+"',";
                     sqlstr=sqlstr + "duandiangaojing ='"+QString::number(bit4,10)+"',";
                     sqlstr=sqlstr + "beiyong2 ='"+QString::number(bit3,10)+"',";
                     sqlstr=sqlstr + "beiyong3 ='"+QString::number(bit2,10)+"',";
                     sqlstr=sqlstr + "shidugaojing ='"+QString::number(bit1,10)+"',";
                     sqlstr=sqlstr + "wendugaojing ='"+QString::number(bit0,10)+"' where devid = '"+QString::number(id,10)+"'";
                     succe = q_savedevinfo->exec(sqlstr);  //query=QSqlQuery::QSqlQuery(m_db);//
                     if(!succe){
                         if (! db_mysql->open()) {
                                 QSqlError e = db_mysql->lastError();
                                 qDebug() << "QSqlError:" << e.text();

                             }
                         else
                         {
                              qDebug() << "QSql connected:" ;//调试打印
                              qDebug("QSql connected:!");//输出日志
                         }
                     }

                    // succ = query.exec(strSelect);   /*数据库会在没有打开的情况下，不对query重新赋予db关键字，执行sql语句会挂死*/
                     qDebug()<<"sqlstr:"<<sqlstr;
                }
            }

        }

        tcpWork->SendData("OKZZ");
        //sleep(1000);
        if (tcpWork->isConnect)
        {
            tcpWork->disconnect();
            qDebug()<<"20200904 QSetTcpServer::receive_messagetcpWork->disconnect();"<<temp;
        }
    }

    emit sg_SendMessage(9, temp.toHex(),this);
}

//
bool QSetTcpServer::listen(int port)
{
//    qDebug() << " QSetTcpServer::listen";
    if(mp_tcpServer->listen(QHostAddress::AnyIPv4, port))
    {
        return true;
    }

    return false;
}

//
void QSetTcpServer::close()
{
//    qDebug() << " QSetTcpServer::close";
    mp_tcpServer->close();
}

void QSetTcpServer::sleep(unsigned int msec)
{
//    qDebug() << " QSetTcpServer::sleep";
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        //----- 放弃处理器时间片
        QMutex mutex;
        QWaitCondition sleep;
        mutex.lock();
        sleep.wait(&mutex, 10);
        mutex.unlock();
    }
}

void QSetTcpServer::onTimer()
{

    int icount = mp_client_list.count() ;
    qDebug()<<"20200909 QSetTcpServer::onTimer():mp_client_list.removeOne(client)" <<QString::number(icount);

    foreach (QTcpWork* client, mp_client_list)
    {
        if (!client->isConnect)
        {
            mp_client_list.removeOne(client);
            delete client;
        }
    }

}

