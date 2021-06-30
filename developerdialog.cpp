#include "developerdialog.h"
#include "ui_developerdialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

DeveloperDialog::DeveloperDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::DeveloperDialog)
{
	ui->setupUi(this);
}

DeveloperDialog::~DeveloperDialog()
{
	delete ui;
}

void DeveloperDialog::setlist(QJsonArray list)
{
	this->list = list;
}

void DeveloperDialog::on_buttonBox_accepted()
{
	QCryptographicHash hash(QCryptographicHash::Sha512);
	hash.addData(ui->name->text().toLatin1().data());
	QString namehash = hash.result().toHex().toLower();
	hash.reset();
	hash.addData(ui->password->text().toLatin1().data());
	QString passwordhash = hash.result().toHex().toLower();
	int index = -1;
	for (int i = 0; i < list.size(); i++) {
		QJsonObject jo = list.at(i).toObject();
		if (jo.find("name")->toString() == namehash) {
			index = i;
			break;
		}
	}
	if (index > -1) {
		QJsonObject jo = list.at(index).toObject();
		if (jo.find("password")->toString() == passwordhash) {
			this->name = ui->name->text();
		}
		else {
			QMessageBox::warning(this, "出错", "密码有误！");
			this->name = "";
		}
	}
	else {
		QMessageBox::warning(this, "出错", "无效的用户名：" + ui->name->text());
		this->name = "";
	}
}

void DeveloperDialog::on_buttonBox_rejected()
{
	this->name = "";
}

QString DeveloperDialog::result()
{
	return this->name;
}
