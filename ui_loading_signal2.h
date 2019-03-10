/********************************************************************************
** Form generated from reading UI file 'loading_signal2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_SIGNAL2_H
#define UI_LOADING_SIGNAL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "radiusprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_loading_signal2
{
public:
    RadiusProgressBar *bar1;

    void setupUi(QWidget *loading_signal2)
    {
        if (loading_signal2->objectName().isEmpty())
            loading_signal2->setObjectName(QString::fromUtf8("loading_signal2"));
        loading_signal2->resize(400, 300);
        bar1 = new RadiusProgressBar(loading_signal2);
        bar1->setObjectName(QString::fromUtf8("bar1"));
        bar1->setGeometry(QRect(90, 110, 180, 40));

        retranslateUi(loading_signal2);

        QMetaObject::connectSlotsByName(loading_signal2);
    } // setupUi

    void retranslateUi(QWidget *loading_signal2)
    {
        loading_signal2->setWindowTitle(QApplication::translate("loading_signal2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loading_signal2: public Ui_loading_signal2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_SIGNAL2_H
