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
     * Get element at specified position
     * @param position number
     * @return reference to the value
     */
    T & at(const int) const;

    /**
     * Get size of the container.
     * @return int size
     */
    int size(void) const;

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

    /**
     * Assignment operator
     *
     * @param another vector
     * @return reference to the object
     */
    aghContainer<T> &operator=(const aghContainer<T> &);

private:
    struct Node{
        T value;
        Node * next;
        Node * prev;

        Node(T value, Node* next = nullptr, Node* prev = nullptr) : value(value), next(next), prev(prev) {}
    };
    Node * head;
    Node * tail;
    unsigned int elements;
};

// --------------------------------------------------------------------------------
// End of aghDlist declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghDlist::aghDlist() : head(nullptr), tail(nullptr), elements(0) {}

// --------------------------------------------------------------------------------

template<typename T>
aghDlist::aghDlist(const aghContainer<T> &container) : head(nullptr) {
    this->copy(container);
}

// --------------------------------------------------------------------------------

template<typename T>
aghDlist::~aghDlist() {

}

// --------------------------------------------------------------------------------

template<typename T>
bool aghDlist::insert(const int index, const T& value) {
    
}

// --------------------------------------------------------------------------------

template<typename T>
T & aghDlist::at(const int pos) const {

}

// --------------------------------------------------------------------------------

template<typename T>
int aghDlist::size(void) const {
    return this->elements;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghDlist::remove(const int pos) {
}

// --------------------------------------------------------------------------------

template<typename T>
void aghDlist::clear(void) {

}

// --------------------------------------------------------------------------------

template<typename T>
void aghDlist::copy(const aghContainer<T> &source) {
    
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghDlist::operator=(const aghContainer<T> &container) {
    
}

// --------------------------------------------------------------------------------

#endif
