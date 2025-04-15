#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "Etablissement.h"  // Inclure la classe Etablissement
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QQmlApplicationEngine>
#include <QQuickView>

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

    void updateTableView();  // Fonction pour mettre à jour le tableau

private slots:
    // Slots pour les boutons de navigation
    void on_examButton_clicked();
    void on_supButton_clicked();
    void on_eqButton_clicked();
    void on_FourButton_clicked();
    void on_candButton_clicked();
    void on_etaButton_clicked();
    void on_homeBtn_clicked();

    // Slots pour les actions CRUD
    void on_Ajbtn_clicked();  // Ajouter un établissement
    void on_BinSuperbtn_clicked();  // Supprimer un établissement
    void on_Modbtn_clicked();  // Modifier un établissement
    void on_SaveMod_clicked();  // Sauvegarder les modifications
    void on_newBtn_clicked();
    // Slots pour les notifications et autres fonctionnalités
    void on_notifBtn_clicked();
    void on_EvalAssist_clicked();
    void on_searchDirector_textChanged(const QString &text);
    void on_sortGovernorate_clicked();
    void on_exportPdfBtn_clicked();
    void on_statsButton_clicked();
    void on_mapsButton_clicked();
    void on_selectImageBtn_clicked();
    void on_tableView1_clicked(const QModelIndex &index);
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::MainWindow *ui;  // Interface utilisateur générée par Qt
    Etablissement E;  // Objet pour gérer les établissements
    QQuickView *mapView = nullptr;
    QSqlTableModel *model;  // Modèle pour afficher les données dans le tableau
    void afficherImage(const QString &cheminImage);
    // Variables pour stocker les données en cours de modification
    QString currentId;
    QString currentVille;
    QString currentType;
    QString currentDirecteur;
    QString currentNom;
    QString currentAdresse;

    QString selectedImagePath; // Chemin de l'image sélectionnée
    void showImageSelectionDialog(); // Méthode pour afficher la boîte de dialogue
    void displayImage(const QString &imagePath);
    int currentNbS;
    void setupGovernorateStats();
    int m_positionX = 0;
    QPixmap m_currentPixmap;
};

#endif // MAINWINDOW_H
