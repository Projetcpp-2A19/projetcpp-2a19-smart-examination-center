#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD
#include <QLabel>
#include"Superviseur.h"
#include <QMainWindow>
#include <QWidget>  // For the popup widget
#include <QPushButton>  // For the button
#include <QSqlTableModel>
#include <QSignalBlocker>
#include <QtCharts>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QNetworkAccessManager>  // Ajout pour les requêtes HTTP
#include <QNetworkReply>          // Pour gérer les réponses des requêtes
#include "arduino.h"
#include "speechtotext.h"
#include <QLineEdit>
#include "examen.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
#include <QSortFilterProxyModel>
#include "examenfilterproxymodel.h"
#include <QMap>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>
=======

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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0

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
<<<<<<< HEAD
=======
    void on_examBtn_clicked();

    void on_supBtn_clicked();

    void on_eqBtn_clicked();

    void on_fourBtn_clicked();

    void on_candBtn_clicked();

    void on_etaBtn_clicked();
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0

    void on_examButton_clicked();

    void on_supButton_clicked();

    void on_eqButton_clicked();

    void on_FourButton_clicked();

    void on_candButton_clicked();

    void on_etaButton_clicked();

<<<<<<< HEAD
    void on_homeBtn_clicked();

    void on_StatButton_clicked();

    void on_BinSuperbtn_clicked();//supp

    void on_Modbtn_clicked();//modifier

    void on_SaveMod_clicked();
    void actualiserTableView();
    void on_Ajbtn_clicked();
    void rechercherSuperviseur(); // Fonction de recherche
    void onTriButtonClicked(); // Méthode appelée lors du clic sur le bouton
    void resetTableView(); // Fonction pour réinitialiser tableView1
    void showStatistiques();
    void on_pdfSuperbtn_clicked();//pdf
    void envoyerRappelExamenSuperviseur(); //sms
    void on_btnEnvoyerSMS_clicked(); //sms
    void handleChatCommand();
    void processAddCommand(const QStringList &parts);
    void processDeleteCommand(const QStringList &parts);
    void processUpdateCommand(const QStringList &parts);
    void showHelp();
    void refreshTableView();
    void processPreUpdateCommand(const QStringList &parts); // Pré-remplissage des champs à modifier
    //void processFlexibleUpdateCommand(const QStringList &parts); // mise à jour avec id=... nom=...
    void processFlexibleUpdateCommand(const QStringList &parts);
    void updateSerialData(); // slot déclenché quand des données arrivent


    // Exam-related buttons
    void on_AjExamButton_clicked();  // Add exam
    void on_ModExamButton_clicked(); // Modify exam
    void onSerialData();      // slot to read incoming data

    void on_AddExamConfirm_3_clicked(); // Confirm adding exam
    void onExamSelected(const QModelIndex &index); // Updated slot signature
    void on_pushButton_2_clicked();
    void onViewPdfButtonClicked();
    void handleInsertExamPdf();
    void handleSuppExam();
    void handleModifExamConfirm();
    //speech to text
    /*void onMatiereSpeechClicked();
    void onNiveauSpeechClicked();
    void onDureeSpeechClicked();
    */
    void onMatiereSpeechClicked();
    void onNiveauSpeechClicked();
    void onDureeSpeechClicked();

    void onSpeechTextRecognized(const QString &text);
    void on_pdfExambtn_clicked();  // slot pour le bouton PDF
    //void showExamStatistics();
    void on_examButton_2_clicked();
    //void showChart(const QMap<QString, int>& statusCounts);
    void clearChartWidget();
    void loadExamStatistics();
    void on_supButton_2_clicked();
    void showChartInPage(const QMap<QString, int>& statusCounts);
    QMap<QString, int> getExamStatusCounts();


    void on_listexamensbutton_clicked();

    void on_statButton_clicked();

public :
    void updateTableView();
=======

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


>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0


private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
    QNetworkAccessManager *networkManager; // Gestionnaire de requêtes HTTP
    Superviseur S;
    QSqlTableModel *model;

    bool modificationInProgress = false; // Track if modification has started
    // Fonction pour gérer les messages du chatbot
    void appendMessage(const QString &message, bool isUser);
    QString generateBotResponse(const QString &userMessage);
    QString currentId;
    int originalCin;
    QString originalStatut;
    QString originalPoste;
    QString originalPrenom;
    QString originalNom;
    QString originalTel;
    QString originalEmail;
    QString originalZone;
    Superviseur Etmp;
    void on_EvalAssist_clicked();
    void addToChat(const QString &message, bool isUser = false);
    Arduino A; // objet arduino
    QString uid;
    QString serialBuffer;
    void verifierStatutSuperviseur(const QString& uid);
    Examen examen;
    QSerialPort *serial;
    QByteArray buffer;
    QString codeBuffer;       // holds up to 10 digits
    QSqlDatabase db;          // database connection
    const int CODE_LENGTH = 10;
    QByteArray pdfData;              // To store the PDF file data
    QString selectedExamId;
    void refreshExamenTable();       // Refresh the exam table
    void clearForm();                // Clear the exam form
    SpeechToText *speechToText;
    QLineEdit *currentLineEdit; // To track which field to populate
    ExamenFilterProxyModel *m_proxyModel = nullptr;
    QSqlQueryModel *m_examenDisplayModel = nullptr;

=======
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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0

};
#endif // MAINWINDOW_H
