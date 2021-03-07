/*dqc tcp service
 *tcp server ��ÿ����������
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
//----- ��������IP
//----- �������� SetHostIP
//----- ����QString ip, IP��ַ
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
//----- ���������˿�
//----- �������� SetHostPort
//----- ����int port, �˿ں� 1~65535
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
//----- ��������
//----- �������� SendData
//----- ���� QString data, Ҫ���͵�����
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


        // emit sg_SendMessage(1, tr("���ύ����"), this);
        //QDateTime now = QDateTime::currentDateTime();

        //m_Client->disconnectFromHost();//20200903
        //m_Client->disconnect();

    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- �ۺ��� ��socket��ȡ����
//----- �������� sl_ReadData
//----- ���� ��  dqc ����������ݽ������
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::sl_ReadData()
{
 //   qDebug() << " QTcpWork::sl_ReadData";
    int len = m_Client->bytesAvailable();
    QByteArray temp = m_Client->read( len );
    qDebug() << "20200904 void QTcpWork::sl_ReadData():" << temp << "\n";

   // emit sg_SendMessage(1, tr("�յ�����"), this);
    emit sg_SendMessage(2, temp, this);  //dqc 20200814��settcpserver����Ӧ�����Ϣ��ͨ��this��������ֱ�ӷ�������
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- �ۺ��� ����״̬�ı�
//----- �������� sl_ConnectStatus
//----- ���� QAbstractSocket::SocketState
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
            emit sg_SendMessage(1, tr("�����ж�"), this);
        }
        break;

    case QAbstractSocket::HostLookupState:
        {
         //   qDebug() << "QTcpWork::sl_ConnectStatus status:HostLookupState";
            //emit sg_SendMessage(1, tr("����������......"), this);
        }
        break;

    case QAbstractSocket::ConnectingState:
        {
          //  qDebug() << "QTcpWork::sl_ConnectStatus status:ConnectingState";
            //emit sg_SendMessage(1, tr("������������......"), this);
        }
        break;

    case QAbstractSocket::ConnectedState:
        {
            qDebug() << "QTcpWork::sl_ConnectStatus status:ConnectedState";
            isConnect = true;
            //emit sg_SendMessage(0, tr("changeStatus 1"), this);
            //emit sg_SendMessage(1, tr("���ӳɹ�"), this);
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
//----- ���ӵ�����
//----- �������� ConnectToHost
//----- ���� ��
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::ConnectToHost()
{
    m_Client->connectToHost(m_IpAddress, m_Port);
   // qDebug() << "QTcpWork::ConnectToHost";
    //emit sg_SendMessage(1, tr("��������ͨѶ"), this);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----- �������Ͽ�
//----- �������� DisConnectFromHost
//----- ���� ��
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void QTcpWork::DisConnectFromHost()
{
    m_Client->disconnectFromHost();
   //  qDebug() << "QTcpWork::DisConnectFromHost";
    //emit sg_SendMessage(1, tr("���ڶϿ�����"), this);
}

int QTcpWork::localPort()
{
    return m_Client->localPort();
}
