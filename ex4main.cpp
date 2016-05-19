#include "aghInclude.h"
#include <iostream>

using namespace std;
// ---------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void)
{
    cout << "main by kk. Last updated 15.04.2013\n";

    aghDlist<aghDlist<int> > a;
    aghContainer<int> *c1 = new aghDlist<int>;
    aghContainer<int> *c2;
    a << *((aghDlist<int> *)c1);

    // 1st test - dodawanie do pojemnika stalych, zmiennych, tymczasowych
    c1->append(3);
    c1->insert(0, 1 + 1);
    c1->insert(c1->size(), c1->size());

    bool t1 = c1->size() == 3;
    int ttab1[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t1 = t1 && (ttab1[i] == c1->at(i));
    }
    showTestResult(1, t1);

    // 2nd test - konstruktor
    c2 = new aghDlist<int>(*c1);
    bool t2 = c2->size() == 3;
    int ttab2[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t2 = t2 && (ttab2[i] == c2->at(i));
    }
    showTestResult(2, t2);

    // 3rd test - odwolania
    try
    {
        c2->at(-1);
        c2->at(100);
        (*c2)[-1];
        (*c2)[100];
        showTestResult(3, true);
    }
    catch (aghException &e)
    {
        showTestResult(3, true);
    }
    catch (...)
    {
        showTestResult(3, false);
    }

    // 4th test - usuwanie z pojemnika
    c1->clear();
    for (int i = 0; i < 5; i++) {
        *c1 += i;
    }
    *c1 << 4 << 2 + 3;
    c1->remove(2);

    int ttab4[] = {0, 1, 3, 4, 4, 5};
    bool t4 = c1->size() == 6;
    for (int i = 0; t4 && i < 6; i++) {
        t4 = t4 && (ttab4[i] == c1->at(i));
    }
    showTestResult(4, t4);

    // 5th test - sprawdzenie dzialanie konstruktora kopiujacego
    bool t5 = c2->size() == 3;
    int ttab5[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t5 = t5 && (ttab5[i] == c2->at(i));
    }
    showTestResult(5, t5);

    // 6th test - metoda indexOf
    showTestResult(6, c1->indexOf(3) == 2);

    // 7th test - metoda indexOf
    showTestResult(7, c1->indexOf(4, 3) == 3);

    // 8th test - metoda indexOf
    showTestResult(8, c1->indexOf(4, 4) == 4);

    // 9th test - metoda indexOf
    showTestResult(9, c1->indexOf(3, 3) == -1);

    // 10th test - metoda contains
    showTestResult(10, !c1->contains(-6));


    // 11th test - operacje na pojemniku w pojemniku
    for (int i = 3; i >= 0; i--) {
        a.at(0) += i + 1;
    }

    bool t11 = a.at(0).size() == 4;
    int ttab11[] = {4, 3, 2, 1};
    for (int i = 0; t11 && i < 4; i++) {
        t11 = t11 && (a.at(0).at(i) == ttab11[i]);
    }
    showTestResult(11, t11);

    // 12th test - usuwanie z pojemnika
    a.at(0).remove(2);   // 4,3,1
    a.at(0).remove(1);   // 4,1
    a.at(0).remove(1);   // 4
    a.at(0).remove(0);   // empty
    showTestResult(12, a.at(0).isEmpty());

    // 13th test - dzialanie operatora przypisania
    *c2 = a.at(0) = *c1;
    showTestResult(13, *c1 == a.at(0));

    // 14th test - operator przypisania
    try
    {
        *c2 = *c2;
        showTestResult(14, *c1 == *c2);
    }
    catch (...)
    {
        showTestResult(14, false);
    }

    // 15th test - zwalnianie paieci
    try
    {
        delete c1;
        delete c2;
        showTestResult(15, true);
    }
    catch (...)
    {
        showTestResult(15, false);
    }

    cout << "Finally, this is the end...\n";

    return 0;
}
// ---------------------------------------------------------

void showTestResult(int _ti, bool _r)
{
    if (_r) {
        cout << "Test" << _ti << " PASSED\n";
    }
    else {
        cout << "Test" << _ti << " FAILED\n";
    }
}
// ---------------------------------------------------------
