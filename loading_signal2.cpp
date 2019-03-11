#include "loading_signal2.h"
#include "ui_loading_signal2.h"
#include <qpropertyanimation.h>

loading_signal2::loading_signal2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loading_signal2)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_persent = 0;
    m_persent1 = 0;
    m_persent2 = 0;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgressbar()));

    m_timer->start(100);
    ui->bar1_2->hide();
    ui->bar1_3->hide();
    ui->label_2->hide();
    ui->label_3->hide();
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
    ui->bar1->setValue(m_persent);
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
             ui->bar1_2->show();
             ui->label_2->show();
             ui->bar1_2->setValue(m_persent1);
             //this->close();
             if(m_persent1 < 25 && m_persent1 %4 == 1  ) {
                 m_persent1 += 2;
             }
             else if(m_persent1 < 25 ){
                 m_persent1 += 2;
             }
             else if(m_persent1 < 75 && m_persent1 %4 == 1  ) {
                 m_persent1 += 3;
             }
             else if(m_persent1 < 75  ) {
                 m_persent1 += 2;
             }
             else {
                  m_persent1 += 7;
                  if(m_persent1 >= 100){
                      m_persent1 = 100;
                      ui->bar1_3->show();
                      ui->label_3->show();
                      ui->bar1_3->setValue(m_persent2);
                      if(m_persent2 < 25 && m_persent2 %4 == 1  ) {
                          m_persent2 += 2;
                      }
                      else if(m_persent2 < 25 ){
                          m_persent2 += 2;
                      }
                      else if(m_persent2 < 75 && m_persent2 %4 == 1  ) {
                          m_persent2 += 3;
                      }
                      else if(m_persent2 < 75  ) {
                          m_persent2 += 2;
                      }
                      else {
                           m_persent2 += 7;
                           if(m_persent2 >= 100){
                               m_persent2 = 100;

                               emit guid_signal();
                               this->close();
                           }
                      }
                  }
             }
         }
    }


    //ui->bar2->setPersent(m_persent);
    //ui->bar3->setPersent(m_persent);
}



void loading_signal2::flash()
{
    QPropertyAnimation *anim = new QPropertyAnimation(this,"geometry");



}
