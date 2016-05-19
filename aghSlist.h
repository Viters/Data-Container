/**
 * @file aghSlist.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 19|05|2016
 * @version 0.1
 * @brief Contains declaration and definition of aghSlist template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHSLIST_H
#define DATA_CONTAINER_AGHSLIST_H

#include "aghContainer.h"
#include <iostream>

using namespace std;

/**
 * Class template to provide operations on single-sided list.
*/
template<typename T>
class aghSlist :
        public aghContainer<T> {
public:
    aghSlist();

    aghSlist(const aghContainer<T> &);

    ~aghSlist();

    /**
    * Insert an element at specified position.
    * @param position number
    * @param new element
    */
    bool insert(const int, const T &);

    /**
     * Get element at specified position.
     * @param position number
     */
    T &at(const int) const;

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
     * Make copy of another containe
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
    struct Node {
        T value;
        listElem next;

        Node(T value, listElem next = nullptr) : value(value), next(next) { }
    };

    listElem head;
    listElem tail;

    unsigned int elements;

    typedef Node *listElem;
};

// --------------------------------------------------------------------------------
// End of aghSlist declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghSlist::aghSlist() : head(nullptr), tail(nullptr), elements(0) { }

// --------------------------------------------------------------------------------

template<typename T>
aghSlist::aghSlist(const aghContainer<T> &container) : head(nullptr), tail(nullptr) {
    this->copy(container);
}

// --------------------------------------------------------------------------------

template<typename T>
aghSlist::~aghSlist() {

}

// --------------------------------------------------------------------------------

template<typename T>
bool aghSlist::insert(const int index, const T &value) {
    if (index > this->elements || index < 0)
        return false;

    if (index > 0) {
        listElem oldElem = this->at(index - 1);
        listElem newElem = new Node(value, oldElem->next);
        oldElem->next = newElem;

        if (index == this->size())
            this->tail = newElem;
    }
    else {
        listElem oldElem = this->at(0);
        listElem newElem = new Node(value, oldElem);
        this->head = newElem;
    }

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghSlist::at(const int pos) const {
    if (pos < 0 || pos >= this->elements)
        throw aghException(1, "Wrong index demanded", __FILE__, __LINE__);

    bool callForLast = (pos == this->size() - 1);

    if (callForLast) {
        return *(this->tail);
    }
    else {
        listElem iter = this->head;
        for (int i = 0; i < pos; ++i) {
            iter = iter->next;
        }
        return *iter;
    }
}

// --------------------------------------------------------------------------------

template<typename T>
int aghSlist::size(void) const {
    return this->elements;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghSlist::remove(const int i) {
    return false;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghSlist::clear(void) {

}

// --------------------------------------------------------------------------------

template<typename T>
void aghSlist::copy(const aghContainer<T> &source) {

}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghSlist::operator=(const aghContainer<T> &container) {
    return aghContainer::operator=(container);
}

// --------------------------------------------------------------------------------

#endif