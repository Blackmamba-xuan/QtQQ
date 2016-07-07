#include "mylistwidget.h"
#include "ui_mylistwidget.h"

Mylistwidget::Mylistwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mylistwidget)
{
    ui->setupUi(this);
}

Mylistwidget::~Mylistwidget()
{
    delete ui;
}
void Mylistwidget::init(QString name,QString sign)
{
    ui->label_3->setText(name);
    ui->label_4->setText(sign);
}
