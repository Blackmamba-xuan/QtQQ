#include "one.h"
#include "ui_one.h"
#include<QToolBox>
#include<QListWidget>
#include<QListWidgetItem>
#include"mylistwidget.h"
#include"drawer.h"
#include"QVBoxLayout"
One::One(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::One)
{
    ui->setupUi(this);
    //this->setLayout();
    QVBoxLayout* boxlayout=new QVBoxLayout(this);
    Drawer* d=new Drawer(this);
    boxlayout->addWidget(d);
    this->setLayout(boxlayout);


}

One::~One()
{
    delete ui;
}
