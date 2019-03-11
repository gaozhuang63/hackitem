#include "MsgBox.h"

MsgBox::MsgBox(int style,QString text)
{
    this->resize(332,167);

  //获取主界面的宽度
    int width = this->width();
    int height = this->height();
    setStyleSheet("QWidget{background-color: rgb(219,229,245);}");
  //初始化为未按下鼠标左键

  //设置标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    titleLabel = new QLabel(this);
    titleLabel->setGeometry(0,0,width,30);
    if(style==1)
        titleLabel->setText(QStringLiteral("  警告  "));
    else
        titleLabel->setText(QStringLiteral("  提示  "));
    titleLabel->setStyleSheet("QLabel{font-family :微软雅黑;font-size : 5em;color : rgb(255,255,255);background-color: rgb(139,159,185);}");

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(width-30, 5, 20, 20);
    closeBtn->setStyleSheet("QPushButton{image:url(:/new/icon/pic/icon/closebutton.png);background: transparent;border:none;}QPushButton:hover{image:url(:/new/icon/pic/icon/closebutton.png);background: transparent;border:none;}QPushButton:pressed{image:url(:/new/icon/pic/icon/closebutton.png);background: transparent;border:none;}");

    msgBtn = new QPushButton(this);
    msgBtn->setGeometry(40,56,44,44);
    if(style == 1)
        msgBtn->setStyleSheet("QPushButton{image:url(warning.png);background: transparent;border:none;}");
    else if(style == 2)
        msgBtn->setStyleSheet("QPushButton{image:url(:/new/icon/pic/icon/success.png);background: transparent;border:none;}");
    else if(style == 3)
        msgBtn->setStyleSheet("QPushButton{image:url(query.png);background: transparent;border:none;}");

    askLabel = new QLabel(this);
    askLabel->setGeometry(133,56,width,50);
    askLabel->setText(text);

    okBtn=new QPushButton(this);
    if(style==3)
        okBtn->setGeometry(90,119,85,30);
    else
        okBtn->setGeometry(135,119,85,30);
    okBtn->setText(QStringLiteral("确定"));
    okBtn->setStyleSheet("QPushButton{border:1px groove gray;border-radius:4px;border-color: rgb(139,159,185);}QPushButton:hover{background-color: rgb(119,146,183);}QPushButton:pressed{background-color: rgb(139,159,185);}");

    cancleBtn=new QPushButton(this);
    cancleBtn->setGeometry(187,119,85,30);
    cancleBtn->setText(QStringLiteral("取消"));
    cancleBtn->setStyleSheet("QPushButton{border:1px groove gray;border-radius:4px;border-color: rgb(139,159,185);}QPushButton:hover{background-color: rgb(119,146,183);}QPushButton:pressed{background-color: rgb(139,159,185);}");
    if(style == 3)
        cancleBtn->show();
    else
        cancleBtn->hide();

    connect(okBtn,SIGNAL(clicked()),this,SLOT(okBtn_press()));
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_press()));
    connect(cancleBtn,SIGNAL(clicked()),this,SLOT(cancleBtn_press()));
}




MsgBox::~MsgBox(void)
{
}



void MsgBox::mousePressEvent(QMouseEvent *qevent)
{
    if(qevent->button() == Qt::LeftButton)
    {
        mouse_press = true;
        //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
        move_point = qevent->pos();;
    }
}
void MsgBox::mouseMoveEvent(QMouseEvent *qevent)
{
    //若鼠标左键被按下
    if(mouse_press)
    {
        //鼠标相对于屏幕的位置
        QPoint move_pos = qevent->globalPos();

        //移动主窗体位置
        this->move(move_pos - move_point);
    }
}
void MsgBox::mouseReleaseEvent(QMouseEvent *qevent)
{
    //设置鼠标为未被按下
    mouse_press = false;
}

void MsgBox::okBtn_press()
{
    //qDebug()<<1;
    this->accept();
}
void MsgBox::cancleBtn_press()
{
    this->reject();
}
void MsgBox::closeBtn_press()
{
    close();
}

