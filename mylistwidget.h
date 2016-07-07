#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QWidget>

namespace Ui {
class Mylistwidget;
}

class Mylistwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Mylistwidget(QWidget *parent = 0);
    ~Mylistwidget();
    void init(QString name,QString sign);

private:
    Ui::Mylistwidget *ui;
};

#endif // MYLISTWIDGET_H
