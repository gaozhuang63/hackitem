#include "message_qemu.h"
#include "ui_message_qemu.h"
#include <QMainWindow>
#include <QDebug>
#include <QTabWidget>
#include <QMovie>
#include <QVBoxLayout>
#include "title_bar.h"
#include "test.h"
#include <QTimer>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QStandardItemModel>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
#include <QFile>
#include <QTextStream>
#include "msgbox.h"
#include <math.h>
#include <QSequentialAnimationGroup>

#define TIMER_TIMEOUT   (0.35*1000)
#define STOPTIME (0.1*1000)

int CurrentValue = 0;


message_qemu::message_qemu(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::message_qemu)
{
    TitleBar *pTitleBar = new TitleBar(this);
    installEventFilter(pTitleBar);

    ui->setupUi(this);
    Init();
    //自定义标题栏
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(50, 50, 50));
    setAutoFillBackground(true);
    setPalette(pal);

    ui->verticalLayout_2->addWidget(pTitleBar);
    //ui->verticalLayout_2->addStretch();
    ui->verticalLayout_2->setSpacing(0);
    ui->verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    ui->verticalLayout_2->setDirection(QBoxLayout::BottomToTop);//自下而上
    wid_x=width();
    wid_y=height();

//    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);                             //设置横向文字
//    ui->tabWidget->setStyleSheet("QTabWidget::pane {border-left:0px solid #eeeeee;\
                                                    background:  transparent;}");           /*整个最上面的tab栏*/
    ui->tabWidget_2->setStyleSheet("QTabWidget#tabWidget_2::tab-bar{ alignment: left; \
                                                         left:160px;}\
                                    QTabWidget#tabWidget_2::pane   {border-top:0px solid #e8f3f9;\
                                                        background:  transparent; }  \
                                    QTabBar::tab{background:rgb(186, 186, 186);	\
                                                        color:white;            \
                                                        min-width:160px;        \
                                                        min-height:40px;}\
                                    QTabBar::tab:selected { background:rgb(8, 156, 255);	\
                                                            color:white;            \
                                                            min-width:160px;        \
                                                            min-height:40px;}"
                                                            );

   // ui->tabWidget->setStyleSheet("}");          //背景透明
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/icon/pic/icon/icon_classify.png")), QIcon::Normal, QIcon::Off);     //系统图标
    this->setWindowIcon(icon);

    movie = new QMovie(":/new/unit/pic/unit/code.gif");
    ui->label_2->setMovie(movie);
    movie->start();

    movie_1 = new QMovie(":/new/unit/pic/unit/sc_db.gif");
//    ui->label_3->setMovie(movie_1);
    movie_1->start();

