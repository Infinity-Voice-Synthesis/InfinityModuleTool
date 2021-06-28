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
};
#endif // MAINWINDOW_H
