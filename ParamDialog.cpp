#include "ParamDialog.h"
#include "ui_ParamDialog.h"

ParamDialog::ParamDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::ParamDialog();
	ui->setupUi(this);
}

ParamDialog::~ParamDialog()
{
	delete ui;
}

void ParamDialog::on_max_valueChanged(double value)
{
	ui->min->setMaximum(value);
	ui->def->setMaximum(value);
}

void ParamDialog::on_min_valueChanged(double value)
{
	ui->max->setMinimum(value);
	ui->def->setMinimum(value);
}

void ParamDialog::setparam(QString name, double max, double min, double def)
{
	ui->name->setText(name);
	ui->max->setValue(max);
	ui->min->setValue(min);
	ui->def->setValue(def);
	this->name = "";
}

void ParamDialog::on_buttonBox_accepted()
{
	this->name = ui->name->text();
	this->max = ui->max->value();
	this->min = ui->min->value();
	this->def = ui->def->value();
}