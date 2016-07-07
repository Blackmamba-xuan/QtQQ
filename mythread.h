#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QThread>
#include<QtNetwork>
#include<QTcpSocket>
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(int socketDesciptor,QObject *parent=0);
    void run();
private:
    int socketDesciptor;
    QTcpSocket* tcpsocket;
public slots:
    void handlmessage();
};

#endif // MYTHREAD_H
