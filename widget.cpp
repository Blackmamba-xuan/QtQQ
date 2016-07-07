#include "widget.h"
#include "ui_widget.h"
#include <qmessagebox.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //this->installEventFilter(this);
    ui->setupUi(this);
     ui->label_3->installEventFilter(this);
     ui->label->installEventFilter(this);
     ui->label_2->installEventFilter(this);
    //this->setMouseTracking(true);
     QMovie *movie = new QMovie(":/purple0.4.gif");
    setWindowFlags(Qt::FramelessWindowHint);
    //this->setAutoFillBackground(true);
    QString qss;
      QFile qssFile(":/myqss/login.qss");

      qssFile.open(QFile::ReadOnly);
      qDebug()<<"sdfasd";
      if(qssFile.isOpen())

      {

        qss = QLatin1String(qssFile.readAll());

        this->setStyleSheet(qss);

        qssFile.close();
        qDebug()<<"成功引入qss";

      }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
     {
        this->setMouseTracking(true);
          mouse_press = true;
          //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
          move_point = event->pos();;
     }

}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
        mouse_press = false;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
  //  qDebug()<<"mouse_press="<<event->globalPos();
        if(!mouse_press)
        {
            //鼠标相对于屏幕的位置
            QPoint move_pos = event->globalPos();

           //移动主窗体位置
           qDebug()<<"移动";
           this->move(move_pos - move_point);
        }
}

bool Widget::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label)
    {
         close();
        
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_2){
        showMinimized();
    }
    return false;
}


