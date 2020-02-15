#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomizer.h"

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


void MainWindow::on_randomAButton_clicked()
{
    ui->lineEdit->setText(randomizer().getRandom());
}

void MainWindow::on_randomBButton_clicked()
{
    ui->lineEdit_2->setText(randomizer().getRandom());
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}
