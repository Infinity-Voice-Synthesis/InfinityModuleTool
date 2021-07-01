#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include "FSThread.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

namespace Ui { class FTBDialog; };

class FTBDialog : public QDialog
{
	Q_OBJECT

public:
	FTBDialog(QWidget* parent = Q_NULLPTR);
	~FTBDialog();

private:
	Ui::FTBDialog* ui;
	FSThread fst;
private slots:
	void on_selectpath_clicked();
	void on_startscan_clicked();
	void on_fst_finished(QStringList result, QString path);
};
