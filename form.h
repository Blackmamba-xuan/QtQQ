#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QLabel>
#include<QMovie>
#include<QMouseEvent>
#include<QDebug>
#include<QPropertyAnimation>
#include<QImage>
#include<QDesktopServices>
#include<QPropertyAnimation>
#include<QNetworkAccessManager>
#include<QCryptographicHash>
#include "talk.h"
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
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

private slots:
     void on_pushButton_clicked();

     void on_lineEdit_2_returnPressed();
     void on_lineEdit_textEdited(const QString &arg1);
     void parseresult(QNetworkReply* reply);


protected:
     void showEvent(QShowEvent *event);
private:
    Ui::Form *ui;
    int i;
    QPropertyAnimation *animation;
    QByteArray byte_array;//发送验证信息
};

#endif // FORM_H
