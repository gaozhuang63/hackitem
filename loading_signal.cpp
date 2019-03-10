#include "loading_signal.h"
#include "ui_loading_signal.h"
#include <QDesktopWidget>




Loading_Signal::Loading_Signal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loading_Signal)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_persent = 0;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgressbar()));

    m_timer->start(100);
    //ui->bar4->startAnimation();
}

Loading_Signal::~Loading_Signal()
{
    delete ui;
}

void Loading_Signal::updateProgressbar()
{
//    if(m_persent >= 100){
//        //m_persent = 0;
//        this->close();
//    }
    if(m_persent < 25 && m_persent %4 == 1  ) {
        m_persent += 3;
    }
    else if(m_persent < 25 ){
        m_persent += 1;
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
             m_persent = 100;
             this->close();
         }
    }


    //ui->bar1->setValue(m_persent);
    ui->bar2->setPersent(m_persent);
    //ui->bar3->setPersent(m_persent);
}
