#include "StatusWidgetGroup.h"
#include "ui_StatusWidgetGroup.h"

StatusWidgetGroup::StatusWidgetGroup(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::StatusWidgetGroup)
{
	ui->setupUi(this);
}

StatusWidgetGroup::~StatusWidgetGroup()
{
	delete ui;
}

void
StatusWidgetGroup::on_statusComboBox_currentIndexChanged(const int index) {
	switch (index) {
		case None        :
			ui->statusCommentIconLabel->setPixmap(QPixmap());
			ui->statusCommentWidget->setStyleSheet("color: black;");
			ui->statusCommentWidget->hide();
			return;
		case Question    :
			ui->statusCommentIconLabel->setPixmap(QPixmap(":/Gui/Icon/Warnings/Medium/Question.png"));
			ui->statusCommentWidget->setStyleSheet("color: #719017;");
			ui->statusCommentWidget->show();
			return;
		case Idea        :
			ui->statusCommentIconLabel->setPixmap(QPixmap(":/Gui/Icon/Warnings/Medium/Idea.png"));
			ui->statusCommentWidget->setStyleSheet("color: #5db1a1;");
			ui->statusCommentWidget->show();
			return;
		case Information :
			ui->statusCommentIconLabel->setPixmap(QPixmap(":/Gui/Icon/Warnings/Medium/Information.png"));
			ui->statusCommentWidget->setStyleSheet("color: #4c73a7;");
			ui->statusCommentWidget->show();
			return;
		case Warning     :
			ui->statusCommentIconLabel->setPixmap(QPixmap(":/Gui/Icon/Warnings/Medium/Warning.png"));
			ui->statusCommentWidget->setStyleSheet("color: #b42735;");
			ui->statusCommentWidget->show();
			return;
		case Error       :
			ui->statusCommentIconLabel->setPixmap(QPixmap(":/Gui/Icon/Warnings/Medium/Error.png"));
			ui->statusCommentWidget->setStyleSheet("color: #8a1167;");
			ui->statusCommentWidget->show();
			return;
	}
}
