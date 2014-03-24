#ifndef LOGISTICTAB_H
#define LOGISTICTAB_H

#include <QString>
#include <QWidget>

class LogisticTab : public QWidget {

	Q_OBJECT

public:

	explicit LogisticTab(QWidget* parent = 0);
	virtual ~LogisticTab();

	void setTheme(const QString& name);

protected:

	QString alertTheme;

private:

	void loadTheme();

};

#endif // LOGISTICTAB_H
