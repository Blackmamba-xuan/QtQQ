#ifndef DRAWER_H
#define DRAWER_H

#include <QObject>
#include <QToolBox>
#include <QToolButton>
#include<QListWidgetItem>

class Drawer : public QToolBox
{
    Q_OBJECT
public:
    Drawer(QWidget *parent=0,Qt::WindowFlags f=0);
    void addfriend(QString name,QString sign);
private:

    QListWidget* listWidget;
    QListWidget* listWidget2;
public slots:
    void showitemclick(QListWidgetItem *item);
};

#endif // DRAWER_H
