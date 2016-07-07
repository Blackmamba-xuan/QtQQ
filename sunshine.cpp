#include "sunshine.h"
#include "ui_sunshine.h"
#include<QDesktopWidget>
Sunshine::Sunshine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sunshine)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool|Qt::FramelessWindowHint);
    QRect rect = QApplication::desktop()->availableGeometry();
        m_point.setX(rect.width() - width());
        m_point.setY(rect.height() - height());
        move(m_point.x(), m_point.y());

        m_pStayTimer = new QTimer(this);
        m_pCloseTimer = new QTimer(this);
        m_nDesktopHeight=rect.height();
        m_dTransparent=1.0;
        m_pShowTimer = new QTimer(this);
        connect(m_pShowTimer, SIGNAL(timeout()), this, SLOT(onMove()));
        connect(m_pStayTimer, SIGNAL(timeout()), this, SLOT(onStay()));
        connect(m_pCloseTimer, SIGNAL(timeout()), this, SLOT(onClose()));
        m_pShowTimer->start(1);
}

Sunshine::~Sunshine()
{
    delete ui;
}
// 移动
void Sunshine::onMove()
{
    qDebug()<<"移动了";
    m_nDesktopHeight--;
    move(m_point.x(), m_nDesktopHeight);
    if (m_nDesktopHeight <= m_point.y())
    {
        m_pShowTimer->stop();
        m_pStayTimer->start(2000);
    }
}

// 驻留
void Sunshine::onStay()
{
    qDebug()<<"执行了停留的函数";
    m_pStayTimer->stop();
    m_pCloseTimer->start(100);
}

// 关闭
void Sunshine::onClose()
{
    m_dTransparent -= 0.1;
    if (m_dTransparent <= 0.0)
    {
        m_pCloseTimer->stop();
        close();
    }
    else
    {
        setWindowOpacity(m_dTransparent);
    }
}
