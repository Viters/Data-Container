/**
 * @file aghContainer.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 05|05|2016
 * @version 0.1
 * @brief Contains declaration and definitions of aghContainer template class.
 */

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHCONTAINER_H
#define DATA_CONTAINER_AGHCONTAINER_H

#include <iostream>
#include "aghException.h"

using namespace std;

/**
 * Class template for data containers.
 */
template<typename T>
class aghContainer {
public:
    /**
     * Virtual destructor.
     */
    virtual ~aghContainer() { }

    /**
     * Add element to container.
     * @param new element
     */
    virtual void append(const T &) = 0;

    /**
     * Join two containers of the same type.
     * @param another container
     */
    virtual void append(const aghContainer<T> &right) = 0;

    /**
     * Insert an element at specified position.
     * @param position number
     * @param new element
     */
    virtual bool insert(const int, T const &) = 0;

    /**
     * Replace an element at specified position.
     * @param position number
     * @param new element
     */
    virtual bool replace(const int, T const &) = 0;

    /**
     * Get element at specified position.
     * @param position number
     */
    virtual T &at(const int) const = 0;

    /**
     * Get size of the container.
     * @return int size
     */
    virtual int size(void) const = 0;

    /**
     * Remove element at specified position.
     * @param position number
     * @return bool
     */
    virtual bool remove(const int) = 0;

    /**
     * Remove all elements from the container.
     */
    virtual void clear(void) = 0;

    /**
     * Check if there are any elements in container.
     *
     * @return bool
     */
    virtual bool isEmpty(void) = 0;

    /**
     * Get index of element in container within specified range.
     *
     * @param element value
     * @param start index (default = 0)
     * @return int index
     */
    virtual int indexOf(const T &_value, int _from = 0) const = 0;

    /**
     * Check if element exists in container within specified range.
     *
     * @param element value
     * @param start index (default = 0)
     * @return bool
     */
    virtual bool contains(const T &_value, int _from = 0) const;

    /**
     * Print elements of container to output.
     *
     * @param output
     */
    virtual void print(ostream &) const;

    /**
     * Check if two containers are the same.
     *
     * @param another container
     * @return bool
     */
    virtual bool equal(const aghContainer<T> &right) const;

    /**
     * Make copy of another container.
     *
     * @param another container
     */
    virtual void copy(const aghContainer<T> &) = 0;

    /**
     * Assignment operator
     *
     * @param another container
     * @return reference to the object
     */
    virtual aghContainer<T> &operator=(const aghContainer<T> &);

    /**
     * Operator to check if two containers are the same.
     *
     * @param another container
     * @return bool
     */
    virtual bool operator==(const aghContainer<T> &right) const;

    /**
     * Operator to check if two containers are not the same.
     *
     * @param another container
     * @return bool
     */
    virtual bool operator!=(const aghContainer<T> &right) const;

    /**
     * Operator to get element from specified position.
     *
     * @param position number
     * @return element
     */
    virtual T &operator[](const int n) const;

    /**
     * Operator to add element at specified position.
     *
     * @param new element
     * @return reference to itself
     */
    virtual aghContainer<T> &operator+=(const T &element);

    /**
     * Operator to join two containers of the same type.
     *
     * @param another container
     * @return reference to itself
     */
    virtual aghContainer<T> &operator+=(const aghContainer<T> &right);

    /**
     * Operator to add element at specified position.
     *
     * @param new element
     * @return reference to itself
     */
    virtual aghContainer<T> &operator<<(const T &element);

    /**
     * Operator to join two containers of the same type.
     *
     * @param another container
     * @return reference to itself
     */
    virtual aghContainer<T> &operator<<(const aghContainer<T> &right);

    /**
     * Operator to print container elements.
     *
     * @param container
     * @return reference to ostream object
     */
    template<typename Y>
    friend ostream &operator<<(ostream &, const aghContainer<Y> &right);
};

// --------------------------------------------------------------------------------
// End of aghContainer declaration.
// --------------------------------------------------------------------------------

template<typename T>
bool aghContainer<T>::contains(const T &_value, int _from) const {
    return this->indexOf(_value, _from) != -1;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghContainer<T>::print(ostream &out) const {
    for (int i = 0; i < this->size(); ++i)
        out << this->at(i) << endl;
    return;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghContainer<T>::equal(const aghContainer<T> &right) const {
    bool sameSize = this->size() == right.size();
    if (!sameSize)
        return false;
    for (int i = 0; i < this->size(); ++i)
        if (this->at(i) != right.at(i))
            return false;

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghContainer<T>::operator=(const aghContainer<T> &right) {
    this->copy(right);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghContainer<T>::operator==(const aghContainer<T> &right) const {
    return this->equal(right);
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghContainer<T>::operator!=(const aghContainer<T> &right) const {
    return !(this->equal(right));
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghContainer<T>::operator[](const int n) const {
    return this->at(n);
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghContainer<T>::operator+=(const T &element) {
    this->append(element);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghContainer<T>::operator+=(const aghContainer<T> &right) {
    this->append(right);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghContainer<T>::operator<<(const T &element) {
    this->append(element);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghContainer<T>::operator<<(const aghContainer<T> &right) {
    this->append(right);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename Y>
ostream &operator<<(ostream &out, const aghContainer<Y> &right) {
    right.print(out);
    return out;
}

#endif //DATA_CONTAINER_AGHCONTAINER_H
