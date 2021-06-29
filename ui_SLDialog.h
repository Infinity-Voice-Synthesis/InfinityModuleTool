/********************************************************************************
** Form generated from reading UI file 'SLDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLDIALOG_H
#define UI_SLDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SLDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *pitch;
    QLabel *label_2;
    QComboBox *sdb;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SLDialog)
    {
        if (SLDialog->objectName().isEmpty())
            SLDialog->setObjectName(QString::fromUtf8("SLDialog"));
        SLDialog->resize(400, 135);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        SLDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(SLDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(SLDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pitch = new QComboBox(groupBox);
        pitch->setObjectName(QString::fromUtf8("pitch"));

        gridLayout->addWidget(pitch, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        sdb = new QComboBox(groupBox);
        sdb->setObjectName(QString::fromUtf8("sdb"));

        gridLayout->addWidget(sdb, 0, 3, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SLDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(pitch);
        label_2->setBuddy(sdb);
#endif // QT_CONFIG(shortcut)

        retranslateUi(SLDialog);

        QMetaObject::connectSlotsByName(SLDialog);
    } // setupUi

    void retranslateUi(QDialog *SLDialog)
    {
        SLDialog->setWindowTitle(QCoreApplication::translate("SLDialog", "\346\230\240\345\260\204\347\274\226\350\276\221", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SLDialog", "\346\230\240\345\260\204\347\274\226\350\276\221", nullptr));
        label->setText(QCoreApplication::translate("SLDialog", "\351\237\263\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("SLDialog", "\345\243\260\345\272\223\351\237\263\351\230\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SLDialog: public Ui_SLDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLDIALOG_H
