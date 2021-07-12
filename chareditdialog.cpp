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

void CharEditDialog::setchar(QString name, bool consonant, QString x_sampa)
{
	ui->name->setText(name);
	ui->consonant->setChecked(consonant);
	ui->x_sampa->setText(x_sampa);
	this->name = name;
	this->consonant = consonant;
	this->x_sampa = x_sampa;
}

void CharEditDialog::on_buttonBox_accepted()
{
	if ((!ui->name->text().isEmpty()) && (!ui->x_sampa->text().isEmpty())) {
		this->name = ui->name->text();
		this->consonant = ui->consonant->isChecked();
		this->x_sampa = ui->x_sampa->text();
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
