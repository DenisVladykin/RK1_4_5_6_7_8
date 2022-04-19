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

void task4(int H_of_elka)
{
    if(H_of_elka<=0)
    {
        cout << "takih elok ne bivaet." << endl;
        return;
    }
    int max_yarus = 1;
    int kolvoprob = 0;
    for(int i = 0; i < H_of_elka; i++)
    {
        kolvoprob++;
    }


    for(int i = 0; i < H_of_elka;i++)
    {
        for(int i = 0; i<kolvoprob;i++)
        {
            cout << " ";
        }
        for(int i = 0; i < max_yarus; i++)
        {
            cout << "*";
        }
        kolvoprob--;
        max_yarus += 2;
        cout << endl;
    }
}
double sred(int*mas, int m)
{
    double rez = 0;
    for(int i = 0; i < m; i++)
    {
        double temp = mas[i];
        rez = rez + temp/m;
    }
    return rez;
}
QList<double> task5(int* mas, int m, int n)
{
    QList<double> rez;
    rez.clear();
    for(int i = 0; i < n; i++)
    {
        double promrez;
        promrez = sred(&mas[m*i], m);
        rez.append(promrez);
    }
    return(rez);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    cout << "Test of task 4: " << endl;
    cout << "Kakoi visoti elky mne sdelat?" << endl;
    int n;
    cin >> n;
    task4(n);
    cout << endl << endl << endl;


    cout << "Test of task 5: " << endl;
    int A[4][3] = {
        {8, 2, 3},
        {21, 24, 30},
        {0, 0, 1},
        {1, 2, 3}
      };
    QList<double> T = task5(*A, 3, 4);
    for(int i = 0; i < T.length(); i++)
    {
        cout << "Average " << i+1 << ": " << T.at(i) << endl;
    }

    cout << endl << endl << endl;
    return a.exec();
}
