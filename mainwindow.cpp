/* РЕАЛІЗАЦІЯ ФУНКЦІЙ ГОЛОВНОГО ВІКНА */

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

    // RESIZING

    // виклик функції, яка малює кола
    drawCircles(list1,list2);
}


void MainWindow::drawCircles(QStringList list1, QStringList list2)
{
    // знаходження площі QGroupBox
    int S = ui->groupBox_2->width() * ui->groupBox_2->height();
    // знаходження радіусу
    int r = sqrt(S/2/17/3.14);

    // ширина і виота groupBox
    int w = ui->groupBox_2->width();
    int h = ui->groupBox_2->height();

    // встановлення необхідних розмірів
    ui->pushButton->setGeometry(w*0.2,h*0.25,r*list1.length()/3.5,r*list1.length()/3.5);
    ui->pushButton_2->setGeometry(w*0.45,h*0.25,r*list2.length()/3.5,r*list2.length()/3.5);

    if (ui->lineEdit_4->text() != "")
    {
        while(ui->pushButton->x() + ui->pushButton->width() < ui->pushButton_2->x()+30)
        {
            ui->pushButton->setGeometry(ui->pushButton->x(),ui->pushButton->y(), ui->pushButton->width()+2,ui->pushButton->height()+2);
        }
    }

    // встановлення стилів
    ui->pushButton->setStyleSheet("background-color: rgb(115, 210, 22);border-radius: " + QString::number(ui->pushButton->width()/2) + ";");
    ui->pushButton_2->setStyleSheet("background-color: rgba(52, 101, 164,75%);border-radius: " + QString::number(ui->pushButton_2->width()/2) + ";");
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
//    int x = ui->groupBox_2->x();
//    int y = ui->groupBox_2->y();
//    int h = ui->groupBox_2->height();
//    int w = ui->groupBox_2->width();
//    int S = h * w;
//    int r = h > w ? w : h;
//    r /= 4;

//    int correctS = 3.14 * r * r;

//    ui->pushButton->setGeometry((this->width() - ui->pushButton->x())/10,(this->height() - ui->pushButton->y())/2,r*2,r*2);
//    ui->pushButton_2->setGeometry((this->width() - ui->pushButton_2->x())/1.5,(this->height() - ui->pushButton_2->y())/2,r*2,r*2);
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
