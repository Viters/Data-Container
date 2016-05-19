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
    template<typename Y>
    struct Node {
        Y value;
        Node<Y> *next;

        Node(Y value, Node<Y> *next = nullptr) : value(value), next(next) { }
    };

    typedef Node<T> *listElem;

    listElem head;
    listElem tail;

    unsigned int elements;
};

// --------------------------------------------------------------------------------
// End of aghSlist declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghSlist<T>::aghSlist() : head(nullptr), tail(nullptr), elements(0) { }

// --------------------------------------------------------------------------------

template<typename T>
aghSlist<T>::aghSlist(const aghContainer<T> &container) : head(nullptr), tail(nullptr) {
    this->copy(container);
}

// --------------------------------------------------------------------------------

template<typename T>
aghSlist<T>::~aghSlist() {
    this->clear();
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghSlist<T>::insert(const int index, const T &value) {
    if (index > this->elements || index < 0)
        return false;

    listElem oldElem;
    listElem newElem;

    if (index > 0) {
        oldElem = this->at(index - 1);
        newElem = new Node<T>(value, oldElem->next);
        oldElem->next = newElem;
    }
    else {
        oldElem = this->at(0);
        newElem = new Node<T>(value, oldElem);
        this->head = newElem;
    }

    if (index == this->size())
        this->tail = newElem;

    ++elements;

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghSlist<T>::at(const int index) const {
    if (index < 0 || index >= this->elements)
        throw aghException(1, "Wrong index demanded", __FILE__, __LINE__);

    bool callForLast = (index == this->size() - 1);

    if (callForLast) {
        return *(this->tail);
    }
    else {
        listElem iter = this->head;
        for (int i = 0; i < index; ++i) {
            iter = iter->next;
        }
        return *iter;
    }
}

// --------------------------------------------------------------------------------

template<typename T>
int aghSlist<T>::size(void) const {
    return this->elements;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghSlist<T>::remove(const int index) {
    if (index >= this->elements || index < 0)
        return false;

    listElem prevElem;
    listElem toRemove;

    if (index > 0) {
        prevElem = this->at(index - 1);
        toRemove = prevElem->next;
        prevElem->next = toRemove->next;
        delete toRemove;
    }
    else {
        toRemove = this->at(0);
        this->head = toRemove->next;
        delete toRemove;
    }

    if (index == this->size() - 1)
        this->tail = prevElem;

    --elements;

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghSlist<T>::clear(void) {
    listElem toRemove;
    while (!this->head) {
        toRemove = this->head;
        this->head = head->next;
        delete toRemove;
    }
    this->tail = nullptr;
    this->elements = 0;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghSlist<T>::copy(const aghContainer<T> &source) {

}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghSlist<T>::operator=(const aghContainer<T> &source) {
    this->copy(source);
    return *this;
}

// --------------------------------------------------------------------------------

#endif