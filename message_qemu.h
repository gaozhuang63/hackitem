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
#include <QProcess>
#include "loading_signal.h"
#include "loading_signal2.h"

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

    void Recputton();
    QMovie *movie;
    QMovie *movie_1;
    QMovie *movie_2;
    QMovie *movie_3;
    int msg_x;
    int msg_y;
    QStringList config;
    loading *load;
    Loading_Signal *load_sig;
    loading_signal2 *load_sig2;
    test *t1;
    qintptr socketDescriptor;
    int choose;
    int wid_x;
    int wid_y;
    QByteArray ttt;



public slots:
    void load_info();
    void handleTimeout();  //超时处理函数
    void handleTimeout1();  //超时处理函数
    void handleTimeout2();  //超时处理函数
    void handleTimeout3();  //超时处理函数
    void handleTimeout4();  //超时处理函数
    void handleTimeout5();  //超时处理函数
    void handleTimeoutRec();  //超时处理函数
    void passEvent();
    void endload();
    void endcompare();
    void on_readoutput();
    void on_readerror();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void OnConnectClientSlot(const int , const QString & ,const quint16 );
    void OnReadDataSlot(const int,const QString &, quint16, const QByteArray &);
    //void OnReadDataSlot1(const int,const QString &, quint16, const QByteArray &);
    void OnsockDisConnectSlot(int ,QString ,quint16);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

signals:
    void send_signal();//这个函数用户向主界面通知关闭的消息
    void pas_sig();

private:
    void Init();
     qint64 m_MessageType;

private:
    Ui::message_qemu *ui;
    QTimer *Timer;
    QProcess* caller;


};

//#endif  MESSAGE_QEMU_H
