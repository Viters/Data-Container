/**
 * @file aghIterator.h
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 * @date 01/06/2016
 * @version 0.8
 * @brief Contains declaration and definitions of aghIterator template class.
*/

// --------------------------------------------------------------------------------

#ifndef DATA_CONTAINER_AGHITERATOR_H
#define DATA_CONTAINER_AGHITERATOR_H

#include "aghContainer.h"

/**
 * @class aghIterator
 *
 * @brief Class template to provide aghContainer iterators.
 *
 * @author Łukasz Mielczarek, Łukasz Szcześniak
 *
 * @version 0.8
 *
 * @date 01/06/2016
 */
template<typename T>
class aghIterator {
public:
    /**
     * Default constructor.
     */
    aghIterator();

    /**
     * Parametric constructor. Creates iterator pointing at given container.
     *
     * @param container
     */
    aghIterator(aghContainer<T> *);

    /**
     * Copy constructor.
     *
     * @param another iterator
     */
    aghIterator(const aghIterator<T> &iterator);

    /**
     * Destructor.
     */
    ~aghIterator();

    /**
     * Returns new iterator pointing to first element of container.
     *
     * @return aghIterator
     */
    aghIterator<T> first();

    /**
     * Returns new iterator pointing to last element of container.
     *
     * @return aghIterator
     */
    aghIterator<T> last();

    /**
     * Sets iterator to next element and returns it.
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &next();

    /**
     * Sets iterator to previous element and returns it.
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &prev();

    /**
     * Returns element currently pointed at by iterator.
     *
     * @return reference to T element
     */
    T &current();

    /**
     * Sets iterator to first element and returns it.
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &atFirst();

    /**
     * Sets iterator to last element and returns it.
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &atLast();

    /**
     * Counts how many elements are left before container ends.
     *
     * @return number of elements left
     */
    int size();

    /**
     * Set container at which iterator points.
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &operator=(aghContainer<T> *);

    /**
     * Copies provided iterator.
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &operator=(const aghIterator<T> &iterator);

    /**
     * Checks if iterator has attached container and position is within
     * this container's size.
     *
     * @return:
     *  @li 1 if iterator is OK
     *  @li NULL if something is wrong
     */
    operator int() const;

    /**
     * Returns element at which iterator is pointing.
     *
     * @return reference to T element
     */
    T &operator*();

    /**
     * Returns element positioned [index] elements further than
     * current iterator position.
     *
     * @param number of elements to pass through
     *
     * @return reference to T element
     */
    T &operator[](int);

    /**
     * Returns new iterator advanced by given number.
     *
     * @param number of elements to advance
     *
     * @return aghIterator
     */
    aghIterator<T> operator+(int);

    /**
     * Advances iterator by given number.
     *
     * @param number of elements to advance
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &operator+=(int);

    /**
     * Returns new iterator reversed by given number.
     *
     * @param number of elements to reverses
     *
     * @return aghIterator
     */
    aghIterator<T> operator-(int);

    /**
     * Reverses iterator by given number.
     *
     * @param number of elements to reverse
     *
     * @return reference to aghIterator
     */
    aghIterator<T> &operator-=(int);

    /**
     * Advances iterator by one element.
     *
     * @return reference to advanced aghIterator
     */
    aghIterator<T> &operator++();

    /**
     * Advances iterator by one element.
     *
     * @return not advanced aghIterator
     */
    aghIterator<T> operator++(int);

    /**
     * Reverses iterator by one element.
     *
     * @return reference to reversed aghIterator
     */
    aghIterator<T> &operator--();

    /**
     * Reverses iterator by one element.
     *
     * @return not reversed aghIterator
     */
    aghIterator<T> operator--(int);

    /**
     * Checks if two iterators are exactly the same.
     *
     * @return true if containers are the same, false otherwise
     */
    bool operator==(const aghIterator<T> &);

    /**
     * Checks if two iterators are different.
     *
     * @return true if containers are different, false otherwise
     */
    bool operator!=(const aghIterator<T> &);

private:
    int position; /**< Number of element iterator at which iterator is pointing. */
    aghContainer<T> *container; /**< Container at which iterator is poiting. */

    /**
     * Sets iterator position.
     */
    void setPosition(int);
};

// --------------------------------------------------------------------------------
// End of aghIterator declaration.
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator() : position(0), container(nullptr) {
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator(aghContainer<T> *container) : position(0), container(container) {
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::aghIterator(const aghIterator<T> &iterator) : container(iterator.container),
                                                              position(iterator.position) {
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::~aghIterator() {
    position = 0;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::first() {
    aghIterator<T> tmp = *this;
    tmp.setPosition(0);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::last() {
    aghIterator<T> tmp = *this;
    tmp.setPosition(tmp.container->size() - 1);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::next() {
    this->setPosition(this->position + 1);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::prev() {
    this->setPosition(position - 1);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::current() {
    if ((int) *this == NULL)
        throw aghException(1, "Access to wrong element demanded", __FILE__, __LINE__);
    return this->container->at(position);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atFirst() {
    this->setPosition(0);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::atLast() {
    this->setPosition(this->container->size() - 1);
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
int aghIterator<T>::size() {
    int size = this->container->size();
    return size - this->position;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator=(aghContainer<T> *container) {
    this->container = container;
    if (this->container->size() != 0)
        this->atFirst();
    return *this;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator=(const aghIterator<T> &iterator) {
    this->container = iterator.container;
    this->setPosition(iterator.position);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T>::operator int() const {
    if (!this->container || this->position >= this->container->size() || this->position < 0)
        return NULL;
    else
        return 1;
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::operator*() {
    return this->current();
}

// --------------------------------------------------------------------------------

template<typename T>
T &aghIterator<T>::operator[](int i) {
    return this->container->at(position + i);
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator+(int i) {
    aghIterator<T> tmp = *this;
    tmp.setPosition(this->position + i);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator+=(int i) {
    return *this = *this + i;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator-(int i) {
    aghIterator<T> tmp = *this;
    tmp.setPosition(this->position - i);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator-=(int i) {
    return *this = *this - i;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator++() {
    return this->next();
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator++(int i) {
    aghIterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> &aghIterator<T>::operator--() {
    return this->prev();
}

// --------------------------------------------------------------------------------

template<typename T>
aghIterator<T> aghIterator<T>::operator--(int i) {
    aghIterator<T> tmp = *this;
    --(*this);
    return tmp;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghIterator<T>::operator==(const aghIterator<T> &iterator) {
    bool sameContainer = (this->container == iterator.container);
    bool samePosition = (this->position == iterator.position);
    return sameContainer && samePosition;
}

// --------------------------------------------------------------------------------

template<typename T>
bool aghIterator<T>::operator!=(const aghIterator<T> &iterator) {
    return !(*this == iterator);
}

// --------------------------------------------------------------------------------

template<typename T>
void aghIterator<T>::setPosition(int newPosition) {
    this->position = newPosition;
}

// --------------------------------------------------------------------------------

#endif //DATA_CONTAINER_AGHITERATOR_H
