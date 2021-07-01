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
	connect(&fst, &FSThread::finished, this, &FTBDialog::on_fst_finished, Qt::UniqueConnection);
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

void FTBDialog::on_startscan_clicked()
{
	QString path = ui->rootpath->text();
	if (!path.isEmpty()) {
		ui->results->clear();
		if (fst.isRunning()) {
			ui->results->appendPlainText("等待未完成的扫描线程结束...");
			fst.terminate();
			fst.wait();
		}

		QDir dir(path);
		if (dir.exists()) {

			QFile file(path + "/.Infinity.MT.Filelist.raw");
			if (file.exists()) {
				QMessageBox::StandardButton result = QMessageBox::question(this, "文件树生成", "检测到目录中已有扫描结果，是否要重新扫描？", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
				if (result == QMessageBox::Yes) {
					file.remove();
					ui->results->appendPlainText("配置本次扫描...");
					fst.setPath(path);
					ui->results->appendPlainText("启动扫描...");
					fst.start();
				}
				else {
					ui->results->appendPlainText("扫描已取消！");
				}
			}
			else {
				ui->results->appendPlainText("配置本次扫描...");
				fst.setPath(path);
				ui->results->appendPlainText("启动扫描...");
				fst.start();
			}
		}
		else {
			ui->results->appendPlainText("不存在的扫描目录！");
		}
	}
	else {
		QMessageBox::warning(this, "出错", "未选择要扫描的目录");
	}
}

void FTBDialog::on_fst_finished(QStringList result, QString path)
{
	ui->results->appendPlainText("扫描结果：");
	for (int i = 0; i < result.size(); i++) {
		ui->results->appendPlainText(result.at(i));
	}
	QFile file(path + "/.Infinity.MT.Filelist.raw");
	if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
		ui->results->appendPlainText("生成扫描结果...");
		QString data;
		for (int i = 0; i < result.size(); i++) {
			data += result.at(i);
			if (i < result.size() - 1) {
				data += "\n";
			}
		}
		ui->results->appendPlainText("保存扫描结果...");
		file.write(data.toUtf8());
		file.close();
		ui->results->appendPlainText("扫描完成！");
	}
	else {
		ui->results->appendPlainText("未能保存扫描结果！");
	}
}
