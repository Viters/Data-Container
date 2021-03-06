/**
 * @file aghDlist.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 19/05/2016
 * @version 1.0
 * @brief Contains declaration and definition of aghDlist template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHLIST_H
#define DATA_CONTAINER_AGHLIST_H

#include "aghContainer.h"

/**
 * @class aghDlist
 *
 * @brief Class template to provide double-sided list container with interface.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 1.0
 *
 * @date 19/05/2016
 */
template<typename T>
class aghDlist :
        public aghContainer<T> {
public:
    /**
     * Default constructor.
     */
    aghDlist();

    /**
     * Copy constructor
     * @param another aghDlist
     */
    aghDlist(const aghContainer<T> &);

    /**
     * Destructor.
     */
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
     * Structure template to keep values added to the list
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
        Node(Y value, Node<Y> *next = nullptr, Node<Y> *prev = nullptr) : value(value), next(next), prev(prev) { }
    };

    /**
     * This typedef simplifies operating on list elements in list methods.
     */
    typedef Node<T> *listElem;

    listElem head; /**< Pointer to the first structure. */
    listElem tail; /**< Pointer to the last structure. */

    unsigned int elements; /**< Number of elements in list. */

    /**
     * Get the pointer to the structure at specified position
     *
     * @param position
     * @return pointer to the structure
     */
    listElem getNode(const int) const;
};

// --------------------------------------------------------------------------------
// End of aghDlist declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghDlist<T>::aghDlist() : head(nullptr), tail(nullptr), elements(0) { }

// --------------------------------------------------------------------------------

template<typename T>
aghDlist<T>::aghDlist(const aghContainer<T> &container) : head(nullptr), tail(nullptr), elements(0) {
    this->copy(container);
}

// --------------------------------------------------------------------------------

template<typename T>
aghDlist<T>::~aghDlist() {
    this->clear();
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghDlist<T>::insert(const int index, const T &value) {
    if (index < 0 || index > this->elements)
        return false;

    listElem oldElem;
    listElem newElem;

    newElem = new Node<T>(value);

    if (index > 0) {
        oldElem = this->getNode(index - 1);
        newElem->prev = oldElem;
        newElem->next = oldElem->next;
        oldElem->next = newElem;
    }
    else {
        newElem->next = this->head;
        this->head = newElem;
    }

    if (index != this->elements)
        (newElem->next)->prev = newElem;
    else
        this->tail = newElem;

    ++(this->elements);
    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghDlist<T>::at(const int pos) const {
    return getNode(pos)->value;
}

// --------------------------------------------------------------------------------

template<typename T>
int aghDlist<T>::size(void) const {
    return this->elements;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghDlist<T>::remove(const int index) {
    if (index < 0 || index >= this->elements)
        return false;

    listElem toRemove = this->getNode(index);

    if (index > 0)
        (toRemove->prev)->next = toRemove->next;
    else
        this->head = toRemove->next;

    if (index != this->elements - 1)
        (toRemove->next)->prev = toRemove->prev;
    else
        this->tail = toRemove->prev;

    delete toRemove;
    --(this->elements);
    return true;

}

// --------------------------------------------------------------------------------

template<typename T>
void aghDlist<T>::clear(void) {
    listElem current = this->head;
    listElem following;
    while (current) {
        following = current->next;
        delete current;
        current = following;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->elements = 0;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghDlist<T>::operator=(const aghContainer<T> &container) {
    this->copy(container);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
typename aghDlist<T>::listElem aghDlist<T>::getNode(const int index) const {
    if (index < 0 || index >= elements)
        throw aghException(1, "Wrong index demanded", __FILE__, __LINE__);

    bool callBackwards = (index > this->size() / 2);

    listElem iter;
    int pos;

    if (callBackwards) {
        iter = this->tail;
        pos = this->size() - 1;
        while (pos != index) {
            iter = iter->prev;
            --pos;

        }
        return iter;
    }
    else {
        iter = this->head;
        pos = 0;
        while (pos != index) {
            iter = iter->next;
            ++pos;
        }
        return iter;
    }
}

#endif
