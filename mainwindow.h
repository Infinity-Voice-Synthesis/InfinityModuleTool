#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPainter>
#include <QDateTime>
#include "developerdialog.h"
#include <QMenu>
#include <QAction>
#include "chareditdialog.h"
#include "transeditdialog.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QMap>
#include <QDebug>
#include <QPixmap>
#include "version.h"
#include <QTableWidgetItem>
#include "ParamDialog.h"
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QJsonArray developer;
    QString Developername="No Developer Name";

    void getDeve();
    void devetrue();
    void setcharrow(int row, QString name, double CP = 0, double PP = 0, double VSP = 0.2, double VEP = 0.8);
    void settransrow(int row, QString name, QString phoneme);
    void setewprow(int row, QString name, double max, double min, double def);
    void setenprow(int row, QString name, double max, double min, double def);
    QMap<QString,QString> getTransFromCedict(QString data);
    QStringList getCharListfromTrans(QMap<QString, QString> trans);

    QMenu *charmenu,*transmenu;
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_actionDeveloper_triggered();
    void on_charactertable_customContextMenuRequested(const QPoint &pos);
    void on_translatetable_customContextMenuRequested(const QPoint &pos);
    void oncn();
    void once();
    void oncd();
    void ontn();
    void onte();
    void ontd();
    void on_actionNew_dic_triggered();
    void on_actionOpen_dic_triggered();
    void on_actionSave_dic_triggered();
    void on_actionFrom_cedict_triggered();
    void on_actionAutoC_triggered();
    void on_loadenginemain_clicked();
    void on_openengineicon_clicked();
    void on_ewplist_currentItemChanged(QTableWidgetItem* item1, QTableWidgetItem* item2);
    void on_ewpadd_clicked();
    void on_ewpedit_clicked();
    void on_ewpdel_clicked();
    void on_ewpup_clicked();
    void on_ewpdown_clicked();
    void on_enplist_currentItemChanged(QTableWidgetItem* item1, QTableWidgetItem* item2);
    void on_enpadd_clicked();
    void on_enpedit_clicked();
    void on_enpdel_clicked();
    void on_enpup_clicked();
    void on_enpdown_clicked();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
};
#endif // MAINWINDOW_H
