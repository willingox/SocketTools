/*
 * 点停止监听的时候，会触发 ：on_treeWidget_root_itemClicked ，导致按钮显示不符合逻辑
   为什么会触发  on_treeWidget_root_itemClicked ？
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dialogtcpserver.h"


#include <QScrollBar>


void MainWindow::addtip(QString strline)
{
    QDateTime curDateTime=QDateTime::currentDateTime();
   // ui->textEdittip->moveCursor(QTextCursor::Start);  //插入到最上面
    ui->textEdittip->insertPlainText(curDateTime.toString("yyyy-MM-dd hh:mm:ss  ")+strline+"\r\n");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("QTextEdit {background: white} QGroupBox {background: rgb(250, 248, 238, 100%)} QTreeWidget {background: rgb(250, 248, 238, 100%)}");

    //dqc create level one nodes
    m_tree_root = ui->treeWidget_root; //dqc pointer to the tree root
    createRootNode(m_TcpServerRoot, tr("TCP Server"));
    ui->groupBox_socketStatus_tcpServer->hide();//hide tcpserver board
    ui->pushButton_delete->setEnabled(0);
    ui->pushButton_create->setEnabled(0);
    ui->textEdittip->document ()->setMaximumBlockCount (1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//dqc create five root nodes
void MainWindow::createRootNode(QTreeWidgetItem *rootItem, const QString &nodeName)
{
    //qDebug() << " MainWindow::createRootNode" ;
    rootItem = new QTreeWidgetItem(m_tree_root);//dqc rootItem‘s parent node is m_tree_root
    rootItem->setData(0, Qt::EditRole, nodeName);
    rootItem->setIcon(0, QIcon(tr(":/PNG/ico16-1.png")));
}

//create a object According to m_createMode
void MainWindow::on_pushButton_create_clicked()
{
   createTcpServer();
}

//when tree node was cliecked.assigned m_createMode；adjust m_textRecevieWindow according status of ui->checkBox。
//according the value of node，call different functions
void MainWindow::on_treeWidget_root_itemClicked(QTreeWidgetItem* item, int column)
{
    QTreeWidgetItem *phItem = item->parent();
   //  qDebug() << "on_treeWidget_root_itemClicked" ;
    //if cliecked level 1,return m_createMode
    if(!phItem)
    {
    }

    int kind = item->data(1, Qt::UserRole + 1).toInt();
    if (kind > 0)
    {
        qDebug() << "kind:" << kind;
    }

    switch (kind)
    {
    case 0:
        break;

    case 1:
        {
            click_TcpServer();
        }
        break;

    case 2:
        {
            qDebug() << "click TcpServer chield Client";
        }
        break;
    default:
        {

        }
        break;
    }

}

//tcp server ，on/off listen
//tcpWork is object of connection，when listening off，free all of them
void MainWindow::on_pushButton_listen_clicked()
{
   //qDebug() << " MainWindow::on_pushButton_listen_clicked" ;
    //qDebug()<<ui->pushButton_listen->text()<<endl;

    QTreeWidgetItem *m_currentItem = ui->treeWidget_root->currentItem();
  //  qDebug() << m_currentItem->text(0);
    if (!m_currentItem)
    {
        addtip("no select create type");
        return;
    }
    if(m_currentItem->parent())
    {

    }
    else
    {
        QMessageBox::warning(NULL, QStringLiteral("warning"),QStringLiteral("please create and select service!"));
         return;
    }

    QSetTcpServer *tcpServer = (QSetTcpServer*)(m_currentItem->data(1, Qt::UserRole + 2).toInt());

    if(ui->pushButton_listen->text()==QStringLiteral("stop listen"))
    {
        // for (int i = 0; i < m_currentItem->childCount(); i++)
        //  {
        //	   QTreeWidgetItem *childClient = m_currentItem->child(i);
        //	   QTcpWork *tcpWork = (QTcpWork*)(childClient->data(1, Qt::UserRole + 2).toInt());
        //	   if (tcpWork->isConnect)
        //	   {
        //		   tcpWork->DisConnectFromHost();
        //	   }
                //m_currentItem->removeChild(childClient);//dqc 没有这一句，树节点怎么也删除掉了？
        //   }

        addtip(QStringLiteral("stop listen port")+QString::number(tcpServer->m_port));
        tcpServer->close();
        ui->pushButton_listen->setText(QStringLiteral("start listen"));
	}
	else
	{
        tcpServer->listen(tcpServer->m_port);
        addtip(QStringLiteral("start listen port")+QString::number(tcpServer->m_port));
        ui->pushButton_listen->setText(QStringLiteral("stop listen"));
	}
}

//create tcpserver，create tree node and set it as current node，
//then call addTcpServer
void MainWindow::createTcpServer()
{
   // qDebug() << " MainWindow::createTcpServer" ;
    QTreeWidgetItem *m_currentItem = ui->treeWidget_root->currentItem();

    if (!m_currentItem)
    {
       // qDebug() << "no select create type";
        return;
    }
    if(m_currentItem->parent())
    {
        //qDebug() << "no";
        return;
    }

    DialogTcpServer m_dialogTcpServer;
    if (!m_dialogTcpServer.exec())
    {
        return;
    }

    int port = m_dialogTcpServer.getPort();
    QString name = "Tcp Server [" + QString::number(port) + "]";
    int count = m_currentItem->childCount();
    for (int i=0; i<count; i++)  // Validity judgment
    {
        QTreeWidgetItem *m_childItem = m_currentItem->child(i);
        if (m_childItem->text(0) == name)
        {
            QMessageBox::warning(NULL, QStringLiteral("warning"), QStringLiteral("the port already open"));
            ui->treeWidget_root->setCurrentItem(m_childItem);
            return;
        }
    }

    QTreeWidgetItem *TcpServerItem = new QTreeWidgetItem(m_currentItem);//create a new node which is the children of param one
    TcpServerItem->setData(0, Qt::EditRole, name);
    TcpServerItem->setIcon(0, QIcon(tr(":/PNG/TcpServerOFF.png")));

    ui->treeWidget_root->setCurrentItem(TcpServerItem);

    addTcpServer(TcpServerItem, port); //add a tcp server （listen）
    //ui->treeWidget_root->expandAll();

}

//dqc  add a tcp server object， assign it's treeitem，initial connect，data，open listen and set icon。then call click_TcpServer
void MainWindow::addTcpServer(QTreeWidgetItem *tcpServerItem, int port)
{
    //qDebug() << " MainWindow::addTcpServer" ;
    newServer = new QSetTcpServer;//dqc 创建一个TCP监听对象，绑定树节点
    newServer->treeItem = tcpServerItem;
    newServer->m_port = port;
    connect(newServer, SIGNAL(sg_SendMessage(int,QString,QSetTcpServer *)), this, SLOT(show_message(int,QString,QSetTcpServer *)));
    connect(newServer, SIGNAL(sg_SendMessage(int,QString,int)), this, SLOT(show_message(int,QString,int)));

    tcpServerItem->setData(1, Qt::UserRole + 1, 1); //----- 类型为1 tcp server
    tcpServerItem->setData(1, Qt::UserRole + 2, (qint64)newServer);
    tcpServerItem->setData(1, Qt::UserRole + 3, port);
    addtip("addTcpServer:"+QString::number(port));

    newServer->listen(port);
    tcpServerItem->setIcon(0, QIcon(tr(":/PNG/TcpServerON.png")));

    click_TcpServer();
}

void MainWindow::show_message(int type, QString message,QSetTcpServer *CurTcpServer)
{

   // qDebug() << " MainWindow::show_message(int type, QString message)" ;
    switch (type)
    {
    case 0: //----- 命令类
        {
            if (message.indexOf(tr("disConnect:")) >= 0)
            {
                QString s_pointer = message.remove(tr("disConnect:"));
                int i_pointer = s_pointer.toInt(0, 10);
                if (i_pointer > 0)
                {
                    QTcpWork *tcpWork = (QTcpWork*)i_pointer;

                    if (&m_TcpWork == tcpWork)
                    {
                        qDebug() << "is client";
                    }
                    else
                    {
                        mp_removeClient_list.append(tcpWork);  //dqc 断开时候去掉该监听

                        for (int i = 0; i < m_TcpServerRoot->childCount(); i++)
                        {
                            QTreeWidgetItem *childClient = m_TcpServerRoot->child(i);
                            int mem_pointer = childClient->data(0, Qt::UserRole + 1).toInt();
                            //QTcpWork *memTcp = (QTcpWork *)(childClient->data(0, Qt::UserRole + 1).toInt());
                            if (mem_pointer == i_pointer)
                            {
                                m_TcpServerRoot->removeChild(childClient);
                                break;
                            }
                        }
                    }
                }
            }
            else if (tr("changeStatus 0") == message)
            {

            }
            else if (tr("changeStatus 1") == message)
            {

            }
        }
        break;

    case 1: //----- 状态栏显示
        {
            //ui->statusBar->showMessage(message);
            //ui->textEdit_showMsg->append(message);
        }
        break;

    case 2: //----- 输出窗显示
        {
            //ui->textEdit_dataReceive->append(message);
        }
        break;

    case 3:
        {
        }
        break;

    case 9:
        {
            QDateTime now = QDateTime::currentDateTime();//
           // QString msg = now.toString("hh:mm:ss <B><font color=#FF0000>" + QString::fromLocal8Bit("收到数据") + ": </font></B>") + QString::fromLocal8Bit(message);
            QString msg = now.toString("hh:mm:ss <B><font color=#FF0000>" + QString::fromLocal8Bit("收到数据") + ": </font></B>") + message;
            ui->textEditcustom->append(msg);
        }
        break;
    case 10:
    {
        addtip("TCP Server-"+ QString::number(CurTcpServer->m_port)+":" +message);
    }
    break;

    default:
        break;
    }
}

void MainWindow::show_message(int type, QString message,int i)
{
    //qDebug() << " MainWindow::show_message(int type, QString message,int i)" ;
    switch (type)
    {
    case 0: //----- 命令类
        {
            if (message.indexOf(tr("disConnect:")) >= 0)
            {
                QString s_pointer = message.remove(tr("disConnect:"));
                int i_pointer = s_pointer.toInt(0, 10);
                if (i_pointer > 0)
                {
                    QTcpWork *tcpWork = (QTcpWork*)i_pointer;

                    if (&m_TcpWork == tcpWork)
                    {
                        qDebug() << "is client";
                    }
                    else
                    {
                        mp_removeClient_list.append(tcpWork);

                        for (int i = 0; i < m_TcpServerRoot->childCount(); i++)
                        {
                            QTreeWidgetItem *childClient = m_TcpServerRoot->child(i);
                            int mem_pointer = childClient->data(0, Qt::UserRole + 1).toInt();
                            //QTcpWork *memTcp = (QTcpWork *)(childClient->data(0, Qt::UserRole + 1).toInt());
                            if (mem_pointer == i_pointer)
                            {
                                m_TcpServerRoot->removeChild(childClient);
                                break;
                            }
                        }
                    }
                }
            }
            else if (tr("changeStatus 0") == message)
            {

            }
            else if (tr("changeStatus 1") == message)
            {

            }
        }
        break;

    case 1: //----- 状态栏显示
        {
            //ui->statusBar->showMessage(message);
            //ui->textEdit_showMsg->append(message);
        }
        break;

    case 2: //----- 输出窗显示
        {
            //ui->textEdit_dataReceive->append(message);
        }
        break;

    case 3:
        {

        }
        break;

    default:
        break;
    }
}

//dqc clieck tcpserver node
void MainWindow::click_TcpServer()
{
    //qDebug() << " MainWindow::click_TcpServer" ;
    QTreeWidgetItem *m_currentItem = ui->treeWidget_root->currentItem();
    if (!m_currentItem)
    {
        //qDebug() << "no select create type";
        return;
    }

    //dqc if not cliecked the tcpserver node
    if (m_currentItem->data(1, Qt::UserRole + 1).toInt() != 1)
    {
        return;
    }

    QSetTcpServer *tcpServer = (QSetTcpServer*)(m_currentItem->data(1, Qt::UserRole + 2).toInt());

    //dqc not to be set caption here
    if (tcpServer->islisten())
    {
        ui->pushButton_listen->setText(QStringLiteral("stop listen"));
    }
    else
    {
        ui->pushButton_listen->setText(QStringLiteral("start listen"));
    }
}

//----- 删除
void MainWindow::on_pushButton_delete_clicked()
{
    //qDebug() << " MainWindow::on_pushButton_delete_clicked" ;
    QTreeWidgetItem *m_currentItem = ui->treeWidget_root->currentItem();

    if (!m_currentItem)
    {
        //qDebug() << "no select delete item";
        return;
    }

    int kind = m_currentItem->data(1, Qt::UserRole + 1).toInt();

    if (kind > 0)
    {
        qDebug() << "kind:" << kind;
    }

    switch (kind)
    {
    case 0:
        break;

    case 1: //----- Tcp Server
        {
            QSetTcpServer *newServer = (QSetTcpServer*)(m_currentItem->data(1, Qt::UserRole + 2).toInt());

            addtip("delete TcpServer:"+QString::number(newServer->m_port));

            newServer->close();
            delete(newServer);
            ((QTreeWidgetItem*)m_currentItem->parent())->removeChild(m_currentItem);

        }
        break;

    case 2:
        {
            QTreeWidgetItem* parentItem = (QTreeWidgetItem*)m_currentItem->parent();
            QSetTcpServer *parentServer = (QSetTcpServer*)(parentItem->data(1, Qt::UserRole + 2).toInt());

            QTcpWork *tcpWork = (QTcpWork*)(m_currentItem->data(1, Qt::UserRole + 2).toInt());
            tcpWork->disconnect();
            parentServer->mp_client_list.removeOne(tcpWork);
            parentItem->removeChild(m_currentItem);
            delete(tcpWork);
        }
        break;

    default:
        break;
    }
}

void MainWindow::on_pushButton_exit_clicked()
{
   // qDebug() << " MainWindow::on_pushButton_exit_clicked" ;
    close();
}

void MainWindow::on_treeWidget_root_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    ui->pushButton_delete->setEnabled(current->parent());
    ui->pushButton_create->setEnabled(!current->parent());

    if(current->parent())
    {
        ui->groupBox_socketStatus_tcpServer->show();//hide tcpserver board

        QSetTcpServer *tcpServer = (QSetTcpServer*)(current->data(1, Qt::UserRole + 2).toInt());

        ui->textEditcustom->clear();
        /*
        int i = tcpServer->mp_client_list.count();
        if (i>0)
        {
            foreach (QTcpWork* client, tcpServer->mp_client_list)  //settcpserver layer，void QSetTcpServer::onTimer()  冲突？
            {
                if (client->isConnect)
                {
                    ui->textEditcustom->append(client->m_Client->peerAddress().toString() + tr(":") + QString::number(client->m_Client->peerPort()));
                    delete client;
                }
            }

        }
        */

    }
    else
    {
        ui->groupBox_socketStatus_tcpServer->hide();//hide tcpserver board
    }






}
