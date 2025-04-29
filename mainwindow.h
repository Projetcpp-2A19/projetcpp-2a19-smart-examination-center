#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QtCharts>

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

private slots:
    void on_examBtn_clicked();

    void on_supBtn_clicked();

    void on_eqBtn_clicked();

    void on_fourBtn_clicked();

    void on_candBtn_clicked();

    void on_etaBtn_clicked();

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

    void actualiserTableView();
    void handleAddFournisseur();
    void handleDeleteFournisseur();
    void updateTableView();
    void showStatistiques();
//modification
    void on_ModButton_clicked();
    void on_SaveMod_clicked();

    void on_rechBtn_clicked();


    void on_emailBtn_clicked();

    void on_EnvBtn_clicked();

    void on_btnAfficherTout_clicked();


    void on_btnTrierNom_clicked();

    void on_pdfBtn_clicked();

    void on_statButton_clicked();

    void on_chatbotBtn_clicked();
     void on_sendChatBtn_clicked();

    void on_historiqueBtn_clicked();

     void on_label_25_linkActivated(const QString &link);
         void verifierEtEnvoyerCode();

 private:
    QSqlQueryModel *model;  // Modèle pour stocker les données des fournisseurs

//public:
  //void updateTableView();




private:
    Ui::MainWindow *ui;
    //modification
    bool modificationInProgress= false;
private :
    QString currentId;
    QString originalNom;
    int originalNumTel ;
    QString originalEmail;
    QString originalAdresse;
    QString originalTypeService;

};
#endif // MAINWINDOW_H
