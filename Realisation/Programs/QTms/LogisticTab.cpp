#include "LogisticTab.h"

#include <QFile>

LogisticTab::LogisticTab(QWidget* parent) :
	QWidget(parent) {
	loadTheme();
}

LogisticTab::~LogisticTab() {
}

void
LogisticTab::setTheme(const QString& name) {
	QFile css("Theme/" + name + "/alert.css");
	if (css.open(QIODevice::ReadOnly)) {
		alertTheme = css.readAll();
		css.close();
	}
}
