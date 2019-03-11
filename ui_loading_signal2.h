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
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "radiusprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_loading_signal2
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    RadiusProgressBar *bar1;
    QLabel *label_2;
    RadiusProgressBar *bar1_2;
    QLabel *label_3;
    RadiusProgressBar *bar1_3;

    void setupUi(QWidget *loading_signal2)
    {
        if (loading_signal2->objectName().isEmpty())
            loading_signal2->setObjectName(QString::fromUtf8("loading_signal2"));
        loading_signal2->resize(250, 240);
        loading_signal2->setMinimumSize(QSize(250, 240));
        loading_signal2->setMaximumSize(QSize(250, 240));
        loading_signal2->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 25, 36);"));
        verticalLayout = new QVBoxLayout(loading_signal2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(loading_signal2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 20));
        label->setMaximumSize(QSize(100, 20));
        label->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(label);

        bar1 = new RadiusProgressBar(loading_signal2);
        bar1->setObjectName(QString::fromUtf8("bar1"));
        bar1->setMinimumSize(QSize(200, 40));
        bar1->setMaximumSize(QSize(200, 40));

        verticalLayout->addWidget(bar1);

        label_2 = new QLabel(loading_signal2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 20));
        label_2->setMaximumSize(QSize(100, 20));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(label_2);

        bar1_2 = new RadiusProgressBar(loading_signal2);
        bar1_2->setObjectName(QString::fromUtf8("bar1_2"));
        bar1_2->setMinimumSize(QSize(200, 40));
        bar1_2->setMaximumSize(QSize(200, 40));

        verticalLayout->addWidget(bar1_2);

        label_3 = new QLabel(loading_signal2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 20));
        label_3->setMaximumSize(QSize(100, 20));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(label_3);

        bar1_3 = new RadiusProgressBar(loading_signal2);
        bar1_3->setObjectName(QString::fromUtf8("bar1_3"));
        bar1_3->setMinimumSize(QSize(200, 40));
        bar1_3->setMaximumSize(QSize(200, 40));

        verticalLayout->addWidget(bar1_3);


        retranslateUi(loading_signal2);

        QMetaObject::connectSlotsByName(loading_signal2);
    } // setupUi

    void retranslateUi(QWidget *loading_signal2)
    {
        loading_signal2->setWindowTitle(QApplication::translate("loading_signal2", "Form", nullptr));
        label->setText(QApplication::translate("loading_signal2", "\350\247\243\346\236\220\344\270\255...", nullptr));
        label_2->setText(QApplication::translate("loading_signal2", "\345\257\271\346\257\224\344\270\255...", nullptr));
        label_3->setText(QApplication::translate("loading_signal2", "\345\244\204\347\220\206\344\270\255...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loading_signal2: public Ui_loading_signal2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_SIGNAL2_H
