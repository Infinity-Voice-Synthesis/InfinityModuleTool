/********************************************************************************
** Form generated from reading UI file 'chareditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAREDITDIALOG_H
#define UI_CHAREDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CharEditDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *consonant;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *x_sampa;
    QLineEdit *name;

    void setupUi(QDialog *CharEditDialog)
    {
        if (CharEditDialog->objectName().isEmpty())
            CharEditDialog->setObjectName(QString::fromUtf8("CharEditDialog"));
        CharEditDialog->resize(400, 219);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        CharEditDialog->setWindowIcon(icon);
        CharEditDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(CharEditDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(CharEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        groupBox = new QGroupBox(CharEditDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        consonant = new QCheckBox(groupBox);
        consonant->setObjectName(QString::fromUtf8("consonant"));

        gridLayout_2->addWidget(consonant, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(67, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        x_sampa = new QLineEdit(groupBox);
        x_sampa->setObjectName(QString::fromUtf8("x_sampa"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(x_sampa->sizePolicy().hasHeightForWidth());
        x_sampa->setSizePolicy(sizePolicy1);
        x_sampa->setClearButtonEnabled(true);

        gridLayout_2->addWidget(x_sampa, 1, 1, 1, 2);

        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        name->setClearButtonEnabled(true);

        gridLayout_2->addWidget(name, 0, 1, 1, 2);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(name);
        label_2->setBuddy(x_sampa);
#endif // QT_CONFIG(shortcut)

        retranslateUi(CharEditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CharEditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CharEditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CharEditDialog);
    } // setupUi

    void retranslateUi(QDialog *CharEditDialog)
    {
        CharEditDialog->setWindowTitle(QCoreApplication::translate("CharEditDialog", "\347\274\226\350\276\221\345\255\227\345\205\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CharEditDialog", "\345\255\227\345\205\270\347\274\226\350\276\221", nullptr));
        label->setText(QCoreApplication::translate("CharEditDialog", "name", nullptr));
        consonant->setText(QCoreApplication::translate("CharEditDialog", "consonant", nullptr));
        label_2->setText(QCoreApplication::translate("CharEditDialog", "x-sampa", nullptr));
        x_sampa->setText(QCoreApplication::translate("CharEditDialog", "a", nullptr));
        x_sampa->setPlaceholderText(QCoreApplication::translate("CharEditDialog", "\350\276\223\345\205\245x-sampa\351\237\263\347\264\240", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("CharEditDialog", "\350\276\223\345\205\245\345\217\221\351\237\263\346\240\207\350\256\260\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharEditDialog: public Ui_CharEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAREDITDIALOG_H