//    movie_2= new QMovie(":/new/unit/pic/unit/number.gif");
//    ui->label->setScaledContents(true);
//    ui->label->setMovie(movie_2);
//    movie_2->start();
//    movie_3= new QMovie(":/new/unit/pic/unit/block.gif");
//    ui->label_6->setMovie(movie_3);
//    movie_3->start();

    msg_x=width();
    msg_y=height();



  //  test *back_gif = new test(this);
  //  back_gif ->show();

    ui->label->setScaledContents(true);
    ui->label->resize(ui->widget->size());


    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");

    ui->RecButton->setIcon(button_ico_off);
    ui->RecButton->setMinimumSize(150,150);
    ui->RecButton->setMaximumSize(150,150);
    ui->RecButton->setIconSize(QSize(80,80));
    ui->RecButton->setFlat(true);                                      //按钮无边框
    ui->RecButton->setStyleSheet("color:white");                       //按钮背景透明 对ICon无效

    ui->pushButton->setIcon(button_ico_off);
    ui->pushButton->setMinimumSize(150,150);
    ui->pushButton->setMaximumSize(150,150);
    ui->pushButton->setIconSize(QSize(80,80));
    ui->pushButton->setFlat(true);                                      //按钮无边框
    ui->pushButton->setStyleSheet("color:white");                       //按钮背景透明 对ICon无效
    //ui->pushButton->setStyleSheet("border:none;");                      //按钮背景透明 按下无反馈

    ui->pushButton_2->setIcon(button_ico_off);
    ui->pushButton_2->setMinimumSize(150,150);
    ui->pushButton_2->setMaximumSize(150,150);
    ui->pushButton_2->setIconSize(QSize(80,80));
    ui->pushButton_2->setFlat(true);
    ui->pushButton_2->setStyleSheet("color:white");
    //ui->pushButton_2->setStyleSheet("border:none;");


    ui->pushButton_3->setIcon(button_ico_off);
    ui->pushButton_3->setMinimumSize(150,150);
    ui->pushButton_3->setMaximumSize(150,150);
    ui->pushButton_3->setIconSize(QSize(80,80));
    ui->pushButton_3->setFlat(true);
    ui->pushButton_3->setStyleSheet("color:white");

    ui->pushButton_4->setIcon(button_ico_off);
    ui->pushButton_4->setMinimumSize(150,150);
    ui->pushButton_4->setMaximumSize(150,150);
    ui->pushButton_4->setIconSize(QSize(80,80));
    ui->pushButton_4->setFlat(true);
    ui->pushButton_4->setStyleSheet("color:white");

    ui->pushButton_5->setIcon(button_ico_off);
    ui->pushButton_5->setMinimumSize(150,150);
    ui->pushButton_5->setMaximumSize(150,150);
    ui->pushButton_5->setIconSize(QSize(80,80));
    ui->pushButton_5->setFlat(true);
    ui->pushButton_5->setStyleSheet("color:white");

    ui->pushButton_6->setIcon(button_ico_off);
    ui->pushButton_6->setMinimumSize(150,150);
    ui->pushButton_6->setMaximumSize(150,150);
    ui->pushButton_6->setIconSize(QSize(80,80));
    ui->pushButton_6->setFlat(true);
    ui->pushButton_6->setStyleSheet("color:white");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget_2->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget_2->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget_2->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget_2->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget_2->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget_2->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget_2->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget_2->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));

    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget_3->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget_3->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget_3->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget_3->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget_3->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget_3->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget_3->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget_3->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget_3->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));


    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget_4->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget_4->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget_4->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget_4->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget_4->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget_4->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget_4->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget_4->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget_4->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));

    ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget_5->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget_5->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget_5->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget_5->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget_5->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget_5->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget_5->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget_5->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget_5->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));


    ui->tableWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget_6->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget_6->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget_6->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget_6->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget_6->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget_6->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget_6->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget_6->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget_6->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));

    ui->tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
    ui->tableWidget_7->verticalHeader()->setVisible(true); // 隐藏水平header
    ui->tableWidget_7->setItem(0,0,new QTableWidgetItem("电脑信息："));
    ui->tableWidget_7->setItem(1,0,new QTableWidgetItem("MAC地址："));
    ui->tableWidget_7->setItem(2,0,new QTableWidgetItem("IP地址："));
    ui->tableWidget_7->setItem(3,0,new QTableWidgetItem("内存："));
    ui->tableWidget_7->setItem(4,0,new QTableWidgetItem("CPU："));
    ui->tableWidget_7->setItem(5,0,new QTableWidgetItem("操作系统："));
    ui->tableWidget_7->setItem(6,0,new QTableWidgetItem("硬盘："));
    ui->tableWidget_7->setItem(7,0,new QTableWidgetItem("屏幕分辨率："));

    QPixmap iconnn(":/new/unit/pic/resource/huaji.jpg");
    ui->label_4->setPixmap(iconnn);
    ui->label_4->resize(iconnn.width(),iconnn.height());

    ui->label_4->hide();

    /*  声明动画类，并将控制对象 this (this一定是继承自QObject的窗口部件)  以及属性名 "geometry" 传入构造函数  */
    QPropertyAnimation* animation = new QPropertyAnimation(ui->label_4, "pos");
//    /*  设置动画持续时长为 2 秒钟  */
//    animation->setDuration(2000);
//    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
//    animation->setStartValue(QRect(20, 120, 70, 70));
//    /*  设置动画的结束状态 结束点 (100,200)  结束大小 (300,400)  */
//    animation->setEndValue(QRect(100, 200, 300, 400));
//    /*  设置动画效果  */
//    animation->setEasingCurve(QEasingCurve::OutInExpo);
//    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理(效果就好像智能指针里的自动delete animation) */
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
    animation->setDuration(500);
    animation->setLoopCount(20);  //永远运行，直到stop
    animation->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
    animation->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
    animation->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() + 6));
    animation->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() - 6));
    animation->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
    animation->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
    animation->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() + 6));
    animation->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() - 6));
    animation->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
    animation->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
    animation->setKeyValueAt(1, QPoint(geometry().x() - 3, geometry().y() - 3));

    animation->start(QAbstractAnimation::DeleteWhenStopped);

//    QPixmap iconn(":/new/icon/pic/icon/radar.png");
//    ui->label_5->setPixmap(iconn);
//    ui->label_5->resize(iconn.width(),iconn.height());

    QImage image = QImage(":/new/background/pic/resource/2017web.png");
    QSize laSize=ui->label_39->size();//label_carema是要显示图片的label的名称
    QImage image1=image.scaled(laSize,Qt::IgnoreAspectRatio);//重新调整图像大小以适应窗口
    ui->label_39->setPixmap(QPixmap::fromImage(image1));//显示



