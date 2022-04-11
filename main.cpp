#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QtGlobal>
#include <stdio.h>
#include <QList>

using namespace std;
int sred(int*mas, int m)
{
    int rez = 0;
    for(int i = 0; i < m; i++)
    {
        //rez = rez + mas[i]/m; - данная конструкция работает некорректно. Если mas[i] не делится нацело на m идёт округлуние.
        rez = rez + mas[i];
    }
    rez = rez/m;
    return rez;
}
QList<int> task5(int* mas, int m, int n)
{
    QList<int> rez;
    for(int i = 0; i < n; i++)
    {
        int promrez;
        promrez = sred(&mas[m*i], m);
        rez.append(promrez);
    }
    return(rez);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int A[4][3] = {
        {12, 80, 21},
        {21, 24, 30},
        {13, 30, 94},
        {6, 11, 72}
      };
    QList<int> T = task5(*A, 3, 5);
    for(int i = 0; i < T.length(); i++)
    {
        cout << "Average " << i+1 << ": " << T.at(i) << endl;
    }
    return a.exec();
}
