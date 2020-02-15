#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomizer.h"
#include "basic.h"

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
    QStringList list1, list2;
    splitThings(ui->lineEdit->text(),ui->lineEdit_2->text(),list1,list2);

    ui->label_2->setText(Union(list1,list2));
    ui->label_3->setText(DifferenceAB(list1,list2));
    ui->label_4->setText(DifferenceAB(list2,list1));
    ui->label_5->setText(Intersection(list1,list2));
    ui->label_8->setText(SymmetricDifference(list1,list2));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QStringList list1, list2;
    splitThings(ui->lineEdit->text(),ui->lineEdit_2->text(),list1,list2);

    ui->label_2->setText(Union(list1,list2));
    ui->label_3->setText(DifferenceAB(list1,list2));
    ui->label_4->setText(DifferenceAB(list2,list1));
    ui->label_5->setText(Intersection(list1,list2));
    ui->label_8->setText(SymmetricDifference(list1,list2));
}
