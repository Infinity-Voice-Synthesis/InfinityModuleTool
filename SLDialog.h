﻿#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include <QStringList>
namespace Ui { class SLDialog; };

class SLDialog : public QDialog
{
	Q_OBJECT

public:
	SLDialog(QWidget* parent = Q_NULLPTR);
	~SLDialog();
	void setlist(QStringList sdb);
	void setlink(QString pitch, QString sdb);

	QString pitch, sdb;

private:
	Ui::SLDialog* ui;
private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();
};
