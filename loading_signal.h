#ifndef LOADING_SIGNAL_H
#define LOADING_SIGNAL_H

#include <QWidget>
#include <QTimer>

#include "ringsmapprogressbar.h"

namespace Ui {
class Loading_Signal;
}

class Loading_Signal : public QWidget
{
    Q_OBJECT

public:
    explicit Loading_Signal(QWidget *parent = nullptr);
    ~Loading_Signal();
signals:
    void success_signal();

public slots:
    void updateProgressbar();

private:
    Ui::Loading_Signal *ui;
    QTimer *m_timer;
    int m_persent;

    RingsMapProgressbar *m_progressbar2;
};

#endif // LOADING_SIGNAL_H
