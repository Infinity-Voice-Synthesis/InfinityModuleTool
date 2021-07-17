/********************************************************************************
** Form generated from reading UI file 'FTBDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTBDIALOG_H
#define UI_FTBDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FTBDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *rootpath;
    QPushButton *selectpath;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startscan;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *results;

    void setupUi(QDialog *FTBDialog)
    {
        if (FTBDialog->objectName().isEmpty())
            FTBDialog->setObjectName(QString::fromUtf8("FTBDialog"));
        FTBDialog->resize(691, 472);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTBDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(FTBDialog);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(FTBDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        rootpath = new QLineEdit(groupBox);
        rootpath->setObjectName(QString::fromUtf8("rootpath"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rootpath->sizePolicy().hasHeightForWidth());
        rootpath->setSizePolicy(sizePolicy1);
        rootpath->setReadOnly(true);

        gridLayout->addWidget(rootpath, 0, 1, 1, 3);

        selectpath = new QPushButton(groupBox);
        selectpath->setObjectName(QString::fromUtf8("selectpath"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectpath->sizePolicy().hasHeightForWidth());
        selectpath->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(selectpath, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 2);

        startscan = new QPushButton(groupBox);
        startscan->setObjectName(QString::fromUtf8("startscan"));
        sizePolicy2.setHeightForWidth(startscan->sizePolicy().hasHeightForWidth());
        startscan->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(startscan, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(282, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 3, 1, 2);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(FTBDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        results = new QPlainTextEdit(groupBox_2);
        results->setObjectName(QString::fromUtf8("results"));
        results->setReadOnly(true);

        gridLayout_2->addWidget(results, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(rootpath);
#endif // QT_CONFIG(shortcut)

        retranslateUi(FTBDialog);

        QMetaObject::connectSlotsByName(FTBDialog);
    } // setupUi

    void retranslateUi(QDialog *FTBDialog)
    {
        FTBDialog->setWindowTitle(QCoreApplication::translate("FTBDialog", "\347\224\237\346\210\220\346\226\207\344\273\266\346\240\221", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FTBDialog", "\351\200\211\346\213\251\347\233\256\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("FTBDialog", "\347\273\204\344\273\266\347\233\256\345\275\225", nullptr));
        rootpath->setPlaceholderText(QCoreApplication::translate("FTBDialog", "\350\257\267\351\200\211\346\213\251\350\246\201\346\211\223\345\214\205\347\232\204\347\273\204\344\273\266\346\211\200\345\234\250\347\232\204\347\233\256\345\275\225\350\277\233\350\241\214\346\211\253\346\217\217", nullptr));
        selectpath->setText(QCoreApplication::translate("FTBDialog", "\346\265\217\350\247\210", nullptr));
        startscan->setText(QCoreApplication::translate("FTBDialog", "\346\211\253\346\217\217\345\271\266\344\277\235\345\255\230\347\273\223\346\236\234", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FTBDialog", "\346\211\253\346\217\217\347\273\223\346\236\234", nullptr));
        results->setPlaceholderText(QCoreApplication::translate("FTBDialog", "\346\227\240\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTBDialog: public Ui_FTBDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTBDIALOG_H
