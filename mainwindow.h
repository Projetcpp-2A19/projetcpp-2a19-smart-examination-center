#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "candidat.h"
#include <QMessageBox>

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
    void on_AffButton_5_clicked();  // Afficher les candidats
    void on_AjButton_5_clicked();   // Ajouter un candidat
    void on_ModButton_5_clicked();  // Modifier un candidat
    void on_SuppButton_5_clicked(); // Supprimer un candidat

private:
    Ui::MainWindow *ui;
    Candidat candidat;  // Instance de la classe Candidat
};

#endif // MAINWINDOW_H
