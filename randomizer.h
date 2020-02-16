/* КЛАС ДЛЯ СТВОРЕННЯ ВИПАДКОВИХ
 * ЗНАЧЕНЬ ВІДПОВІДНО ДО ЗАВДАННЯ */

#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <QApplication>

class randomizer
{
private:
//    const int universum[18] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    static int randomBetween(int low, int high); // випадкове число в межах
    static void sort(int ar[], int n); // сортування бульбашкою
    static QString makeString(int ar[], int n); // створення масиву символів(string) з числового масиву
public:
    randomizer(); // констуктор класу, створюється автоматично
    static QString getRandom(); // функція, яка використовуює усі попередні і повертає необхідний результат
};

#endif // RANDOMIZER_H
