#ifndef MYCHATWIDGET_H
#define MYCHATWIDGET_H

#include <QWidget>

namespace Ui {
class Mychatwidget;
}

class Mychatwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Mychatwidget(QWidget *parent = 0);
    ~Mychatwidget();

private:
    Ui::Mychatwidget *ui;
public slots:
    void changehight();
};

#endif // MYCHATWIDGET_H
