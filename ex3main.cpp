#define CATCH_CONFIG_MAIN
#include "catch.h"

#include "aghInclude.h"
#include <iostream>

// ---------------------------------------------------------
using namespace std;

TEST_CASE( "wektory spełniają wymagania podane na wiki", "[aghVector]" ) {
    aghVector<aghVector<int> > a;

    aghContainer<int> *c1 = new aghVector<int>;
    aghContainer<int> *c2;
    a << *((aghVector<int> *)c1);

    c1->append(3);
    c1->insert(0, 1 + 1);
    c1->insert(c1->size(), c1->size());


    SECTION( "dodawanie do pojemnika stalych, zmiennych, tymczasowych" ) {
        REQUIRE( c1->size() == 3 );
        int ttab1[] = {2, 3, 2};
        for (int i = 0; i < 3; i++) {
            REQUIRE( ttab1[i] == c1->at(i) );
        }
    }

    SECTION( "konstruktor kopiujący" ) {
        c2 = new aghVector<int>(*c1);

        REQUIRE( c2->size() == 3 );
        int ttab1[] = {2, 3, 2};
        for (int i = 0; i < 3; i++) {
            REQUIRE( ttab1[i] == c2->at(i) );
        }

        delete c2;
    }

    SECTION( "wyrzucanie wyjątków" ) {
        REQUIRE_THROWS_AS( c1->at(-1), aghException );
        REQUIRE_THROWS_AS( c1->at(100), aghException );
        REQUIRE_THROWS_AS( c1->at(c1->size()), aghException );
        REQUIRE_THROWS_AS( (*c1)[-10], aghException );
        REQUIRE_THROWS_AS( (*c1)[100], aghException );
    }

    SECTION( "usuwanie z pojemnika" ) {
        c1->clear();
        for (int i = 0; i < 5; i++) {
            *c1 += i;
        }
        *c1 << 4 << 2 + 3;
        c1->remove(2);

        int ttab4[] = {0, 1, 3, 4, 4, 5};
        REQUIRE( c1->size() == 6 );

        for (int i = 0; i < 6 ; i++) {
            REQUIRE( ttab4[i] == c1->at(i) );
        }
    }

    SECTION ( "sprawdzanie zawartości kontenera" ) {
        REQUIRE( c1->indexOf(3) == 1  );
        REQUIRE( c1->indexOf(3, 2) == -1 );
        REQUIRE( c1->indexOf(2, 0) == 0 );
        REQUIRE( c1->indexOf(2, 1) == 2 );
        REQUIRE( c1->indexOf(2, 4) == -1 );
        REQUIRE( !c1->contains(-6) );
    }

    SECTION ( "operacje na pojemniku w pojemniku" ) {

        for (int i = 3; i >= 0; i--) {
            a.at(0) += i + 1;
        }

        REQUIRE( a.at(0).size() == 4 );
        int ttab11[] = {4, 3, 2, 1};
        for (int i = 0; i < 4; i++) {
            REQUIRE( a.at(0).at(i) == ttab11[i] );
        }

        SECTION ( "operacje usuwania elementow" ) {
            REQUIRE( !a.at(0).isEmpty() );
            a.at(0).remove(2);   // 4,3,1
            REQUIRE( !a.at(0).isEmpty() );
            a.at(0).remove(1);   // 4,1
            REQUIRE( !a.at(0).isEmpty() );
            a.at(0).remove(1);   // 4
            REQUIRE( !a.at(0).isEmpty() );
            a.at(0).remove(0);   // empty
            REQUIRE( a.at(0).isEmpty() );
        }
    }

    SECTION( "operator przypisania" ) {
        c2 = new aghVector<int>();
        *c2  = a.at(0) = *c1;
        REQUIRE( *c1 == a.at(0) );
        *c2 = *c2;
        REQUIRE( *c1 == *c2);
        delete c2;
    }

    delete c1;
}