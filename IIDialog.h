#pragma once

#include <QDialog>
#include "version.h"
#include <QMessageBox>
namespace Ui { class IIDialog; };

class IIDialog : public QDialog
{
	Q_OBJECT

public:
	IIDialog(QWidget* parent = Q_NULLPTR);
	~IIDialog();

private:
	Ui::IIDialog* ui;
private slots:
	void on_QVersion_clicked();
};
