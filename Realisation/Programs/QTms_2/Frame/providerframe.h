#ifndef PROVIDERFRAME_H
#define PROVIDERFRAME_H

#include <QFrame>

namespace Ui {
class ProviderFrame;
}

class ProviderFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ProviderFrame(QWidget *parent = 0);
    ~ProviderFrame();

private:
    Ui::ProviderFrame *ui;
};

#endif // PROVIDERFRAME_H
