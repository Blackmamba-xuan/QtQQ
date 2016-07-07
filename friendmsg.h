#ifndef FRIENDMSG_H
#define FRIENDMSG_H

#include <QWidget>

namespace Ui {
class Friendmsg;
}

class Friendmsg : public QWidget
{
    Q_OBJECT

public:
    explicit Friendmsg(QWidget *parent = 0);
    ~Friendmsg();

private:
    Ui::Friendmsg *ui;
};

#endif // FRIENDMSG_H
