#include "Util.h"

#ifndef TEST_GUI_WAYBILL_TAB

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}

#endif // TEST_GUI_WAYBILL_TAB
