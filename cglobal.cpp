#include "cglobal.h"
#include <QByteArray>

CGlobal::CGlobal()
{
}
CGlobal::~CGlobal()
{
}
int CGlobal::testValue2=1;    //全局方式 two

int testValue1=1; //全局方式 one

QSqlDatabase *db_lite;
QSqlDatabase *db_mysql;

QSqlQuery *q_savevalue;
QSqlTableModel *comm_cfg_sqlmodel;

/*全局方式 one 调用
#include "cglobal.h"
#include <QDebug>

qDebug()<<CGlobal::testValue1;
CGlobal::testValue=1;
qDebug()<<CGlobal::testValue1;
*/

/*全局方式 two 调用
#include "cglobal.h"
#include <QDebug>

qDebug()<<CGlobal::testValue2;
CGlobal::testValue=2;
qDebug()<<CGlobal::testValue2;
*/
