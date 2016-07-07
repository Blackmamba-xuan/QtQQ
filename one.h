#ifndef ONE_H
#define ONE_H

#include <QWidget>

namespace Ui {
class One;
}

class One : public QWidget
{
    Q_OBJECT

public:
    explicit One(QWidget *parent = 0);
    ~One();

private:
    Ui::One *ui;
};

#endif // ONE_H
