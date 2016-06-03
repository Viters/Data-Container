/**
 * @file aghIterator.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 01/06/2016
 * @version 0.2
 * @brief Contains declaration and definitions of aghIterator template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHITERATOR_H
#define DATA_CONTAINER_AGHITERATOR_H

#include "aghContainer.h"

/**
 * @class aghIterator
 *
 * @brief Class template to provide aghContainer iterators.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 0.2
 *
 * @date 01/06/2016
 */
template<typename T>
class aghIterator {
public:
    aghIterator();

    aghIterator(const aghContainer<T> *);

    ~aghIterator();

    aghIterator<T> &first();

    aghIterator<T> &last();

    aghIterator<T> &next();

    aghIterator<T> &prev();

    T &current();

    aghIterator<T> &atFirst();

    aghIterator<T> &atLast();

    int size();

    aghIterator<T> &operator=(const aghContainer<T> *);

    operator int() const;

    T &operator*();

    T &operator[](int);

    aghIterator<T> &operator+(int);

    aghIterator<T> &operator+=(int);

    aghIterator<T> &operator-(int);

    aghIterator<T> &operator-=(int);

    aghIterator<T> &operator++();

    aghIterator<T> operator++(int);

    aghIterator<T> &operator--();

    aghIterator<T> operator--(int);

    bool operator==(const aghIterator<T> &);

    bool operator!=(const aghIterator<T> &);

private:
    int position;
    aghContainer<T> *iter;
};

// --------------------------------------------------------------------------------
// End of aghIterator declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator() : position(0), iter(nullptr) {
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator(const aghContainer<T> *container) : position(0), iter(nullptr) {
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::~aghIterator() {
    position = 0;
    iter = nullptr;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::first() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::last() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::next() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::prev() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::current() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atFirst() {

}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atLast() {

}

// --------------------------------------------------------------------------------

template<typename T>
int aghIterator<T>::size() {
    return 0;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator=(const aghContainer<T> *container) {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::operator int() const {
    return 0;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::operator*() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::operator[](int i) {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator+(int i) {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator+=(int i) {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator-(int i) {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator-=(int i) {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator++() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator++(int i) {
    return aghIterator();
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator--() {
    return <#initializer#>;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator--(int i) {
    return aghIterator();
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghIterator<T>::operator==(const aghIterator<T> &iterator) {
    return false;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghIterator<T>::operator!=(const aghIterator<T> &iterator) {
    return false;
}

// --------------------------------------------------------------------------------

#endif //DATA_CONTAINER_AGHITERATOR_H