/**
 * @file aghVector.h
 * @author �ukasz Mielczarek, �ukasz Szcze�niak
 * @date 05|05|2016
 * @version 0.1
 * @brief Contains declaration and definitions of aghVector template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHVECTOR_H
#define DATA_CONTAINER_AGHVECTOR_H

#include "aghContainer.h"
#include <iostream>

using namespace std;

/**
 * Class template to provide operation on vectors.
*/
template <typename T>
class aghVector :
    public aghContainer<T> {
public:
    /**
     * Default constructor.
     */
    aghVector();

    /**
     * Destructor.
     */
    ~aghVector();

    /**
     * Add element to container.
     * @param new element
     */
    void append(T const&);

    /**
     * Join two containers of the same type.
     * @param another container
     */
    void append(aghContainer<T> const& right);

    /**
     * Insert an element at specified position.
     * @param position number
     * @param new element
     */
    bool insert(const int, T const&);

    /**
     * Replace an element at specified position.
     * @param position number
     * @param new element
     */
    bool replace(const int, T const&);

    /**
     * Get element at specified position.
     * @param position number
     */
    T& at(const int) const;

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
     * Check if there are any elements in container.
     *
     * @return bool
     */
    bool isEmpty(void);

    /**
     * Get index of element in container within specified range.
     *
     * @param element value
     * @param start index (default = 0)
     * @return int index
     */
    int indexOf(T const& _value, int _from = 0) const;

    /**
     * Check if element exists in container within specified range.
     *
     * @param element value
     * @param start index (default = 0)
     * @return bool
     */
    bool contains(T const& _value, int _from = 0) const;

    /**
     * Print elements of container to output.
     *
     * @param output
     */
    void print(ostream&) const;

    /**
     * Check if two containers are the same.
     *
     * @param another container
     * @return bool
     */
    bool equal(aghContainer<T> const& right) const;

private:
    T* vector; //< Pointer to table that holds vector.
    unsigned int elements; //< Number of elements in vector.

    /**
     * Frees memory allocated for vector.
     */
    void destroyVector();
};

// --------------------------------------------------------------------------------
// End of aghVector declaration.
// --------------------------------------------------------------------------------

template <typename T>
aghVector<T>::aghVector() : vector(nullptr), elements(0) {
}

// --------------------------------------------------------------------------------

template <typename T>
aghVector<T>::~aghVector() {
    if(!this->vector)
        this->destroyVector();
}

// --------------------------------------------------------------------------------

template <typename T>
void aghVector<T>::append(T const&) {

}

// --------------------------------------------------------------------------------

template <typename T>
void aghVector<T>::append(aghContainer<T> const& right) {
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghVector<T>::insert(const int, T const&) {
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghVector<T>::replace(const int, T const&) {
}

// --------------------------------------------------------------------------------

template <typename T>
T& aghVector<T>::at(const int) const {
}

// --------------------------------------------------------------------------------

template <typename T>
int aghVector<T>::size() const {
    return elements;
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghVector<T>::remove(const int) {
}

// --------------------------------------------------------------------------------

template <typename T>
void aghVector<T>::clear() {
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghVector<T>::isEmpty() {
}

// --------------------------------------------------------------------------------

template <typename T>
int aghVector<T>::indexOf(T const& _value, int _from) const {
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghVector<T>::contains(T const& _value, int _from) const {
}

// --------------------------------------------------------------------------------

template <typename T>
void aghVector<T>::print(ostream& out) const {
}

// --------------------------------------------------------------------------------

template <typename T>
bool aghVector<T>::equal(aghContainer<T> const& right) const {
}

// --------------------------------------------------------------------------------

template<typename T>
void aghVector<T>::destroyVector(){
    if(!this->vector)
        delete [] this->vector;
    this->vector = nullptr;
    this->elements = 0;
}

#endif
