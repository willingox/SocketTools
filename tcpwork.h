/*dqc
 * a connection of the tcp server.
*/
#ifndef TCPWORK_H
#define TCPWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
/*dqc tcp service
 *
 */
QT_BEGIN_NAMESPACE
class QTreeWidgetItem;
class QTextEdit;
QT_END_NAMESPACE

class QTcpWork : public QObject
{
    Q_OBJECT

public:
    explicit QTcpWork(QObject *parent = 0);
    ~QTcpWork();

    void SetHostIP(QString ip);               //----- 设定主机IP
    void SetHostPort(int port);               //----- 设定主机端口
    QString getHostIP()
    {
        return m_Client->peerAddress().toString();
    }
    int getPort()
    {
        return m_Client->peerPort();
    }
    void SendData(QString data);              //----- 发送数据
    void ConnectToHost();                     //----- 连接主机
    void DisConnectFromHost();                     //----- 连接主机
    void setTcpSocket(QTcpSocket *client);
    int localPort();


public:
    bool isConnect;

signals:
    void sg_SendMessage(int kind, QString msg, QTcpWork *tcpWork);  //----- 发送信号 kind 代表信号类型，msg是具体的信号
    void sg_SendMessage(int kind, QByteArray msg, QTcpWork *tcpWork);  //----- 发送信号 kind 代表信号类型，msg是具体的信号
    void sg_ConnectStatus(QAbstractSocket::SocketState); //----- 发送连接状态信号

private slots:
    void sl_ReadData();                          //----- 读取数据 槽
    void sl_ConnectStatus(QAbstractSocket::SocketState); //----- 连接状态改变 槽


//private:
public:
    QTcpSocket  *m_Client;

private:
    QString m_IpAddress;                      //----- IP地址
    int m_Port;                               //----- 端口
};

#endif // TCPWORK_H
