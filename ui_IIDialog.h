/********************************************************************************
** Form generated from reading UI file 'IIDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IIDIALOG_H
#define UI_IIDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_IIDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QPushButton *openssl;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *QVersion;
    QLabel *comt;
    QLabel *version;

    void setupUi(QDialog *IIDialog)
    {
        if (IIDialog->objectName().isEmpty())
            IIDialog->setObjectName(QString::fromUtf8("IIDialog"));
        IIDialog->resize(658, 243);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        IIDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(IIDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(IIDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 6, 0, 1, 2);

        openssl = new QPushButton(groupBox);
        openssl->setObjectName(QString::fromUtf8("openssl"));
        openssl->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(255, 255, 255, 0);"));

        gridLayout->addWidget(openssl, 5, 0, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 7, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 2);

        QVersion = new QPushButton(groupBox);
        QVersion->setObjectName(QString::fromUtf8("QVersion"));
        QVersion->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(255, 255, 255, 0);"));

        gridLayout->addWidget(QVersion, 3, 0, 1, 2);

        comt = new QLabel(groupBox);
        comt->setObjectName(QString::fromUtf8("comt"));
        comt->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(comt, 2, 0, 1, 2);

        version = new QLabel(groupBox);
        version->setObjectName(QString::fromUtf8("version"));
        version->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(version, 1, 0, 1, 2);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(IIDialog);

        QMetaObject::connectSlotsByName(IIDialog);
    } // setupUi

    void retranslateUi(QDialog *IIDialog)
    {
        IIDialog->setWindowTitle(QCoreApplication::translate("IIDialog", "\345\205\263\344\272\216Infinity\347\273\204\344\273\266\345\267\245\345\205\267", nullptr));
        groupBox->setTitle(QCoreApplication::translate("IIDialog", "\345\205\263\344\272\216Infinity\347\273\204\344\273\266\345\267\245\345\205\267", nullptr));
        label_3->setText(QCoreApplication::translate("IIDialog", "Infinity\346\255\214\345\243\260\345\220\210\346\210\220\345\233\242\351\230\237\344\277\235\347\225\231\346\211\200\346\234\211\346\235\203\345\210\251", nullptr));
        openssl->setText(QCoreApplication::translate("IIDialog", "\346\234\254\347\250\213\345\272\217\344\275\277\347\224\250OpenSSL\345\272\2231.1.1.11\347\211\210\346\234\254(OpenSSL License)", nullptr));
        label->setText(QCoreApplication::translate("IIDialog", "Infinity\347\273\204\344\273\266\345\267\245\345\205\267", nullptr));
        label_4->setText(QCoreApplication::translate("IIDialog", "\344\273\273\344\275\225\346\234\252\347\273\217\350\256\270\345\217\257\347\232\204\345\257\271\346\255\244\347\250\213\345\272\217\347\232\204\344\277\256\346\224\271\343\200\201\346\224\271\347\274\226\343\200\201\351\200\206\345\220\221\347\274\226\350\257\221\343\200\201\345\217\215\346\261\207\347\274\226\343\200\201\345\217\215\347\274\226\350\257\221\350\241\214\344\270\272\351\203\275\345\260\206\350\242\253\350\247\206\344\270\272\351\235\236\346\263\225", nullptr));
        label_2->setText(QCoreApplication::translate("IIDialog", "\346\234\254\347\250\213\345\272\217\344\273\245\345\212\250\346\200\201\351\223\276\346\216\245\345\275\242\345\274\217\344\275\277\347\224\250Qt(LGPLv3)\345\272\223", nullptr));
        QVersion->setText(QCoreApplication::translate("IIDialog", "Qt\345\272\223\347\211\210\346\234\254\357\274\232", nullptr));
        comt->setText(QCoreApplication::translate("IIDialog", "\347\274\226\350\257\221\346\227\266\351\227\264\357\274\232", nullptr));
        version->setText(QCoreApplication::translate("IIDialog", "\347\211\210\346\234\254\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IIDialog: public Ui_IIDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IIDIALOG_H
