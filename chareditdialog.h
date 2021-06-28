#ifndef CHAREDITDIALOG_H
#define CHAREDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class CharEditDialog;
}

class CharEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CharEditDialog(QWidget *parent = nullptr);
    ~CharEditDialog();
    void setchar(QString name,double CP=0,double PP=0,double VSP=0.2,double VEP=0.8);
    QString name;
    double CP=0;
    double PP=0;
    double VSP=0.2;
    double VEP=0.8;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::CharEditDialog *ui;
};

#endif // CHAREDITDIALOG_H
