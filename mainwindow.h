#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include"Superviseur.h"
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QSqlTableModel>
#include <QSignalBlocker>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QNetworkAccessManager>
#include <QNetworkReply>
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
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "Etablissement.h"
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

    void on_examButton_clicked();
    void on_supButton_clicked();
    void on_eqButton_clicked();
    void on_FourButton_clicked();
    void on_candButton_clicked();
    void on_etaButton_clicked();
    void on_homeBtn_clicked();
    //void on_StatButton_clicked();
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
    void on_AjExamButton_clicked();  // Add exam
    void on_ModExamButton_clicked(); // Modify exam
    //void onSerialData();      // slot to read incoming data
    void on_AddExamConfirm_3_clicked(); // Confirm adding exam
    void onExamSelected(const QModelIndex &index); // Updated slot signature
    void onViewPdfButtonClicked();
    void handleInsertExamPdf();
    void handleSuppExam();
    void handleModifExamConfirm();
    void onMatiereSpeechClicked();
    void onNiveauSpeechClicked();
    void onDureeSpeechClicked();
    void onSpeechTextRecognized(const QString &text);
    void on_pdfExambtn_clicked();  // slot pour le bouton PDF
    void on_examButton_2_clicked();
    void clearChartWidget();
    void loadExamStatistics();
    void on_supButton_2_clicked();
    void showChartInPage(const QMap<QString, int>& statusCounts);
    QMap<QString, int> getExamStatusCounts();
    void on_listexamensbutton_clicked();
    void on_statButton_clicked();
    void actualiserTableView_Fourn();
    void handleDeleteFournisseur();
    void updateTableView_Fourn();
    void showStatistiques_Fourn(const QString& critere);
    void on_ModButton_clicked();
    void on_SaveMod_2_clicked();
    void on_rechBtn_5_clicked();
    void on_EnvBtn_clicked();
    void on_btnAfficherTout_clicked();
    void on_btnTrierNom_clicked();
    void on_pdfBtn_4_clicked();
    //void verifierEtEnvoyerCode();
    void on_Ajteta_3_clicked();
    void on_Binetabtn_clicked();
    void on_Modeta_clicked();
    void on_Saveta_3_clicked();
    void on_neweta_clicked();
    void on_searchDirector_2_textChanged(const QString &text);
    void on_sortGovernorateBtn_clicked();
    void on_exportPdfBtn_2_clicked();
    void on_mapsButton_clicked();
    void on_selectImageBtn_3_clicked();
    void on_tableView_Eta_clicked(const QModelIndex &index);
    bool eventFilter(QObject *obj, QEvent *event) override;
    void on_etaButton_2_clicked();

    void on_eqButton_2_clicked();

    void on_FourButton_2_clicked();

    void on_candButton_2_clicked();

    void on_Ajbtn_2_clicked();

    void on_ReMod_2_clicked();

    void on_statTypeServ_clicked();

    void on_statAdresse_clicked();

    void afficherCandidats();
    void on_AjButton_5_clicked();
    void on_btnSupprimer_clicked();
    void on_ModButton_5_clicked();
    void on_lineCode_textChanged(const QString &arg1);
    void on_btnTrierNiveau_clicked();
    void on_btnRechercher_clicked();
    void on_btnpdf_clicked();
    bool genererConvocationPDF(const QString& codeCandidat);
    void readSerialData();

    void on_btnConvocation_clicked();



//Akrem
    void on_BinSuperbtn_2_clicked();
    void afficherEquipements();
    void on_ModifEquip_clicked();

    void genererRapportPDF();
    void on_pdfSuperbtn_2_clicked();
    void afficherStatistiquesEquipements();
    void rechercheVocale();
    void on_btnRechercheVocale_2_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_22_clicked();
    void on_Ajbtn_4_clicked();
    void on_Modbtn_3_clicked();
    //void readSerialDataEquip();
    void handleArduinoConnection(int ret, Arduino* arduino, const char* slot);
    void handleArduinoCandidateVerification();

    void on_ArduinoCandid_clicked();
    //void onSerialData();
    //void verifyCandidate(const QString &code);

public :
    void updateTableView();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager; // Gestionnaire de requêtes HTTP
    Superviseur S;
    QSqlTableModel *model;
    QSqlQueryModel *model_Fourn;  // Modèle pour stocker les données des fournisseurs
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
    //modification
    bool modificationInProgressFourn= false;
    // etablissement
    Etablissement E;  // Objet pour gérer les établissements
    QQuickView *mapView = nullptr;
    void afficherImage(const QString &cheminImage);
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
    QString selectedImagePath; // Chemin de l'image sélectionnée
    void showImageSelectionDialog(); // Méthode pour afficher la boîte de dialogue
    void displayImage(const QString &imagePath);
    void setupGovernorateStats();
    int m_positionX = 0;
    QPixmap m_currentPixmap;
    void updatetableView_Eta();
    QString currentIdFourn;//currentId
    QString originalNomFourn;//originalNom
    int originalNumTelFourn ;//originalNumTel
    QString originalEmailFourn;//originalEmail
    QString originalAdresseFourn;//originalAdresse
    QString originalTypeServiceFourn;//originalTypeService
    QByteArray data;
    bool verifierSaisie(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel);
    QImage genererQRCodeImage(const QString &contenu, int pixelParModule);

    Arduino A;
    Arduino A2;
    Arduino arduino;

};
#endif // MAINWINDOW_H
