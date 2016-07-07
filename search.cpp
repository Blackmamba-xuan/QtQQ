#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    ui->label_4->installEventFilter(this);
    ui->label_5->installEventFilter(this);

    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->pushButton_2->setVisible(false);

}

Search::~Search()
{
    delete ui;
}

void Search::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
     {
         this->setMouseTracking(true);
          mouse_press = true;
          //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
          move_point = event->pos();
          qDebug()<<"移动1";
          qDebug()<<event->source();
     }

}

void Search::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
        mouse_press = false;

}

void Search::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
  //  qDebug()<<"mouse_press="<<event->globalPos();
        if(mouse_press)
        {

            //鼠标相对于屏幕的位置
            QPoint move_pos = event->globalPos();
           //移动主窗体位置
           this->move(move_pos - move_point);
        }
}

bool Search::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label_3)
    {
         //this->close();
         //e->ignore();
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_2){
        showMinimized();
        qDebug()<<"最小化";
        qDebug()<<mouse_press;

    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_4){

        ui->label_4->setStyleSheet("color:white;font-size:16px;font-weight:bold;");
        ui->label_5->setStyleSheet("color:white");
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_5){

        ui->label_5->setStyleSheet("color:white;font-size:16px;font-weight:bold;");
        ui->label_4->setStyleSheet("color:white");
    }

    return false;
}

void Search::showEvent(QShowEvent *event)
{
     qDebug()<<"出现了";
     mouse_press=false;
     qDebug()<<mouse_press;
}


void Search::on_pushButton_2_clicked()
{

}
void Search::doSearch(QString message)
{
    ui->lineEdit->setText(message);
}

void Search::on_pushButton_clicked()
{
    QNetworkAccessManager* network_manager = new QNetworkAccessManager();
    QNetworkRequest network_request;
    QByteArray post_data;
    QJsonObject json;
    //QByteArray bb;
//        QString pwd=ui->lineEdit_2->text();
//        bb = QCryptographicHash::hash ( pwd.toUtf8(), QCryptographicHash::Md5 );
//        pwd=bb.toHex();
    //QByteArray mid="你好";
    //QString ID=QString::fromUtf8(mid);

    json.insert("findID",ui->lineEdit->text());

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    post_data.append("data="+byte_array);
    network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    network_request.setHeader(QNetworkRequest::ContentLengthHeader, post_data.length());
    network_request.setUrl(QUrl("http://172.29.107.7:8080/ChatProject/chat/findUser"));

    network_manager->post(network_request, post_data);
    connect(network_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(parseresult(QNetworkReply*)));
    qDebug()<<post_data;
}
void Search::parseresult(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QString qba= reply->readAll(); //读取
        qba.toStdString().c_str();
         qDebug()<<qba;
         QJsonParseError error;
         QJsonDocument jsonDocument = QJsonDocument::fromJson(qba.toUtf8(), &error);

         if (error.error == QJsonParseError::NoError) {
             if (jsonDocument.isObject()) {

                 QJsonObject obj=jsonDocument.object();
                  QJsonObject obj1=obj["infoFindVo"].toObject();
                  ui->label_8->setText(obj1["name"].toString());
                  ui->label_7->setVisible(true);
                  ui->label_8->setVisible(true);
                  ui->pushButton_2->setVisible(true);

             }
         } else {
            qDebug()<<"解析失败";
         }
    }
    delete reply;
}
