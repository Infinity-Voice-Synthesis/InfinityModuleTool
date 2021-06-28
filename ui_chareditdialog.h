/********************************************************************************
** Form generated from reading UI file 'chareditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAREDITDIALOG_H
#define UI_CHAREDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CharEditDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QDoubleSpinBox *CP;
    QLabel *label_3;
    QDoubleSpinBox *PP;
    QLabel *label_4;
    QDoubleSpinBox *VSP;
    QLabel *label_5;
    QDoubleSpinBox *VEP;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CharEditDialog)
    {
        if (CharEditDialog->objectName().isEmpty())
            CharEditDialog->setObjectName(QString::fromUtf8("CharEditDialog"));
        CharEditDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        CharEditDialog->setWindowIcon(icon);
        CharEditDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(CharEditDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(CharEditDialog);
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

        CP = new QDoubleSpinBox(groupBox);
        CP->setObjectName(QString::fromUtf8("CP"));
        CP->setMaximum(2.000000000000000);
        CP->setSingleStep(0.010000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, CP);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        PP = new QDoubleSpinBox(groupBox);
        PP->setObjectName(QString::fromUtf8("PP"));
        PP->setMinimum(-1.000000000000000);
        PP->setMaximum(1.000000000000000);
        PP->setSingleStep(0.010000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, PP);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        VSP = new QDoubleSpinBox(groupBox);
        VSP->setObjectName(QString::fromUtf8("VSP"));
        VSP->setMaximum(1.000000000000000);
        VSP->setSingleStep(0.010000000000000);
        VSP->setValue(0.200000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, VSP);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        VEP = new QDoubleSpinBox(groupBox);
        VEP->setObjectName(QString::fromUtf8("VEP"));
        VEP->setMaximum(1.000000000000000);
        VEP->setSingleStep(0.010000000000000);
        VEP->setValue(0.800000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, VEP);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CharEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(name);
        label_2->setBuddy(CP);
        label_3->setBuddy(PP);
        label_4->setBuddy(VSP);
        label_5->setBuddy(VEP);
#endif // QT_CONFIG(shortcut)

        retranslateUi(CharEditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CharEditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CharEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CharEditDialog);
    } // setupUi

    void retranslateUi(QDialog *CharEditDialog)
    {
        CharEditDialog->setWindowTitle(QCoreApplication::translate("CharEditDialog", "\347\274\226\350\276\221\345\255\227\345\205\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CharEditDialog", "\345\255\227\345\205\270\347\274\226\350\276\221", nullptr));
        label->setText(QCoreApplication::translate("CharEditDialog", "name", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("CharEditDialog", "\350\276\223\345\205\245\345\217\221\351\237\263\346\240\207\350\256\260\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("CharEditDialog", "CP", nullptr));
        label_3->setText(QCoreApplication::translate("CharEditDialog", "PP", nullptr));
        label_4->setText(QCoreApplication::translate("CharEditDialog", "VSP", nullptr));
        label_5->setText(QCoreApplication::translate("CharEditDialog", "VEP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharEditDialog: public Ui_CharEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAREDITDIALOG_H
