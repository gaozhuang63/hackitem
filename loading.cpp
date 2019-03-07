#include "loading.h"
#include "ui_loading.h"
#include <QMovie>
#include <QDesktopWidget>



loading::loading(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loading)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);// 去掉标题栏,去掉任务栏显示，窗口置顶
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
    setAttribute(Qt::WA_DeleteOnClose);//关闭窗体时销毁窗口 使得再次打开窗体gif动画重新播放



    //加载gif图片
    movie = new QMovie(":/new/unit/pic/unit/downloading.gif");
    ui->label->setMovie(movie);
    movie->start();

}

loading::~loading()
{
    delete ui;
    delete movie;
}

