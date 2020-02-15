#include "basic.h"


void splitThings(const QString &string1, const QString &string2, QStringList &text1, QStringList &text2)
{
    text1 = string1.split(" ");
    text2 = string2.split(" ");
}


bool sortingAlg(QString str1, QString str2)
{
    if (str1.toInt() < str2.toInt())
        return true;
    return false;
}


QString Union(QStringList list1, QStringList list2)
{
    QString result = "";

    list1 << list2;
    list1.removeDuplicates();

    std::sort(list1.begin(),list1.end(), sortingAlg);

    result = list1.join(" ");

    return result;
}


QString DifferenceAB(QStringList list1, QStringList list2)
{
    for (int i = 0; i < list2.length();i++)
    {
        if (list1.indexOf(list2[i]) != -1)
        {
            list1.removeAt(list1.indexOf(list2[i]));
        }
    }
    return list1.join(" ");
}


QString Intersection(QStringList list1, QStringList list2)
{
    for (int i = 0; i < list1.length();i++)
    {
        if (list2.indexOf(list1[i]) == -1)
        {
            list1.removeAt(i);
            i--;
        }
    }
    return list1.join(" ");
}


QString SymmetricDifference(QStringList list1, QStringList list2)
{
    for (int i = 0; i < list1.length();i++)
    {
        if (list2.indexOf(list1[i]) != -1)
        {
            list2.removeAt(list2.indexOf(list1[i]));
            list1.removeAt(i);
            i--;
        }
    }
    list1 << list2;

    std::sort(list1.begin(),list1.end(), sortingAlg);

    return list1.join(" ");
}


















