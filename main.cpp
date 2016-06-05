#include "login.h"
#include "database.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login loginWindow;


    loginWindow.show();

    qDebug()<<QSqlDatabase::drivers();
    DataBase::createDataBase();


    return a.exec();
}
