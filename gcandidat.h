#ifndef GCANDIDAT_H
#define GCANDIDAT_H

#include <QMainWindow>
#include "arduino.h"
#include "ui_gcandidat.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class gcandidat;
}
QT_END_NAMESPACE

class gcandidat : public QMainWindow
{
    Q_OBJECT

public:
    gcandidat(QWidget *parent = nullptr);
    ~gcandidat();

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
    void on_btnAfficherConvocation_clicked();


private slots:
    void readSerialData();

private :
    QByteArray data;
    Arduino A;






private:
    Ui::gcandidat *ui;
    bool verifierSaisie(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel);
    QImage genererQRCodeImage(const QString& data, int pixelParModule = 4);




};

#endif // GCANDIDAT_H
