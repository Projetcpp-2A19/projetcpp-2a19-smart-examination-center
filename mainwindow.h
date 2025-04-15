#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void afficherCandidats();
    void on_AjButton_5_clicked();
    void on_btnSupprimer_clicked();
    void on_ModButton_5_clicked();

    void on_lineCode_textChanged(const QString &arg1);
    void on_btnTrierNiveau_clicked();
    void on_btnRechercher_clicked();
    void on_btnStats_clicked();
    void on_btnpdf_clicked();
    void on_btnConvocation_clicked();
    bool genererConvocationPDF(const QString& codeCandidat);






private:
    Ui::MainWindow *ui;
    bool verifierSaisie(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel);
    QImage genererQRCodeImage(const QString& data, int pixelParModule = 4);




};

#endif // MAINWINDOW_H
