#include "randomizer.h"

// створено автоматично
randomizer::randomizer()
{

}

// ГОЛОВНА ФУНКЦІЯ, ЯКА ПОВЕРТАЄ НЕОБХІДНІ ЗНАЧЕННЯ
QString randomizer::getRandom()
{
    // скільки випадкових чисел ми хочемо отримати?
    int count = randomBetween(1, 17);
    // створення масиву необхідної місткості
    int used[count];
    // цикл для створення необхідної кількості чисел
    for (int i = 0; i < count; i++)
    {
        // надання стартового значення змінній
        int num = 0;
        // змінна , необхідна для контролю, аби не було повторюваних значень
        bool ok;
        do {
            ok = true;
            // отримання випадкового числа
            num = randomBetween(0,17);
            // перегляд серед усіх згенерованих чисел на даний момент
            for(int j = 0; j < i; j++)
            {
                // якщо згенероване число вже є у масиві
                if (num == used[j])
                    ok = false; // присвоєння значення false
            }
            // цикл продовжується поки ми не згенеруємо унікальне число(якого ще немає у масиві)
        } while (!ok);
        // запис числа до масиву
        used[i] = num;
    }
    // сортування масиву
    sort(used,count);
    // створення текстового рядка з масиву цифр, при цьому, після кожного значення проставляється " "
    // і устворюється не масив, а текствоий рядок
    return makeString(used,count);
}


// ФУНКЦІЯ ДЛЯ СТВОРЕННЯ ТЕКСТОВОГО РЯДКА З МАСИВУ ЦИФР
QString randomizer::makeString(int ar[], int n)
{
    QString randomized; // створення початкового текстового рядку
    // перегляд усіх елементів масиву
    for (int i = 0; i < n; i++)
    {
        // додавання до текстового рядку числа
        randomized += QString::number(ar[i]);
        // додавання розділювального символа " "
        randomized += " ";
    }
    // поверення значення
    return randomized;
}


// ЗВИЧАЙНЕ СОРТУВАННЯ БУЛЬБАШКОЮ НА ЗРОСТАННЯ
void randomizer::sort(int ar[], int n)
{
    bool ok;
    int last = n;
    do
    {
        ok = true;
        last -= 1;
        for (int i = 0; i < last;i++)
        {
            if (ar[i] > ar[i+1])
            {
                int tmp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = tmp;
                ok = false;
            }
        }

    } while(!ok);
}

// ОТРИМАННЯ ВИПАДКОВОГО ЧИСЛА У ЗАДАНИХ МЕЖАХ
int randomizer::randomBetween(int low, int high)
{
    // ПОВЕРНЕННЯ ЗНАЧЕННЯ
    return (qrand() % ((high + 1) - low) + low);
}
