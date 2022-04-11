#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QtGlobal>
#include <stdio.h>

using namespace std;

QByteArray filedata;

void ReadFromFile(const char* filename)
{
    QFile f(filename);
    f.open(QIODevice::ReadOnly);

    filedata = f.readAll();

    f.close();
}

char binNumb[32];
void WriteToFile(const char* fileout)
{
    QFile f(fileout);
    f.open(QIODevice::WriteOnly);

    for(int i = 0; i < 32; i++)
    {
        QTextStream writeStream(&f);
        writeStream << binNumb[i];
    }
    f.close();
}


QString perevod(int numBinary) //Функция перевода бинарного числа в 16-чный формат
{
    QMap<QString, char> per;
    QString rez;
    rez.clear();
    QVector<QString> bin;
    int temp = numBinary;
    while(temp > 0)
    {
        bin.push_back(QString::number(temp%10));
        temp = temp/10;
    }
    while(bin.length()%4 != 0)
    {
        bin.push_back("0");
    }
    per["0000"] = '0';
    per["0001"] = '1';
    per["0010"] = '2';
    per["0011"] = '3';
    per["0100"] = '4';
    per["0101"] = '5';
    per["0110"] = '6';
    per["0111"] = '7';
    per["1000"] = '8';
    per["1001"] = '9';
    per["1010"] = 'A';
    per["1011"] = 'B';
    per["1100"] = 'C';
    per["1101"] = 'D';
    per["1110"] = 'E';
    per["1111"] = 'F';

    for(int i = 0; i < bin.length()/4; i++)
    { //Необходимо проходить по массиву bin с конца. Тогда переводит верно
        QString temp1;
        temp1.clear();
        for(int t = 0; t < 4; t++)
        {
            temp1.append(bin.at(bin.length()-i*4 - t - 1));
        }
        rez.append(per.lowerBound(temp1).value());
    }
    return rez;
}

void task3(QString inp)
{
    int i = 0;
    i = inp.toInt();
    QString itog = perevod(i);
    cout << "Result: ";
    QTextStream out(stdout);
    out << itog;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString s;
    int n;
    cout << "Vvedite kol-vo simvolov: " << endl;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        cout << "Vvedite simvol :" << endl;
        unsigned long im;
        cin >> hex >> im;
        char c = im;
        s.append(c);
    }
    task3(s);
    return a.exec();
}
