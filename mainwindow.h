#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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

    void on_BinSuperbtn_clicked();//supp

    void on_Modbtn_clicked();//modifier

    void on_SaveMod_clicked();
    void actualiserTableView();





public :
    void updateTableView();
private:
    Superviseur Etmp;


    void on_EvalAssist_clicked();
private slots:
    void on_Ajbtn_clicked();




   // void onTableViewClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager; // Gestionnaire de requêtes HTTP
    Superviseur S;
    QSqlTableModel *model;


//Modifier
    bool modificationInProgress = false; // Track if modification has started
    // Fonction pour gérer les messages du chatbot
    void appendMessage(const QString &message, bool isUser);
    QString generateBotResponse(const QString &userMessage);
private:
    QString currentId;
    int originalCin;
    QString originalStatut;
    QString originalPoste;
    QString originalPrenom;
    QString originalNom;
    QString originalTel;
    QString originalEmail;
    QString originalZone;


private slots:
    void rechercherSuperviseur(); // Fonction de recherche
private slots:
    void onTriButtonClicked(); // Méthode appelée lors du clic sur le bouton
    void resetTableView(); // Fonction pour réinitialiser tableView1
    void showStatistiques();
    void on_pdfSuperbtn_clicked();//pdf
    void envoyerRappelExamenSuperviseur(); //sms
    void on_btnEnvoyerSMS_clicked(); //sms
private slots:
    void handleChatCommand();
    void processAddCommand(const QStringList &parts);
    void processDeleteCommand(const QStringList &parts);
    void processUpdateCommand(const QStringList &parts);
    void showHelp();
    void refreshTableView();

private:
    void addToChat(const QString &message, bool isUser = false);



};
#endif // MAINWINDOW_H
