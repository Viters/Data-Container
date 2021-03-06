/**
 * @file aghSlist.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 19/05/2016
 * @version 1.0
 * @brief Contains declaration and definition of aghSlist template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHSLIST_H
#define DATA_CONTAINER_AGHSLIST_H

#include "aghContainer.h"

/**
 * @class aghSlist
 *
 * @brief Class template to provide single-sided list container with interface.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 1.0
 *
 * @date 19/05/2016
 */
template<typename T>
class aghSlist :
        public aghContainer<T> {
public:
    /**
     * Default constructor
     */
    aghSlist();

    /**
     * Copy constructor
     * @param another aghSlist
     */
    aghSlist(const aghContainer<T> &);

    /**
     * Destructor
     */
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
     * Assignment operator
     *
     * @param another vector
     * @return reference to the object
     */
    aghContainer<T> &operator=(const aghContainer<T> &);

private:
    /**
     * Node structure to hold data in the list.
     */
    template<typename Y>
    struct Node {
        /**
         * Value that node holds.
         */
        Y value;
        /**
         * Pointer to the next node.
         */
        Node<Y> *next;
        /**
         * Pointer to the previous node.
         */
        Node<Y> *prev;

        /**
         * Node's parameterized constructor
         */
        Node(Y value, Node<Y> *next = nullptr) : value(value), next(next) { }
    };

    /**
     * This typedef simplifies operating on list elements in list methods.
     */
    typedef Node<T> *listElem;

    listElem head; /**< Pointer to first element of a list. */
    listElem tail; /**< Pointer to last element of a list. */

    unsigned int elements; /**< Number of elements in a list. */

    /**
     * Retrieve a specified element of a list.
     *
     * @param number of required element
     * @return pointer to a Node element
     */
    listElem getNode(const int) const;
};

// --------------------------------------------------------------------------------
// End of aghSlist declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghSlist<T>::aghSlist() : head(nullptr), tail(nullptr), elements(0) { }

// --------------------------------------------------------------------------------

template<typename T>
aghSlist<T>::aghSlist(const aghContainer<T> &container) : head(nullptr), tail(nullptr), elements(0) {
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
    if (index < 0 || index > this->elements)
        return false;

    listElem oldElem;
    listElem newElem;

    if (index > 0) {
        oldElem = this->getNode(index - 1);
        newElem = new Node<T>(value, oldElem->next);
        oldElem->next = newElem;
    }
    else {
        oldElem = (!this->isEmpty()) ? this->getNode(0) : nullptr;
        newElem = new Node<T>(value, oldElem);
        this->head = newElem;
    }

    if (index == this->size())
        this->tail = newElem;

    ++(this->elements);

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghSlist<T>::at(const int index) const {
    this->getNode(index)->value;
}

// --------------------------------------------------------------------------------

template<typename T>
int aghSlist<T>::size(void) const {
    return this->elements;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghSlist<T>::remove(const int index) {
    if (index < 0 || index >= this->elements)
        return false;

    listElem prevElem;
    listElem toRemove;

    if (index > 0) {
        prevElem = this->getNode(index - 1);
        toRemove = prevElem->next;
        prevElem->next = toRemove->next;
        delete toRemove;
    }
    else {
        toRemove = this->getNode(0);
        this->head = toRemove->next;
        delete toRemove;
    }

    if (index == this->size() - 1)
        this->tail = prevElem;

    --(this->elements);

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghSlist<T>::clear(void) {
    listElem toRemove;
    while (this->head) {
        toRemove = this->head;
        this->head = head->next;
        delete toRemove;
    }
    this->tail = nullptr;
    this->elements = 0;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghSlist<T>::operator=(const aghContainer<T> &source) {
    this->copy(source);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
typename aghSlist<T>::listElem aghSlist<T>::getNode(const int index) const {
    if (index < 0 || index >= this->elements)
        throw aghException(1, "Wrong index demanded", __FILE__, __LINE__);

    bool callForLast = (index == this->size() - 1);

    if (callForLast) {
        return this->tail;
    }
    else {
        listElem iter = this->head;
        for (int i = 0; i < index; ++i) {
            iter = iter->next;
        }
        return iter;
    }
}

#endif
