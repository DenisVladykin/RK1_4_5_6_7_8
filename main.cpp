#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include <QDebug>

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


void perevod(int numDecimal) {
    memset(binNumb, 0x00, 32 * sizeof(char));

    for (int i = 0; i < 32; i++) {
        binNumb[i] = ((numDecimal & 1 << i)) ? 0x31 : 0x30;
    }
}

void task2(int Num) {
    perevod(Num);
    WriteToFile("result.txt");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    task2(8);
    return a.exec();
}
