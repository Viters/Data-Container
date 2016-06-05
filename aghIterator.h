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
    aghIterator(aghContainer<T> *);

    ~aghIterator();

    aghIterator<T> &first();

    aghIterator<T> &last();

    aghIterator<T> &next();

    aghIterator<T> &prev();

    T &current();

    aghIterator<T> &atFirst();

    aghIterator<T> &atLast();

    int size();

    aghIterator<T> &operator=(aghContainer<T> *);

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
    aghContainer<T> *container;
    T *iter;

    void setPosition(int);
};

// --------------------------------------------------------------------------------
// End of aghIterator declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator(aghContainer<T> *container) : position(0), iter(nullptr), container(container) {
    this->atFirst();
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
    return this->container->at(0);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::last() {
    int lastPosition = this->container->size() - 1;
    return this->container->at(lastPosition);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::next() {
    return *this->iter;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::prev() {
    return *this->iter;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::current() {
    return *this->iter;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atFirst() {
    this->position = 0;
    return this->first();
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atLast() {
    this->position = this->container->size() - 1;
    return this->last();
}

// --------------------------------------------------------------------------------

template<typename T>
int aghIterator<T>::size() {
    int size = this->container->size() - 1;
    return size - this->position;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator=(aghContainer<T> *container) {
    this->container = container;
    if (this->container->size()!=0)
        this->atFirst();
    else
        this->iter=nullptr;
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::operator int() const {
    if(!this->container || !this->iter)
        return NULL;
    //TODO: musi cos zwracac w innym przypadku
}

// --------------------------------------------------------------------------------

template<typename T> 
T &aghIterator<T>::operator*() {
    if((int)*this == NULL)
        throw aghException(1, "Iterator is not correct", __FILE__, __LINE__);
    return *this->iter;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::operator[](int i) {
    return this->container->at(position+i);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator+(int i) {
    aghIterator<T> tmp=*this;
    tmp.setPosition(this->position+i);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator+=(int i) {
    return *this=*this+i;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator-(int i) {
    aghIterator<T> tmp=*this;
    tmp.setPosition(this->position+i);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator-=(int i) {
    return *this=*this-i;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator++() {
    this->setPosition(position+1);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator++(int i) {
    aghIterator<T> tmp=*this;
    ++(*this);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator--() {
    this->setPosition(position-1);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator--(int i) {
    aghIterator<T> tmp;
    --(*this);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghIterator<T>::operator==(const aghIterator<T> &iterator) {
    if(this->container == iterator.container && this->iter == iterator.iter && this->position == iterator.position)
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghIterator<T>::operator!=(const aghIterator<T> &iterator) {
    return !(*this==iterator);
}

// --------------------------------------------------------------------------------

template<typename T>
void aghIterator<T>::setPosition(int newPosition){
    this->iter = & this->container->at(newPosition);
    this->posistion = newPosition;
};

// --------------------------------------------------------------------------------

#endif //DATA_CONTAINER_AGHITERATOR_H
