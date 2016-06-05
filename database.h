#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class DataBase
{


//public:
//    static bool Create();
//    static void Destroy();

//protected:
//    static QSqlDatabase *_mainDB;
//    static bool checkTable(const QString &tblName);
//    static bool createTable(const QString &tblName, const QStringList &fieldList);
//    static void removeTable(const QString &tblName);
//    static void checkDatabase();



public:
    static bool createDataBase();
    static QString findPassword(const QString &username);

protected:
    static QSqlDatabase *db;
    static bool checkTable(const QString &tblName);
    static bool createTable(const QString &tblName, const QStringList &fieldList);
    static void checkDatabase();



};

#endif // DATABASE_H
