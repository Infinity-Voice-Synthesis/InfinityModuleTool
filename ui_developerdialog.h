/********************************************************************************
** Form generated from reading UI file 'developerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOPERDIALOG_H
#define UI_DEVELOPERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DeveloperDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QLineEdit *password;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DeveloperDialog)
    {
        if (DeveloperDialog->objectName().isEmpty())
            DeveloperDialog->setObjectName(QString::fromUtf8("DeveloperDialog"));
        DeveloperDialog->resize(400, 180);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeveloperDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(DeveloperDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(DeveloperDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        password = new QLineEdit(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DeveloperDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(name);
        label_2->setBuddy(password);
#endif // QT_CONFIG(shortcut)

        retranslateUi(DeveloperDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeveloperDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeveloperDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeveloperDialog);
    } // setupUi

    void retranslateUi(QDialog *DeveloperDialog)
    {
        DeveloperDialog->setWindowTitle(QCoreApplication::translate("DeveloperDialog", "\350\256\244\350\257\201\345\274\200\345\217\221\350\200\205\350\265\204\346\240\274", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DeveloperDialog", "\345\274\200\345\217\221\350\200\205\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("DeveloperDialog", "\347\224\250\346\210\267", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("DeveloperDialog", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("DeveloperDialog", "\345\257\206\347\240\201", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("DeveloperDialog", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeveloperDialog: public Ui_DeveloperDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPERDIALOG_H
