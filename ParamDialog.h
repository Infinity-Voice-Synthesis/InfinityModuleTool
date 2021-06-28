#pragma once

#include <QDialog>
namespace Ui { class ParamDialog; };

class ParamDialog : public QDialog
{
	Q_OBJECT

public:
	ParamDialog(QWidget *parent = Q_NULLPTR);
	~ParamDialog();
	void setparam(QString name, double max, double min, double def);
	QString name;
	double max = 1;
	double min = 0;
	double def = 0;

private:
	Ui::ParamDialog *ui;
private slots:
	void on_max_valueChanged(double value);
	void on_min_valueChanged(double value);
	void on_buttonBox_accepted();
};
