#include "transeditdialog.h"
#include "ui_transeditdialog.h"

TransEditDialog::TransEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransEditDialog)
{
    ui->setupUi(this);
}

TransEditDialog::~TransEditDialog()
{
    delete ui;
}

void TransEditDialog::settrans(QString name,QString phoneme)
{
    ui->name->setText(name);
    ui->phone->setText(phoneme);
    this->name=name;
    this->phoneme=phoneme;
}
void TransEditDialog::on_buttonBox_accepted()
{
    if((!ui->phone->text().isEmpty())&&(!ui->name->text().isEmpty())){
        this->name=ui->name->text();
        this->phoneme=ui->phone->text();
    }else{
        QMessageBox::warning(this,"error","settings error");
    }
    this->close();
}

void TransEditDialog::on_buttonBox_rejected()
{
    this->close();
}