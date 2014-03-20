#ifndef VEHICLEFRAME_H
#define VEHICLEFRAME_H

#include <QFrame>

namespace Ui {
class VehicleFrame;
}

class VehicleFrame : public QFrame
{
    Q_OBJECT

public:
    explicit VehicleFrame(QWidget *parent = 0);
    ~VehicleFrame();

private:
    Ui::VehicleFrame *ui;
};

#endif // VEHICLEFRAME_H
