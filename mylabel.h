#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QEvent>
#include <QMatrix>
#include <QTimer>

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    MyLabel(QPixmap, QWidget *parent = 0);
    ~MyLabel();
protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void timerEvent(QTimerEvent *event);
private:
    //记录定时器id.
    int m_enterId;
    int m_leaveId;
    //保存label显示的图片.
    QPixmap m_pixmap;
    //记录旋转角度.
    float m_rotateAngle;

};

#endif // MYLABEL_H
