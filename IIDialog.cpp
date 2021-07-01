#include "IIDialog.h"
#include "ui_IIDialog.h"

IIDialog::IIDialog(QWidget* parent)
	: QDialog(parent)
{
	ui = new Ui::IIDialog();
	ui->setupUi(this);
	ui->version->setText("版本：" + QString::number(::_IMT_Version));
	ui->comt->setText("编译时间：" + QString(__DATE__) + " " + QString(__TIME__));
	ui->QVersion->setText("Qt库版本：" + QString(QT_VERSION_STR));
}

IIDialog::~IIDialog()
{
	delete ui;
}

void IIDialog::on_QVersion_clicked()
{
	QMessageBox::aboutQt(this, "关于Qt库");
}
