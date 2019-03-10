#include "loading_signal2.h"
#include "ui_loading_signal2.h"

loading_signal2::loading_signal2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loading_signal2)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_persent = 0;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgressbar()));

    m_timer->start(100);
    //ui->bar4->startAnimation();
}

loading_signal2::~loading_signal2()
{
    delete ui;
}

void loading_signal2::updateProgressbar()
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

    ui->bar1->setValue(m_persent);
    //ui->bar2->setPersent(m_persent);
    //ui->bar3->setPersent(m_persent);
}
