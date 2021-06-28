#include "QIconWidget.h"
#include "ui_QIconWidget.h"

QIconWidget::QIconWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QIconWidget();
	ui->setupUi(this);
}

QIconWidget::~QIconWidget()
{
	delete ui;
}
