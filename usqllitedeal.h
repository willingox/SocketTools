/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef USQLLITEDEAL_H
#define USQLLITEDEAL_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include "cglobal.h"

/*
    This file defines a helper function to open a connection to an
    in-memory SQLITE database and to create a test table.

    If you want to use another database, simply modify the code
    below. All the examples in this directory use this function to
    connect to a database.
*/
//! [0]


bool IsTableExist(QSqlQuery &query,QString table)
{
   QString sql = QString("select * from sqlite_master where name='%1'").arg(table);
   query.exec(sql);
   return query.next();
}

static bool createConnection()
{
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("10.15.21.222");
        db.setPort(3306);
        db.setDatabaseName("WFC_Solution");
        db.setUserName("root");
        db.setPassword("root");
        if (!db.open()) {
            qDebug("Sql connect failed.");
            QMessageBox::warning(nullptr, "警告", "无法连接数据库");

        }
        else {
            qDebug("Sql connected.");
        }
*/

    db_lite =  new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));

    //db_lite = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName(":memory:");
    //QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

    db_lite->setDatabaseName("sys_params.db");
  //  db.setDatabaseName("WindmodbusReg.db");
    db_lite->setUserName("root");
    db_lite->setPassword("123456");

    if (!db_lite->open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


    db_mysql =  new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL","db_mysql")); // 如果要连接多个数据库，必须指定不同的连接名字，否则会覆盖上面的默认连接
   // db_mysql = QSqlDatabase::addDatabase("QMYSQL","db_mysql"); //db_mysql为指针连不上
    db_mysql->setHostName("117.78.7.51");
    db_mysql->setDatabaseName("shouzhenwuxian");
    db_mysql->setPort(3306);
    db_mysql->setUserName("shouzhenwuxian");
    db_mysql->setPassword("123qwe..");
  //  db_mysql->setConnectOptions("MYSQL_OPT_RECONNECT");

            /*
        mysql_init() ...
        mysql_real_connect()...
        char value = 1;
        mysql_options(&mysql, MYSQL_OPT_RECONNECT, (char *)&value);
        */

    if (! db_mysql->open()) {
            QSqlError e = db_mysql->lastError();
            qDebug() << "QSqlError:" << e.text();

 //           qFatal("ServerDB db_mysql : Failed initialization: %s",qPrintable(e.text()));
//            return false;
        }
    else
    {
         qDebug() << "QSql connected:" ;//调试打印
         qDebug("QSql connected:!");//输出日志
    }
/**/
/*
    void q2::on_pushButton_clicked()
    {
        if (db->isValid())
        {
            QSqlQuery query;    // 查默认库，即 db

            if (query.prepare("select * from users"))
            {
                if (query.exec())
                {
                    if (query.next())
                        ui.pushButton->setText(query.value(2).toString());
                    else
                        qWarning("SQL Error [%s]: %s", qPrintable(query.lastQuery()), qPrintable(query.lastError().text()));
                }
                else
                {
                    qWarning("SQL Error [%s]: %s", qPrintable(query.lastQuery()), qPrintable(query.lastError().text()));
                }
            }
            else
            {
                qWarning("SQL Error [%s]: %s", qPrintable(query.lastQuery()), qPrintable(query.lastError().text()));
            }
        }
        else
        {
            qWarning("SQL rejected: Database is gone");
        }
    }

    void q2::on_pushButton_2_clicked()
    {
        if (db2->isValid())
        {
            QSqlQuery query(*db2);    // 查另一个数据库 db2

            if (query.prepare("select * from users"))
            {
                if (query.exec())
                {
                    if (query.next())
                        ui.pushButton_2->setText(query.value(2).toString());
                    else
                        qWarning("SQL Error [%s]: %s", qPrintable(query.lastQuery()), qPrintable(query.lastError().text()));
                }
                else
                {
                    qWarning("SQL Error [%s]: %s", qPrintable(query.lastQuery()), qPrintable(query.lastError().text()));
                }
            }
            else
            {
                qWarning("SQL Error [%s]: %s", qPrintable(query.lastQuery()), qPrintable(query.lastError().text()));
            }
        }
        else
        {
            qWarning("SQL rejected: Database is gone");
        }
    }
    */
    //创建数据表
    /*
    QSqlQuery query;
    if(!IsTableExist(query,"inputReg") )
        query.exec("create table inputReg (id int primary key, fname varchar(20), fvarname varchar(50), "
                   "funit varchar(10), fdtype varchar(6), fregaddr int, fvalue float)");

    if(!IsTableExist(query,"holdReg") )
        query.exec("create table holdReg (id int primary key, fname varchar(20), fvarname varchar(50), "
                   "funit varchar(10), fdtype varchar(6), fregaddr int, fvalue float)");

    if(!IsTableExist(query,"coils") )
        query.exec("create table coils (id int primary key, fname varchar(20), fvarname varchar(50), "
                   "funit varchar(10), fdtype varchar(6), fregaddr int, fvalue float)");
    if(!IsTableExist(query,"disc") )
        query.exec("create table disc (id int primary key, fname varchar(20), fvarname varchar(50), "
                   "funit varchar(10), fdtype varchar(6), fregaddr int, fvalue float)");
    if(!IsTableExist(query,"test") )
        query.exec("create table test (id int primary key, fname varchar(20), fvarname varchar(50), "
                   "funit varchar(10), fdtype varchar(6), fregaddr int, fvalue float)");
*/
    /*
    QSqlQuery query;
    query.exec("create table person (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Danny', 'Young')");
    query.exec("insert into person values(102, 'Christine', 'Holand')");
    query.exec("insert into person values(103, 'Lars', 'Gordon')");
    query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

    query.exec("create table items (id int primary key,"
                                             "imagefile int,"
                                             "itemtype varchar(20),"
                                             "description varchar(100))");
    query.exec("insert into items "
               "values(0, 0, 'Qt',"
               "'Qt is a full development framework with tools designed to "
               "streamline the creation of stunning applications and  "
               "amazing user interfaces for desktop, embedded and mobile "
               "platforms.')");
    query.exec("insert into items "
               "values(1, 1, 'Qt Quick',"
               "'Qt Quick is a collection of techniques designed to help "
               "developers create intuitive, modern-looking, and fluid "
               "user interfaces using a CSS & JavaScript like language.')");
    query.exec("insert into items "
               "values(2, 2, 'Qt Creator',"
               "'Qt Creator is a powerful cross-platform integrated "
               "development environment (IDE), including UI design tools "
               "and on-device debugging.')");
    query.exec("insert into items "
               "values(3, 3, 'Qt Project',"
               "'The Qt Project governs the open source development of Qt, "
               "allowing anyone wanting to contribute to join the effort "
               "through a meritocratic structure of approvers and "
               "maintainers.')");

    query.exec("create table images (itemid int, file varchar(20))");
    query.exec("insert into images values(0, 'images/qt-logo.png')");
    query.exec("insert into images values(1, 'images/qt-quick.png')");
    query.exec("insert into images values(2, 'images/qt-creator.png')");
    query.exec("insert into images values(3, 'images/qt-project.png')");
*/
    /*
例如：用第一种方法绑定
sql_query.prepare("INSERTINTOPersons(id,name,slary)VALUES(?,?,?)");
sql_query.addBindValue(2);
sql_query.addBindValue("taopeng");
sql_query.addBindValue(25);
if(sql_query.exec())

或者：第二种方法：
sql_query.prepare("INSERTINTOPersons(id,name,age)VALUES(:id,:name,:bbb)");
sql_query.bindValue(":id",4);
sql_query.bindValue(":name","taopeng");
sql_query.bindValue(":bbb",25);

*/
    return true;
}
//! [0]

#endif // USQLLITEDEAL_H
