/*dqc tcp service
 *tcp server 的每个监听例程
 *
 */
#include "tcpwork.h"
#include "mainwindow.h"
#include <QtGui>

#include <QScrollBar>

QTcpWork::QTcpWork(QObject *parent) : QObject(parent)
{
    m_Client = NULL;

//    connect(m_Client, SIGNAL(readyRead()), this, SLOT(sl_ReadData()));
//    connect(m_Client, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(sl_ConnectStatus(QAbstractSocket::SocketState)));
    isConnect = false;
}

QTcpWork::~QTcpWork()
{
    if (NULL != m_Client)
    {
        delete m_Client;
    }
}

void QTcpWork::setTcpSocket(QTcpSocket *client)
{
    if (NULL == client)
    {
        m_Client = new QTcpSocket;
    }
    else
    {
        m_Client = client;
        isConnect = true;
    }
    connect(m_Client, SIGNAL(readyRead()), this, SLOT(sl_ReadData()));
    connect(m_Client, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(sl_ConnectStatus(QAbstractSocket::SocketState)));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 设置主机IP
//----- 函数名称 SetHostIP
//----- 参数QString ip, IP地址
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::SetHostIP(QString ip)
{
    if (NULL == m_Client)
    {
        setTcpSocket(NULL);
    }
    m_IpAddress = ip;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 设置主机端口
//----- 函数名称 SetHostPort
//----- 参数int port, 端口号 1~65535
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::SetHostPort(int port)
{
    if (NULL == m_Client)
    {
        setTcpSocket(NULL);
    }
    m_Port = port;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 发送数据
//----- 函数名称 SendData
//----- 参数 QString data, 要发送的数据
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::SendData(QString data)
{
//    qDebug() << " QTcpWork::SendData";
    if (NULL == m_Client)
    {
        setTcpSocket(NULL);
    }

    if (isConnect)
    {
        qDebug()<<"20200904 void QTcpWork::SendData(QString data):"<<data;
        m_Client->write(data.toLocal8Bit());


        // emit sg_SendMessage(1, tr("已提交数据"), this);
        //QDateTime now = QDateTime::currentDateTime();

        //m_Client->disconnectFromHost();//20200903
        //m_Client->disconnect();

    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 槽函数 从socket读取数据
//----- 函数名称 sl_ReadData
//----- 参数 无  dqc 从这里把数据解析入库
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::sl_ReadData()
{
 //   qDebug() << " QTcpWork::sl_ReadData";
    int len = m_Client->bytesAvailable();
    QByteArray temp = m_Client->read( len );
    qDebug() << "20200904 void QTcpWork::sl_ReadData():" << temp << "\n";

   // emit sg_SendMessage(1, tr("收到数据"), this);
    emit sg_SendMessage(2, temp, this);  //dqc 20200814在settcpserver中响应这个消息，通过this参数可以直接返回数据
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 槽函数 连接状态改变
//----- 函数名称 sl_ConnectStatus
//----- 参数 QAbstractSocket::SocketState
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::sl_ConnectStatus(QAbstractSocket::SocketState s)
{
 //   qDebug() << " QTcpWork::sl_ReadData";

    switch(s)
    {
    case QAbstractSocket::UnconnectedState:
        {
            //qDebug() << "QTcpWork::sl_ConnectStatusstatus:UnconnectedState\n";
            isConnect = false;
            //emit sg_SendMessage(0, tr("changeStatus 0"));
            QString msg = tr("QTcpWork::sl_ConnectStatus disConnect:") + QString::number((qint64)this);
            qDebug() << msg;
            m_Client->close();
            //emit sg_SendMessage(0, msg, this);
            emit sg_SendMessage(1, tr("连接中断"), this);
        }
        break;

    case QAbstractSocket::HostLookupState:
        {
         //   qDebug() << "QTcpWork::sl_ConnectStatus status:HostLookupState";
            //emit sg_SendMessage(1, tr("查找主机中......"), this);
        }
        break;

    case QAbstractSocket::ConnectingState:
        {
          //  qDebug() << "QTcpWork::sl_ConnectStatus status:ConnectingState";
            //emit sg_SendMessage(1, tr("正在连接主机......"), this);
        }
        break;

    case QAbstractSocket::ConnectedState:
        {
            qDebug() << "QTcpWork::sl_ConnectStatus status:ConnectedState";
            isConnect = true;
            //emit sg_SendMessage(0, tr("changeStatus 1"), this);
            //emit sg_SendMessage(1, tr("连接成功"), this);
        }
        break;

    case QAbstractSocket::BoundState:
        {
           // qDebug() << "QTcpWork::sl_ConnectStatus status:BoundState";
        }
        break;

    case QAbstractSocket::ListeningState:
        {
          //  qDebug() << "QTcpWork::sl_ConnectStatus status:ListeningState";
        }
        break;

    case QAbstractSocket::ClosingState:
        {
           // qDebug() << "QTcpWork::sl_ConnectStatus status:ClosingState";
        }
        break;

    default:
        break;
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 连接到主机
//----- 函数名称 ConnectToHost
//----- 参数 无
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::ConnectToHost()
{
    m_Client->connectToHost(m_IpAddress, m_Port);
   // qDebug() << "QTcpWork::ConnectToHost";
    //emit sg_SendMessage(1, tr("正在连接通讯"), this);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- 从主机断开
//----- 函数名称 DisConnectFromHost
//----- 参数 无
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::DisConnectFromHost()
{
    m_Client->disconnectFromHost();
   //  qDebug() << "QTcpWork::DisConnectFromHost";
    //emit sg_SendMessage(1, tr("正在断开连接"), this);
}

int QTcpWork::localPort()
{
    return m_Client->localPort();
}
