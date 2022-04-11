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


//Указанная функция возвращает:
//"-1" : если первая строка меньше второй(либо первая строка является подстрокой второй, но ее длина меньше);
//"1" : если первая строка больше второй(либо вторая строка является подстрокой первой, но ее длина меньше);
//"0" : если строки одинаковые(полное совпадение).
//"-999" : неизвестная ошибка. Сбой в работе программы.
int Mystrcmp(char* first, const char* second)
{
    int len = strlen(first);
    int len1 = strlen(second);
    int len2 = strlen(first);
    if(len1<len)
    {
        len = len1;
    }
    for(int i = 0; i < len; i++)
    {
        if(int(first[i]) < int(second[i]))
        {
            return -1;
        }
        if(int(first[i]) > int(second[i]))
        {
            return 1;
        }
    }
    if(len2>len1)
    {
        return 1;
    }
    if(len2<len1)
    {
        return -1;
    }
    if(len2==len1)
    {
        return 0;
    }
    return -999;
}

struct StudentInfo {
    char* name;
    char* surname;
    int age;
    char* numTicket;
};

struct SubjMark {
    char* subj;
    int id_subj;
    QVector<int> marks_list;
    float averMark;

    SubjMark() {
        subj = new char[4]; //создать предмет по умолчанию - def с id '-1'
        subj[0] = 'd';
        subj[1] = 'e';
        subj[2] = 'f';
        subj[3] = '\n';
        id_subj = -1;
    }
    SubjMark(const char* _subj) {
        subj = new char[strlen(_subj)];
        strcpy(subj, _subj);
        id_subj = -1;
    }

    SubjMark(const char* _subj, int _idSubj) {
        subj = new char[strlen(_subj)];
        strcpy(subj, _subj);
        id_subj = _idSubj;
    }

    ~SubjMark() {
        if (subj != nullptr) {
            delete [] subj;
        }
    }

};


class Student {
private :
    StudentInfo* info;
    QList<SubjMark*> listSubjMark;

    int lookForSub(const char* subjName) {
        for (int i = 0; i < listSubjMark.size(); i++) {
            if (Mystrcmp(listSubjMark[i]->subj, subjName) == 0) {
                return i;
            }
        }

        listSubjMark.push_back(new SubjMark(subjName));
        return listSubjMark.size() - 1;
    }

public :

    void addSubject(const char* subjName, int idSubj = 0) {
        listSubjMark.push_back(new SubjMark(subjName, idSubj));
    }

    int addMarkToSubj(const char* subjName /*int _idSubj*/, int mark) {
        int numSubj = lookForSub(subjName);

        listSubjMark[numSubj]->marks_list.push_back(mark);
        double temp = 0;
        for(int i = 0; i < listSubjMark.length(); i++)
        {
            temp = 0;
            for(int t = 0; t < listSubjMark.at(i)->marks_list.length(); t++)
                temp = temp + listSubjMark.at(i)->marks_list.at(t);
            temp = temp/listSubjMark.at(i)->marks_list.length();
            listSubjMark.at(i)->averMark = temp;
        }

        return 0;
    }
    void checkstud()
    {
        cout << "Name: " << info->name << endl;
        cout << "Surname: " << info->surname << endl;
        cout << "Age: " << info->age << endl;
        cout << "Num.Tick: " << info->numTicket << endl;
        for(int i = 0; i < listSubjMark.length(); i++)
        {
            cout << "Score " << i << " : " << listSubjMark.at(i)->averMark;
        }
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    return a.exec();
}
