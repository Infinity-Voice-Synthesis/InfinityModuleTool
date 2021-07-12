#ifndef CHAREDITDIALOG_H
#define CHAREDITDIALOG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include <QMessageBox>

namespace Ui {
	class CharEditDialog;
}

class CharEditDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CharEditDialog(QWidget* parent = nullptr);
	~CharEditDialog();
	void setchar(QString name, bool consonant, QString x_sampa);
	QString name;
	bool consonant;
	QString x_sampa;
private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

private:
	Ui::CharEditDialog* ui;
};

#endif // CHAREDITDIALOG_H
