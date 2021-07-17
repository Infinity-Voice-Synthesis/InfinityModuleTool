/********************************************************************************
** Form generated from reading UI file 'ParamDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMDIALOG_H
#define UI_PARAMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ParamDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QDoubleSpinBox *max;
    QLabel *label_3;
    QDoubleSpinBox *min;
    QLabel *label_4;
    QDoubleSpinBox *def;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ParamDialog)
    {
        if (ParamDialog->objectName().isEmpty())
            ParamDialog->setObjectName(QString::fromUtf8("ParamDialog"));
        ParamDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        ParamDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(ParamDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(ParamDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
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

        max = new QDoubleSpinBox(groupBox);
        max->setObjectName(QString::fromUtf8("max"));
        max->setMaximum(999999999.000000000000000);
        max->setSingleStep(0.100000000000000);
        max->setValue(1.000000000000000);

        gridLayout->addWidget(max, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        min = new QDoubleSpinBox(groupBox);
        min->setObjectName(QString::fromUtf8("min"));
        min->setMinimum(-999999999.000000000000000);
        min->setMaximum(1.000000000000000);
        min->setSingleStep(0.100000000000000);

        gridLayout->addWidget(min, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        def = new QDoubleSpinBox(groupBox);
        def->setObjectName(QString::fromUtf8("def"));
        def->setMaximum(1.000000000000000);
        def->setSingleStep(0.100000000000000);

        gridLayout->addWidget(def, 3, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ParamDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(name);
        label_2->setBuddy(max);
        label_3->setBuddy(min);
        label_4->setBuddy(def);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ParamDialog);

        QMetaObject::connectSlotsByName(ParamDialog);
    } // setupUi

    void retranslateUi(QDialog *ParamDialog)
    {
        ParamDialog->setWindowTitle(QCoreApplication::translate("ParamDialog", "\345\217\202\346\225\260\347\274\226\350\276\221", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ParamDialog", "\345\217\202\346\225\260\347\274\226\350\276\221", nullptr));
        label->setText(QCoreApplication::translate("ParamDialog", "\345\217\202\346\225\260\345\220\215\347\247\260", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("ParamDialog", "\350\257\267\350\276\223\345\205\245\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("ParamDialog", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("ParamDialog", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("ParamDialog", "\351\273\230\350\256\244\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParamDialog: public Ui_ParamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMDIALOG_H
