/********************************************************************************
** Form generated from reading UI file 'transeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSEDITDIALOG_H
#define UI_TRANSEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TransEditDialog
{
public:
    QFormLayout *formLayout_2;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QLineEdit *phone;

    void setupUi(QDialog *TransEditDialog)
    {
        if (TransEditDialog->objectName().isEmpty())
            TransEditDialog->setObjectName(QString::fromUtf8("TransEditDialog"));
        TransEditDialog->resize(400, 146);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        TransEditDialog->setWindowIcon(icon);
        formLayout_2 = new QFormLayout(TransEditDialog);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        buttonBox = new QDialogButtonBox(TransEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, buttonBox);

        groupBox = new QGroupBox(TransEditDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        phone = new QLineEdit(groupBox);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setClearButtonEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, phone);


        formLayout_2->setWidget(0, QFormLayout::SpanningRole, groupBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(name);
        label_2->setBuddy(phone);
#endif // QT_CONFIG(shortcut)

        retranslateUi(TransEditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TransEditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TransEditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TransEditDialog);
    } // setupUi

    void retranslateUi(QDialog *TransEditDialog)
    {
        TransEditDialog->setWindowTitle(QCoreApplication::translate("TransEditDialog", "\347\274\226\350\276\221\350\257\221\346\226\207\346\230\240\345\260\204", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TransEditDialog", "\346\230\240\345\260\204\347\274\226\350\276\221", nullptr));
        label->setText(QCoreApplication::translate("TransEditDialog", "\345\255\227", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("TransEditDialog", "\350\276\223\345\205\245\345\255\227", nullptr));
        label_2->setText(QCoreApplication::translate("TransEditDialog", "\345\217\221\351\237\263", nullptr));
        phone->setPlaceholderText(QCoreApplication::translate("TransEditDialog", "\350\276\223\345\205\245\345\217\221\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransEditDialog: public Ui_TransEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSEDITDIALOG_H
