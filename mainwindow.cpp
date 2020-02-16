/* РЕАЛІЗАЦІЯ ФУНКЦІЙ ГОЛОВНОГО ВІКНА */

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
    QStringList list1, list2; // голошення змінних, які буде повернено значення
    // виклик функції, яка записує у list1 list2 масив чисел з полей на формі
    splitThings(ui->lineEdit->text(),ui->lineEdit_2->text(),list1,list2);

    // зміна значень надписів(label) на формі з результатами роботи функцій
    ui->label_2->setText(Union(list1,list2));
    ui->label_3->setText(DifferenceAB(list1,list2));
    ui->label_4->setText(DifferenceAB(list2,list1));
    ui->label_5->setText(Intersection(list1,list2));
    ui->label_8->setText(SymmetricDifference(list1,list2));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    // голошення змінних, які буде повернено значення
    QStringList list1, list2;
    // виклик функції, яка записує у list1 list2 масив чисел з полей на формі
    splitThings(ui->lineEdit->text(),ui->lineEdit_2->text(),list1,list2);

    // зміна значень надписів(label) на формі з результатами роботи функцій
    ui->label_2->setText(Union(list1,list2));
    ui->label_3->setText(DifferenceAB(list1,list2));
    ui->label_4->setText(DifferenceAB(list2,list1));
    ui->label_5->setText(Intersection(list1,list2));
    ui->label_8->setText(SymmetricDifference(list1,list2));
}
