#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "speechtotext.h"
#include <QLineEdit>
#include <QMainWindow>
#include "examen.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
#include <QSortFilterProxyModel>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Navigation buttons
    void on_examButton_clicked();
    void on_supButton_clicked();
    void on_eqButton_clicked();
    void on_FourButton_clicked();
    void on_candButton_clicked();
    void on_etaButton_clicked();
    void on_homeBtn_clicked();

    // Exam-related buttons
    void on_AjExamButton_clicked();  // Add exam
    void on_ModExamButton_clicked(); // Modify exam
    void on_statButton_clicked();    // Statistics

    void on_AddExamConfirm_3_clicked(); // Confirm adding exam
    void onExamSelected(const QModelIndex &index); // Updated slot signature
    void on_pushButton_2_clicked();
    void onViewPdfButtonClicked();
    void handleInsertExamPdf();
    void handleSuppExam();
    void handleModifExamConfirm();
    //speech to text
    void onMatiereSpeechClicked();
    void onNiveauSpeechClicked();
    void onDureeSpeechClicked();
    void onSpeechTextRecognized(const QString &text);
    void filterExams(const QString &searchText);
    void filtrerParDate(const QDate &date);

private:
    Ui::MainWindow *ui;
    Examen examen;                   // Examen object for CRUD operations
    QByteArray pdfData;              // To store the PDF file data
    QString selectedExamId;
    void refreshExamenTable();       // Refresh the exam table
    void clearForm();                // Clear the exam form
    SpeechToText *speechToText;
    QLineEdit *currentLineEdit; // To track which field to populate
    QSortFilterProxyModel *proxyModel;
    QSqlQueryModel *yourExamModel;

};
#endif // MAINWINDOW_H
