#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include "arduino.h"
#include "ui_mainwindow.h"
#include "gcandidat.h"

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


public slots:
    void on_BinSuperbtn_clicked();
    void afficherEquipements();
    void on_Modbtn_clicked();
    /*void modifierEquipement();*/
    /*void supprimerEquipement();*/
    void on_candBtn_clicked();




private slots:
    /*void showNotifications();  // Déclare ton slot ici*/
private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_examBtn_clicked();

    void on_supBtn_clicked();

    void on_eqBtn_clicked();

    void on_fourBtn_clicked();


    void on_etaBtn_clicked();

    void on_examButton_clicked();

    void on_supButton_clicked();

    void on_eqButton_clicked();

    void on_FourButton_clicked();



    void on_etaButton_clicked();


    void on_homeBtn_clicked();


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


    void genererRapportPDF();
    void on_pdfSuperbtn_clicked();
    void afficherStatistiquesEquipements();
    void rechercheVocale();
    void on_btnRechercheVocale_clicked();

/*protected:
    void mousePressEvent(QMouseEvent *event) override; // Détecter le clic en dehors*/
/*public slots:
    void on_linkActivated(const QString &link);
 // Add this line

*/







    void on_EvalAssist_clicked();

   //void on_Modbtn_clicked();

    void on_Ajbtn_clicked();

private slots:
    void on_Modbtn_2_clicked();
    void readSerialData();

    void on_candButton_clicked();

private :
    QByteArray data;
    Arduino A;


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
