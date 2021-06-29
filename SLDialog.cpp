#include "SLDialog.h"
#include "ui_SLDialog.h"

SLDialog::SLDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::SLDialog();
	ui->setupUi(this);
	ui->pitch->clear();
	for (int i = 0; i <= 10; i++) {
		ui->pitch->insertItem(0, QString("C" + QString::number(i)));
		ui->pitch->insertItem(0, QString("C#" + QString::number(i)));
		ui->pitch->insertItem(0, QString("D" + QString::number(i)));
		ui->pitch->insertItem(0, QString("D#" + QString::number(i)));
		ui->pitch->insertItem(0, QString("E" + QString::number(i)));
		ui->pitch->insertItem(0, QString("F" + QString::number(i)));
		ui->pitch->insertItem(0, QString("F#" + QString::number(i)));
		ui->pitch->insertItem(0, QString("G" + QString::number(i)));
		ui->pitch->insertItem(0, QString("G#" + QString::number(i)));
		ui->pitch->insertItem(0, QString("A" + QString::number(i)));
		ui->pitch->insertItem(0, QString("A#" + QString::number(i)));
		ui->pitch->insertItem(0, QString("B" + QString::number(i)));
	}
	ui->pitch->setCurrentText("C5");
}

SLDialog::~SLDialog()
{
	delete ui;
}

void SLDialog::setlist(QStringList sdb)
{
	ui->sdb->clear();
	for (int i = 0; i < sdb.size(); i++) {
		ui->sdb->addItem(sdb.at(i));
	}
}

void SLDialog::setlink(QString pitch, QString sdb)
{
	ui->pitch->setCurrentText(pitch);
	ui->sdb->setCurrentText(sdb);
	this->pitch.clear();
	this->sdb.clear();
}

void SLDialog::on_buttonBox_accepted()
{
	this->pitch = ui->pitch->currentText();
	this->sdb = ui->sdb->currentText();
	this->close();
}

void SLDialog::on_buttonBox_rejected()
{
	this->close();
}
