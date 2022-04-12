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
#include <string.h>


using namespace std;
struct Data
{
    int num;
    char sim;
};

struct Node
{
    Node *next;
    Node *prev;
    struct Data d;
};

class LinkedList
{
    private:
        Data d;
        Node* HEAD;
        Node* TAIL;
        Node* curNode; // Текущий эл-т
        int len;
    public:
        void push_back(const Data d);
        struct Data pop_back();
        struct Data pop_front();
        void push_front(const Data&data);
        Data nextNode();
        bool search(int ID);
        bool Swap(int ID1, int ID2);
        void resetCurNode();
        int listLen();
};

Data LinkedList::pop_back()
{
    if(TAIL!=nullptr) //Иначе len = 0 и цикл for в main не начнет выполняться.
    {
        Node* temp = TAIL->prev;
        Data tempd = TAIL->d;
        temp->next = nullptr;
        delete TAIL;
        len--;
        return tempd;
    }
}

int task_6()
{
    LinkedList MyList;
    QFile f("LinkedListData.txt");
    f.open(QIODevice::ReadWrite);
    Data ThisData;
    int z = MyList.listLen();
    if(z==0)
    {
        return -1;
    }
    for(int i = 0; i < z;i++)
    {
        ThisData = MyList.pop_back();
        QTextStream writeStream(&f);
        writeStream << "1. " << ThisData.num << " " << ThisData.sim << "\n";
    }
    f.close();
    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int m = task_6();
    if(m == -1)
    {
        cout << "Список пуст." << endl;
    }
    else
    {
        cout << "Данные успешно записаны." << endl;
    }
    return a.exec();
}
