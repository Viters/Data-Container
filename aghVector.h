/**
 * @file aghVector.h
 * @author £ukasz Mielczarek, £ukasz Szczeœniak
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
    aghVector();
    ~aghVector();
};

#endif