//    QPropertyAnimation *anim = new QPropertyAnimation(ui->label_5, "geometry");
//    anim->setDuration(1000);
//    anim->setLoopCount(-1);
//    anim->setKeyValueAt(0, QRect(70, 80, 100, 100));
//    anim->setKeyValueAt(1, QRect(70, 80, 10, 10));
//    anim->setEasingCurve(QEasingCurve::InCubic);
//    anim->start();



    //隐藏tab
    ui->tabWidget_2->removeTab(2);
    //ui->tabWidget_2->removeTab(1);
    ui->pushButton_7->hide();
    ui->comboBox->hide();



    // 进度条

    m_timer = new QTimer(this);
    m_persent = 0;
    m_persent2 = 0;
    m_persent3 = 0;

    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgressbar()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgressbar2()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgressbar3()));

    m_timer->start(100);
    ui->bar4->startAnimation();
    Rotate();

//    TcpSocket *a = new TcpSocket(99);
//    connect(a , SIGNAL(send_sig()), this , SLOT(passEvent()) );


    this->setAttribute(Qt::WA_DeleteOnClose,1);     //子窗口关闭销毁
    qDebug()<<"构造了video窗口"<<endl;

}

message_qemu::~message_qemu()
{


    delete ui;


}


//加载背景图
void message_qemu::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/new/background/pic/background/background.jpg").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);

}


void message_qemu::on_pushButton_clicked()
{
    emit send_signal();
    //this->hide();
}


void message_qemu::on_pushButton_2_clicked()
{

//    qDebug()<<"ttt:" << ttt ;
//    QString c = "taskkill /im tcp_server.exe /f";
//    caller->execute(c);
//    caller->close();

//   load = new loading(this);
//   load->show();
//   load->move ((msg_x - load->width())/2,(msg_y - load->height())/2);
//   QTimer::singleShot(5000, this, SLOT(load_info()));  // 这里是一个3秒定时器， 且只执行一次。

}

void message_qemu::load_info()
{

    load->close();
    t1 = new test();
    t1 -> show();

}

void message_qemu::Init()
{
    TcpServer *ser = new TcpServer();
    connect(ser,&TcpServer::connectClientSig,this,&message_qemu::OnConnectClientSlot);
    connect(ser,&TcpServer::readDataSig,this,&message_qemu::OnReadDataSlot);
    //connect(ser,&TcpServer::readDataSig1,this,&message_qemu::OnReadDataSlot);
    connect(ser,&TcpServer::sockDisConnectSig,this,&message_qemu::OnsockDisConnectSlot);
    ser->listen(QHostAddress::Any,6666);
    ui->textBrowser->append("listen:");
}

void message_qemu::OnConnectClientSlot(const int , const QString &strIP ,const quint16 nPort)
{
    QString str;
    str += "IP:";
    str += strIP;
    str += "Port:";
    str += QString::number(nPort);
    qDebug() << str;
    ui->textBrowser->append(str);
}

