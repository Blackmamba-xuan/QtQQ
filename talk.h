#ifndef TALK_H
#define TALK_H

#include <QWidget>
#include<QLabel>
#include<QMovie>
#include<QMouseEvent>
#include<QDebug>
#include<QPropertyAnimation>
#include<QImage>
#include<QDesktopServices>
#include<QPropertyAnimation>
#include<QPainter>
#include<QRect>
#include "qmath.h"
#include<QStackedLayout>
#include<QRect>
#include<QDesktopWidget>
#include<QHideEvent>
#include<QSystemTrayIcon>
#include<QTimer>
#include "one.h"
#include "two.h"
#include "drawer.h"
#include "search.h"
#include<QTcpSocket>
namespace Ui {
class Talk;
}

class Talk : public QWidget
{
    Q_OBJECT

public:
    explicit Talk(QWidget *parent = 0);
    ~Talk();
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
         void paintEvent(QPaintEvent *event);
       void hideEvent(QHideEvent *event);
       void init(QByteArray byte_array);


private:
    Ui::Talk *ui;
    int i;
    QStackedLayout* qstacklayout;
     QSystemTrayIcon* trayIcon;
     QTimer* m_pShowTimer;
     QTimer* m_pShowTimer2;
     int m_nDesktopHeight;
     int m_nDesktopHeight2;
     Drawer* drwer;
     Two* two;
     QTcpSocket* socket;
public slots:
     void iconActivated(QSystemTrayIcon::ActivationReason reason);
     void onMove();
      void onMove2();
      void showResearch();
      void resolveMessage();
      void solvedisconnect();
};

#endif // TALK_H
