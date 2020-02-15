#include "basic.h"


void splitThings(const QString &string1, const QString &string2, QStringList &text1, QStringList &text2)
{
    text1 = string1.split(" ");
    text2 = string2.split(" ");
}


QString countUnion(QString text1, QString text2)
{
    QStringList list1, list2;
    splitThings(text1,text2,list1,list2);
}
