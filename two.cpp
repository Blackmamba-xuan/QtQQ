#include "two.h"
#include "ui_two.h"
#include"mylistwidget.h"
#include "QListWidgetItem"
#include<QListWidget>
#include<QVBoxLayout>
#include<mychatwidget.h>
#include<QDebug>
Two::Two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Two)
{
    ui->setupUi(this);
    QVBoxLayout* layout=new QVBoxLayout(ui->listWidget);
    QListWidgetItem* item1=new QListWidgetItem();
    item1->setSizeHint(QSize(0,35));
    Mychatwidget* m1=new Mychatwidget();
    ui->listWidget->addItem(item1);
    ui->listWidget->setItemWidget(item1,m1);
    ui->listWidget->setStyleSheet("QListWidget::item:hover {background-color:#FCF0C1;}");
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),m1,SLOT(changehight()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(changeheight(QListWidgetItem*)));

}

Two::~Two()
{
    delete ui;
}
void Two::changeheight(QListWidgetItem* item)
{
    qDebug()<<"进入了";
    item->setSizeHint(QSize(0,60));
}
