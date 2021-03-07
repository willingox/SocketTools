#include <QtWidgets/QApplication>   //#include <QtGui/QApplication> this is qt4
#include "mainwindow.h"
#include <QTextCodec>
#include "usqllitedeal.h"
#include "log.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));  //linux 下出错

    //注册监听级别函数
    //qInstallMessageHandler(myMessageOutput);

    if (!createConnection())
       return EXIT_FAILURE;

    logSysInit("log.txt");
    //运行日志示例
    qDebug("sockettool start!");
    //qWarning("This is a warning message");
    //qCritical("This is a critical message");
    //qFatal("This is a fatal message");

    MainWindow w;
    w.resize(1200,600);
    QDesktopWidget *deskdop = QApplication::desktop();
    w.move((deskdop->width() - w.width())/2,(deskdop->height() - w.height())/2);
    //   w.move(10,10);
    // w.setGeometry(100,100,1200,600);
    // a.move((wdesktop()->width() - window.width()) / 2, (app.desktop()->height() - window.height()) / 2);
    w.setWindowTitle("数据采集实验");
    w.show();

    return a.exec();
}





