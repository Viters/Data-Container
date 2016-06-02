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
    first();
    last();
    next();
    prev();
    current();
    atFirst();
    atLast();
    size();
    operator=(const aghContainer<T> *);
    operator int() const;
    T& operator*();
    T& operator[](int);
    operator+(int);
    operator-(int);
    operator+=(int);
    operator-=(int);
    operator++();
    aghIterator& operator++(int);
    operator--();
    operator--(int);
    bool operator==(const aghIterator<T> &);
    bool operator!=(const aghIterator<T> &);
private:
    int position;
    aghContainer * iter;
};


#endif //DATA_CONTAINER_AGHITERATOR_H
