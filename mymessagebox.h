#ifndef MYMESSAGEBOX_H
#define MYMESSAGEBOX_H

#include <QWidget>

namespace Ui {
class Mymessagebox;
}

class Mymessagebox : public QWidget
{
    Q_OBJECT

public:
    explicit Mymessagebox(QWidget *parent = 0);
    ~Mymessagebox();
     bool eventFilter(QObject *object, QEvent *e);
private:
    Ui::Mymessagebox *ui;
};

#endif // MYMESSAGEBOX_H
