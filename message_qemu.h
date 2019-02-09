#pragma once                                    //相互包含头文件
//#ifndef MESSAGE_QEMU_H
//#define MESSAGE_QEMU_H

#include <QWidget>
#include <QPainter>
#include <QDialog>
#include "customtabstyle.h"
#include "loading.h"
#include "test.h"
#include "tcpserver.h"
#include "tcpsocket.h"
#include <QTcpSocket>
#include <QQueue>
#include <QFutureWatcher>
#include <QByteArray>
#include <QFile>
#include <QTime>

//=====枚举标志信息类型，分别为登陆、消息、文件==============
//enum MessageType{Login,Message,FileName,NONE};



namespace Ui {
class message_qemu;
}



class message_qemu : public QWidget
{
    Q_OBJECT

public:
    explicit message_qemu(QWidget *parent = 0 );
    ~message_qemu();
    void paintEvent(QPaintEvent *);


    QMovie *movie;
    QMovie *movie_1;
    QMovie *movie_2;
    QMovie *movie_3;
    int msg_x;
    int msg_y;
    QStringList config;
    loading *load;
    test *t1;
    qintptr socketDescriptor;
    int choose;


public slots:
    void load_info();
    void handleTimeout();  //超时处理函数
    void handleTimeout1();  //超时处理函数
    void handleTimeout2();  //超时处理函数
    void handleTimeout3();  //超时处理函数
    void handleTimeout4();  //超时处理函数
    void handleTimeout5();  //超时处理函数
    void passEvent();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void OnConnectClientSlot(const int , const QString & ,const quint16 );
    void OnReadDataSlot(const int,const QString &, quint16, const QByteArray &);
    void OnsockDisConnectSlot(int ,QString ,quint16);

    void on_pushButton_6_clicked();

signals:
    void send_signal();//这个函数用户向主界面通知关闭的消息
    void pas_sig();

private:
    void Init();
     qint64 m_MessageType;

private:
    Ui::message_qemu *ui;
    QTimer *Timer;

};

//#endif  MESSAGE_QEMU_H
