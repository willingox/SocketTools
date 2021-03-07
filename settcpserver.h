/*dqc tcp service
 *  object of A TCP service
*/
#ifndef SETTCPSERVER_H
#define SETTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include "tcpwork.h"
#include <QTreeWidgetItem>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
class QTreeWidgetItem;
class QTimer;
QT_END_NAMESPACE

class QSetTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit QSetTcpServer(QObject *parent = 0);
    ~QSetTcpServer();

    //void SendData(QString data);              //----- 发送数据
    bool listen(int port);
    void close();
    bool islisten()
    {
        return mp_tcpServer->isListening();
    }

public:
    QTreeWidgetItem *treeItem;        //dqc Corresponding tree node
    QList<QTcpWork*> mp_client_list;  //dqc connections of this service object
    int m_port; //dqc 20200909

signals:
    void sg_SendMessage(int kind, QString msg,QSetTcpServer *CurTcpServer);          //----- 发送信号 kind 代表信号类型，msg是具体的信号
    void sg_ConnectStatus(QAbstractSocket::SocketState); //----- 发送连接状态信号
	void sg_SendMessage(int kind, QString msg,int);

private slots://dqc 这里两个receive曹函数，接收的是tcpwork的消息
    void onNewConnection();
    void receive_message(int type, QString message, QTcpWork* tcpWork);
    void receive_message(int type, QByteArray message, QTcpWork* tcpWork);
    void onTimer();
private:
    QTcpServer * mp_tcpServer;
    QSqlQuery * q_savedevinfo;
    QTimer *m_timer;


private:
    void acceptClient(QTcpSocket *client);
    void sleep(unsigned int msec);
};

#endif // SETTCPSERVER_H
