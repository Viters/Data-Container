/**
 * @file aghIterator.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 01/06/2016
 * @version 0.1
 * @brief Contains declaration and definitions of aghIterator template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHITERATOR_H
#define DATA_CONTAINER_AGHITERATOR_H

/**
 * @class aghIterator
 *
 * @brief Class template to provide aghContainer iterators.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 0.1
 *
 * @date 01/06/2016
 */
template<typename T>
class aghIterator {
public:
    aghIterator();
    ~aghIterator();
    aghIterator<T>& first();
    aghIterator<T>& last();
    aghIterator<T>& next();
    aghIterator<T>& prev();
    T& current();
    void atFirst();
    void atLast();
    int size();
    aghIterator<T>& operator=(const aghContainer<T> *);
    operator int() const;
    T& operator*();
    T& operator[](int);
    aghIterator<T>& operator+(int);
    agHIterator<T>& operator+=(int);
    aghIterator<T>& operator-(int);
    aghIterator<T>& operator-=(int);
    aghIterator<T>& operator++();
    aghIterator<T> operator++(int);
    aghIterator<T>& operator--();
    aghIterator<T> operator--(int);
    bool operator==(const aghIterator<T> &);
    bool operator!=(const aghIterator<T> &);
private:
    int position;
    aghContainer<T> * iter;
};

template<typename T>
aghIterator<T>::aghIterator():position(0), iter(nullptr){
}

template<typename T>
aghIterator<T>::~aghIterator(){
    position=0;
    iter=nullptr;
}

aghIterator& aghIterator<T>

#endif //DATA_CONTAINER_AGHITERATOR_H
