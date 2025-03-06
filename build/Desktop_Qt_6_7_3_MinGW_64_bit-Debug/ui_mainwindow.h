/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *fullMenu;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *supButton;
    QPushButton *eqButton;
    QPushButton *FourButton;
    QPushButton *candButton;
    QPushButton *etaButton;
    QPushButton *examButton;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_4;
    QPushButton *statButton;
    QLabel *label_10;
    QTableWidget *TableExams;
    QWidget *Menu;
    QStackedWidget *stackedWidget;
    QWidget *HOME;
    QWidget *GestExam;
    QPushButton *pdfExambtn;
    QPushButton *ModExamButton;
    QPushButton *SuppExamButton;
    QPushButton *AjExamButton;
    QLabel *Trilabel4;
    QFrame *AddExamFrame_3;
    QLineEdit *lineEdit_16;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLineEdit *lineEdit_18;
    QLabel *label_39;
    QLabel *label_40;
    QLineEdit *lineEdit_20;
    QLabel *label_41;
    QPushButton *InsertExamPdf_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QComboBox *TypeExamenChoix;
    QComboBox *StatutExamenChoix;
    QDateEdit *dateExamenChoix;
    QDateEdit *filterExam;
    QPushButton *RechExam;
    QLineEdit *lineEdit_2;
    QStackedWidget *stackedWidget_2;
    QWidget *AddExamLabel;
    QLabel *addExamText;
    QPushButton *AddExamConfirm_3;
    QWidget *ModifExamLabel;
    QLabel *modifExamText;
    QPushButton *ModifExamConfirm;
    QWidget *page;
    QLabel *label_28;
    QTableView *ListeExamensTab;
    QPushButton *pushButton_2;
    QWidget *GestSup;
    QLabel *label_11;
    QWidget *GestEquip;
    QLabel *label_14;
    QWidget *GestFourn;
    QLabel *label_12;
    QWidget *GestCand;
    QLabel *label_15;
    QWidget *GestEtab;
    QLabel *label_16;
    QWidget *GestStats;
    QLabel *label_29;
    QPushButton *closeBtn;
    QPushButton *notifBtn;
    QPushButton *emailBtn;
    QPushButton *paramBtn;
    QPushButton *homeBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1325, 840);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #D9E6F2; /* Bleu pastel plus visible */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        fullMenu = new QWidget(centralwidget);
        fullMenu->setObjectName("fullMenu");
        fullMenu->setGeometry(QRect(3, 0, 161, 831));
        label_2 = new QLabel(fullMenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(2, 6, 71, 61));
        label_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/logo.png")));
        label_3 = new QLabel(fullMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(59, 22, 91, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 18px;\n"
"    font-weight: bold;"));
        supButton = new QPushButton(fullMenu);
        supButton->setObjectName("supButton");
        supButton->setGeometry(QRect(0, 240, 151, 41));
        supButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        supButton->setStyleSheet(QString::fromUtf8("QPushButton#supButton {\n"
"	image: url(:/new/prefix1/img/rechercher-des-personnes.png);\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#supButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#supButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/rechercher-des-personnes.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supButton->setIcon(icon);
        supButton->setIconSize(QSize(22, 22));
        supButton->setCheckable(true);
        supButton->setAutoExclusive(true);
        eqButton = new QPushButton(fullMenu);
        eqButton->setObjectName("eqButton");
        eqButton->setGeometry(QRect(0, 328, 151, 41));
        eqButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        eqButton->setStyleSheet(QString::fromUtf8("QPushButton#eqButton {\n"
"	image: url(:/new/prefix1/img/equipe.png);\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#eqButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#eqButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/equipe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eqButton->setIcon(icon1);
        eqButton->setIconSize(QSize(23, 22));
        eqButton->setCheckable(true);
        eqButton->setAutoExclusive(true);
        FourButton = new QPushButton(fullMenu);
        FourButton->setObjectName("FourButton");
        FourButton->setGeometry(QRect(0, 410, 151, 41));
        FourButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        FourButton->setStyleSheet(QString::fromUtf8("QPushButton#FourButton {\n"
"	image: url(:/new/prefix1/img/livreur.png);\n"
"	\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#FourButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#FourButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/livreur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        FourButton->setIcon(icon2);
        FourButton->setIconSize(QSize(22, 22));
        FourButton->setCheckable(true);
        FourButton->setAutoExclusive(true);
        candButton = new QPushButton(fullMenu);
        candButton->setObjectName("candButton");
        candButton->setGeometry(QRect(0, 499, 151, 41));
        candButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        candButton->setStyleSheet(QString::fromUtf8("QPushButton#candButton {\n"
"	\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#candButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#candButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/candidat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        candButton->setIcon(icon3);
        candButton->setIconSize(QSize(22, 22));
        candButton->setCheckable(true);
        candButton->setAutoExclusive(true);
        etaButton = new QPushButton(fullMenu);
        etaButton->setObjectName("etaButton");
        etaButton->setGeometry(QRect(0, 583, 151, 41));
        etaButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        etaButton->setStyleSheet(QString::fromUtf8("QPushButton#etaButton {\n"
"	image: url(:/new/prefix1/img/batiment-educatif.png);\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#etaButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#etaButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/batiment-educatif.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        etaButton->setIcon(icon4);
        etaButton->setIconSize(QSize(22, 22));
        etaButton->setCheckable(true);
        etaButton->setAutoExclusive(true);
        examButton = new QPushButton(fullMenu);
        examButton->setObjectName("examButton");
        examButton->setGeometry(QRect(0, 150, 151, 41));
        examButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        examButton->setStyleSheet(QString::fromUtf8("QPushButton#examButton {\n"
"    image: url(:/new/prefix1/img/examen.png);\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#examButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#examButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/examen.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        examButton->setIcon(icon5);
        examButton->setIconSize(QSize(22, 22));
        examButton->setCheckable(true);
        examButton->setAutoExclusive(true);
        label_5 = new QLabel(fullMenu);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 250, 91, 20));
        label_5->setStyleSheet(QString::fromUtf8(" color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));
        label_6 = new QLabel(fullMenu);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 338, 91, 20));
        label_6->setStyleSheet(QString::fromUtf8(" color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));
        label_7 = new QLabel(fullMenu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 420, 91, 20));
        label_7->setStyleSheet(QString::fromUtf8(" color: black;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_8 = new QLabel(fullMenu);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 509, 71, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_9 = new QLabel(fullMenu);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 593, 91, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_4 = new QLabel(fullMenu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 160, 71, 20));
        label_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"\n"
""));
        statButton = new QPushButton(fullMenu);
        statButton->setObjectName("statButton");
        statButton->setGeometry(QRect(0, 670, 151, 41));
        statButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statButton->setStyleSheet(QString::fromUtf8("QPushButton#statButton {\n"
"	image: url(:/new/prefix1/img/batiment-educatif.png);\n"
"    background-color: #4A90E2;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#statButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#statButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/stat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        statButton->setIcon(icon6);
        statButton->setIconSize(QSize(22, 22));
        statButton->setCheckable(true);
        statButton->setAutoExclusive(true);
        label_10 = new QLabel(fullMenu);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 680, 91, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        TableExams = new QTableWidget(fullMenu);
        if (TableExams->columnCount() < 8)
            TableExams->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        TableExams->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        TableExams->setObjectName("TableExams");
        TableExams->setGeometry(QRect(-10, 810, 61, 31));
        TableExams->setStyleSheet(QString::fromUtf8("#TableExams {\n"
"    border: 2px solid #A0B9D9; /* Bordure bleue */\n"
"    border-radius: 7px; /* Coins arrondis */\n"
"    background-color: #F0F4F8; /* Fond l\303\251g\303\250rement gris-bleu */\n"
"    gridline-color: rgb(61, 61, 61); /* Couleur des lignes du tableau */\n"
"    selection-background-color: #4A90E2; /* Couleur de s\303\251lection */\n"
"    selection-color: white; /* Texte blanc lors de la s\303\251lection */\n"
"}\n"
"\n"
"#TableExams::item {\n"
"    padding: 8px; /* Espacement entre le texte et la cellule */\n"
"    color: #2C3E50; /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"#TableExams::item:selected {\n"
"    background-color: #4A90E2; /* Fond bleu lors de la s\303\251lection */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"#TableExams QHeaderView::section {\n"
"    background-color: #A0B9D9; /* En-t\303\252te avec une teinte bleu-gris */\n"
"    color: #2C3E50; /* Texte des en-t\303\252tes en bleu fonc\303\251 */\n"
"    padding: 6px;\n"
"    border: 1px solid rgb(61, 61, 61)"
                        "; /* Bordure des en-t\303\252tes */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#TableExams QTableCornerButton::section {\n"
"    background-color: rgb(61, 61, 61); /* Coin sup\303\251rieur gauche */\n"
"    border: 1px solid #4A90E2;\n"
"}\n"
""));
        TableExams->horizontalHeader()->setVisible(true);
        examButton->raise();
        etaButton->raise();
        candButton->raise();
        eqButton->raise();
        label_2->raise();
        label_3->raise();
        supButton->raise();
        FourButton->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_4->raise();
        statButton->raise();
        label_10->raise();
        TableExams->raise();
        Menu = new QWidget(centralwidget);
        Menu->setObjectName("Menu");
        Menu->setGeometry(QRect(161, 70, 1161, 761));
        stackedWidget = new QStackedWidget(Menu);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1161, 771));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));
        HOME = new QWidget();
        HOME->setObjectName("HOME");
        HOME->setStyleSheet(QString::fromUtf8("color: rgb(215, 255, 246);"));
        stackedWidget->addWidget(HOME);
        GestExam = new QWidget();
        GestExam->setObjectName("GestExam");
        pdfExambtn = new QPushButton(GestExam);
        pdfExambtn->setObjectName("pdfExambtn");
        pdfExambtn->setGeometry(QRect(20, 640, 321, 51));
        pdfExambtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pdfExambtn->setStyleSheet(QString::fromUtf8("QPushButton#pdfExambtn {\n"
"    background-color: #3A7BD5; \n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    border: 2px dashed #3A7BD5;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#pdfExambtn:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#pdfExambtn:pressed {\n"
"    background-color: #C74C4C; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPrintPreview));
        pdfExambtn->setIcon(icon7);
        pdfExambtn->setIconSize(QSize(20, 20));
        pdfExambtn->setCheckable(true);
        pdfExambtn->setAutoExclusive(true);
        ModExamButton = new QPushButton(GestExam);
        ModExamButton->setObjectName("ModExamButton");
        ModExamButton->setGeometry(QRect(100, 570, 51, 41));
        QFont font;
        font.setBold(true);
        ModExamButton->setFont(font);
        ModExamButton->setStyleSheet(QString::fromUtf8("QPushButton#ModExamButton  {\n"
"    background-color: #3A7BD5; /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#ModExamButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#ModExamButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}"));
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        ModExamButton->setIcon(icon8);
        SuppExamButton = new QPushButton(GestExam);
        SuppExamButton->setObjectName("SuppExamButton");
        SuppExamButton->setGeometry(QRect(40, 570, 51, 41));
        SuppExamButton->setFont(font);
        SuppExamButton->setStyleSheet(QString::fromUtf8("QPushButton#SuppExamButton  {\n"
"    background-color: #D64545; /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#SuppExamButton:hover {\n"
"    background-color: #E06666; /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#SuppExamButton:pressed {\n"
"    background-color: #B83232; /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}"));
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        SuppExamButton->setIcon(icon9);
        AjExamButton = new QPushButton(GestExam);
        AjExamButton->setObjectName("AjExamButton");
        AjExamButton->setGeometry(QRect(160, 570, 51, 41));
        AjExamButton->setFont(font);
        AjExamButton->setStyleSheet(QString::fromUtf8("QPushButton#AjExamButton  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#AjExamButton:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#AjExamButton :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        AjExamButton->setIcon(icon10);
        Trilabel4 = new QLabel(GestExam);
        Trilabel4->setObjectName("Trilabel4");
        Trilabel4->setGeometry(QRect(290, 90, 131, 41));
        Trilabel4->setStyleSheet(QString::fromUtf8("#Trilabel4 { \n"
"    font-size: 15px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"  \n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        AddExamFrame_3 = new QFrame(GestExam);
        AddExamFrame_3->setObjectName("AddExamFrame_3");
        AddExamFrame_3->setGeometry(QRect(570, 160, 571, 491));
        AddExamFrame_3->setStyleSheet(QString::fromUtf8("    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px; /* Coins l\303\251g\303\250rement arrondis */"));
        AddExamFrame_3->setFrameShape(QFrame::Shape::StyledPanel);
        AddExamFrame_3->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_16 = new QLineEdit(AddExamFrame_3);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(50, 60, 161, 41));
        lineEdit_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
""));
        label_36 = new QLabel(AddExamFrame_3);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(50, 29, 81, 31));
        label_36->setStyleSheet(QString::fromUtf8("    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\";\n"
"border:none;"));
        label_37 = new QLabel(AddExamFrame_3);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(50, 140, 81, 31));
        label_37->setStyleSheet(QString::fromUtf8("border:none;    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\";\n"
""));
        label_38 = new QLabel(AddExamFrame_3);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(48, 259, 81, 31));
        label_38->setStyleSheet(QString::fromUtf8("border:none;\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\";\n"
""));
        lineEdit_18 = new QLineEdit(AddExamFrame_3);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(370, 170, 161, 41));
        lineEdit_18->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
""));
        label_39 = new QLabel(AddExamFrame_3);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(370, 29, 81, 31));
        label_39->setStyleSheet(QString::fromUtf8("border:none;\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\";\n"
""));
        label_40 = new QLabel(AddExamFrame_3);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(370, 139, 81, 31));
        label_40->setStyleSheet(QString::fromUtf8("border:none;    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\";\n"
""));
        lineEdit_20 = new QLineEdit(AddExamFrame_3);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(370, 290, 161, 41));
        lineEdit_20->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
""));
        label_41 = new QLabel(AddExamFrame_3);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(370, 259, 81, 31));
        label_41->setStyleSheet(QString::fromUtf8("border:none;\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\";\n"
""));
        InsertExamPdf_3 = new QPushButton(AddExamFrame_3);
        InsertExamPdf_3->setObjectName("InsertExamPdf_3");
        InsertExamPdf_3->setGeometry(QRect(180, 370, 251, 61));
        InsertExamPdf_3->setStyleSheet(QString::fromUtf8("QPushButton#InsertExamPdf_3{\n"
"color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"font: 10pt \"Segoe UI\"; \n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px dashed #A0B9D9;\n"
"}\n"
"\n"
"\n"
"QPushButton#InsertExamPdf_3:hover {\n"
"    background-color: #E3ECF8; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"\n"
"QPushButton#InsertExamPdf_3:pressed {\n"
"    background-color: #A0B9D9; /* Bleu-gris pastel */\n"
"    border-color: #2C3E50; /* Bleu fonc\303\251 */\n"
"    color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}"));
        QIcon icon11(QIcon::fromTheme(QString::fromUtf8("document-print-preview")));
        InsertExamPdf_3->setIcon(icon11);
        pushButton = new QPushButton(AddExamFrame_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 65, 31, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/mic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon12);
        pushButton->setIconSize(QSize(28, 30));
        pushButton_4 = new QPushButton(AddExamFrame_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(532, 296, 31, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("border:none;"));
        pushButton_4->setIcon(icon12);
        pushButton_4->setIconSize(QSize(28, 30));
        pushButton_5 = new QPushButton(AddExamFrame_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(533, 175, 31, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("border:none;"));
        pushButton_5->setIcon(icon12);
        pushButton_5->setIconSize(QSize(28, 30));
        pushButton_6 = new QPushButton(AddExamFrame_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(532, 63, 31, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("border:none;"));
        pushButton_6->setIcon(icon12);
        pushButton_6->setIconSize(QSize(28, 30));
        TypeExamenChoix = new QComboBox(AddExamFrame_3);
        TypeExamenChoix->addItem(QString());
        TypeExamenChoix->addItem(QString());
        TypeExamenChoix->addItem(QString());
        TypeExamenChoix->setObjectName("TypeExamenChoix");
        TypeExamenChoix->setGeometry(QRect(50, 170, 161, 41));
        TypeExamenChoix->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */"));
        StatutExamenChoix = new QComboBox(AddExamFrame_3);
        StatutExamenChoix->addItem(QString());
        StatutExamenChoix->addItem(QString());
        StatutExamenChoix->addItem(QString());
        StatutExamenChoix->addItem(QString());
        StatutExamenChoix->setObjectName("StatutExamenChoix");
        StatutExamenChoix->setGeometry(QRect(48, 290, 161, 41));
        StatutExamenChoix->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
""));
        dateExamenChoix = new QDateEdit(AddExamFrame_3);
        dateExamenChoix->setObjectName("dateExamenChoix");
        dateExamenChoix->setGeometry(QRect(370, 60, 161, 41));
        dateExamenChoix->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */"));
        filterExam = new QDateEdit(GestExam);
        filterExam->setObjectName("filterExam");
        filterExam->setGeometry(QRect(420, 90, 131, 41));
        filterExam->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid  rgb(1, 121, 111); /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 13px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */"));
        RechExam = new QPushButton(GestExam);
        RechExam->setObjectName("RechExam");
        RechExam->setGeometry(QRect(1100, 30, 41, 41));
        RechExam->setStyleSheet(QString::fromUtf8("QPushButton#RechExam  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 20px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: 1px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#RechExam:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#RechExam :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/recherche.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        RechExam->setIcon(icon13);
        lineEdit_2 = new QLineEdit(GestExam);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(930, 30, 171, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid  rgb(1, 121, 111); /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 14px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
""));
        stackedWidget_2 = new QStackedWidget(GestExam);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(580, 90, 551, 61));
        AddExamLabel = new QWidget();
        AddExamLabel->setObjectName("AddExamLabel");
        addExamText = new QLabel(AddExamLabel);
        addExamText->setObjectName("addExamText");
        addExamText->setGeometry(QRect(10, 10, 221, 41));
        addExamText->setStyleSheet(QString::fromUtf8("    font-size: 19px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border-radius: 10px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */"));
        AddExamConfirm_3 = new QPushButton(AddExamLabel);
        AddExamConfirm_3->setObjectName("AddExamConfirm_3");
        AddExamConfirm_3->setGeometry(QRect(490, 10, 51, 41));
        AddExamConfirm_3->setStyleSheet(QString::fromUtf8("QPushButton#AddExamConfirm_3  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#AddExamConfirm_3:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#AddExamConfirm_3 :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/valider.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AddExamConfirm_3->setIcon(icon14);
        AddExamConfirm_3->setIconSize(QSize(23, 23));
        stackedWidget_2->addWidget(AddExamLabel);
        ModifExamLabel = new QWidget();
        ModifExamLabel->setObjectName("ModifExamLabel");
        modifExamText = new QLabel(ModifExamLabel);
        modifExamText->setObjectName("modifExamText");
        modifExamText->setGeometry(QRect(10, 10, 211, 41));
        modifExamText->setStyleSheet(QString::fromUtf8("    font-size: 19px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border-radius: 10px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */"));
        ModifExamConfirm = new QPushButton(ModifExamLabel);
        ModifExamConfirm->setObjectName("ModifExamConfirm");
        ModifExamConfirm->setGeometry(QRect(490, 10, 51, 41));
        ModifExamConfirm->setStyleSheet(QString::fromUtf8("QPushButton#ModifExamConfirm  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#ModifExamConfirm:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#ModifExamConfirm :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon15(QIcon::fromTheme(QString::fromUtf8("emblem-synchronized")));
        ModifExamConfirm->setIcon(icon15);
        stackedWidget_2->addWidget(ModifExamLabel);
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget_2->addWidget(page);
        label_28 = new QLabel(GestExam);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 10, 271, 51));
        label_28->setStyleSheet(QString::fromUtf8("  \n"
"    font-size: 22px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border-radius: 10px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"\n"
""));
        ListeExamensTab = new QTableView(GestExam);
        ListeExamensTab->setObjectName("ListeExamensTab");
        ListeExamensTab->setGeometry(QRect(20, 160, 521, 391));
        ListeExamensTab->setStyleSheet(QString::fromUtf8("color:black;"));
        pushButton_2 = new QPushButton(GestExam);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 90, 251, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("  \n"
"    font-size: 22px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border-radius: 10px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"\n"
""));
        stackedWidget->addWidget(GestExam);
        GestSup = new QWidget();
        GestSup->setObjectName("GestSup");
        label_11 = new QLabel(GestSup);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(260, 20, 181, 41));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(GestSup);
        GestEquip = new QWidget();
        GestEquip->setObjectName("GestEquip");
        label_14 = new QLabel(GestEquip);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(310, 40, 181, 41));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(GestEquip);
        GestFourn = new QWidget();
        GestFourn->setObjectName("GestFourn");
        label_12 = new QLabel(GestFourn);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(270, 40, 171, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));
        stackedWidget->addWidget(GestFourn);
        GestCand = new QWidget();
        GestCand->setObjectName("GestCand");
        label_15 = new QLabel(GestCand);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(280, 50, 161, 31));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        stackedWidget->addWidget(GestCand);
        GestEtab = new QWidget();
        GestEtab->setObjectName("GestEtab");
        label_16 = new QLabel(GestEtab);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(250, 50, 191, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        stackedWidget->addWidget(GestEtab);
        GestStats = new QWidget();
        GestStats->setObjectName("GestStats");
        label_29 = new QLabel(GestStats);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(40, 30, 171, 51));
        label_29->setStyleSheet(QString::fromUtf8("  \n"
"    font-size: 22px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border-radius: 10px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"\n"
""));
        stackedWidget->addWidget(GestStats);
        closeBtn = new QPushButton(centralwidget);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setGeometry(QRect(1270, 20, 36, 36));
        closeBtn->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton#closeBtn {\n"
