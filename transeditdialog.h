#ifndef TRANSEDITDIALOG_H
#define TRANSEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class TransEditDialog;
}

class TransEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransEditDialog(QWidget *parent = nullptr);
    ~TransEditDialog();
    void settrans(QString name,QString phoneme);
    QString name,phoneme;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::TransEditDialog *ui;
};

#endif // TRANSEDITDIALOG_H
