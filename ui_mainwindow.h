/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionNew_2;
    QAction *actionOpen_2;
    QAction *actionSave_as_2;
    QAction *actionBuild;
    QAction *actionAbout;
    QAction *actionDeveloper;
    QAction *actionFiles;
    QAction *actionNew_dic;
    QAction *actionOpen_dic;
    QAction *actionSave_dic;
    QAction *actionFrom_cedict;
    QAction *actionSign;
    QAction *actionAutoC;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *engine;
    QWidget *database;
    QWidget *dictionary;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *dicname;
    QSplitter *splitter;
    QTableWidget *charactertable;
    QTableWidget *translatetable;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/icon/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionNew_2 = new QAction(MainWindow);
        actionNew_2->setObjectName(QString::fromUtf8("actionNew_2"));
        actionOpen_2 = new QAction(MainWindow);
        actionOpen_2->setObjectName(QString::fromUtf8("actionOpen_2"));
        actionSave_as_2 = new QAction(MainWindow);
        actionSave_as_2->setObjectName(QString::fromUtf8("actionSave_as_2"));
        actionBuild = new QAction(MainWindow);
        actionBuild->setObjectName(QString::fromUtf8("actionBuild"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionDeveloper = new QAction(MainWindow);
        actionDeveloper->setObjectName(QString::fromUtf8("actionDeveloper"));
        actionFiles = new QAction(MainWindow);
        actionFiles->setObjectName(QString::fromUtf8("actionFiles"));
        actionNew_dic = new QAction(MainWindow);
        actionNew_dic->setObjectName(QString::fromUtf8("actionNew_dic"));
        actionOpen_dic = new QAction(MainWindow);
        actionOpen_dic->setObjectName(QString::fromUtf8("actionOpen_dic"));
        actionSave_dic = new QAction(MainWindow);
        actionSave_dic->setObjectName(QString::fromUtf8("actionSave_dic"));
        actionFrom_cedict = new QAction(MainWindow);
        actionFrom_cedict->setObjectName(QString::fromUtf8("actionFrom_cedict"));
        actionSign = new QAction(MainWindow);
        actionSign->setObjectName(QString::fromUtf8("actionSign"));
        actionSign->setEnabled(false);
        actionAutoC = new QAction(MainWindow);
        actionAutoC->setObjectName(QString::fromUtf8("actionAutoC"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        engine = new QWidget();
        engine->setObjectName(QString::fromUtf8("engine"));
        tabWidget->addTab(engine, QString());
        database = new QWidget();
        database->setObjectName(QString::fromUtf8("database"));
        tabWidget->addTab(database, QString());
        dictionary = new QWidget();
        dictionary->setObjectName(QString::fromUtf8("dictionary"));
        formLayout = new QFormLayout(dictionary);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dictionary);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dicname = new QLineEdit(dictionary);
        dicname->setObjectName(QString::fromUtf8("dicname"));
        dicname->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, dicname);

        splitter = new QSplitter(dictionary);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        charactertable = new QTableWidget(splitter);
        if (charactertable->columnCount() < 5)
            charactertable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        charactertable->setObjectName(QString::fromUtf8("charactertable"));
        charactertable->setContextMenuPolicy(Qt::CustomContextMenu);
        charactertable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        charactertable->setAlternatingRowColors(true);
        charactertable->setSelectionMode(QAbstractItemView::SingleSelection);
        charactertable->setSelectionBehavior(QAbstractItemView::SelectRows);
        charactertable->setShowGrid(true);
        charactertable->setGridStyle(Qt::SolidLine);
        charactertable->setSortingEnabled(true);
        charactertable->setWordWrap(true);
        charactertable->setCornerButtonEnabled(true);
        splitter->addWidget(charactertable);
        charactertable->horizontalHeader()->setCascadingSectionResizes(true);
        charactertable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        translatetable = new QTableWidget(splitter);
        if (translatetable->columnCount() < 2)
            translatetable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        translatetable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        translatetable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        translatetable->setObjectName(QString::fromUtf8("translatetable"));
        translatetable->setContextMenuPolicy(Qt::CustomContextMenu);
        translatetable->setEditTriggers(QAbstractItemView::DoubleClicked);
        translatetable->setAlternatingRowColors(true);
        translatetable->setSelectionMode(QAbstractItemView::SingleSelection);
        translatetable->setSelectionBehavior(QAbstractItemView::SelectRows);
        translatetable->setShowGrid(true);
        translatetable->setGridStyle(Qt::SolidLine);
        translatetable->setSortingEnabled(true);
        translatetable->setWordWrap(true);
        translatetable->setCornerButtonEnabled(true);
        splitter->addWidget(translatetable);
        translatetable->horizontalHeader()->setCascadingSectionResizes(true);
        translatetable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        formLayout->setWidget(1, QFormLayout::SpanningRole, splitter);

        tabWidget->addTab(dictionary, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label->setBuddy(dicname);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave_as);
        menu_2->addAction(actionNew_2);
        menu_2->addAction(actionOpen_2);
        menu_2->addAction(actionSave_as_2);
        menu_3->addAction(actionFiles);
        menu_3->addAction(actionSign);
        menu_3->addAction(actionBuild);
        menu_4->addAction(actionAbout);
        menu_4->addAction(actionDeveloper);
        menu_5->addAction(actionNew_dic);
        menu_5->addAction(actionOpen_dic);
        menu_5->addAction(actionSave_dic);
        menu_5->addSeparator();
        menu_5->addAction(actionFrom_cedict);
        menu_5->addSeparator();
        menu_5->addAction(actionAutoC);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Infinity\347\273\204\344\273\266\345\267\245\345\205\267", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\344\277\241\346\201\257\350\241\250", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\344\277\241\346\201\257\350\241\250", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\241\346\201\257\350\241\250", nullptr));
        actionNew_2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\344\277\241\346\201\257\350\241\250", nullptr));
        actionOpen_2->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\344\277\241\346\201\257\350\241\250", nullptr));
        actionSave_as_2->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\241\346\201\257\350\241\250", nullptr));
        actionBuild->setText(QCoreApplication::translate("MainWindow", "\345\260\201\350\243\205\347\273\204\344\273\266", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        actionDeveloper->setText(QCoreApplication::translate("MainWindow", "\351\252\214\350\257\201\345\274\200\345\217\221\350\200\205\350\272\253\344\273\275", nullptr));
        actionFiles->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\226\207\344\273\266\346\240\221", nullptr));
        actionNew_dic->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\255\227\345\205\270", nullptr));
        actionOpen_dic->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\255\227\345\205\270", nullptr));
        actionSave_dic->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\255\227\345\205\270", nullptr));
        actionFrom_cedict->setText(QCoreApplication::translate("MainWindow", "\344\273\216cedict\345\255\227\345\205\270\345\257\274\345\205\245", nullptr));
        actionSign->setText(QCoreApplication::translate("MainWindow", "\347\255\276\345\220\215", nullptr));
        actionAutoC->setText(QCoreApplication::translate("MainWindow", "\350\257\206\345\210\253\350\276\205\351\237\263\345\274\200\345\244\264\347\232\204\345\217\221\351\237\263\345\271\266\350\256\276\347\275\256\351\273\230\350\256\244CP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(engine), QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(database), QCoreApplication::translate("MainWindow", "\345\243\260\345\272\223", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\205\270\345\220\215\347\247\260", nullptr));
        dicname->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\255\227\345\205\270\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = charactertable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = charactertable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "CP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = charactertable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "PP", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = charactertable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "VSP", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = charactertable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "VEP", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = translatetable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\345\255\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = translatetable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\237\263", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(dictionary), QCoreApplication::translate("MainWindow", "\345\255\227\345\205\270", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\243\260\345\272\223", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\260\201\350\243\205", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\345\255\227\345\205\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