void message_qemu::OnReadDataSlot(const int,const QString &strIP, quint16, const QByteArray &strData)
{
    QString str;
    int flag = 0;

    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    str += "IP:";
    str += strIP;
    str += "Data:";
    str += "目标信息抓取成功！";
    qDebug() << str;
//    qDebug() << "\n验证啊啊啊" << TcpSocket::list;
//    qDebug () << "list:"<< TcpSocket::list [1];
    config = TcpSocket::list;

    QString lab;
    lab = QString("<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#e20000;\">状态：</span><span style=\" font-size:24pt; font-weight:600; color:#e20000;\">已连接</span></p></body></html>");
    ui->label_13->setText(lab);

    qDebug () << "config: " <<config ;

    if(config[1]=="1")
        {

        if (flag == 0)
        {
        Timer = new QTimer(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
        Timer->start(TIMER_TIMEOUT);
        flag = 1;
        }
        no1 = config ;
        //ui->pushButton->setIcon(button_ico_on);
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget->setItem(7,1,new QTableWidgetItem(config[10]));

        repaint();

        //passEvent();
        qDebug() <<"TcpSocket::pas_signal:" <<TcpSocket::pas_signal;
        qDebug() <<"aaaaaaa"<< config[1];
        }
    else if(config[1] == "0")
        {

        Recputton();

        ui->tableWidget_7->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget_7->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget_7->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget_7->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget_7->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget_7->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget_7->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget_7->setItem(7,1,new QTableWidgetItem(config[10]));
        repaint();

        }

    else if(config[1]=="2")
        {
        if (flag == 0)
        {
        Timer = new QTimer(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeout1()));
        Timer->start(TIMER_TIMEOUT);
        flag = 1;
        }
        no2 = config ;
        ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget_2->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget_2->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget_2->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget_2->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget_2->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget_2->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget_2->setItem(7,1,new QTableWidgetItem(config[10]));
        repaint();
        //passEvent();
        qDebug() <<"TcpSocket::pas_signal" <<TcpSocket::pas_signal;
        qDebug() <<"bbbbbbbb"<< config[1];
        }
    else if(config[1]=="3")
        {
        if (flag == 0)
        {
        Timer = new QTimer(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeout2()));
        Timer->start(TIMER_TIMEOUT);
        flag = 1;
        }
        no3 = config ;
        ui->tableWidget_3->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget_3->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget_3->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget_3->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget_3->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget_3->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget_3->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget_3->setItem(7,1,new QTableWidgetItem(config[10]));
        repaint();
        //passEvent();
        qDebug() <<"TcpSocket::pas_signal" <<TcpSocket::pas_signal;
        qDebug() <<"cccc"<< config[1];
        }
    else if(config[1]=="4")
        {
        if (flag == 0)
        {
        Timer = new QTimer(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeout3()));
        Timer->start(TIMER_TIMEOUT);
        flag = 1;
        }
        no4 = config ;
        ui->tableWidget_4->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget_4->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget_4->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget_4->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget_4->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget_4->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget_4->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget_4->setItem(7,1,new QTableWidgetItem(config[10]));
        repaint();
        //passEvent();
        qDebug() <<"TcpSocket::pas_signal" <<TcpSocket::pas_signal;
        qDebug() <<"ddd"<< config[1];
        }
    else if(config[1]=="5")
        {
        if (flag == 0)
        {
        Timer = new QTimer(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeout4()));
        Timer->start(TIMER_TIMEOUT);
        flag = 1;
        }
        no5 = config ;
        ui->tableWidget_5->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget_5->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget_5->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget_5->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget_5->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget_5->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget_5->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget_5->setItem(7,1,new QTableWidgetItem(config[10]));
        repaint();
        //passEvent();
        qDebug() <<"TcpSocket::pas_signal" <<TcpSocket::pas_signal;
        qDebug() <<"eeee"<< config[1];
        }
    else if(config[1]=="6")
        {
        if (flag == 0)
        {
        Timer = new QTimer(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeout5()));
        Timer->start(TIMER_TIMEOUT);
        flag = 1;
        }

        no6 = config ;
        ui->tableWidget_6->setItem(0,1,new QTableWidgetItem(config[3]));
        ui->tableWidget_6->setItem(1,1,new QTableWidgetItem(config[4]));
        ui->tableWidget_6->setItem(2,1,new QTableWidgetItem(config[5]));
        ui->tableWidget_6->setItem(3,1,new QTableWidgetItem(config[6]));
        ui->tableWidget_6->setItem(4,1,new QTableWidgetItem(config[7]));
        ui->tableWidget_6->setItem(5,1,new QTableWidgetItem(config[8]));
        ui->tableWidget_6->setItem(6,1,new QTableWidgetItem(config[9]));
        ui->tableWidget_6->setItem(7,1,new QTableWidgetItem(config[10]));
        repaint();
        //passEvent();
        qDebug() <<"TcpSocket::pas_signal" <<TcpSocket::pas_signal;
        qDebug() <<"ffffff"<< config[1];
        }

    else if(config[1] == "7")
    {
        int i ;
        for(i==2;i<10;i++)
        {
            ui->textBrowser_2->append(config[i]);
        }
    }
    //    qDebug() << config;
    else if(config[1] == "8")
    {

        guid = config ;

    }

    ui->textBrowser->append(str);

}


void message_qemu::OnsockDisConnectSlot(int ,QString strIP ,quint16)
{
    QString str;
    str += "IP:";
    str += strIP;
    str += "DisConnect!";
    qDebug() << str;
    ui->textBrowser->append(str);
}

void message_qemu::on_pushButton_6_clicked()
{
    void update();
    load_sig2 = new loading_signal2(this);
    load_sig2->show();
    load_sig2->move((wid_x - load_sig2->width())/2,(wid_y - load_sig2->height())/2);
}



void message_qemu::handleTimeout()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
        ui->pushButton->setIcon(button_ico_on);
        CurrentValue = 0 ;
        Timer->stop();
     }

    else if (CurrentValue%3==0 ){
        ui->pushButton->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->pushButton->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->pushButton->setIcon(button_ico_on);
    }
}

void message_qemu::handleTimeout1()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
        ui->pushButton_2->setIcon(button_ico_on);
        CurrentValue = 0 ;
        Timer->stop();
     }
    else if (CurrentValue%3==0 ){
        ui->pushButton_2->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->pushButton_2->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->pushButton_2->setIcon(button_ico_on);
    }
}
void message_qemu::handleTimeout2()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
       Timer->stop();
       CurrentValue = 0 ;
       ui->pushButton_3->setIcon(button_ico_on);
     }
    else if (CurrentValue%3==0 ){
        ui->pushButton_3->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->pushButton_3->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->pushButton_3->setIcon(button_ico_on);
    }
}
void message_qemu::handleTimeout3()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
       Timer->stop();
       CurrentValue = 0 ;
       ui->pushButton_6->setIcon(button_ico_on);
     }
    else if (CurrentValue%3==0 ){
        ui->pushButton_6->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->pushButton_6->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->pushButton_6->setIcon(button_ico_on);
    }
}
void message_qemu::handleTimeout4()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
       Timer->stop();
       CurrentValue = 0 ;
       ui->pushButton_4->setIcon(button_ico_on);
     }
    else if (CurrentValue%3==0 ){
        ui->pushButton_4->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->pushButton_4->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->pushButton_4->setIcon(button_ico_on);
    }
}
void message_qemu::handleTimeout5()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
       Timer->stop();
       CurrentValue = 0 ;
       ui->pushButton_5->setIcon(button_ico_on);
     }
    else if (CurrentValue%3==0 ){
        ui->pushButton_5->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->pushButton_5->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->pushButton_5->setIcon(button_ico_on);
    }
}

