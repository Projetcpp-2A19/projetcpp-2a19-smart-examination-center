#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include"Superviseur.h"
#include <QMainWindow>
#include <QWidget>  // For the popup widget
#include <QPushButton>  // For the button
#include <QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
/*private slots:
    void showNotifications(); */ // Déclare ton slot ici
private slots:

    void on_examButton_clicked();

    void on_supButton_clicked();

    void on_eqButton_clicked();

    void on_FourButton_clicked();

    void on_candButton_clicked();

    void on_etaButton_clicked();


    void on_homeBtn_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_AffButton_clicked();

    void on_AjButton_clicked();

    void on_ModButton_clicked();

    void on_AffButton_2_clicked();

    void on_AjButton_2_clicked();

    void on_ModButton_2_clicked();

    void on_SuppButton_2_clicked();

    void on_SuppButton_clicked();

    void on_AffButton_3_clicked();

    void on_AjButton_3_clicked();

    void on_ModButton_3_clicked();

    void on_SuppButton_3_clicked();

    void on_AffButton_4_clicked();

    void on_AjButton_4_clicked();

    void on_ModButton_4_clicked();

    void on_SuppButton_4_clicked();

    void on_notifBtn_clicked();



public :
    void updateTableView();
private:
    Superviseur Etmp;


    void on_EvalAssist_clicked();
private slots:
    void on_Ajbtn_clicked();

//Modification
private slots:
    void on_Modbtn_clicked() ;

   // void onTableViewClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Superviseur S;
    QSqlTableModel *model;
    void initialiserTableView();

};
#endif // MAINWINDOW_H
