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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qiconwidget.h>

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
    QFormLayout *formLayout_2;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QLineEdit *enginemain;
    QPushButton *loadenginemain;
    QLineEdit *enginename;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *engineiconname;
    QIconWidget *engineicon;
    QPushButton *openengineicon;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLineEdit *engineauthor;
    QLabel *label_5;
    QDoubleSpinBox *engineversion;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPlainTextEdit *engineinfor;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QTableWidget *ewplist;
    QPushButton *ewpadd;
    QPushButton *ewpedit;
    QPushButton *ewpdel;
    QPushButton *ewpup;
    QPushButton *ewpdown;
    QWidget *page_3;
    QGridLayout *gridLayout_6;
    QTableWidget *enplist;
    QPushButton *enpadd;
    QPushButton *enpedit;
    QPushButton *enpdel;
    QPushButton *enpup;
    QPushButton *enpdown;
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
        MainWindow->resize(912, 653);
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
        formLayout_2 = new QFormLayout(engine);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        toolBox = new QToolBox(engine);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 862, 440));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 3, 0, 1, 5);

        horizontalSpacer_5 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 4, 0, 1, 5);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        enginemain = new QLineEdit(groupBox_2);
        enginemain->setObjectName(QString::fromUtf8("enginemain"));
        enginemain->setReadOnly(true);

        gridLayout_3->addWidget(enginemain, 2, 1, 1, 1);

        loadenginemain = new QPushButton(groupBox_2);
        loadenginemain->setObjectName(QString::fromUtf8("loadenginemain"));

        gridLayout_3->addWidget(loadenginemain, 2, 2, 1, 1);

        enginename = new QLineEdit(groupBox_2);
        enginename->setObjectName(QString::fromUtf8("enginename"));

        gridLayout_3->addWidget(enginename, 0, 1, 1, 2);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        engineiconname = new QLineEdit(groupBox);
        engineiconname->setObjectName(QString::fromUtf8("engineiconname"));
        engineiconname->setReadOnly(true);

        gridLayout_2->addWidget(engineiconname, 0, 0, 1, 1);

        engineicon = new QIconWidget(groupBox);
        engineicon->setObjectName(QString::fromUtf8("engineicon"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(engineicon->sizePolicy().hasHeightForWidth());
        engineicon->setSizePolicy(sizePolicy2);
        engineicon->setMinimumSize(QSize(50, 50));

        gridLayout_2->addWidget(engineicon, 0, 1, 3, 1);

        openengineicon = new QPushButton(groupBox);
        openengineicon->setObjectName(QString::fromUtf8("openengineicon"));

        gridLayout_2->addWidget(openengineicon, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 5, 5, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        engineauthor = new QLineEdit(groupBox_3);
        engineauthor->setObjectName(QString::fromUtf8("engineauthor"));

        gridLayout_4->addWidget(engineauthor, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_5, 0, 2, 1, 1);

        engineversion = new QDoubleSpinBox(groupBox_3);
        engineversion->setObjectName(QString::fromUtf8("engineversion"));
        engineversion->setSingleStep(0.100000000000000);
        engineversion->setValue(0.100000000000000);

        gridLayout_4->addWidget(engineversion, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(320, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(348, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        engineinfor = new QPlainTextEdit(groupBox_3);
        engineinfor->setObjectName(QString::fromUtf8("engineinfor"));

        gridLayout_4->addWidget(engineinfor, 2, 0, 1, 4);


        verticalLayout->addWidget(groupBox_3);

        toolBox->addItem(page, QString::fromUtf8("\345\274\225\346\223\216\344\277\241\346\201\257"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 862, 440));
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        ewplist = new QTableWidget(page_2);
        if (ewplist->columnCount() < 4)
            ewplist->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ewplist->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ewplist->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ewplist->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ewplist->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        ewplist->setObjectName(QString::fromUtf8("ewplist"));
        ewplist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ewplist->setAlternatingRowColors(true);
        ewplist->horizontalHeader()->setCascadingSectionResizes(true);

        gridLayout_5->addWidget(ewplist, 0, 0, 1, 5);

        ewpadd = new QPushButton(page_2);
        ewpadd->setObjectName(QString::fromUtf8("ewpadd"));

        gridLayout_5->addWidget(ewpadd, 1, 0, 1, 1);

        ewpedit = new QPushButton(page_2);
        ewpedit->setObjectName(QString::fromUtf8("ewpedit"));
        ewpedit->setEnabled(false);

        gridLayout_5->addWidget(ewpedit, 1, 1, 1, 1);

        ewpdel = new QPushButton(page_2);
        ewpdel->setObjectName(QString::fromUtf8("ewpdel"));
        ewpdel->setEnabled(false);

        gridLayout_5->addWidget(ewpdel, 1, 2, 1, 1);

        ewpup = new QPushButton(page_2);
        ewpup->setObjectName(QString::fromUtf8("ewpup"));
        ewpup->setEnabled(false);

        gridLayout_5->addWidget(ewpup, 1, 3, 1, 1);

        ewpdown = new QPushButton(page_2);
        ewpdown->setObjectName(QString::fromUtf8("ewpdown"));
        ewpdown->setEnabled(false);

        gridLayout_5->addWidget(ewpdown, 1, 4, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("\345\217\202\346\225\260\346\233\262\347\272\277"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_6 = new QGridLayout(page_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        enplist = new QTableWidget(page_3);
        if (enplist->columnCount() < 4)
            enplist->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        enplist->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        enplist->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        enplist->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        enplist->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        enplist->setObjectName(QString::fromUtf8("enplist"));
        enplist->setEnabled(true);
        enplist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        enplist->setAlternatingRowColors(true);
        enplist->horizontalHeader()->setCascadingSectionResizes(true);

        gridLayout_6->addWidget(enplist, 0, 0, 1, 5);

        enpadd = new QPushButton(page_3);
        enpadd->setObjectName(QString::fromUtf8("enpadd"));

        gridLayout_6->addWidget(enpadd, 1, 0, 1, 1);

        enpedit = new QPushButton(page_3);
        enpedit->setObjectName(QString::fromUtf8("enpedit"));
        enpedit->setEnabled(false);

        gridLayout_6->addWidget(enpedit, 1, 1, 1, 1);

        enpdel = new QPushButton(page_3);
        enpdel->setObjectName(QString::fromUtf8("enpdel"));
        enpdel->setEnabled(false);

        gridLayout_6->addWidget(enpdel, 1, 2, 1, 1);

        enpup = new QPushButton(page_3);
        enpup->setObjectName(QString::fromUtf8("enpup"));
        enpup->setEnabled(false);

        gridLayout_6->addWidget(enpup, 1, 3, 1, 1);

        enpdown = new QPushButton(page_3);
        enpdown->setObjectName(QString::fromUtf8("enpdown"));
        enpdown->setEnabled(false);

        gridLayout_6->addWidget(enpdown, 1, 4, 1, 1);

        toolBox->addItem(page_3, QString::fromUtf8("\351\237\263\347\254\246\345\217\202\346\225\260"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, toolBox);

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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        charactertable->setHorizontalHeaderItem(4, __qtablewidgetitem12);
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
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        translatetable->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        translatetable->setHorizontalHeaderItem(1, __qtablewidgetitem14);
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
        menubar->setGeometry(QRect(0, 0, 912, 26));
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
        label_2->setBuddy(enginename);
        label_4->setBuddy(enginemain);
        label_3->setBuddy(engineauthor);
        label_5->setBuddy(engineversion);
        label_6->setBuddy(engineinfor);
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

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


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
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\345\220\215\347\247\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\344\270\273\346\250\241\345\235\227", nullptr));
        enginemain->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\234\252\351\200\211\346\213\251", nullptr));
        loadenginemain->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\351\200\211\346\213\251", nullptr));
        enginename->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\274\225\346\223\216\345\220\215\347\247\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\345\233\276\346\240\207", nullptr));
        engineiconname->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\227\240\346\226\207\344\273\266", nullptr));
        openengineicon->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\350\275\275\345\205\245", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\351\231\204\345\212\240\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\344\275\234\350\200\205", nullptr));
        engineauthor->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\344\275\234\350\200\205", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\347\211\210\346\234\254", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\344\273\213\347\273\215", nullptr));
        engineinfor->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\227\240\344\273\213\347\273\215", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ewplist->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ewplist->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ewplist->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = ewplist->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\345\200\274", nullptr));
        ewpadd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        ewpedit->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        ewpdel->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        ewpup->setText(QCoreApplication::translate("MainWindow", "\344\270\212\347\247\273", nullptr));
        ewpdown->setText(QCoreApplication::translate("MainWindow", "\344\270\213\347\247\273", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\346\233\262\347\272\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = enplist->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = enplist->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = enplist->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = enplist->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\345\200\274", nullptr));
        enpadd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        enpedit->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        enpdel->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        enpup->setText(QCoreApplication::translate("MainWindow", "\344\270\212\347\247\273", nullptr));
        enpdown->setText(QCoreApplication::translate("MainWindow", "\344\270\213\347\247\273", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "\351\237\263\347\254\246\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(engine), QCoreApplication::translate("MainWindow", "\345\274\225\346\223\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(database), QCoreApplication::translate("MainWindow", "\345\243\260\345\272\223", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\205\270\345\220\215\347\247\260", nullptr));
        dicname->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\255\227\345\205\270\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = charactertable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = charactertable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "CP", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = charactertable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "PP", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = charactertable->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "VSP", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = charactertable->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "VEP", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = translatetable->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\345\255\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = translatetable->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\237\263", nullptr));
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
