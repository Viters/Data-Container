/**
 * @file aghContainer.h
 * @author £ukasz Mielczarek, £ukasz Szczeœniak
 * @date 05|05|2016
 * @version 0.1
 * @brief Contains declaration and definitions of aghContainer template class.
 */

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHCONTAINER_H
#define DATA_CONTAINER_AGHCONTAINER_H

#include <iostream>

using namespace std;

/**
 * Class template for data containers.
 */
template <typename T>
class aghContainer {
public:
    /**
     * Pure virtual destructor.
     */
    virtual ~aghContainer() = 0;

    /**
     * Add element to container.
     * @param new element
     */
    virtual void append(T const&) = 0;

    /**
     * Join two containers of the same type.
     * @param another container
     */
    virtual void append(aghContainer<T> const& right) = 0;

    /**
     * Insert an element at specified position.
     * @param position number
     * @param new element
     */
    virtual bool insert(const int, T const&) = 0;

    /**
     * Replace an element at specified position.
     * @param position number
     * @param new element
     */
    virtual bool replace(const int, T const&) = 0;

    /**
     * Get element at specified position.
     * @param position number
     */
    virtual T& at(const int) const = 0;

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
    virtual int indexOf(T const& _value, int _from = 0) const = 0;

    /**
     * Check if element exists in container within specified range.
     *
     * @param element value
     * @param start index (default = 0)
     * @return bool
     */
    virtual bool contains(T const& _value, int _from = 0) const = 0;

    /**
     * Check if two containers are the same.
     *
     * @param another container
     * @return bool
     */
    virtual bool equal(aghContainer<T> const& right) const = 0;

    /**
     * Operator to check if two containers are the same.
     *
     * @param another container
     * @return bool
     */
    virtual bool operator==(aghContainer<T> const& right) const;

    /**
     * Operator to check if two containers are not the same.
     *
     * @param another container
     * @return bool
     */
    virtual bool operator!=(aghContainer<T> const& right) const;

    /**
     * Operator to get element from specified position.
     *
     * @param position number
     * @return element
     */
    virtual T& operator[](const int n) const;

    /**
     * Operator to add element at specified position.
     *
     * @param new element
     * @return reference to itself
     */
    virtual aghContainer<T>& operator+=(T const& element);

    /**
     * Operator to join two containers of the same type.
     *
     * @param another container
     * @return reference to itself
     */
    virtual aghContainer<T>& operator+=(aghContainer<T> const& right);

    /**
     * Operator to add element at specified position.
     *
     * @param new element
     * @return reference to itself
     */
    virtual aghContainer<T>& operator<<(T const& element);

    /**
     * Operator to join two containers of the same type.
     *
     * @param another container
     * @return reference to itself
     */
    virtual aghContainer<T>& operator<<(aghContainer<T> const& right);

    /**
     * Operator to print container elements.
     *
     * @param container
     * @return reference to ostream object
     */
    virtual ostream& operator<<(ostream&, aghContainer<T> const& right) = 0;
};

// --------------------------------------------------------------------------------
// End of aghContainer declaration.
// --------------------------------------------------------------------------------

template <typename T>
bool aghContainer<T>::operator==(aghContainer<T> const& right) const {
    return this->equal(right);
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right) const {
    return !(this->equal(right));
}

// --------------------------------------------------------------------------------

template <typename T>
T& aghContainer<T>::operator[](const int n) const {
    return this->at(n);
}

// --------------------------------------------------------------------------------

template <typename T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element) {
    this->append(element);
    return *this;
}

// --------------------------------------------------------------------------------

template <typename T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right) {
    this->append(right);
    return *this;
}

// --------------------------------------------------------------------------------

template <typename T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element) {
    this->append(element);
    return *this;
}

// --------------------------------------------------------------------------------

template <typename T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right) {
    this->append(right);
    return *this;
}

// --------------------------------------------------------------------------------

#endif //DATA_CONTAINER_AGHCONTAINER_H
