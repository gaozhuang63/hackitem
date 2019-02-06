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
#include "tcpserver.h"
#include "tcpsocket.h"
#include <QDebug>
#include<QStandardItemModel>


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


    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);                             //设置横向文字
    ui->tabWidget->setStyleSheet("QTabWidget::pane {border-left:0px solid #eeeeee;\
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
    ui->label_3->setMovie(movie_1);
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

    QIcon button_ico_on(":/new/icon/pic/icon/com_online.png");
    QIcon button_ico_off(":/new/icon/pic/icon/com_offline.png");

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
    QPixmap pixmap = QPixmap(":/new/background/pic/background/background1.jpg").scaled(this->size());
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

   load = new loading(this);
   load->show();
   load->move ((msg_x - load->width())/2,(msg_y - load->height())/2);
   QTimer::singleShot(5000, this, SLOT(load_info()));  // 这里是一个3秒定时器， 且只执行一次。

}

void message_qemu::load_info()
{

    load->close();
    t1=new test();
    t1->show();

}

void message_qemu::Init()
{
    TcpServer *ser = new TcpServer();
    connect(ser,&TcpServer::connectClientSig,this,&message_qemu::OnConnectClientSlot);
    connect(ser,&TcpServer::readDataSig,this,&message_qemu::OnReadDataSlot);
    connect(ser,&TcpServer::sockDisConnectSig,this,&message_qemu::OnsockDisConnectSlot);
    ser->listen(QHostAddress::Any,6666);
    ui->textBrowser->append("listen");
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
    QStringList config;
    str += "IP:";
    str += strIP;
    str += "Data:";
    str += strData;

    qDebug() << str;
    qDebug() << "\n验证啊啊啊" << TcpSocket::list;
    config = TcpSocket::list;



//    QStandardItemModel *model = new QStandardItemModel();
//    ui->tableView->setModel(model);
//    for(int i = 0; i < 8; i++)
//     {
//         model->setItem(i,0,new QStandardItem("2009441676"));
//            //设置字符颜色
//         model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
//            //设置字符位置
//         model->item(i,0)->setTextAlignment(Qt::AlignCenter);
//         model->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("哈哈")));
//     }

    ui->tableWidget->setItem(0,1,new QTableWidgetItem(config[3]));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(config[4]));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem(config[5]));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem(config[6]));
    ui->tableWidget->setItem(4,1,new QTableWidgetItem(config[7]));
    ui->tableWidget->setItem(5,1,new QTableWidgetItem(config[8]));
    ui->tableWidget->setItem(6,1,new QTableWidgetItem(config[9]));
    ui->tableWidget->setItem(7,1,new QTableWidgetItem(config[10]));

    repaint();
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
}
