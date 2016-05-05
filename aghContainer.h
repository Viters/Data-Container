//
// Created by sir.viters on 2016-05-05.
//

#ifndef DATA_CONTAINER_AGHCONTAINER_H
#define DATA_CONTAINER_AGHCONTAINER_H

#include <iostream>

using namespace std;

template<typename T>
class aghContainer {
public:
    virtual void append(T const &) = 0;

    virtual bool insert(const int, T const &) = 0;

    virtual bool replace(const int, T const &) = 0;

    virtual T &at(const int) const = 0;

    virtual int size(void) const = 0;

    virtual bool remove(const int) = 0;

    virtual void clear(void) = 0;

    virtual bool isEmpty(void) = 0;

    virtual int indexOf(T const &_value, int _from = 0) const = 0;

    virtual bool contains(T const &_value, int _from = 0) const = 0;

    virtual bool operator==(aghContainer<T> const& right) = 0;

    virtual bool operator!=(aghContainer<T> const& right) = 0;

    virtual T& operator[](int n) const = 0;

    virtual aghContainer<T>& operator+=(aghContainer<T> const& right) = 0;

    virtual aghContainer<T>& operator+=(T const& element) = 0;

    virtual aghContainer<T>& operator<<(T const& element) = 0;

    virtual aghContainer<T>& operator<<(aghContainer<T> const& right) = 0;

    virtual ostream& operator<<(ostream&, aghContainer<T> const& right) = 0;
};


#endif //DATA_CONTAINER_AGHCONTAINER_H
