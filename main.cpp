#include "widget.h"
#include <QApplication>
#include<form.h>
#include "talk.h"
#include "drawer.h"
#include "one.h"
#include "chat.h"
#include "wechat.h"
#include "search.h"
#include "emotion.h"
#include "mymessagebox.h"
#include<QTextCodec>
#include "sunshine.h"
#include "friendmsg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    Form f;
    f.show();
    //Sunshine s;
    //s.show();
    //Talk t;
    //t.show();
    //Talk* ta=new Talk();
    //ta->show();
    //Talk t;
    //t.show();
    //Drawer d;
    //d.show();
    //One* one=new One;
    //one->show();
    //Chat c;
    //c.show();
    //Wechat w;
   // w.show();
    //Search s;
    //s.show();
    //Emotion e;
    //e.show();
     //Mymessagebox m;
     //m.show();
    //Friendmsg fs;
    //fs.show();
     QTextCodec* codec=QTextCodec::codecForName("UTF-8");
     QTextCodec::setCodecForLocale(codec);

    return a.exec();
}

