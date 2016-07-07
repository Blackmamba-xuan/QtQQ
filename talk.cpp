#include "talk.h"
#include "ui_talk.h"

Talk::Talk(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Talk)
{
    ui->setupUi(this);
    i=0;
    //setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    setAutoFillBackground(true);
    ui->label->installEventFilter(this);
    ui->label_2->installEventFilter(this);
    ui->label_9->installEventFilter(this);
    ui->label_10->installEventFilter(this);
    ui->label_8->installEventFilter(this);

    QImage image;
    image.load(":/myicon_3.png");
    QImage result = image.scaled(40, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label_4->setPixmap(QPixmap::fromImage(result));

    QImage image2;
    image2.load(":/kobe_1.jpg");
    QImage result2 = image2.scaled(55, 55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label_3->setPixmap(QPixmap::fromImage(result2));
    ui->label_3->setStyleSheet("QLabel{padding:2px;border-radius:4px;}QLabel:hover{border:2px solid rgb(12, 255, 235);}");

    QImage image3;
    image3.load(":/myicon_1.png");
    //QImage result3 = image3.scaled(255, 511, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //QPalette palette(ui->widget->palette());
    //palette.setBrush(ui->widget->backgroundRole(), QBrush(result3));
    //ui->widget->setAutoFillBackground(true);
    //ui->widget->setPalette(palette);
    //ui->widget->show();
    //ui->widget->setWindowOpacity(0.7);
    qstacklayout=new QStackedLayout;
    ui->widget_2->setLayout(qstacklayout);
    //One* one=new One;
    drwer=new Drawer(this);
    two=new Two;
    qstacklayout->addWidget(drwer);
    qstacklayout->addWidget(two);
    QRect rect = QApplication::desktop()->availableGeometry();

    move(rect.width() - width()-280,5);
    QIcon icon = QIcon(":/kobe_1.jpg"); //png,ico,svg,bmp各种格式，尺寸无限制（推荐60x60），加载图标可以用相对、绝对、资源路径
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);
    trayIcon->show();
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                   this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    m_pShowTimer = new QTimer(this);
    m_pShowTimer2 = new QTimer(this);
    connect(m_pShowTimer, SIGNAL(timeout()), this, SLOT(onMove()));
    connect(m_pShowTimer2, SIGNAL(timeout()), this, SLOT(onMove2()));
    //setMouseTracking(true);
    mouse_press=false;
    ui->label_8->installEventFilter(this);
    ui->label_9->installEventFilter(this);
    ui->label_10->installEventFilter(this);

    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(showResearch()));
    //与server端建立连接
    socket=new QTcpSocket(this);
    socket->connectToHost("172.29.107.7",12306);
    connect(socket,SIGNAL(readyRead()),this,SLOT(resolveMessage()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(solvedisconnect()));

}

Talk::~Talk()
{
    delete ui;
}
void Talk::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->screenPos();
    if(event->button() == Qt::LeftButton)
     {
        qDebug()<<"鼠标左键";
         this->setMouseTracking(true);
          mouse_press = true;
          //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
          move_point = event->pos();
          qDebug()<<event->source();
     }

}

void Talk::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
        mouse_press = false;
    qDebug()<<"鼠标释放事件促发了";
    if(y()<=0)
    {
        qDebug()<<"y的坐标是0";
        m_nDesktopHeight=0;
        m_pShowTimer->start(0.5);
    }
}

void Talk::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
  //  qDebug()<<"mouse_press="<<event->globalPos();
      qDebug()<<"进入了移动这个函数";
        if(mouse_press)
        {
            i++;
            //鼠标相对于屏幕的位置
            QPoint move_pos = event->globalPos();
             qDebug()<<"移动"<<i;
           //移动主窗体位置
           this->move(move_pos - move_point);
        }
        qDebug()<<"鼠标在移动";
}

