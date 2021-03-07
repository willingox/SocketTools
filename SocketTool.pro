#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T11:04:57
#
#-------------------------------------------------

QT       += core gui sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SocketTool
TEMPLATE = app


SOURCES += main.cpp\
    cglobal.cpp \
    log.cpp \
        mainwindow.cpp \
    qtitemtest.cpp \
    tcpwork.cpp \
    settcpserver.cpp \
    dialogtcpserver.cpp

HEADERS  += mainwindow.h \
    cglobal.h \
    log.h \
    qtitemtest.h \
    tcpwork.h \
    settcpserver.h \
    dialogtcpserver.h \
    usqllitedeal.h

FORMS    += mainwindow.ui \
    dialogtcpserver.ui

RESOURCES += \
    SocketTool.qrc
RC_FILE = SocketTool.rc
