#include "FTBDialog.h"
#include "ui_FTBDialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

FTBDialog::FTBDialog(QWidget* parent)
	: QDialog(parent)
{
	ui = new Ui::FTBDialog();
	ui->setupUi(this);
}

FTBDialog::~FTBDialog()
{
	if (fst.isRunning()) {
		fst.terminate();
		fst.wait();
	}
	delete ui;
}

void FTBDialog::on_selectpath_clicked()
{
	QString path = QFileDialog::getExistingDirectory(this, "选择组件所在的目录", QDir::currentPath());
	if (!path.isEmpty()) {
		QDir::setCurrent(path);
		ui->rootpath->setText(path);
	}
}

void FTBDialog::on_scan_clicked()
{
	QString path = ui->rootpath->text();
	if (!path.isEmpty()) {
		ui->results->clear();
		if (fst.isRunning()) {
			ui->results->appendPlainText("等待未完成的扫描线程结束...");
			fst.terminate();
			fst.wait();
		}
	}
	else {

	}
}

void FTBDialog::on_fst_finished()
{

}
