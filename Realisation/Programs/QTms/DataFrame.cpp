#include "DataFrame.h"
#include "ui_DataFrame.h"

DataFrame::DataFrame(QWidget* parent) :
	QFrame(parent),
	ui(new Ui::DataFrame) {
	ui->setupUi(this);
}

DataFrame::~DataFrame() {
	delete ui;
}
