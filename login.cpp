#include "login.h"
#include "database.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle(tr("登录界面"));
    mainWindow = new Widget;

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->nameEdit->text();
    if(ui->passwordEdit->text().isEmpty() || ui->passwordEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码不能为空！"));
    }
    else if(ui->passwordEdit->text() == DataBase::findPassword(username))
    {
        this->hide();
        mainWindow->show();
    }
    else
    {
        QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码错误！"));
    }

}
