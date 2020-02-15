#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <QApplication>

class randomizer
{
private:
//    const int universum[18] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    static int randomBetween(int low, int high);
    static void sort(int ar[], int n);
    static QString makeString(int ar[], int n);
public:
    randomizer();
    static QString getRandom();
};

#endif // RANDOMIZER_H
