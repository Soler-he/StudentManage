#include "database.h"'

#include <QtSql/QSqlDriver>

QSqlDatabase *DataBase::db = NULL;

bool DataBase::createDataBase()
{
    if(db != NULL)
        return true;

    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE", "Student");
    db->setDatabaseName("Student.db");

    qDebug()<<"Creating Database \"db\" ...";
    if(!db->open())
    {
        qDebug()<<"Createa Database \"db\" failed";

        delete db;
        db = NULL;
        QSqlDatabase::removeDatabase("Student");

        return false;
    }

    qDebug()<<"Createa Database \"db\" success";
    checkDatabase();
    return true;
}

bool DataBase::checkTable(const QString &tblName)
{
    if(db == NULL)
        return false;
    QSqlQuery q(*db);
    QString sql = QString("SELECT COUNT(*) FROM sqlite_master WHERE [name] = '%1'").arg(tblName);
    if(!q.exec(sql))
        return false;
    if(!q.first())
    {
        q.finish();
        return false;
    }
    int count = q.value(0).toInt();
    q.finish();
    return (count > 0);
}

bool DataBase::createTable(const QString &tblName, const QStringList &fieldList)
{
    if(db == NULL)
        return false;
    if(fieldList.count() <= 0)
        return false;
    if(checkTable(tblName))
        return true;
    QSqlQuery q(*db);
    QString sql = QString("CREATE TABLE [%1] (").arg(tblName);
    QStringList::const_iterator i;
    for(i = fieldList.constBegin(); i != fieldList.constEnd(); ++i)
    {
        sql += (*i);
        sql += ",";
    }
    if(sql.at(sql.length() - 1) == ',')
        sql = sql.left(sql.length() - 1);
    else
        return false;
    sql += ")";
    bool ret = q.exec(sql);
    q.finish();
    return ret;
}

void DataBase::checkDatabase()  // 创建 表
{
    if(db == NULL)
        return;
    if(!checkTable("student"))
    {
        createTable("student", QStringList()
                    <<"[number] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"
                    <<"[name] TEXT  UNIQUE NOT NULL"
                    <<"[gender] TEXT  NOT NULL"
                    );
    }
    qDebug()<<"Create table \"student\" success";
    if(!checkTable("users"))
    {
        createTable("users",QStringList()
                    <<"[username] TEXT NOT NULL PRIMARY KEY"
                    <<"[password] TEXT NOT NULL"
                    );
    }

}

QString DataBase::findPassword(const QString &username)   // 根据 Card ID 查找 Name
{
    QString sql = QString("SELECT [password] FROM [users] WHERE [username] = '%1'").arg(username);
    QSqlQuery q(*db);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}














