#include "friendmsg.h"
#include "ui_friendmsg.h"

Friendmsg::Friendmsg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Friendmsg)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);


}

Friendmsg::~Friendmsg()
{
    delete ui;
}
