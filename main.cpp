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
        int task_7(int n, Data _d);
};


int LinkedList::task_7(int n, Data _d)
{
    if(n==0)
    {
        Node* temp = new Node;
        temp->d = HEAD->d;
        temp->next = HEAD->next;
        temp->prev = HEAD;
        HEAD->d = _d;
        HEAD->next = temp;
        len++;
        return 0;
    }
    if(n==len-1)
    {
        Node* temp = new Node;
        temp->d = TAIL->d;
        temp->prev = TAIL->prev;
        temp->next = TAIL;
        TAIL->d = _d;
        TAIL->prev = temp;
        len++;
        return 0;
    }
    if(n>=len)
    {
        return -1;
    }
    if(n==1)
    {
        Node* temp = new Node;
        temp->d = _d;
        temp->prev = HEAD;
        HEAD->next->prev = temp;
        temp->next = HEAD->next;
        HEAD->next = temp;
    }

    Node* prev = HEAD;
    Node* it = HEAD->next;
    for(int i = 2; i < n; i++)
    {
        prev = prev->next;
        it = it->next;
    }

    Node* temp = new Node;
    temp->d = _d;
    temp->prev = prev;
    temp->next = it;
    it->prev = temp;
    prev->next = temp;
    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    return a.exec();
}
