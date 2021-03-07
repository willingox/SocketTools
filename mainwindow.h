#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>//#include <QMainWindow>
#include "tcpwork.h"
#include <QtGui>
#include "settcpserver.h"


namespace Ui {
    class MainWindow;
}

QT_BEGIN_NAMESPACE
class QTcpClient;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addtip(QString strline);
	static bool  hexToAsciiFlag;

private:
    Ui::MainWindow *ui;

    QTcpWork m_TcpWork;
    QTcpServer * m_tcpServer;
    QSetTcpServer *newServer;
    QString m_ip;      //----- ��̨ͨ��IP��ַ
    //int m_port;        //----- ��̨ͨ�Ŷ˿�

    bool server_status;

    QList<QTcpWork*> mp_tcpClient_list;
    QList<QSetTcpServer*> mp_tcpServer_list;

    int run_mode;    
    QTreeWidget *m_tree_root;
    QTreeWidgetItem *m_TcpServerRoot;

    QList<QTcpWork*> mp_removeClient_list;

    QGridLayout *gridLayout_receive;
    QGridLayout *groupBox_dataSend;
    QTextEdit *m_textRecevieWindow; //receive text
    QTextEdit *m_textSendWindow;    //send text

    int timer_startsend,timer_saveValue;//dqc 20200828
private slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_create_clicked();
	void on_pushButton_listen_clicked();
    void on_treeWidget_root_itemClicked(QTreeWidgetItem* item, int column);
    void show_message(int type, QString message,QSetTcpServer *CurTcpServer);
	void show_message(int type, QString message,int i);


    //void read_click_UdpClientToServer(QString,int);

    void on_treeWidget_root_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    void Send_Data(QString data);
    void checkClientList();
    void createRootNode(QTreeWidgetItem *rootItem, const QString &nodeName);
    void createTcpServer();
    void addTcpServer(QTreeWidgetItem *tcpServerItem, int port);
    void click_TcpServer();

    void sleep(unsigned int msec);  //----- ��ʱ����
};

#endif // MAINWINDOW_H
