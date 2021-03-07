/*dqc tcp service
 *
 */

#include "dialogtcpserver.h"
#include "ui_dialogtcpserver.h"

#include <QPushButton>
#include <QIntValidator>

DialogTcpServer::DialogTcpServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTcpServer)
{
    ui->setupUi(this);
	ui->buttonBox->setStandardButtons(/*QDialogButtonBox::Apply|*/QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringLiteral("ok"));
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("cancel"));
 //           ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QString::fromLocal8Bit("ȷ��"));//��buttonbox�е�ok ��ɺ���
 //           ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QString::fromLocal8Bit("ȡ��"));
    ui->lineEdit_port->setValidator(new QIntValidator(0, 65535, this));
}

DialogTcpServer::~DialogTcpServer()
{
    delete ui;
}

int DialogTcpServer::getPort()
{
    m_port = ui->lineEdit_port->text().toInt();
    return m_port;
}

void DialogTcpServer::on_buttonBox_accepted()
{
    //m_port = ui->lineEdit_port->text().toInt();
}
