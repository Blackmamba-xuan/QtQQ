#include "mythread.h"


MyThread::MyThread(int socketDesciptor, QObject *parent)
    :QThread(parent),socketDesciptor(socketDesciptor)
{

}
void MyThread::run()
{
     tcpsocket=new QTcpSocket(this);
     tcpsocket->setSocketDescriptor(socketDesciptor);
     connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(handlmessage()));
}
void MyThread::handlmessage()
{
        QByteArray qba= tcpsocket->readAll(); //读取
        qDebug()<<qba;
        QString ss=QVariant(qba).toString();
        qDebug()<<ss;
}
