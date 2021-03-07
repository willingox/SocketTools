/*dqc tcp service
 *
 */
#ifndef DIALOGTCPSERVER_H
#define DIALOGTCPSERVER_H

#include <QDialog>

namespace Ui {
    class DialogTcpServer;
}

class DialogTcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTcpServer(QWidget *parent = 0);//显示构造函数，避免隐转换
    ~DialogTcpServer();

    int getPort();

private:
    Ui::DialogTcpServer *ui;
    int m_port;

private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGTCPSERVER_H
