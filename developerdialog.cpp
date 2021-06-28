#include "developerdialog.h"
#include "ui_developerdialog.h"

DeveloperDialog::DeveloperDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeveloperDialog)
{
    ui->setupUi(this);
}

DeveloperDialog::~DeveloperDialog()
{
    delete ui;
}

void DeveloperDialog::setlist(QJsonArray list)
{
    this->list=list;
}

void DeveloperDialog::on_buttonBox_accepted()
{
    QCryptographicHash hash(QCryptographicHash::Sha512);
    hash.addData(ui->name->text().toLatin1().data());
    QString namehash=hash.result().toHex().toLower();
    hash.reset();
    hash.addData(ui->password->text().toLatin1().data());
    QString passwordhash=hash.result().toHex().toLower();
    int index=-1;
    for(int i=0;i<list.size();i++){
        QJsonObject jo=list.at(i).toObject();
        if(jo.find("name")->toString()==namehash){
            index=i;
            break;
        }
    }
    if(index>-1){
        QJsonObject jo=list.at(index).toObject();
        if(jo.find("password")->toString()==passwordhash){
            this->name=ui->name->text();
        }else{
            QMessageBox::warning(this,"error","bad password!");
            this->name="";
        }
    }else{
        QMessageBox::warning(this,"error","bad user name:"+ui->name->text());
        this->name="";
    }
}

void DeveloperDialog::on_buttonBox_rejected()
{
    this->name="";
}

QString DeveloperDialog::result()
{
    return this->name;
}
