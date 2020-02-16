/* БІБЛІОТЕКА З БАЗОВИМИ ФУНКЦІЯМИ,
 * ЯКІ БУДУТЬ НЕОБХІДНИМИ ПРОТЯГОМ
 * УСЬОГО ЧАСУ КОРИСТУВАННЯ ПРОГРАМОЮ */

#ifndef BASIC_H
#define BASIC_H
#include <QApplication>

// Сигнатури фукнцій
bool sortingAlg(QString str1, QString str2);
void splitThings(const QString &string1, const QString &string2, QStringList &text1, QStringList &text2);
QString Union(QStringList text1, QStringList text2);
QString DifferenceAB(QStringList text1, QStringList text2);
QString Intersection(QStringList text1, QStringList text2);
QString SymmetricDifference(QStringList text1, QStringList text2);


#endif // BASIC_H
