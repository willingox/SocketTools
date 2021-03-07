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

    void SetHostIP(QString ip);               //----- �趨����IP
    void SetHostPort(int port);               //----- �趨�����˿�
    QString getHostIP()
    {
        return m_Client->peerAddress().toString();
    }
    int getPort()
    {
        return m_Client->peerPort();
    }
    void SendData(QString data);              //----- ��������
    void ConnectToHost();                     //----- ��������
    void DisConnectFromHost();                     //----- ��������
    void setTcpSocket(QTcpSocket *client);
    int localPort();


public:
    bool isConnect;

signals:
    void sg_SendMessage(int kind, QString msg, QTcpWork *tcpWork);  //----- �����ź� kind �����ź����ͣ�msg�Ǿ�����ź�
    void sg_SendMessage(int kind, QByteArray msg, QTcpWork *tcpWork);  //----- �����ź� kind �����ź����ͣ�msg�Ǿ�����ź�
    void sg_ConnectStatus(QAbstractSocket::SocketState); //----- ��������״̬�ź�

private slots:
    void sl_ReadData();                          //----- ��ȡ���� ��
    void sl_ConnectStatus(QAbstractSocket::SocketState); //----- ����״̬�ı� ��


//private:
public:
    QTcpSocket  *m_Client;

private:
    QString m_IpAddress;                      //----- IP��ַ
    int m_Port;                               //----- �˿�
};

#endif // TCPWORK_H
