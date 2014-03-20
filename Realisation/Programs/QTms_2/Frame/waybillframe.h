#ifndef WAYBILLFRAME_H
#define WAYBILLFRAME_H

#include <QFrame>

namespace Ui {
class WayBillFrame;
}

class WayBillFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WayBillFrame(QWidget *parent = 0);
    ~WayBillFrame();

public slots:

//	void on_waybillTableView_clicked(const QModelIndex index);

private slots:

    void on_waybillIdTitle_toggled(const bool checked);

    void on_waybillPlanningTitle_toggled(const bool checked);

    void on_waybillStatusTitle_toggled(const bool checked);

    void on_waybillTransportTitle_toggled(const bool checked);

private:
    Ui::WayBillFrame *ui;
};

#endif // WAYBILLFRAME_H
