#include "aghInclude.h"
#include <iostream>

using namespace std;
// ---------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void)
{
    cout << "main by kk. modified by viters. Last updated 21.05.2016\n";

    // ---- testy dla aghDlist - listy podwojnej ----

    cout << "Testy dla aghDlist:\n";

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
        showTestResult(3, false);
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

    // 5th test - sprawdzenie dzialania konstruktora kopiujacego
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

    // 15th test - zwalnianie pamieci
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

    cout << "Finally, this is the end... or isn't?\n";

    // ---- testy dla aghSlist - lista pojedyncza ----

    cout << "\nTesty dla aghSlist:\n";

    aghSlist<aghSlist<int> > slist1;
    aghContainer<int> *slistptr1 = new aghSlist<int>;
    aghContainer<int> *slistptr2;
    slist1 << *((aghSlist<int> *)slistptr1);

    // 16th test - dodawanie do pojemnika stalych, zmiennych, tymczasowych
    slistptr1->append(3);
    slistptr1->insert(0, 1 + 1);
    slistptr1->insert(slistptr1->size(), slistptr1->size());

    bool t16 = slistptr1->size() == 3;
    int ttab16[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t16 = t16 && (ttab16[i] == slistptr1->at(i));
    }

    showTestResult(16, t16);

    // 17th test - konstruktor
    slistptr2 = new aghDlist<int>(*slistptr1);
    bool t17 = slistptr2->size() == 3;
    int ttab17[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t17 = t17 && (ttab17[i] == slistptr2->at(i));
    }
    showTestResult(17, t17);

    // 18th test - odwolania
    try
    {
        slistptr2->at(-1);
        slistptr2->at(100);
        (*slistptr2)[-1];
        (*slistptr2)[100];
        showTestResult(18, false);
    }
    catch (aghException &e)
    {
        showTestResult(18, true);
    }
    catch (...) {
        showTestResult(18, false);
    }

    // 19th test - usuwanie z pojemnika
    slistptr1->clear();
    for (int i = 0; i < 5; i++) {
        *slistptr1 += i;
    }
    *slistptr1 << 4 << 2 + 3;
    slistptr1->remove(2);

    int ttab19[] = {0, 1, 3, 4, 4, 5};
    bool t19 = slistptr1->size() == 6;
    for (int i = 0; t19 && i < 6; i++) {
        t19 = t19 && (ttab19[i] == slistptr1->at(i));
    }
    showTestResult(19, t19);

    // 20th test - sprawdzenie dzialanie konstruktora kopiujacego
    bool t20 = slistptr2->size() == 3;
    int ttab20[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t20 = t20 && (ttab20[i] == slistptr2->at(i));
    }
    showTestResult(20, t20);

    // 21th test - metoda indexOf
    showTestResult(21, slistptr1->indexOf(3) == 2);

    // 22th test - metoda indexOf
    showTestResult(22, slistptr1->indexOf(4, 3) == 3);

    // 23th test - metoda indexOf
    showTestResult(23, slistptr1->indexOf(4, 4) == 4);

    // 24th test - metoda indexOf
    showTestResult(24, slistptr1->indexOf(3, 3) == -1);

    // 25th test - metoda contains
    showTestResult(25, !slistptr1->contains(-6));

    // 26th test - operacje na pojemniku w pojemniku
    for (int i = 3; i >= 0; i--) {
        slist1.at(0) += i + 1;
    }

    bool t26 = slist1.at(0).size() == 4;
    int ttab26[] = {4, 3, 2, 1};
    for (int i = 0; t26 && i < 4; i++) {
        t26 = t26 && (slist1.at(0).at(i) == ttab26[i]);
    }
    showTestResult(26, t26);

    // 27th test - usuwanie z pojemnika
    slist1.at(0).remove(2);   // 4,3,1
    slist1.at(0).remove(1);   // 4,1
    slist1.at(0).remove(1);   // 4
    slist1.at(0).remove(0);   // empty
    showTestResult(27, slist1.at(0).isEmpty());

    // 28th test - dzialanie operatora przypisania
    *slistptr2 = slist1.at(0) = *slistptr1;
    showTestResult(28, *slistptr1 == slist1.at(0));

    // 29th test - operator przypisania
    try
    {
        *slistptr2 = *slistptr2;
        showTestResult(29, *slistptr1 == *slistptr2);
    }
    catch (...)
    {
        showTestResult(29, false);
    }

    // 30th test - zwalnianie pamieci
    try
    {
        delete slistptr1;
        delete slistptr2;
        showTestResult(30, true);
    }
    catch (...)
    {
        showTestResult(30, false);
    }

    cout << "Now it definitely is the end...\n";

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