void message_qemu::handleTimeoutRec()
{
    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");
    CurrentValue++;
    if(CurrentValue == 13)
     {
        ui->RecButton->setIcon(button_ico_on);
        CurrentValue = 0 ;
        Timer->stop();
     }
    else if (CurrentValue%3==0 ){
        ui->RecButton->setIcon(button_ico_off);
    }
    else if (CurrentValue%3 ==1 ){
        ui->RecButton->setIcon(button_ico_on);
    }
    else if (CurrentValue%3 ==2 ){
         ui->RecButton->setIcon(button_ico_on);
    }
}


void message_qemu::passEvent()
{
    choose = QMessageBox::information(NULL, "WARNING!!!", "是否允许登陆", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (choose == QMessageBox::Yes)
    {

        TcpSocket::pas_signal = "pass";

//        TcpSocket *a = new TcpSocket(99);
//        connect(this , SIGNAL(pas_sig()), a , SLOT(passevt()) ,Qt::QueuedConnection);

        emit pas_sig();
        //qDebug() <<"发信号了哎哎哎哎";

        //TcpSocket a(qintptr socketDescriptor);
        //a->setSocketDescriptor(socketDescriptor);


    }

    else if(choose  == QMessageBox::No)
    {

        TcpSocket::pas_signal = "reject" ;
        emit pas_sig();
    }
}



void message_qemu::Recputton()
{


    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(handleTimeoutRec()));
    Timer->start(TIMER_TIMEOUT);


}

void message_qemu::on_pushButton_7_clicked()
{
    load = new loading(this);
    load->show();
    load->move((wid_x - load->width())/2,(wid_y - load->height())/2);
    QTimer::singleShot(3000, this, SLOT(endload()));  // 这里是一个3秒定时器， 且只执行一次。
}

void message_qemu::endload()
{
    load->close();
}

void message_qemu::on_pushButton_8_clicked()
{
//    t1 = new test(this);
//    t1->show();
//    t1->move((wid_x - t1->width())/2,(wid_y - t1->height())/2);
//    QTimer::singleShot(3000, this, SLOT(endcompare()));  // 这里是一个3秒定时器， 且只执行一次。
    load_sig2 = new loading_signal2(this);
    load_sig2->show();
    load_sig2->move((wid_x - load_sig2->width())/2,(wid_y - load_sig2->height())/2);

    connect(load_sig2,SIGNAL(guid_signal()),this,SLOT(show_guid()),Qt::UniqueConnection);



}

void message_qemu::endcompare()
{
    t1->close();
}

void message_qemu::on_comboBox_currentIndexChanged(int index)
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        ui->textBrowser_2->clear();
        break;



    case 1:

        ui->textBrowser_2->clear();
        ui->textBrowser_2->append("G1023-DSAFJK-3GALKS-XZCVB-FADGG");


        break;



    case 2:


        ui->textBrowser_2->clear();
        ui->textBrowser_2->append("ADF12-AG34H-BNGAS-DSAGJ-VCNNF");

        break;




    }
}


void message_qemu::on_readoutput()
{
    QString abc =caller->readAllStandardOutput();
    qDebug() << "啊啊啊啊啊："<< abc ;
    //qDebug() << abc ;   //将输出信息读取到编辑框
}

void message_qemu::on_readerror()
{
    //QMessageBox::information(0, "Error", cmd->readAllStandardError().data());    //弹出信息框提示错误信息
}

void message_qemu::on_pushButton_4_clicked()
{
    load_sig = new Loading_Signal(this);
    load_sig->show();
    load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);


}

void message_qemu::show_guid()
{

    int i ;
    for(i==2;i<10;i++)
    {
        ui->textBrowser_3->append(guid[i]);
    }
    disconnect(load_sig2,SIGNAL(guid_signal()),this,SLOT(show_guid()));

}

