/**
 * @file aghVector.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 05/05/2016
 * @version 1.0
 * @brief Contains declaration and definitions of aghVector template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHVECTOR_H
#define DATA_CONTAINER_AGHVECTOR_H

#include "aghContainer.h"

/**
 * @class aghVector
 *
 * @brief Class template to provide vector container with interface.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 1.0
 *
 * @date 05/05/2016
 */
template<typename T>
class aghVector :
        public aghContainer<T> {
public:
    /**
     * Default constructor.
     */
    aghVector();

    /**
     * Copy constructor
     *
     * @param another vector
     */
    aghVector(const aghContainer<T> &);

    /**
     * Destructor.
     */
    ~aghVector();

    /**
     * Insert an element at specified position.
     *
     * @param position number
     * @param new element
     */
    bool insert(const int, const T &);

    /**
     * Get element at specified position.
     *
     * @param position number
     */
    T &at(const int) const;

    /**
     * Get size of the container.
     *
     * @return int size
     */
    int size(void) const;

    /**
     * Remove element at specified position.
     *
     * @param position number
     *
     * @return bool
     */
    bool remove(const int);

    /**
     * Remove all elements from the container.
     */
    void clear(void);

    /**
     * Make copy of another container.
     *
     * @param another container
     */
    void copy(const aghContainer<T> &source);

    /**
     * Assignment operator
     *
     * @param another vector
     *
     * @return reference to the object
     */
    aghContainer<T> &operator=(const aghContainer<T> &);

private:
    T *vector; /**< Pointer to table that holds vector. */
    unsigned int elements; /**< Number of elements in vector. */
    unsigned int vectorSize; /**< Number of memory blocks allocated for vector. */

    /**
     * Frees memory allocated for vector.
     */
    void destroyVector();

    /**
     * Decides if memory should be realloacted.
     * If it should, it calls reallocMemory().
     */
    void changeVectorSize();

    /**
     * Allocates new memory for vector and copies values.
     */
    void reallocMemory(const unsigned int);
};

// --------------------------------------------------------------------------------
// End of aghVector declaration.
// --------------------------------------------------------------------------------

template<typename T>
aghVector<T>::aghVector() : vector(nullptr), elements(0), vectorSize(8) {
    this->reallocMemory(8);
}

// --------------------------------------------------------------------------------

template<typename T>
aghVector<T>::aghVector(const aghContainer<T> &another) : vector(nullptr), elements(0), vectorSize(0) {
    this->copy(another);
}

// --------------------------------------------------------------------------------

template<typename T>
aghVector<T>::~aghVector() {
    this->clear();
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghVector<T>::insert(const int index, const T &newValue) {
    if (index < 0 || index > this->elements)
        return false;

    ++(this->elements);

    try {
        this->changeVectorSize();
        for (int i = this->elements; i > index; i--)
            this->vector[i] = this->vector[i-1];
        this->vector[index] = newValue;
    }
    catch (aghException &e) {
        --(this->elements);
    }

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghVector<T>::at(const int index) const {
    if (index < 0 || index >= this->elements)
        throw aghException(1, "Wrong index demanded", __FILE__, __LINE__);
    return this->vector[index];
}

// --------------------------------------------------------------------------------

template<typename T>
int aghVector<T>::size() const {
    return this->elements;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghVector<T>::remove(const int index) {
    if (index < 0 || index >= this->elements)
        return false;

    --(this->elements);

    try {
        this->changeVectorSize();
        for (int i = index; i < this->elements; i++)
            this->vector[i] = this->vector[i+1];
    }
    catch (aghException &e) {
        ++(this->elements);
    }

    return true;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghVector<T>::clear() {
    this->destroyVector();
    this->elements = 0;
    this->vectorSize = 0;
}

// --------------------------------------------------------------------------------

template<typename T>
aghContainer<T> &aghVector<T>::operator=(const aghContainer<T> &another) {
    this->copy(another);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghVector<T>::copy(const aghContainer<T> &source) {
    if (this == &source)
        return;

    if (!this->isEmpty())
        this->clear();

    this->elements = source.size();
    if (this->elements > 0)
        this->vector = new T[this->elements];

    for (int i = 0; i < this->elements; ++i)
        this->vector[i] = source.at(i);

    return;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghVector<T>::destroyVector() {
    if (this->vector)
        delete[] this->vector;
    this->vector = nullptr;
}

// --------------------------------------------------------------------------------

template<typename T>
void aghVector<T>::changeVectorSize() {
    if (this->vectorSize == 0)
        this->vectorSize = 1;

    if (this->elements >= this->vectorSize ) {
        this->reallocMemory(this->vectorSize * 2);
    }

    unsigned int halfSize = this->vectorSize / 2;
    if (this->elements < halfSize) {
        this->reallocMemory(halfSize);
    }
}

// --------------------------------------------------------------------------------

template<typename T>
void aghVector<T>::reallocMemory(const unsigned int size) {
    T* tmp = new T[size];
    if (!tmp)
        throw aghException(0, "No memory could be allocated", __FILE__, __LINE__);

    this->vectorSize = size;

    if (this->vector) {
        for (int i = 0; i < this->elements; ++i)
            tmp[i] = this->vector[i];

        delete[] this->vector;
    }

    this->vector = tmp;

    return;
}

// --------------------------------------------------------------------------------

#endif