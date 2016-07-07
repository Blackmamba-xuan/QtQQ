#ifndef WECHAT_H
#define WECHAT_H

#include <QWidget>
#include<QMouseEvent>
#include<QtGui>
#include<QDebug>
#include<QScrollBar>
#include<QFile>
namespace Ui {
class Wechat;
}

class Wechat : public QWidget
{
    Q_OBJECT

public:
    explicit Wechat(QWidget *parent = 0);
    ~Wechat();
    QPoint move_point; //移动的距离

        bool mouse_press; //鼠标按下
        //鼠标按下事件
        void mousePressEvent(QMouseEvent *event);
       //鼠标释放事件
        void mouseReleaseEvent(QMouseEvent *event);
       //鼠标移动事件
        void mouseMoveEvent(QMouseEvent *event);
        //最小化及关闭
     bool eventFilter(QObject *object, QEvent *e);
protected:
     void showEvent(QShowEvent *event);

private:
    Ui::Wechat *ui;
};

#endif // WECHAT_H