void message_qemu::on_pushButton_9_clicked()
{
    QFile data("no.1.txt");


//    QString log_pa1 = "Login#1##DESKTOP - C0GL8EJ#30:9C:23:88:24:CB#192.168.3.89#\xBF\xC9\xD3\xC3 8.68 GB / \xB9\xB2 15.95 GB#Intel(R) Core(TM) i7 - 8700K CPU @ 3.70GHz#Windows 10 (10.0) 64\xCE\xBB#C: 6.6G / 110.5G       D : 104.6G / 1863.0G       E : 103.9G / 465.8G       #(2560\xCF\xF1\xCB\xD8 x 1440\xCF\xF1\xCB\xD8) x 1\xB8\xF6\xA1\xA2(1440\xCF\xF1\xCB\xD8 x 900\xCF\xF1\xCB\xD8) x 1\xB8\xF6#\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" ;

//    no1 = log_pa1.split("#");
       if (data.open (QIODevice::Text | QIODevice::WriteOnly) )

       {

           QTextStream out(&data);

           out << QObject::tr("No1_configure:\t")<<qSetFieldWidth(10)<<center <<no1[3]<< endl;
           int i ;
           for(i = 4 ; i<=10;i++)
           {
              out  << qSetFieldWidth(16)<<"\t"<<center <<no1[i]<< endl;
           }
           qDebug() <<"OK!" ;

           load_sig = new Loading_Signal(this);
           load_sig->show();
           load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);
           connect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()),Qt::UniqueConnection);

           //QMessageBox::about(NULL, "Result", "Complete!!");
       }

   data.close();
}

void message_qemu::on_pushButton_10_clicked()
{
    QFile data("no.2.txt");
//    QString log_pa1 = "Login#1##DESKTOP - C0GL8EJ#30:9C:23:88:24:CB#192.168.3.89#\xBF\xC9\xD3\xC3 8.68 GB / \xB9\xB2 15.95 GB#Intel(R) Core(TM) i7 - 8700K CPU @ 3.70GHz#Windows 10 (10.0) 64\xCE\xBB#C: 6.6G / 110.5G       D : 104.6G / 1863.0G       E : 103.9G / 465.8G       #(2560\xCF\xF1\xCB\xD8 x 1440\xCF\xF1\xCB\xD8) x 1\xB8\xF6\xA1\xA2(1440\xCF\xF1\xCB\xD8 x 900\xCF\xF1\xCB\xD8) x 1\xB8\xF6#\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" ;
//    no2 = log_pa1.split("#");
       if (data.open (QIODevice::Text |QIODevice::WriteOnly) )

       {

           QTextStream out(&data);

           out << QObject::tr("No1_configure:\t")<<qSetFieldWidth(10)<<center <<no2[3]<< endl;
           int i ;
           for(i = 4 ; i<=10;i++)
           {
              out  << qSetFieldWidth(26)<<"\t"<<center <<no2[i]<< endl;
           }
           qDebug() <<"OK!" ;
           load_sig = new Loading_Signal(this);
           load_sig->show();
           load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);
           connect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()),Qt::UniqueConnection);
       }

   data.close();
}

void message_qemu::on_pushButton_11_clicked()
{
    QFile data("no.3.txt");
//    QString log_pa1 = "Login#1##DESKTOP - C0GL8EJ#30:9C:23:88:24:CB#192.168.3.89#\xBF\xC9\xD3\xC3 8.68 GB / \xB9\xB2 15.95 GB#Intel(R) Core(TM) i7 - 8700K CPU @ 3.70GHz#Windows 10 (10.0) 64\xCE\xBB#C: 6.6G / 110.5G       D : 104.6G / 1863.0G       E : 103.9G / 465.8G       #(2560\xCF\xF1\xCB\xD8 x 1440\xCF\xF1\xCB\xD8) x 1\xB8\xF6\xA1\xA2(1440\xCF\xF1\xCB\xD8 x 900\xCF\xF1\xCB\xD8) x 1\xB8\xF6#\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" ;
//    no2 = log_pa1.split("#");
       if (data.open (QIODevice::Text |QIODevice::WriteOnly) )

       {

           QTextStream out(&data);

           out << QObject::tr("No1_configure:\t")<<qSetFieldWidth(10)<<center <<no3[3]<< endl;
           int i ;
           for(i = 4 ; i<=10;i++)
           {
              out  << qSetFieldWidth(26)<<"\t"<<center <<no3[i]<< endl;
           }
           qDebug() <<"OK!" ;
           load_sig = new Loading_Signal(this);
           load_sig->show();
           load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);
           connect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()),Qt::UniqueConnection);
       }

   data.close();
}