bool Talk::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label){
        hide();
        qDebug()<<"最小化";
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_2){
         close();
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_9){
        qDebug()<<"点击了第一页";
        qstacklayout->setCurrentIndex(0);
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_10){
        qDebug()<<"点击了第二页";
        qstacklayout->setCurrentIndex(1);
    }
    else if(object==ui->label_8&&e->type()==QEvent::Enter&&y()<0){
        qDebug()<<"鼠标进入了标签且y小于0";
         qDebug()<<e->type();
        //move(x(),5);
         m_nDesktopHeight2=y();
         m_pShowTimer2->start(0.5);

    }
    else if(object==ui->label_9&&e->type()==QEvent::Enter&&y()<0){
        qDebug()<<"鼠标进入了标签且y小于0";
        qDebug()<<e->type();
       //move(x(),5);
        m_nDesktopHeight2=y();
        m_pShowTimer2->start(0.5);
    }
    else if(object==ui->label_10&&e->type()==QEvent::Enter&&y()<0){
        qDebug()<<"鼠标进入了标签且y小于0";
         qDebug()<<e->type();
        //move(x(),5);
         m_nDesktopHeight2=y();
         m_pShowTimer2->start(0.5);
    }
    return false;
}
void Talk::paintEvent(QPaintEvent *event)
{
    QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(3, 3, this->width()-6, this->height()-6);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.fillPath(path, QBrush(Qt::white));

        QColor color(0, 0, 0, 75);
        for(int i=0; i<3; i++)
        {
            QPainterPath path;
            path.setFillRule(Qt::WindingFill);
            path.addRect(3-i, 3-i, this->width()-(3-i)*2, this->height()-(3-i)*2);
            color.setAlpha(50 - qSqrt(i)*25);
            painter.setPen(color);
            painter.drawPath(path);
        }
}
void Talk::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {

    case QSystemTrayIcon::DoubleClick:


        break;
    case QSystemTrayIcon::Trigger:

        //后面两个默认参数
        mouse_press=false;
        showNormal();
        raise();
        activateWindow();
        move(x(),5);
        break;
    case QSystemTrayIcon::MiddleClick:

        break;
    default:
        break;
    }
}
void Talk::hideEvent(QHideEvent *event)
{
    qDebug()<<"123";
    if(trayIcon->isVisible())
    {
        hide(); //隐藏窗口
        event->ignore(); //忽略事件
    }
}
void Talk::onMove()
{
    qDebug()<<"移动了"<<m_nDesktopHeight;
    m_nDesktopHeight--;
    move(x(), m_nDesktopHeight);
    if (m_nDesktopHeight <= -610)
    {
        m_pShowTimer->stop();
        //hide();
    }
}
void Talk::onMove2()
{
    qDebug()<<"移动了"<<m_nDesktopHeight2;
    m_nDesktopHeight2++;
    move(x(), m_nDesktopHeight2);
    if (y() >=5)
    {
        m_pShowTimer2->stop();
        //hide();
    }
}
//查找好友
void Talk::showResearch()
{
    Search* s=new Search();
    s->show();
    s->doSearch(ui->lineEdit->text());
}

void Talk::resolveMessage()
{
    QByteArray qba= socket->readAll(); //读取

        QString ss=QVariant(qba).toString();
        qDebug()<<ss;
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(ss.toUtf8(), &error);
        //QString ss=QVariant(qba).toString();
        //qDebug("%s", qba);
        //qDebug()<<ss;
        if (error.error == QJsonParseError::NoError) {
            if (jsonDocument.isObject()) {
                /*QVariantMap result = jsonDocument.toVariant().toMap();
                qDebug()<<result;
                qDebug()<<result["userinfo"].toJsonArray();
                foreach (QVariant plugin, result["userinfo"].toList()) {
                            qDebug()<<plugin.toString();
                   }*/
                QJsonObject obj=jsonDocument.object();
                //QJsonArray array=obj["userinfo"].toArray();
                QJsonObject obj1=obj["usersInfoVo"].toObject();
                qDebug()<<obj1["name"].toString();
                ui->label_6->setText(obj1["name"].toString());
                ui->label_7->setText(obj1["sign"].toString());
                QJsonArray friends=obj1["friends"].toArray();
                qDebug()<<friends;
                for(int j=0;j<friends.size();j++){
                    QJsonObject myfriend=friends[i].toObject();
                    qDebug()<<myfriend["name"];
                    QString name;
                    if(myfriend["onLine"]==false)
                        name=myfriend["name"].toString()+"[离线]";
                    else
                        name=myfriend["name"].toString()+"[在线]";
                    drwer->addfriend(name,myfriend["sign"].toString());
                }


            }
        } else {
           qDebug()<<"解析失败";
        }
       // socket->write(qba);
}
void Talk::init(QByteArray byte_array)
{
    qDebug()<<byte_array.append('\n');
    qDebug()<<byte_array;
    socket->write(byte_array);
}
void Talk::solvedisconnect()
{
    qDebug()<<"socket连接断了";
}

