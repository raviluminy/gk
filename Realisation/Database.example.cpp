#include <QtGlobal>
#include <QtSql>

int main() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setUserName("root");
	db.setPassword("");
	db.setDatabaseName("GkLogistic");
	if (!db.open()) {
		qDebug() << "Connection to " << db.hostName() << " is failed" << endl;
		qDebug() << "An error was encountered:" << endl;
		qDebug() << db.lastError().text() << endl;
		return EXIT_FAILURE;
	}
	qDebug() << "Connection to " << db.hostName() << " is successfull" << endl;
	// do something
	db.close();
	return EXIT_SUCCESS;
}
