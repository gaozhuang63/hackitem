#include "MyLabel.h"

const float FixedAngle = 22.5f;
const int Time = 10;

MyLabel::MyLabel(QPixmap pixmap,QWidget *parent)
    : QLabel(parent)
{
    //给一些成员变量归零.
    m_rotateAngle = 0;
    m_enterId = 0;
    m_leaveId = 0;
    m_pixmap = pixmap;
    //设置显示的图片.
    this->setPixmap(m_pixmap);
}

MyLabel::~MyLabel()
{

}
void MyLabel::enterEvent(QEvent *event)
{
    if (m_leaveId == 0)
    {
        m_enterId = this->startTimer(Time, Qt::PreciseTimer);
        qDebug("enter");
    }
}
void MyLabel::leaveEvent(QEvent *event)
{
    if (m_enterId == 0)
    {
        m_leaveId = this->startTimer(Time, Qt::PreciseTimer);
        qDebug("leave");
    }
}
void MyLabel::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_enterId)
    {
        QMatrix matrix;
        m_rotateAngle += FixedAngle;
        //设置旋转的操作.
        matrix.rotate(m_rotateAngle);
        //获取旋转后的图片.
        QPixmap temp = m_pixmap.transformed(matrix);
        this->setPixmap(temp);

        //当转到一圈后.
        if (m_rotateAngle == 360)
        {
            //归零并杀死计时器.
            m_rotateAngle = 0;
            this->killTimer(m_enterId);
            m_enterId = 0;
        }
    }
    else if (event->timerId() == m_leaveId)
    {
        QMatrix matrix;
        m_rotateAngle -= FixedAngle;
        matrix.rotate(m_rotateAngle);
        QPixmap temp = m_pixmap.transformed(matrix);
        this->setPixmap(temp);

        //当转到一圈后.
        if (m_rotateAngle == -360)
        {
            //归零并杀死计时器.
            m_rotateAngle = 0;
            this->killTimer(m_leaveId);
            m_leaveId = 0;
        }
    }
}
