#ifndef EMOTION_H
#define EMOTION_H

#include <QWidget>
#include<QGridLayout>
#include<QLabel>
namespace Ui {
class Emotion;
}

class Emotion : public QWidget
{
    Q_OBJECT

public:
    explicit Emotion(QWidget *parent = 0);
    ~Emotion();
     bool eventFilter(QObject *object, QEvent *e);
signals:
     void imgurl(QString imgurl);
private slots:
     void on_pushButton_clicked();

private:
    Ui::Emotion *ui;

};

#endif // EMOTION_H
