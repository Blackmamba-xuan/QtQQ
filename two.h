#ifndef TWO_H
#define TWO_H

#include <QWidget>
#include<QListWidgetItem>
namespace Ui {
class Two;
}

class Two : public QWidget
{
    Q_OBJECT

public:
    explicit Two(QWidget *parent = 0);
    ~Two();

private:
    Ui::Two *ui;
public slots:
    void changeheight(QListWidgetItem* item);
};

#endif // TWO_H
