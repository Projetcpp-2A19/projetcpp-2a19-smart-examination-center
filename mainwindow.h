#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "Etablissement.h"  // Inclure la classe Etablissement
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include "fournisseurs.h"

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

         void verifierEtEnvoyerCode();

//crud etablissement

         void on_Ajteta_clicked();  // Ajouter un établissement
         void on_Binetabtn_clicked();  // Supprimer un établissement
         void on_Modeta_clicked();  // Modifier un établissement
         void on_Saveta_clicked();  // Sauvegarder les modifications
         void on_neweta_clicked();
         // Slots pour les notifications et autres fonctionnalités
         void on_searchDirector_textChanged(const QString &text);
         void on_sortGovernorate_clicked();
         void on_exportPdfBtn_clicked();
         void on_statsButton_clicked();
         void on_mapsButton_clicked();
         void on_selectImageBtn_clicked();
         void on_tableView_Eta_clicked(const QModelIndex &index);
         bool eventFilter(QObject *obj, QEvent *event) override;



 private:
    QSqlQueryModel *model;  // Modèle pour stocker les données des fournisseurs

//public:
  //void updateTableView();




private:
    Ui::MainWindow *ui;
    //modification
    bool modificationInProgress= false;
    // etablissement
    Etablissement E;  // Objet pour gérer les établissements
    QQuickView *mapView = nullptr;
    void afficherImage(const QString &cheminImage);
    // Variables pour stocker les données en cours de modification
    QString currentIdEta;
    QString currentGouvernoratEta;
    QString currentTypeEta;
    QString currentDirecteurEta;
    QString currentNomEta;
    QString currentVilleEta;
    QString currentAdresseEta;
    QString currentIdSuperviseurEta;
    QString currentIdEquipementEta;
    int currentNbSEta;
    // Métier , image panoramique
    QString selectedImagePath; // Chemin de l'image sélectionnée
    void showImageSelectionDialog(); // Méthode pour afficher la boîte de dialogue
    void displayImage(const QString &imagePath);
    void setupGovernorateStats();
    int m_positionX = 0;
    QPixmap m_currentPixmap;
    void updatetableView_Eta();

private :
    QString currentId;
    QString originalNom;
    int originalNumTel ;
    QString originalEmail;
    QString originalAdresse;
    QString originalTypeService;

};
#endif // MAINWINDOW_H
