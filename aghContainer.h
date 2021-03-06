/**
 * @file aghContainer.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 05/05/2016
 * @version 1.0
 * @brief Contains declaration and definitions of aghContainer template class.
 */

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHCONTAINER_H
#define DATA_CONTAINER_AGHCONTAINER_H

#include <iostream>
#include "aghException.h"

using namespace std;

/**
 * @class aghContainer
 *
 * @brief Pure virtual class template for data containers.
 *
 * Pure virtual class template to create data container classes
 * such as list, vector etc. Just derive from this class, implement
 * all pure virtual methods:
 * $ virtual bool insert(const int, T const &) = 0;
 * $ virtual T &at(const int) const = 0;
 * $ virtual int size(void) const = 0;
 * $ virtual bool remove(const int) = 0;
 * $ virtual void clear(void) = 0;
 * the rest will work just fine.
 * You can reimplement other methods to improve efficiency.
 * Containers are compatible with themselves.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 1.0
 *
 * @date 05/05/2016
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
    virtual void append(const T &);

    /**
     * Join two containers of the same type.
     * @param another container
     */
    virtual void append(const aghContainer<T> &);

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
    virtual bool replace(const int, T const &);

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
    virtual bool isEmpty(void);

    /**
     * Get index of element in container within specified range.
     *
     * @param element value
     * @param start index (default = 0)
     * @return int index
     */
    virtual int indexOf(const T &_value, int _from = 0) const;

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
    virtual void copy(const aghContainer<T> &);

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
     * Operator to add element to the container.
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
void aghContainer<T>::append(const T &newValue) {
    this->insert(this->size(), newValue);
}

// --------------------------------------------------------------------------------

template<typename T>
void aghContainer<T>::append(const aghContainer &newValue) {
    for (int i = 0; i < newValue.size(); ++i)
        this->insert(this->size(), newValue.at(i));
}

// --------------------------------------------------------------------------------

template<typename T>
int aghContainer<T>::indexOf(const T &_value, int _from) const {
    for (int i = _from; i < this->size(); ++i)
        if (this->at(i) == _value)
            return i;
    return -1;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghContainer<T>::isEmpty() {
    return this->size() == 0;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghContainer<T>::replace(const int index, const T &newValue) {
    if (index < 0 || index >= this->size())
        return false;
    this->at(index) = newValue;
    return true;
}

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
void aghContainer<T>::copy(const aghContainer<T> &source) {
    if (this == &source)
        return;

    if (!this->isEmpty())
        this->clear();

    for (int i = 0; i < source.size(); ++i) {
        this->append(source.at(i));
    }

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
