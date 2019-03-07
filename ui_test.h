/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName(QString::fromUtf8("test"));
        test->resize(550, 200);
        test->setMinimumSize(QSize(550, 200));
        test->setMaximumSize(QSize(568, 201));
        verticalLayout = new QVBoxLayout(test);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(test);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(550, 190));
        widget->setMaximumSize(QSize(550, 190));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(199, 199, 199)"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(500, 70));
        label_2->setMaximumSize(QSize(500, 70));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(179, 2, 5);\n"
"font: 87 36pt \"Segoe UI Black\";"));

        verticalLayout_2->addWidget(label_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(500, 113));
        label->setMaximumSize(QSize(500, 113));

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(widget);


        retranslateUi(test);

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QWidget *test)
    {
        test->setWindowTitle(QApplication::translate("test", "Form", nullptr));
        label_2->setText(QApplication::translate("test", "<html><head/><body><p align=\"center\">Comparing...</p></body></html>", nullptr));
        label->setText(QApplication::translate("test", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
