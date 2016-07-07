#-------------------------------------------------
#
# Project created by QtCreator 2016-03-25T19:46:58
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    form.cpp \
    talk.cpp \
    one.cpp \
    two.cpp \
    mylistwidget.cpp \
    drawer.cpp \
    chat.cpp \
    mychatwidget.cpp \
    wechat.cpp \
    search.cpp \
    emotion.cpp \
    mymessagebox.cpp \
    sunshine.cpp \
    mythread.cpp \
    friendmsg.cpp

HEADERS  += widget.h \
    form.h \
    talk.h \
    one.h \
    two.h \
    mylistwidget.h \
    drawer.h \
    chat.h \
    mychatwidget.h \
    wechat.h \
    search.h \
    emotion.h \
    mymessagebox.h \
    sunshine.h \
    mythread.h \
    friendmsg.h

FORMS    += widget.ui \
    form.ui \
    talk.ui \
    one.ui \
    two.ui \
    mylistwidget.ui \
    chat.ui \
    mychatwidget.ui \
    wechat.ui \
    search.ui \
    emotion.ui \
    mymessagebox.ui \
    sunshine.ui \
    friendmsg.ui

RESOURCES += \
    resource.qrc \
    imagesrc.qrc
RC_FILE = myapp.rc
