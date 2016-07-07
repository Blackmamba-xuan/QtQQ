#ifndef SUNSHINE_H
#define SUNSHINE_H

#include <QWidget>
#include<QtGui>
#include<QPoint>
#include<QTimer>

namespace Ui {
class Sunshine;
}

class Sunshine : public QWidget
{
    Q_OBJECT

public:
    explicit Sunshine(QWidget *parent = 0);
    ~Sunshine();
    QPoint m_point;
    QTimer* m_pShowTimer;
    QTimer* m_pStayTimer;
    QTimer* m_pCloseTimer;
    int m_nDesktopHeight;
    double m_dTransparent;

private:
    Ui::Sunshine *ui;
public slots:
    void onMove();
    void onStay();
    void onClose();
};

#endif // SUNSHINE_H