"    background-color: #D64545; /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#closeBtn:hover {\n"
"    background-color: #E06666; /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#closeBtn:pressed {\n"
"    background-color: #B83232; /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/img/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closeBtn->setIcon(icon16);
        closeBtn->setIconSize(QSize(25, 25));
        notifBtn = new QPushButton(centralwidget);
        notifBtn->setObjectName("notifBtn");
        notifBtn->setGeometry(QRect(1220, 20, 36, 36));
        notifBtn->setStyleSheet(QString::fromUtf8("QPushButton#notifBtn {\n"
"    background-color: rgb(131, 151, 166); /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#notifBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#notifBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/img/notif.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifBtn->setIcon(icon17);
        notifBtn->setIconSize(QSize(42, 41));
        emailBtn = new QPushButton(centralwidget);
        emailBtn->setObjectName("emailBtn");
        emailBtn->setGeometry(QRect(1170, 20, 36, 36));
        emailBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        emailBtn->setStyleSheet(QString::fromUtf8("QPushButton#emailBtn {\n"
"	\n"
"    background-color: rgb(131, 151, 166); /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#emailBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#emailBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/img/mail.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emailBtn->setIcon(icon18);
        emailBtn->setIconSize(QSize(33, 32));
        paramBtn = new QPushButton(centralwidget);
        paramBtn->setObjectName("paramBtn");
        paramBtn->setGeometry(QRect(1120, 20, 36, 36));
        paramBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paramBtn->setStyleSheet(QString::fromUtf8("QPushButton#paramBtn {\n"
"	\n"
"    background-color: rgb(131, 151, 166); /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#paramBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#paramBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/img/settings.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        paramBtn->setIcon(icon19);
        paramBtn->setIconSize(QSize(29, 27));
        homeBtn = new QPushButton(centralwidget);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setGeometry(QRect(1070, 20, 36, 36));
        homeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeBtn->setStyleSheet(QString::fromUtf8("QPushButton#homeBtn {\n"
"    color: rgb(8, 8, 8);\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#homeBtn:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#homeBtn:pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}\n"
""));
        QIcon icon20(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        homeBtn->setIcon(icon20);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "SmartEval", nullptr));
        supButton->setText(QString());
        eqButton->setText(QString());
        FourButton->setText(QString());
        candButton->setText(QString());
        etaButton->setText(QString());
        examButton->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Superviseurs", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Equipements", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Candidats", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Etablissements", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Examens", nullptr));
        statButton->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableExams->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableExams->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Mati\303\250re", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableExams->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Niveau", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TableExams->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TableExams->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TableExams->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Dur\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TableExams->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Enonc\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = TableExams->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        pdfExambtn->setText(QCoreApplication::translate("MainWindow", "Liste des Examens Par Ann\303\251e PDF", nullptr));
        ModExamButton->setText(QString());
        SuppExamButton->setText(QString());
        AjExamButton->setText(QString());
        Trilabel4->setText(QCoreApplication::translate("MainWindow", "Filtrer par Date:", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Mati\303\250re :", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        lineEdit_18->setText(QString());
        label_39->setText(QCoreApplication::translate("MainWindow", "Date :", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Niveau :", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "Dur\303\251e :", nullptr));
        InsertExamPdf_3->setText(QCoreApplication::translate("MainWindow", "Ins\303\251rer l'\303\251nonc\303\251 en PDF", nullptr));
        pushButton->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        TypeExamenChoix->setItemText(0, QCoreApplication::translate("MainWindow", "Ecrit ", nullptr));
        TypeExamenChoix->setItemText(1, QCoreApplication::translate("MainWindow", "Orale", nullptr));
        TypeExamenChoix->setItemText(2, QCoreApplication::translate("MainWindow", "Pratique", nullptr));

        StatutExamenChoix->setItemText(0, QCoreApplication::translate("MainWindow", "Pass\303\251", nullptr));
        StatutExamenChoix->setItemText(1, QCoreApplication::translate("MainWindow", "Planifi\303\251", nullptr));
        StatutExamenChoix->setItemText(2, QCoreApplication::translate("MainWindow", "Confirm\303\251", nullptr));
        StatutExamenChoix->setItemText(3, QCoreApplication::translate("MainWindow", "En cours", nullptr));

        RechExam->setText(QString());
        lineEdit_2->setText(QString());
        addExamText->setText(QCoreApplication::translate("MainWindow", "Ajouter un examen :", nullptr));
        AddExamConfirm_3->setText(QString());
        modifExamText->setText(QCoreApplication::translate("MainWindow", "Modifier un examen :", nullptr));
        ModifExamConfirm->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "Gestion des Examens :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Liste des Examens :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Gestion Des Superviseurs", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Gestion Des Equipements", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Gestion des Fournisseurs", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Gestion des Candidats", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Gestion des Etablissements", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Statistiques :", nullptr));
        closeBtn->setText(QString());
        notifBtn->setText(QString());
        emailBtn->setText(QString());
        paramBtn->setText(QString());
        homeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
