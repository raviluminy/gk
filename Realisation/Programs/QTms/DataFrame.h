#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <QFrame>

namespace Ui {
class DataFrame;
}

class DataFrame : public QFrame {

	Q_OBJECT

public:

	explicit DataFrame(QWidget* parent = 0);
	virtual ~DataFrame();

private:

	Ui::DataFrame *ui;

};

#endif // DATAFRAME_H
