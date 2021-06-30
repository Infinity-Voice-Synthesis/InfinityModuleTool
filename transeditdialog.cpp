#include "transeditdialog.h"
#include "ui_transeditdialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

TransEditDialog::TransEditDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::TransEditDialog)
{
	ui->setupUi(this);
}

TransEditDialog::~TransEditDialog()
{
	delete ui;
}

void TransEditDialog::settrans(QString name, QString phoneme)
{
	ui->name->setText(name);
	ui->phone->setText(phoneme);
	this->name = name;
	this->phoneme = phoneme;
}
void TransEditDialog::on_buttonBox_accepted()
{
	if ((!ui->phone->text().isEmpty()) && (!ui->name->text().isEmpty())) {
		this->name = ui->name->text();
		this->phoneme = ui->phone->text();
	}
	else {
		QMessageBox::warning(this, "出错", "设置有误");
	}
	this->close();
}

void TransEditDialog::on_buttonBox_rejected()
{
	this->close();
}
