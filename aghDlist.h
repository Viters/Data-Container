/**
 * @file aghDlist.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 19|05|2016
 * @version 0.1
 * @brief Contains declaration and definition of aghDlist template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHLIST_H
#define DATA_CONTAINER_AGHLIST_H

#include "aghContainer.h"
#include <iostream>

using namespace std;

/**
 * Class template to provide operations on double-sided list
*/
template<typename T>
class aghDlist :
         public aghContainer<T> {
public:
    aghDlist();

    aghDlist(const aghContainer<T> &);

    ~aghDlist();

    /**
     * Insert an element at specified position.
     * @param position number
     * @param new element
     */
    bool insert(const int, const T &);

    /**
     * Remove element at specified position.
     * @param position number
     * @return bool
     */
    bool remove(const int);

    /**
     * Remove all elements from the container.
     */
    void clear(void);

    /**
     * Make copy of another container
     *
     * @param another container
     */
    void copy(const aghContainer<T> &source);
