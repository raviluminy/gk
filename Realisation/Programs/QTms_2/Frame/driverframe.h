#ifndef DRIVERFRAME_H
#define DRIVERFRAME_H

#include <QFrame>

namespace Ui {
class DriverFrame;
}

class DriverFrame : public QFrame
{
    Q_OBJECT

public:
    explicit DriverFrame(QWidget *parent = 0);
    ~DriverFrame();

private:
    Ui::DriverFrame *ui;
};

#endif // DRIVERFRAME_H
