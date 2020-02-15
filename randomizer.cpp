#include "randomizer.h"

randomizer::randomizer()
{

}


QString randomizer::getRandom()
{
    int count = randomBetween(1, 17);
    int used[count];
    for (int i = 0; i < count; i++)
    {
        int num = 0;
        bool ok;
        do {
            ok = true;
            num = randomBetween(0,17);
            for(int j = 0; j < i; j++)
            {
                if (num == used[j])
                    ok = false;
            }

        } while (!ok);
        used[i] = num;
    }
    sort(used,count);
    return makeString(used,count);
}


QString randomizer::makeString(int ar[], int n)
{
    QString randomized;
    for (int i = 0; i < n; i++)
    {
        randomized += QString::number(ar[i]);
        randomized += " ";
    }
    return randomized;
}


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


int randomizer::randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}
