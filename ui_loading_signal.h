/********************************************************************************
** Form generated from reading UI file 'loading_signal.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_SIGNAL_H
#define UI_LOADING_SIGNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "ringsmapprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_Loading_Signal
{
public:
    QHBoxLayout *horizontalLayout;
    RingsMapProgressbar *bar2;

    void setupUi(QWidget *Loading_Signal)
    {
        if (Loading_Signal->objectName().isEmpty())
            Loading_Signal->setObjectName(QString::fromUtf8("Loading_Signal"));
        Loading_Signal->resize(218, 218);
        horizontalLayout = new QHBoxLayout(Loading_Signal);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bar2 = new RingsMapProgressbar(Loading_Signal);
        bar2->setObjectName(QString::fromUtf8("bar2"));
        bar2->setMinimumSize(QSize(200, 200));
        bar2->setMaximumSize(QSize(200, 200));
        bar2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(bar2);


        retranslateUi(Loading_Signal);

        QMetaObject::connectSlotsByName(Loading_Signal);
    } // setupUi

    void retranslateUi(QWidget *Loading_Signal)
    {
        Loading_Signal->setWindowTitle(QApplication::translate("Loading_Signal", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loading_Signal: public Ui_Loading_Signal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_SIGNAL_H
