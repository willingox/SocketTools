#ifndef CGLOBAL_H
#define CGLOBAL_H
#include <QByteArray>
#include <QSqlTableModel>


extern int testValue1;//全局方式 one

extern QSqlDatabase *db_lite;
extern QSqlDatabase *db_mysql;

extern QSqlTableModel *comm_cfg_sqlmodel;
extern QSqlQuery *q_savevalue;

typedef unsigned char BYTE;
typedef unsigned short WORD;
//数据召唤的起始地址和长度 20181023

#define MAKEWORD(a, b)      	((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKELONG(a, b)      	((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define MAKEDWORD(a, b)      	((DWORD)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define LOWORD(l)           		((WORD)(l))
#define HIWORD(l)           		((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#define LOBYTE(w)          		((BYTE)(w))
#define HIBYTE(w)           		((BYTE)(((WORD)(w) >> 8) & 0xFF))

//WORD wind_straddr[7] = { 5000,5124,5248,5372,5496,5620,5744 };
//WORD wind_framelen[7] = { 124,124,124,124,124,124,41 };
class CGlobal
{
public:
    CGlobal();
    ~CGlobal();

    typedef struct WindDataUnitType
    {
        QString m_windno;
        float m_floatvalue[175];                  //175 个浮点数
        unsigned long m_uintvalue[125];           //125 个长整型
        unsigned short m_intvalue[185];          //185 个短整型
    }WindDataUnit;    // 名称可随便

public:
    static int testValue2;  //全局方式 two
};

#endif // CGLOBAL_H




