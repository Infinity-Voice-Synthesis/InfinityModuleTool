/********************************************************************************
** Form generated from reading UI file 'QIconWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QICONWIDGET_H
#define UI_QICONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QIconWidget
{
public:

    void setupUi(QWidget *QIconWidget)
    {
        if (QIconWidget->objectName().isEmpty())
            QIconWidget->setObjectName(QString::fromUtf8("QIconWidget"));
        QIconWidget->resize(400, 300);

        retranslateUi(QIconWidget);

        QMetaObject::connectSlotsByName(QIconWidget);
    } // setupUi

    void retranslateUi(QWidget *QIconWidget)
    {
        QIconWidget->setWindowTitle(QCoreApplication::translate("QIconWidget", "QIconWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QIconWidget: public Ui_QIconWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QICONWIDGET_H
