#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_examBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_supBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_eqBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_fourBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_candBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_etaBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}




void MainWindow::on_examButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_supButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}



void MainWindow::on_eqButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_FourButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_candButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_etaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}






void MainWindow::on_homeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AffButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_SuppButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_AffButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_SuppButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_AffButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_SuppButton_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_AffButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_SuppButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

