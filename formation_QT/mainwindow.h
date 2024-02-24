#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>


#include "my_class.h"
#include "add_class.h"
#include "smtp.h"
#include "exportexcelobject.h"
#include "stat_combo.h"
#include "camera.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    my_class tmp;
    QSortFilterProxyModel *proxy;

    void show_tables();


private slots:
    void on_actionadd_triggered();

    void on_actiondelete_triggered();

    void on_recherche_textChanged(const QString &arg1);

    void on_tableau_doubleClicked();

    void on_tableau_clicked(const QModelIndex &index);

    void sendMail();
    void mailSent(QString);
    void browse();

    void on_actionplay_video_triggered();

    void on_actionstop_video_triggered();

    void on_export_excel_clicked();

    void on_stat_clicked();

    void on_pdf_clicked();

    void on_camera_clicked();

private:
    QMediaPlayer* player;
    QVideoWidget* vw;
    Ui::MainWindow *ui;
    int selected=0;
    QStringList files;
    stat_combo *s;
    camera *c;
};
#endif // MAINWINDOW_H
