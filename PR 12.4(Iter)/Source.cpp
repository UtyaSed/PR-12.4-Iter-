// ������� ������ �������� ������ � ������ ������� ������������ �� ���������.

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value);
Info remove(Elem*& L);
void process(Elem* L, Elem*& T);
void print(Elem* L);

int main()
{
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

    srand((unsigned)time(NULL));
    Elem* L = NULL;
    Info num;
    for (int i = 1; i <= 10; i++) {
        num = 1 + rand() % 100;
        insert(L, num);
    }
    Elem* T = NULL;
    process(L, T);
    cout << "�������� c�����: " << endl << endl;
    print(T);

    cout << endl;
    cout << "����������� ������: " << endl << endl;
    while (L != NULL) {
        cout << remove(L) << " ";
    }
    cout << endl;
}

void insert(Elem*& L, Info value) // ��������� �������� � ������
{
    Elem* tmp = new Elem; // ��������� ���������� �������� 
    tmp->info = value;
    if (L != NULL) // ���� ������ �� �������
    {
        Elem* T = L; // �� ���� ���������� �������
        while (T->link != L) // ���������� �� ���������� �������� 
            T = T->link; // ������� ���
        T->link = tmp;
    }
    else // ���� ������ �������
    {
        L = tmp;
    }
    tmp->link = L;
}

Info remove(Elem*& L) // ��������� �������� � ������ 
{
    Elem* T = L; // ��������� �������
    while (T->link != L) // ���������� �� ���� ������
        T = T->link;
    Info value = L->info;
    if (T != L)
    {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }
    return value;
}

void print(Elem* L) {
    if (L == NULL)
        return;
    Elem* first = L;
    cout << L->info << " ";
    while (L->link != first)
    {
        L = L->link;
        cout << L->info << " ";
    }
    cout << endl;
}

void process(Elem* L, Elem*& T)
{
    if (L == NULL)
        return;
    Elem* first = L;
    Info k = 1; // ���������� ��������� 
    while (L->link != first) // �������� �� ����������
    {
        k++; // �������� ������� ��������
        L = L->link; // ������� ���
    }
    L = first; // ��������� �� �������
    Info value;
    for (Info j = 0; j < k; j++) {
        Info l = k - j - 1; // ���������� �������� 
        for (Info temp = 0; temp < l; temp++) {
            L = L->link; // ����������� �������
        }
        value = L->info;
        L = first; // ���������� �� �������
        insert(T, value);
    }
}