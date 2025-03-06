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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *sideMenu;
    QLabel *label;
    QPushButton *examBtn;
    QPushButton *supBtn;
    QPushButton *eqBtn;
    QPushButton *fourBtn;
    QPushButton *candBtn;
    QPushButton *etaBtn;
    QPushButton *exitBtn;
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
    QPushButton *exitButton;
    QLabel *label_10;
    QLabel *label_4;
    QWidget *Menu;
    QWidget *widget;
    QPushButton *sideBtn;
    QPushButton *rechBtn;
    QLineEdit *lineEdit;
    QStackedWidget *stackedWidget;
    QWidget *HOME;
    QWidget *GestExam;
    QLabel *label_13;
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
    QPushButton *notifButton;
    QPushButton *paramButton;
    QPushButton *closeButton;
    QPushButton *emailButton;
    QPushButton *closeBtn;
    QPushButton *notifBtn;
    QPushButton *emailBtn;
    QPushButton *paramBtn;
    QPushButton *homeBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1037, 665);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #D9E6F2; /* Bleu pastel plus visible */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sideMenu = new QWidget(centralwidget);
        sideMenu->setObjectName("sideMenu");
        sideMenu->setGeometry(QRect(11, 20, 101, 641));
        label = new QLabel(sideMenu);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 63, 61));
        label->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/img/logo.png")));
        label->setScaledContents(true);
        examBtn = new QPushButton(sideMenu);
        examBtn->setObjectName("examBtn");
        examBtn->setGeometry(QRect(20, 100, 61, 41));
        examBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        examBtn->setStyleSheet(QString::fromUtf8("QPushButton#examBtn {\n"
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
"QPushButton#examBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#examBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/examen.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        examBtn->setIcon(icon);
        examBtn->setCheckable(true);
        examBtn->setAutoExclusive(true);
        supBtn = new QPushButton(sideMenu);
        supBtn->setObjectName("supBtn");
        supBtn->setGeometry(QRect(20, 170, 61, 41));
        supBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        supBtn->setStyleSheet(QString::fromUtf8("QPushButton#supBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/rechercher-des-personnes.png);\n"
"    \n"
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
"QPushButton#supBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#supBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/img/rechercher-des-personnes.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supBtn->setIcon(icon1);
        supBtn->setCheckable(true);
        supBtn->setAutoExclusive(true);
        eqBtn = new QPushButton(sideMenu);
        eqBtn->setObjectName("eqBtn");
        eqBtn->setGeometry(QRect(20, 240, 61, 41));
        eqBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        eqBtn->setStyleSheet(QString::fromUtf8("QPushButton#eqBtn {\n"
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
"QPushButton#eqBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#eqBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/img/equipe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eqBtn->setIcon(icon2);
        eqBtn->setCheckable(true);
        eqBtn->setAutoExclusive(true);
        fourBtn = new QPushButton(sideMenu);
        fourBtn->setObjectName("fourBtn");
        fourBtn->setGeometry(QRect(20, 310, 61, 41));
        fourBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        fourBtn->setStyleSheet(QString::fromUtf8("QPushButton#fourBtn {\n"
"     background-color: #4A90E2;\n"
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
"QPushButton#fourBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#fourBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/img/livreur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        fourBtn->setIcon(icon3);
        fourBtn->setCheckable(true);
        fourBtn->setAutoExclusive(true);
        candBtn = new QPushButton(sideMenu);
        candBtn->setObjectName("candBtn");
        candBtn->setGeometry(QRect(20, 380, 61, 41));
        candBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        candBtn->setStyleSheet(QString::fromUtf8("QPushButton#candBtn {\n"
"\n"
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
"QPushButton#candBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#candBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/img/candidat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        candBtn->setIcon(icon4);
        candBtn->setCheckable(true);
        candBtn->setAutoExclusive(true);
        etaBtn = new QPushButton(sideMenu);
        etaBtn->setObjectName("etaBtn");
        etaBtn->setGeometry(QRect(20, 450, 61, 41));
        etaBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        etaBtn->setStyleSheet(QString::fromUtf8("QPushButton#etaBtn {\n"
"\n"
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
"QPushButton#etaBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#etaBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/img/batiment-educatif.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        etaBtn->setIcon(icon5);
        etaBtn->setCheckable(true);
        etaBtn->setAutoExclusive(true);
        exitBtn = new QPushButton(sideMenu);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(20, 550, 61, 41));
        exitBtn->setStyleSheet(QString::fromUtf8("QPushButton#exitBtn {\n"
"	\n"
"    background-color: #D64545; /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #D64545;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#exitBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#exitBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/img/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitBtn->setIcon(icon6);
        fullMenu = new QWidget(centralwidget);
        fullMenu->setObjectName("fullMenu");
        fullMenu->setGeometry(QRect(130, 20, 161, 641));
        label_2 = new QLabel(fullMenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 63, 61));
        label_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/img/logo.png")));
        label_3 = new QLabel(fullMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 20, 91, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 18px;\n"
"    font-weight: bold;"));
        supButton = new QPushButton(fullMenu);
        supButton->setObjectName("supButton");
        supButton->setGeometry(QRect(0, 170, 151, 41));
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
        supButton->setCheckable(true);
        supButton->setAutoExclusive(true);
        eqButton = new QPushButton(fullMenu);
        eqButton->setObjectName("eqButton");
        eqButton->setGeometry(QRect(0, 240, 151, 41));
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
        eqButton->setCheckable(true);
        eqButton->setAutoExclusive(true);
        FourButton = new QPushButton(fullMenu);
        FourButton->setObjectName("FourButton");
        FourButton->setGeometry(QRect(0, 310, 151, 41));
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
        FourButton->setCheckable(true);
        FourButton->setAutoExclusive(true);
        candButton = new QPushButton(fullMenu);
        candButton->setObjectName("candButton");
        candButton->setGeometry(QRect(0, 380, 151, 41));
        candButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        candButton->setStyleSheet(QString::fromUtf8("QPushButton#candButton {\n"
"	\n"
"	image: url(:/new/prefix1/img/candidat.png);\n"
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
        candButton->setIcon(icon4);
        candButton->setCheckable(true);
        candButton->setAutoExclusive(true);
        etaButton = new QPushButton(fullMenu);
        etaButton->setObjectName("etaButton");
        etaButton->setGeometry(QRect(0, 450, 151, 41));
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
        etaButton->setCheckable(true);
        etaButton->setAutoExclusive(true);
        examButton = new QPushButton(fullMenu);
        examButton->setObjectName("examButton");
        examButton->setGeometry(QRect(0, 100, 151, 41));
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
        examButton->setIconSize(QSize(20, 20));
        examButton->setCheckable(true);
        examButton->setAutoExclusive(true);
        label_5 = new QLabel(fullMenu);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 180, 101, 20));
        label_5->setStyleSheet(QString::fromUtf8(" color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));
        label_6 = new QLabel(fullMenu);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 250, 91, 20));
        label_6->setStyleSheet(QString::fromUtf8(" color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));
        label_7 = new QLabel(fullMenu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 320, 91, 20));
        label_7->setStyleSheet(QString::fromUtf8(" color: black;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_8 = new QLabel(fullMenu);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 390, 71, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_9 = new QLabel(fullMenu);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 460, 101, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        exitButton = new QPushButton(fullMenu);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(10, 550, 151, 41));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton#exitButton {\n"
"	\n"
"	image: url(:/new/prefix1/img/close.png);\n"
"    background-color: #D64545; /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #D64545;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#exitButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#exitButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        label_10 = new QLabel(fullMenu);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(60, 560, 81, 20));
        label_10->setStyleSheet(QString::fromUtf8(" color: black;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"  background-color: #D64545; /* Rouge brique pastel */"));
        label_4 = new QLabel(fullMenu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 110, 81, 20));
        label_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
""));
        etaButton->raise();
        candButton->raise();
        eqButton->raise();
        examButton->raise();
        label_2->raise();
        label_3->raise();
        supButton->raise();
        FourButton->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        exitButton->raise();
        label_10->raise();
        label_4->raise();
        Menu = new QWidget(centralwidget);
        Menu->setObjectName("Menu");
        Menu->setGeometry(QRect(301, 60, 721, 601));
        widget = new QWidget(Menu);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 721, 41));
        sideBtn = new QPushButton(widget);
        sideBtn->setObjectName("sideBtn");
        sideBtn->setGeometry(QRect(0, 0, 61, 41));
        sideBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sideBtn->setStyleSheet(QString::fromUtf8("QPushButton#sideBtn {\n"
"	\n"
"    \n"
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
"QPushButton#sideBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#sideBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/img/plus-moins.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sideBtn->setIcon(icon7);
        sideBtn->setCheckable(true);
        rechBtn = new QPushButton(widget);
        rechBtn->setObjectName("rechBtn");
        rechBtn->setGeometry(QRect(630, 0, 61, 41));
        rechBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        rechBtn->setStyleSheet(QString::fromUtf8("QPushButton#rechBtn {\n"
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
"QPushButton#rechBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#rechBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/img/recherche.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        rechBtn->setIcon(icon8);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(410, 0, 221, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
""));
        stackedWidget = new QStackedWidget(Menu);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 50, 721, 561));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 251, 255);"));
        HOME = new QWidget();
        HOME->setObjectName("HOME");
        HOME->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(169, 222, 255, 255), stop:0.55 rgba(99, 161, 229, 255), stop:0.98 rgba(47, 47, 47, 255), stop:1 rgba(0, 0, 0, 0));"));
        stackedWidget->addWidget(HOME);
        GestExam = new QWidget();
        GestExam->setObjectName("GestExam");
        label_13 = new QLabel(GestExam);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(250, 40, 181, 41));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
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
        notifButton = new QPushButton(centralwidget);
        notifButton->setObjectName("notifButton");
        notifButton->setGeometry(QRect(1190, 20, 36, 36));
        notifButton->setStyleSheet(QString::fromUtf8("QPushButton#notifButton {\n"
"	image: url(:/new/prefix1/img/notif.png);\n"
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
"QPushButton#notifButton:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#notifButton:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        paramButton = new QPushButton(centralwidget);
        paramButton->setObjectName("paramButton");
        paramButton->setGeometry(QRect(1090, 20, 36, 36));
        paramButton->setStyleSheet(QString::fromUtf8("QPushButton#paramButton {\n"
"	image: url(:/new/prefix1/img/settings.png);\n"
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
"QPushButton#paramButton:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#paramButton:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(1240, 20, 36, 36));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton#closeButton {\n"
"	image: url(:/new/prefix1/img/close.png);\n"
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
"QPushButton#closeButton:hover {\n"
"    background-color: #E06666; /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#closeButton:pressed {\n"
"    background-color: #B83232; /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        emailButton = new QPushButton(centralwidget);
        emailButton->setObjectName("emailButton");
        emailButton->setGeometry(QRect(1140, 20, 36, 36));
        emailButton->setStyleSheet(QString::fromUtf8("QPushButton#emailButton {\n"
"	image: url(:/new/prefix1/img/mail.png);\n"
"    background-color: rgb(131, 151, 166); /* Bleu-gris */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px;\n"
"    min-height: 36px;\n"
"    max-width: 36px;\n"
"    max-height: 36px;\n"
"    border-radius: 18px;\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#emailButton:hover {\n"
"    background-color: rgb(158, 175, 189); /* Bleu-gris plus clair */\n"
"    box-shadow: 0px 3px 8px rgba(131, 151, 166, 0.5); /* Ombre assortie */\n"
"}\n"
"\n"
"QPushButton#emailButton:pressed {\n"
"    background-color: rgb(109, 126, 138); /* Bleu-gris plus fonc\303\251 */\n"
"    box-shadow: 0px 2px 5px rgba(109, 126, 138, 0.5);\n"
"}\n"
"\n"
""));
        closeBtn = new QPushButton(centralwidget);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setGeometry(QRect(980, 20, 36, 36));
        closeBtn->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton#closeBtn {\n"
"	image: url(:/new/prefix1/img/close.png);\n"
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
        notifBtn = new QPushButton(centralwidget);
        notifBtn->setObjectName("notifBtn");
        notifBtn->setGeometry(QRect(930, 20, 36, 36));
        notifBtn->setStyleSheet(QString::fromUtf8("QPushButton#notifBtn {\n"
"	image: url(:/new/prefix1/img/notif.png);\n"
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
        emailBtn = new QPushButton(centralwidget);
        emailBtn->setObjectName("emailBtn");
        emailBtn->setGeometry(QRect(880, 20, 36, 36));
        emailBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        emailBtn->setStyleSheet(QString::fromUtf8("QPushButton#emailBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/mail.png);\n"
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
        paramBtn = new QPushButton(centralwidget);
        paramBtn->setObjectName("paramBtn");
        paramBtn->setGeometry(QRect(830, 20, 36, 36));
        paramBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paramBtn->setStyleSheet(QString::fromUtf8("QPushButton#paramBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/settings.png);\n"
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
        homeBtn = new QPushButton(centralwidget);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setGeometry(QRect(780, 20, 36, 36));
        homeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeBtn->setStyleSheet(QString::fromUtf8("QPushButton#homeBtn {\n"
"	\n"
"	color: rgb(8, 8, 8);\n"
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
"QPushButton#homeBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#homeBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        homeBtn->setIcon(icon9);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(sideBtn, &QPushButton::toggled, sideMenu, &QWidget::setVisible);
        QObject::connect(sideBtn, &QPushButton::toggled, fullMenu, &QWidget::setHidden);
        QObject::connect(examBtn, &QPushButton::toggled, examButton, &QPushButton::setChecked);
        QObject::connect(supBtn, &QPushButton::toggled, supButton, &QPushButton::setChecked);
        QObject::connect(eqBtn, &QPushButton::toggled, eqButton, &QPushButton::setChecked);
        QObject::connect(fourBtn, &QPushButton::toggled, FourButton, &QPushButton::setChecked);
        QObject::connect(candBtn, &QPushButton::toggled, candButton, &QPushButton::setChecked);
        QObject::connect(etaBtn, &QPushButton::toggled, etaButton, &QPushButton::setChecked);
        QObject::connect(examButton, &QPushButton::toggled, examBtn, &QPushButton::setChecked);
        QObject::connect(supButton, &QPushButton::toggled, supBtn, &QPushButton::setChecked);
        QObject::connect(eqButton, &QPushButton::toggled, eqBtn, &QPushButton::setChecked);
        QObject::connect(FourButton, &QPushButton::toggled, fourBtn, &QPushButton::setChecked);
        QObject::connect(candButton, &QPushButton::toggled, candBtn, &QPushButton::setChecked);
        QObject::connect(etaButton, &QPushButton::toggled, etaBtn, &QPushButton::setChecked);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        examBtn->setText(QString());
        supBtn->setText(QString());
        eqBtn->setText(QString());
        fourBtn->setText(QString());
        candBtn->setText(QString());
        etaBtn->setText(QString());
        exitBtn->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "SmartEval", nullptr));
        supButton->setText(QString());
        eqButton->setText(QString());
        FourButton->setText(QString());
        candButton->setText(QString());
        etaButton->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Superviseurs", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Equipements", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Candidats", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Etablissements", nullptr));
        exitButton->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Examens", nullptr));
        sideBtn->setText(QString());
        rechBtn->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Gestion Des Examens", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Gestion Des Superviseurs", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Gestion Des Equipements", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Gestion des Fournisseurs", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Gestion des Candidats", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Gestion des Etablissements", nullptr));
        notifButton->setText(QString());
        paramButton->setText(QString());
        closeButton->setText(QString());
        emailButton->setText(QString());
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