void message_qemu::on_pushButton_12_clicked()
{
    QFile data("no.4.txt");
//    QString log_pa1 = "Login#1##DESKTOP - C0GL8EJ#30:9C:23:88:24:CB#192.168.3.89#\xBF\xC9\xD3\xC3 8.68 GB / \xB9\xB2 15.95 GB#Intel(R) Core(TM) i7 - 8700K CPU @ 3.70GHz#Windows 10 (10.0) 64\xCE\xBB#C: 6.6G / 110.5G       D : 104.6G / 1863.0G       E : 103.9G / 465.8G       #(2560\xCF\xF1\xCB\xD8 x 1440\xCF\xF1\xCB\xD8) x 1\xB8\xF6\xA1\xA2(1440\xCF\xF1\xCB\xD8 x 900\xCF\xF1\xCB\xD8) x 1\xB8\xF6#\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" ;
//    no2 = log_pa1.split("#");
       if (data.open (QIODevice::Text |QIODevice::WriteOnly) )

       {

           QTextStream out(&data);

           out << QObject::tr("No1_configure:\t")<<qSetFieldWidth(10)<<center <<no4[3]<< endl;
           int i ;
           for(i = 4 ; i<=10;i++)
           {
              out  << qSetFieldWidth(26)<<"\t"<<center <<no4[i]<< endl;
           }
           qDebug() <<"OK!" ;
           load_sig = new Loading_Signal(this);
           load_sig->show();
           load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);
           connect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()),Qt::UniqueConnection);
       }

   data.close();
}

void message_qemu::on_pushButton_13_clicked()
{
    QFile data("no.5.txt");
//    QString log_pa1 = "Login#1##DESKTOP - C0GL8EJ#30:9C:23:88:24:CB#192.168.3.89#\xBF\xC9\xD3\xC3 8.68 GB / \xB9\xB2 15.95 GB#Intel(R) Core(TM) i7 - 8700K CPU @ 3.70GHz#Windows 10 (10.0) 64\xCE\xBB#C: 6.6G / 110.5G       D : 104.6G / 1863.0G       E : 103.9G / 465.8G       #(2560\xCF\xF1\xCB\xD8 x 1440\xCF\xF1\xCB\xD8) x 1\xB8\xF6\xA1\xA2(1440\xCF\xF1\xCB\xD8 x 900\xCF\xF1\xCB\xD8) x 1\xB8\xF6#\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" ;
//    no2 = log_pa1.split("#");
       if (data.open (QIODevice::Text |QIODevice::WriteOnly) )

       {

           QTextStream out(&data);

           out << QObject::tr("No1_configure:\t")<<qSetFieldWidth(10)<<center <<no5[3]<< endl;
           int i ;
           for(i = 4 ; i<=10;i++)
           {
              out  << qSetFieldWidth(26)<<"\t"<<center <<no5[i]<< endl;
           }
           qDebug() <<"OK!" ;
           load_sig = new Loading_Signal(this);
           load_sig->show();
           load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);
           connect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()),Qt::UniqueConnection);
       }

   data.close();
}

void message_qemu::on_pushButton_14_clicked()
{
    QFile data("no.6.txt");
//    QString log_pa1 = "Login#1##DESKTOP - C0GL8EJ#30:9C:23:88:24:CB#192.168.3.89#\xBF\xC9\xD3\xC3 8.68 GB / \xB9\xB2 15.95 GB#Intel(R) Core(TM) i7 - 8700K CPU @ 3.70GHz#Windows 10 (10.0) 64\xCE\xBB#C: 6.6G / 110.5G       D : 104.6G / 1863.0G       E : 103.9G / 465.8G       #(2560\xCF\xF1\xCB\xD8 x 1440\xCF\xF1\xCB\xD8) x 1\xB8\xF6\xA1\xA2(1440\xCF\xF1\xCB\xD8 x 900\xCF\xF1\xCB\xD8) x 1\xB8\xF6#\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" ;
//    no2 = log_pa1.split("#");
       if (data.open (QIODevice::Text |QIODevice::WriteOnly) )

       {

           QTextStream out(&data);

           out << QObject::tr("No1_configure:\t")<<qSetFieldWidth(10)<<center <<no6[3]<< endl;
           int i ;
           for(i = 4 ; i<=10;i++)
           {
              out  << qSetFieldWidth(26)<<"\t"<<center <<no6[i]<< endl;
           }
           qDebug() <<"OK!" ;
           load_sig = new Loading_Signal(this);
           load_sig->show();
           load_sig->move((wid_x - load_sig->width())/2,(wid_y - load_sig->height())/2);
           connect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()),Qt::UniqueConnection);
       }

   data.close();
}

void message_qemu::showBox()
{

//    MsgBox *msgBox=new MsgBox(1,QStringLiteral("请输入卡口名或路口名"));//1为警告框
//    int nRes=msgBox->exec();
    load_sig->hide();
    MsgBox *msgBox=new MsgBox(2,QStringLiteral("SUCCESS!"));//2为提示框
    int nRes=msgBox->exec();
//    msgBox=new MsgBox(3,QStringLiteral("确定修改路口名称"));//3为询问框
//    nRes=msgBox->exec();
//    if(nRes==QDialog::Accepted)
//    {
//    //  处理按下确定按钮的语句
//    }
//    else if(nRes==QDialog::Rejected)
//    {
//        //处理按下取消或者关闭按钮的语句
//    }
    disconnect(load_sig,SIGNAL(success_signal()),this,SLOT(showBox()));
}


