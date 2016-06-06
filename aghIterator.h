
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

    aghIterator(aghContainer<T> *);

    aghIterator(const aghIterator<T>& iterator);

    ~aghIterator();

    aghIterator<T> first();

    aghIterator<T> last();

    aghIterator<T> &next();

    aghIterator<T> &prev();

    T &current();

    aghIterator<T> &atFirst();

    aghIterator<T> &atLast();

    int size();

    aghIterator<T> &operator=(aghContainer<T> *);

    aghIterator<T> &operator=(const aghIterator<T> & iterator);

    operator int() const;

    T &operator*();

    T &operator[](int);

    aghIterator<T> operator+(int);

    aghIterator<T> &operator+=(int);

    aghIterator<T> operator-(int);

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

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator() : position(0), iter(nullptr), container(nullptr) {
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator(aghContainer<T> *container) : position(0), iter(nullptr), container(container) {
    if(container->size()>0)
        iter = & container->at(0);
    else
        iter = nullptr;

}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator(const aghIterator<T>& iterator): container(iterator.container), position(iterator.position), iter(iterator.iter){
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::~aghIterator() {
    position = 0;
    iter = nullptr;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::first() {
    aghIterator<T> tmp = *this;
    tmp.setPosition(0);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::last() {
    aghIterator<T> tmp = *this;
    tmp.setPosition(tmp.container->size()-1);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::next() {
    return ++(*this);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::prev() {
    return --(*this);
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::current() {
    if((int)*this == NULL)
        throw aghException(1, "Access to wrong element demanded", __FILE__, __LINE__);
    return this->container->at(position);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atFirst() {
    this->setPosition(0);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atLast() {
    this->setPosition(this->container->size() - 1);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
int aghIterator<T>::size() {
    int size = this->container->size();
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
aghIterator<T> &aghIterator<T>::operator=(const aghIterator<T> & iterator){
    this->container = iterator.container;
    this->position = iterator.position;
    this->iter = iterator.iter; 
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::operator int() const {
    if(!this->container /*|| !this->iter*/ || this->position>=this->container->size() || this->position<0)
        return NULL;
    else
        return 1; //(tymczasowe)
    //TODO: musi cos zwracac w innym przypadku
}

// --------------------------------------------------------------------------------

template<typename T> 
T &aghIterator<T>::operator*() {
    return this->current();
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::operator[](int i) {
    return this->container->at(position+i);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator+(int i) {
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
aghIterator<T> aghIterator<T>::operator-(int i) {
    aghIterator<T> tmp=*this;
    tmp.setPosition(this->position-i);
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
    aghIterator<T> tmp=*this;
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
    if(newPosition>=0 && newPosition< (this->container->size()))
        this->iter = & this->container->at(newPosition);
    this->position = newPosition;
};

// --------------------------------------------------------------------------------

#endif //DATA_CONTAINER_AGHITERATOR_H
