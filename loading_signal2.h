#ifndef LOADING_SIGNAL2_H
#define LOADING_SIGNAL2_H

#include <QWidget>
#include <QTimer>
#include "ringsmapprogressbar.h"

namespace Ui {
class loading_signal2;
}

class loading_signal2 : public QWidget
{
    Q_OBJECT

public:
    explicit loading_signal2(QWidget *parent = nullptr);
    ~loading_signal2();
    void flash();

signals:
    void guid_signal();


public slots:
    void updateProgressbar();

private:
    Ui::loading_signal2 *ui;
    QTimer *m_timer;
    int m_persent;
    int m_persent1;
    int m_persent2;

    RingsMapProgressbar *m_progressbar2;
};

#endif // LOADING_SIGNAL2_H
