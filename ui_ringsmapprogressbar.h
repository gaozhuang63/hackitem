/********************************************************************************
** Form generated from reading UI file 'ringsmapprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RINGSMAPPROGRESSBAR_H
#define UI_RINGSMAPPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RingsMapProgressbar
{
public:

    void setupUi(QWidget *RingsMapProgressbar)
    {
        if (RingsMapProgressbar->objectName().isEmpty())
            RingsMapProgressbar->setObjectName(QString::fromUtf8("RingsMapProgressbar"));
        RingsMapProgressbar->resize(400, 300);

        retranslateUi(RingsMapProgressbar);

        QMetaObject::connectSlotsByName(RingsMapProgressbar);
    } // setupUi

    void retranslateUi(QWidget *RingsMapProgressbar)
    {
        RingsMapProgressbar->setWindowTitle(QApplication::translate("RingsMapProgressbar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RingsMapProgressbar: public Ui_RingsMapProgressbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RINGSMAPPROGRESSBAR_H
