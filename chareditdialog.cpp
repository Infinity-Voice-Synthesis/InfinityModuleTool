#include "chareditdialog.h"
#include "ui_chareditdialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CharEditDialog::CharEditDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::CharEditDialog)
{
	ui->setupUi(this);
}

CharEditDialog::~CharEditDialog()
{
	delete ui;
}

void CharEditDialog::setchar(QString name, double CP, double PP, double VSP, double VEP)
{
	ui->name->setText(name);
	ui->CP->setValue(CP);
	ui->PP->setValue(PP);
	ui->VSP->setValue(VSP);
	ui->VEP->setValue(VEP);
	this->name = name;
	this->CP = CP;
	this->PP = PP;
	this->VSP = VSP;
	this->VEP = VEP;
}

void CharEditDialog::on_buttonBox_accepted()
{
	if (ui->PP->value() >= (-ui->CP->value()) && ui->VSP->value() >= ui->PP->value() && ui->VEP->value() >= ui->VSP->value() && (!ui->name->text().isEmpty())) {
		this->name = ui->name->text();
		this->CP = ui->CP->value();
		this->PP = ui->PP->value();
		this->VSP = ui->VSP->value();
		this->VEP = ui->VEP->value();
	}
	else {
		QMessageBox::warning(this, "出错", "设置有误");
	}
	this->close();
}

void CharEditDialog::on_buttonBox_rejected()
{
	this->close();
}
