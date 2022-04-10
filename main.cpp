#include <QCoreApplication>
#include <QFile>
#include <iostream>

using namespace std;

QByteArray filedata;

void ReadFromFile(const char* filename)
{
    QFile f(filename);
    f.open(QIODevice::ReadOnly);

    filedata = f.readAll();

    f.close();
}

void WriteToFile(const char* fileout, int ar[])
{
    QFile f(fileout);
    f.open(QIODevice::WriteOnly);

    for(int i = 0; i < 256; i++)
    {
        if(ar[i] != 0)
        {
            char sim = i;
            QTextStream writeStream(&f);
            writeStream << sim << " : " << ar[i] << "\n";
        }
    }
}

void task1(const char* filename, const char* fileout)
{
    ReadFromFile(filename);

    int ar[256];
    memset(&ar, 0x00, sizeof(int)*256);

    for(int i = 0; i < filedata.size();i++)
    {
        ar[filedata[i]]++;
    }
    WriteToFile(fileout, ar);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    task1("data.txt", "result.txt");
    return a.exec();
}
