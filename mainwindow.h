#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "Etablissement.h"  // Inclure la classe Etablissement

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

    // Slots pour les notifications et autres fonctionnalités
    void on_notifBtn_clicked();
    void on_EvalAssist_clicked();

private:
    Ui::MainWindow *ui;  // Interface utilisateur générée par Qt
    Etablissement E;  // Objet pour gérer les établissements
    QSqlTableModel *model;  // Modèle pour afficher les données dans le tableau

    // Variables pour stocker les données en cours de modification
    QString currentId;
    QString currentVille;
    QString currentType;
    QString currentDirecteur;
    QString currentNom;
    int currentNbS;
};

#endif // MAINWINDOW_H
