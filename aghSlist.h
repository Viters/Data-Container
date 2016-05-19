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

using namespace std;

/**
 * Class template to provide operation on single-sided list.
*/
template<typename T>
class aghSlist :
	public aghContainer<T> {
public:


private:
	struct Node {
		T value;
		Node *next;
	} *head;
};

#endif
