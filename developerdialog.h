#ifndef DEVELOPERDIALOG_H
#define DEVELOPERDIALOG_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QCryptographicHash>
#include <QMessageBox>

namespace Ui {
class DeveloperDialog;
}

class DeveloperDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeveloperDialog(QWidget *parent = nullptr);
    ~DeveloperDialog();
    void setlist(QJsonArray list);
    QString result();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DeveloperDialog *ui;
    QJsonArray list;
    QString name="";
};

#endif // DEVELOPERDIALOG_H