void message_qemu::updateProgressbar()
{
//    if(m_persent >= 100){
//        //m_persent = 0;
//        this->close();
//    }
    ui->bar1->setValue(m_persent);
    if(m_persent < 25 && m_persent %4 == 1  ) {
        m_persent += 2;
    }
    else if(m_persent < 25 ){
        m_persent += 4;
    }
    else if(m_persent < 75 && m_persent %4 == 1  ) {
        m_persent += 5;
    }
    else if(m_persent < 75  ) {
        m_persent += 4;
    }
    else {
         m_persent += 7;
         if(m_persent >= 100){
             m_persent = 0;
         }
    }
    //ui->bar2->setPersent(m_persent);
    //ui->bar3->setPersent(m_persent);
}

void message_qemu::updateProgressbar2()
{
    ui->bar1_2->setValue(m_persent2);
    //this->close();
    if(m_persent2 < 25 && m_persent2 %4 == 1  ) {
        m_persent2 += 2;
    }
    else if(m_persent2 < 25 ){
        m_persent2 += 1;
    }
    else if(m_persent2 < 75 && m_persent2 %4 == 1  ) {
        m_persent2 += 7;
    }
    else if(m_persent2 < 75  ) {
        m_persent2 += 3;
    }
    else {
        m_persent2 += 7;
        if(m_persent2 >= 100){

            m_persent2  = 0;

        }
    }
    //ui->bar2->setPersent(m_persent);
    //ui->bar3->setPersent(m_persent);
}


void message_qemu::updateProgressbar3()
{

    ui->bar3->setPersent(m_persent3);
    if(m_persent3 < 25 && m_persent3 %4 == 1  ) {
        m_persent3 += 2;
    }
    else if(m_persent3 < 25 ){
        m_persent3 += 4;
    }
    else if(m_persent3 < 75 && m_persent3 %4 == 1  ) {
        m_persent3 += 5;
    }
    else if(m_persent3 < 75  ) {
        m_persent3 += 4;
    }
    else {
         m_persent3 += 7;
         if(m_persent3 >= 100){
             m_persent3 = 0;
         }
    }
    //ui->bar2->setPersent(m_persent);
    //ui->bar3->setPersent(m_persent);
}

void message_qemu::Rotate()
{

//    QPainter painter(this);

//    painter.translate(50,50);                //使图片的中心作为旋转的中心
//    painter.rotate(20);                //顺时针旋转90°
//    painter.translate(-50,-50);        //将原点复位
//    painter.drawPixmap(0,0,100,100,pix);


    QImage image = QImage(":/new/unit/pic/unit/LOHO.png");
    QSize laSize=ui->label_5->size();//label_carema是要显示图片的label的名称
    QImage image1=image.scaled(laSize,Qt::IgnoreAspectRatio);//重新调整图像大小以适应窗口
    ui->label_5->setPixmap(QPixmap::fromImage(image1));//显示

    QPropertyAnimation *pAnimation = new QPropertyAnimation(ui->label_5, "geometry");

    QDesktopWidget *pDesktopWidget = QApplication::desktop();
    int x = (pDesktopWidget->availableGeometry().width() - width()) / 2;
    int y = (pDesktopWidget->availableGeometry().height() - height()) / 2;

    pAnimation->setDuration(2000);
//    pAnimation->setLoopCount(-1);  //永远运行，直到stop
    pAnimation->setStartValue(QRect(10, -90, width(), height()));
    pAnimation->setEndValue(QRect(10, 230, width(), height()));
    pAnimation->setEasingCurve(QEasingCurve::OutBounce);
//    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *pAnimation1 = new QPropertyAnimation(ui->label_5, "geometry");
    pAnimation1->setDuration(2000);
//    pAnimation1->setLoopCount(-1);  //永远运行，直到stop
    pAnimation1->setStartValue(QRect(10, 230, width(), height()));
    pAnimation1->setEndValue(QRect(10, -90, width(), height()));
    pAnimation1->setEasingCurve(QEasingCurve::OutElastic);
//    pAnimation1->start(QAbstractAnimation::DeleteWhenStopped);

    QSequentialAnimationGroup *m_pGroup = new QSequentialAnimationGroup(this) ;//串行动画组

    // 添加动画
    m_pGroup->addAnimation(pAnimation);
    // 暂停1秒
    //m_pGroup->addPause(1000);
    m_pGroup->addAnimation(pAnimation1);
    // 循环-1次
    m_pGroup->setLoopCount(-1);
    //从后往前执行
//    m_pGroup->setDirection(QAbstractAnimation::Backward);
    m_pGroup ->start();




}
