#include "LogisticTab.h"

#include <QFile>

LogisticTab::LogisticTab(QWidget* parent) :
	QWidget(parent) {
	loadTheme();
}

LogisticTab::~LogisticTab() {
}

void
LogisticTab::loadTheme() {
	QFile css("Web.Alert.css");
	if (css.open(QIODevice::ReadOnly)) {
		theme = css.readAll();
		css.close();
	}
}
