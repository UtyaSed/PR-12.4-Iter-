// ѕом≥н€ти м≥сц€ми елементи списку Ц зм≥нити пор€док розташуванн€ на зворотний.

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
    SetConsoleCP(1251); // встановленн€ стор≥нки win-cp1251 в пот≥к вводу
    SetConsoleOutputCP(1251); // встановленн€ стор≥нки win-cp1251 в пот≥к виводу

    srand((unsigned)time(NULL));
    Elem* L = NULL;
    Info num;
    for (int i = 1; i <= 10; i++) {
        num = 1 + rand() % 100;
        insert(L, num);
    }
    Elem* T = NULL;
    process(L, T);
    cout << "«воротн≥й cписок: " << endl << endl;
    print(T);

    cout << endl;
    cout << "ќриг≥нальний список: " << endl << endl;
    while (L != NULL) {
        cout << remove(L) << " ";
    }
    cout << endl;
}

void insert(Elem*& L, Info value) // додаванн€ елементу у список
{
    Elem* tmp = new Elem; // створенн€ допом≥жного елемента 
    tmp->info = value;
    if (L != NULL) // якщо список не порожн≥й
    {
        Elem* T = L; // ще один допомом≥жий елемент
        while (T->link != L) // скануванн€ до останнього елементу 
            T = T->link; // перех≥д дал≥
        T->link = tmp;
    }
    else // якщо список порожн≥й
    {
        L = tmp;
    }
    tmp->link = L;
}

Info remove(Elem*& L) // видаленн€ елементу з≥ списку 
{
    Elem* T = L; // допом≥жний елемент
    while (T->link != L) // скануванн€ до к≥нц€ списку
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
    Info k = 1; // оголошенн€ л≥чильника 
    while (L->link != first) // перев≥рка до останнього
    {
        k++; // л≥чильник к≥лькост≥ елемент≥в
        L = L->link; // перех≥д дал≥
    }
    L = first; // поврненн€ на початок
    Info value;
    for (Info j = 0; j < k; j++) {
        Info l = k - j - 1; // визначенн€ елементу 
        for (Info temp = 0; temp < l; temp++) {
            L = L->link; // знаходитьс€ елемент
        }
        value = L->info;
        L = first; // поверненн€ на початок
        insert(T, value);
    }
}