#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    hlayout = new QHBoxLayout;
    hlayout->addWidget(ui->pushButton);
    hlayout->addWidget(ui->pushButton_2);
    hlayout->addWidget(ui->pushButton_3);
    hlayout->addSpacerItem(ui->horizontalSpacer);
    hlayout->addWidget(ui->lineEdit);
    hlayout->addWidget(ui->pushButton_4);
    layout = new QVBoxLayout;
    layout->addLayout(hlayout);
    layout->addWidget(ui->treeWidget);

    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
