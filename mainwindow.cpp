﻿/* РЕАЛІЗАЦІЯ ФУНКЦІЙ ГОЛОВНОГО ВІКНА */

#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomizer.h"
#include "basic.h"

/*АВТОМАТИЧНО ЗГЕНЕРОВАНО*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/*АВТОМАТИЧНО ЗГЕНЕРОВАНО*/
MainWindow::~MainWindow()
{
    delete ui;
}

// Функція, яка викликається при натисканні на кнопку( кнопка Random після поля множини А)
void MainWindow::on_randomAButton_clicked()
{
    // Зміна тексту поля lineEdit на формі
    // текст змінюється на значення, повернене з фунції getRandom, класу randomizer(randomizer.cpp)
    ui->lineEdit->setText(randomizer().getRandom());
}

// Функція, яка викликається при натисканні на кнопку( кнопка Random після поля множини В)
void MainWindow::on_randomBButton_clicked()
{
    // Зміна тексту поля lineEdit_2 на формі
    // текст змінюється на значення, повернене з фунції getRandom, класу randomizer(randomizer.cpp)
    ui->lineEdit_2->setText(randomizer().getRandom());
}


// Функція, що викликається при зміні значення текстового поля на формі
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // виклик функції із головною логікою
    lineEditWorker();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    // виклик функції із головною логікою
    lineEditWorker();
}


void MainWindow::lineEditWorker()
{
    // голошення змінних, які буде повернено значення
    QStringList list1, list2;
    // виклик функції, яка записує у list1 list2 масив чисел з полей на формі
    splitThings(ui->lineEdit->text(),ui->lineEdit_2->text(),list1,list2);

    // зміна значень надписів(label) на формі з результатами роботи функцій
    ui->lineEdit_3->setText(Union(list1,list2));
    ui->lineEdit_4->setText(Intersection(list1,list2));
    ui->lineEdit_5->setText(DifferenceAB(list1,list2));
    ui->lineEdit_6->setText(DifferenceAB(list2,list1));
    ui->lineEdit_7->setText(SymmetricDifference(list1,list2));

    // входження А до В і В до А
    if (AintoB(list1,list2))
        ui->label_10->setText(QString::fromUtf8("А входить до B"));
    else if (AintoB(list2,list1))
        ui->label_10->setText(QString::fromUtf8("B входить до А"));
    else // в іншому випадку
         ui->label_10->setText("");

    // RESIZING

    // виклик функції, яка малює кола
    drawCircles(list1,list2);
}


void MainWindow::drawCircles(QStringList list1, QStringList list2)
{
    ui->label_9->setGeometry(0,0,0,0);
    // знаходження площі QGroupBox
    int S = ui->groupBox_2->width() * ui->groupBox_2->height();
    // знаходження радіусу
    int r = sqrt(S/2/17/3.14);

    // ширина і висота groupBox
    int w = ui->groupBox_2->width();
    int h = ui->groupBox_2->height();

    // встановлення необхідних розмірів
    ui->pushButton->setGeometry(w*0.2,h*0.25,r*list1.length()/3.5,r*list1.length()/3.5);
    ui->pushButton_2->setGeometry(w*0.45,h*0.25,r*list2.length()/3.5,r*list2.length()/3.5);

    if (ui->lineEdit_4->text() != "")
    {   // цикл, поки на графічному представленні не буде видно перетину
        while(ui->pushButton->x() + ui->pushButton->width() < ui->pushButton_2->x()+30)
        { // встановлення необхідних розмірів
            ui->pushButton->setGeometry(ui->pushButton->x(),ui->pushButton->y(), ui->pushButton->width()+2,ui->pushButton->height()+2);
        } // вираховування ширини
        int height = ui->pushButton->height() > ui->pushButton_2->height() ? ui->pushButton_2->height() : ui->pushButton->height();
        // встановлення необхідних розмірів і розташування
        ui->label_9->setGeometry(ui->pushButton_2->x() - list2.length()*2, (ui->pushButton->y() > ui->pushButton_2->y() ? ui->pushButton_2->y(): ui->pushButton->y()) + height / 2,22 * list2.length(),22);
        // встановлення значення
        ui->label_9->setText(Intersection(list1,list2));
    }

    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgb(115, 210, 22);border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgba(52, 101, 164,75%);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    // to be continued...
}

void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{
    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgb(255, 0, 0);border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}

void MainWindow::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0,50%);border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgba(255, 0, 0,50%);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}

void MainWindow::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{
    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgb(255, 0, 0);border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgb(52, 101, 164);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}

void MainWindow::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{
    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgb(52, 101, 164);position:absolute;border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgba(255,0,0,50%);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}

void MainWindow::on_lineEdit_7_cursorPositionChanged(int arg1, int arg2)
{
    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0,50%);border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgba(255, 0, 0,50%);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}
