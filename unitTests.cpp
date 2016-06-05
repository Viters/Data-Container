#include "aghInclude.h"
#include <iostream>

using namespace std;

void showTestResult(int number, bool result) {
    if (result) {
        cout << "[" << number << "] PASSED\n";
    }
    else {
        cout << "[" << number << "] FAILED\n";
    }
}

int main(void) {
    // -----------------------------------------------
    // ------ aghDlist tests - double-sided list -----
    // -----------------------------------------------

    cout << "Testing aghDlist:\n";

    aghDlist<aghDlist<int> > a;
    aghContainer<int> *c1 = new aghDlist<int>;
    aghContainer<int> *c2;
    a << *((aghDlist<int> *) c1);

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
    try {
        c2->at(-1);
        c2->at(100);
        (*c2)[-1];
        (*c2)[100];
        showTestResult(3, false);
    }
    catch (aghException &e) {
        showTestResult(3, true);
    }
    catch (...) {
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
    try {
        *c2 = *c2;
        showTestResult(14, *c1 == *c2);
    }
    catch (...) {
        showTestResult(14, false);
    }

    // 15th test - zwalnianie pamieci
    try {
        delete c1;
        delete c2;
        showTestResult(15, true);
    }
    catch (...) {
        showTestResult(15, false);
    }

    // -----------------------------------------------
    // ------ aghSlist tests - single-sided list -----
    // -----------------------------------------------

    cout << "\nTesting aghSlist:\n";

    aghSlist<aghSlist<int> > slist1;
    aghContainer<int> *slistptr1 = new aghSlist<int>;
    aghContainer<int> *slistptr2;
    slist1 << *((aghSlist<int> *) slistptr1);

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
    slistptr2 = new aghSlist<int>(*slistptr1);
    bool t17 = slistptr2->size() == 3;
    int ttab17[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t17 = t17 && (ttab17[i] == slistptr2->at(i));
    }
    showTestResult(17, t17);

    // 18th test - odwolania
    try {
        slistptr2->at(-1);
        slistptr2->at(100);
        (*slistptr2)[-1];
        (*slistptr2)[100];
        showTestResult(18, false);
    }
    catch (aghException &e) {
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
    try {
        *slistptr2 = *slistptr2;
        showTestResult(29, *slistptr1 == *slistptr2);
    }
    catch (...) {
        showTestResult(29, false);
    }

    // 30th test - zwalnianie pamieci
    try {
        delete slistptr1;
        delete slistptr2;
        showTestResult(30, true);
    }
    catch (...) {
        showTestResult(30, false);
    }

    // -----------------------------------------------
    // ------ aghVector tests - vector container -----
    // -----------------------------------------------

    cout << "\nTesting aghVector:\n";

    aghVector<aghVector<int> > vector1;
    aghContainer<int> *vectorptr1 = new aghVector<int>;
    aghContainer<int> *vectorptr2;
    vector1 << *((aghVector<int> *) vectorptr1);

    // 31th test - dodawanie do pojemnika stalych, zmiennych, tymczasowych
    vectorptr1->append(3);
    vectorptr1->insert(0, 1 + 1);
    vectorptr1->insert(vectorptr1->size(), vectorptr1->size());

    bool t31 = vectorptr1->size() == 3;
    int ttab31[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t31 = t31 && (ttab31[i] == vectorptr1->at(i));
    }

    showTestResult(31, t31);

    // 32th test - konstruktor
    vectorptr2 = new aghVector<int>(*vectorptr1);
    bool t32 = vectorptr2->size() == 3;
    int ttab32[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t32 = t32 && (ttab32[i] == vectorptr2->at(i));
    }
    showTestResult(32, t32);

    // 33th test - odwolania
    try {
        vectorptr2->at(-1);
        vectorptr2->at(100);
        (*vectorptr2)[-1];
        (*vectorptr2)[100];
        showTestResult(33, false);
    }
    catch (aghException &e) {
        showTestResult(33, true);
    }
    catch (...) {
        showTestResult(33, false);
    }

    // 34th test - usuwanie z pojemnika
    vectorptr1->clear();
    for (int i = 0; i < 5; i++) {
        *vectorptr1 += i;
    }
    *vectorptr1 << 4 << 2 + 3;
    vectorptr1->remove(2);

    int ttab34[] = {0, 1, 3, 4, 4, 5};
    bool t34 = vectorptr1->size() == 6;
    for (int i = 0; t34 && i < 6; i++) {
        t34 = t34 && (ttab34[i] == vectorptr1->at(i));
    }
    showTestResult(34, t34);

    // 35th test - sprawdzenie dzialanie konstruktora kopiujacego
    bool t35 = vectorptr2->size() == 3;
    int ttab35[] = {2, 3, 2};
    for (int i = 0; i < 3; i++) {
        t35 = t35 && (ttab35[i] == vectorptr2->at(i));
    }
    showTestResult(35, t35);

    // 36th test - metoda indexOf
    showTestResult(36, vectorptr1->indexOf(3) == 2);

    // 37th test - metoda indexOf
    showTestResult(37, vectorptr1->indexOf(4, 3) == 3);

    // 38th test - metoda indexOf
    showTestResult(38, vectorptr1->indexOf(4, 4) == 4);

    // 39th test - metoda indexOf
    showTestResult(39, vectorptr1->indexOf(3, 3) == -1);

    // 40th test - metoda contains
    showTestResult(40, !vectorptr1->contains(-6));

    // 41th test - operacje na pojemniku w pojemniku
    for (int i = 3; i >= 0; i--) {
        vector1.at(0) += i + 1;
    }

    bool t41 = vector1.at(0).size() == 4;
    int ttab41[] = {4, 3, 2, 1};
    for (int i = 0; t41 && i < 4; i++) {
        t41 = t41 && (vector1.at(0).at(i) == ttab41[i]);
    }
    showTestResult(41, t41);

    // 42th test - usuwanie z pojemnika
    vector1.at(0).remove(2);   // 4,3,1
    vector1.at(0).remove(1);   // 4,1
    vector1.at(0).remove(1);   // 4
    vector1.at(0).remove(0);   // empty
    showTestResult(42, vector1.at(0).isEmpty());

    // 43th test - dzialanie operatora przypisania
    *vectorptr2 = vector1.at(0) = *vectorptr1;
    showTestResult(43, *vectorptr1 == vector1.at(0));

    // 44th test - operator przypisania
    try {
        *vectorptr2 = *vectorptr2;
        showTestResult(44, *vectorptr1 == *vectorptr2);
    }
    catch (...) {
        showTestResult(44, false);
    }

    // 45th test - zwalnianie pamieci
    try {
        delete vectorptr1;
        delete vectorptr2;
        showTestResult(45, true);
    }
    catch (...) {
        showTestResult(45, false);
    }

    // -----------------------------------------------
    // --- aghIterator tests - container iterators ---
    // -----------------------------------------------

    cout << "\nTesting aghIterator:\n";

    aghVector<int> vector3, vector4;
    aghContainer<int> *contptr = &vector3;
    aghIterator<int> iter1(&vector3), iter2(&vector4), iter3(contptr);

    vector3.append(1);
    vector3.append(2);
    vector3.append(3);
    vector3.append(4);
    vector3.append(5);

    vector4.append(6);
    vector4.append(7);
    vector4.append(8);
    vector4.append(9);
    vector4.append(10);

    // 46st test - iterators setting up v1
    showTestResult(46, iter1.current() == vector3.at(0));

    // 47nd test - iterators setting up v2
    showTestResult(47, iter2.current() == vector4.at(0));

    // 48rd test - next method
    iter1.next();
    showTestResult(48, iter1.current() == vector3.at(1));

    // 49th test - prev method
    iter2.prev();
    try {
        iter2.current();
        showTestResult(49, false);
    }
    catch (aghException &e) {
        showTestResult(49, true);
    }
    catch (...) {
        showTestResult(49, false);
    }

    // 50th test - first method
    showTestResult(50, (iter1.first().current() == vector3.at(0)) && (iter1.current() == vector3.at(1)));

    // 51th test - last method
    showTestResult(51, (iter3.last().current() == vector3.at(vector3.size() - 1)) && (iter3.current() == vector3.at(0)));

    // 52th test - atFirst method
    iter1.atFirst();
    showTestResult(52, iter1.current() == vector3.at(0));

    // 53th test - atLast method
    iter2.atLast();
    showTestResult(53, iter2.current() == vector4.at(vector4.size() - 1));

    // 54th method - size method
    iter3.atFirst();
    iter3.next().next();
    showTestResult(54, iter3.size() == (vector3.size() - 2));

    // 55th test - operator []
    iter3.atFirst();
    bool t55 = (iter3[2] == vector3.at(2));
    t55 = t55 && (iter3.current() == vector3.at(0));
    t55 = t55 && (iter3.next().next()[1] == vector3.at(3));
    t55 = t55 && (iter3.current() == vector3.at(2));
    t55 = t55 && (iter3[-1] == vector3.at(1));
    showTestResult(55, t55);

    // 56th test - operator int
    iter3.atFirst();
    iter3.prev();
    bool t56 = ((int) iter3 == NULL);
    iter3.next().next().next();
    t56 = t56 && ((int) iter3 != NULL);
    iter3.atLast();
    iter3.next();
    t56 = t56 && ((int) iter3 == NULL);
    showTestResult(56, t56);

    // 57th - test operator*
    iter1.atFirst();
    bool t57 = (*iter1 == vector3.at(0));
    t57 = t57 && (*iter1.next().last() == vector3.at(vector3.size() - 1));
    t57 = t57 && (*iter1 == vector3.at(1));
    *iter1 += 10;
    t57 = t57 && (vector3.at(1) == 57);
    iter1.current() = 2;
    t57 = t57 && (*iter1 == 2);
    showTestResult(57, t57);

    // 58th test - operator+
    iter2.atFirst();
    bool t58 = (*(iter2 + 2) == vector4.at(2));
    try {
        *(iter2.atLast() + 1);
    }
    catch (aghException &e) {
        t58 = t58 && true;
    }
    catch (...) {
        t58 = t58 && false;
    }
    showTestResult(58, t58);

    // 59th test - operator-
    iter2.atLast();
    bool t59 = (*(iter2 - 3) == vector4.at(1));
    try {
        *(iter2.first() - 1);
    }
    catch (aghException &e) {
        t59 = t59 && true;
    }
    catch (...) {
        t59 = t59 && false;
    }
    showTestResult(59, t59);

    // 60th test - operator += and -=
    iter1.atFirst();
    iter1 += 2;
    bool t60 = (*iter1 == vector3.at(2));
    iter1 += 1;
    t60 = t60 && (*iter1 == vector3.at(3));
    iter1 -= 3;
    t60 = t60 && (*iter1 == vector3.at(0));
    try {
        iter1 -= 1;
    }
    catch (...) {
        t60 = false;
    }
    showTestResult(60, t60);

    // 61th test - operators ++
    iter3.atFirst();
    bool t61 = (*iter3++ == contptr->at(0));
    t61 = t61 && (*iter3 == contptr->at(1));
    t61 = t61 && (*++iter3 == contptr->at(2));
    t61 = t61 && (*iter3 == contptr->at(2));
    showTestResult(61, t61);

    // 62th test - operators --
    iter3.atLast();
    bool t62 = (*iter3-- == contptr->at(contptr->size() - 1));
    t62 = t62 && (*iter3 == contptr->at(contptr->size() - 2));
    t62 = t62 && (*--iter3 == contptr->at(contptr->size() - 3));
    t62 = t62 && (*iter3 == contptr->at(contptr->size() - 3));
    showTestResult(62, t62);

    // 63th test - operator == and !=
    iter1.atFirst();
    iter2.atFirst();
    iter3.atFirst();
    bool t63 = (iter1 == iter3);
    t63 = t63 && (iter1 != iter2);
    t63 = t63 && (iter2 != iter3);
    t63 = t63 && (iter1 != (iter3 + 1));
    iter1.next();
    t63 = t63 && (iter1 == (iter3 + 1));
    iter2.next();
    t63 = t63 && (iter1 != iter2);
    iter1.atFirst();
    iter3.atLast();
    t63 = t63 && ((iter1 + 2) == (iter3 - 2));
    iter3.prev();
    t63 = t63 && (*(iter1 + 2) == *(iter3 - 1));
    showTestResult(63, t63);

    // 64th test - operator =
    iter1.atFirst();
    iter2.atFirst().next();
    iter3.atLast();
    iter1 = iter3;
    bool t64 = (iter1 == iter3);
    t64 = t64 && (iter1 != iter2);
    t64 = t64 && (iter1.size() == 1);
    iter1 = iter2;
    t64 = t64 && (iter1 == iter2);
    t64 = t64 && (*iter1 == vector4.at(1));
    showTestResult(64, t64);

    // 65th test - operator =
    iter1.atLast();
    iter2.atLast();
    iter3.atLast();
    bool t65 = (iter1 == iter2);
    iter1 = contptr;
    t65 = t65 && (iter1 != iter2);
    t65 = t65 && (iter1 != iter3);
    t65 = t65 && (iter1 == iter3.first());
    t65 = t65 && (*iter1 == vector3.at(0));
    iter1.atLast();
    t65 = t65 && (iter1 == iter3);
    t65 = t65 && (iter1 != iter2);
    showTestResult(65, t65);

    return 0;
}
