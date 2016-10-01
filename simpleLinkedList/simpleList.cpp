/*
 Simple Linked List Implementation
 by David Wade Hagar
 September 30th, 2016
 
 This work and all associated files is coverde by the Creative Commons 3.0
 Attribution (BY) license.  Full license text can be found in the LICENSE file
 which should accompany this work.  It can also be located at:
 https://creativecommons.org/licenses/by/3.0/us/
 
 This project is kept on GitHub at the URL:
 https://github.com/dwhagar/simpleLinkedList
 
 Read the README.md file for more information.
 
 Class Definitions for the simpleList class.
 
 Purpose:
 This class is defined to be a linked list using the node class.
 */

#include <iostream>
#include "node.hpp"
#include "simpleList.hpp"

using namespace std;

template <class dataType> simpleList<dataType>::simpleList()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    listSize = 0;
}

template <class dataType> simpleList<dataType>::~simpleList()
{
    clear();
}

// Appends data to the end of the list.
template <class dataType> void simpleList<dataType>::append(dataType newData)
{
    node<dataType> *newNode = new node<dataType>;
    if (newNode == nullptr) {
        cerr << "Error allocated memory, append failed." << endl;
    } else {
        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
    }
}

// Inserts new data to the element just before the current pointer.
template <class dataType> void simpleList<dataType>::insert(dataType newData)
{
    
}

/*
 Advance the current pointer distance spaces, or as many spaces as possible if
 distance would place the current pointer beyond the size of the list.
 */
template <class dataType> void simpleList<dataType>::forward(unsigned long distance)
{
    for(int x = 0; x < distance; x++) {
        if (current->nextPtr != nullptr) {
            current = current->nextPtr;
        } else {
            break;
        }
    }
}

/*
 Reverse the current pointer distance spaces, or as many spaces as possible if
 distance would place the current pointer beyond the size of the list.
 */
template <class dataType> void simpleList<dataType>::backwward(unsigned long distance)
{
    for(int x = 0; x < distance; x++) {
        if (current->prevPtr != nullptr) {
            current = current->prevPtr;
        } else {
            break;
        }
    }
}

// Reset the current pointer back to the beginning of the list.
template <class dataType> void simpleList<dataType>::toHead()
{
    current = head;
}

// Reset the current pointer to the end of the list.
template <class dataType> void simpleList<dataType>::toTail()
{
    current = tail;
}

/*
 Returns a pointer to where searchData is within the linked list.  If the data
 is not found, a null pointer is returned.
 
 When the search term is found, the current pointer is set to its location.
 When the search term is not found, the current pointer is set to the head.
 */
template <class dataType> node<dataType>  *simpleList<dataType>::find(dataType searchData)
{
    
}

template <class dataType> void simpleList<dataType>::remove()
{
    
}

template <class dataType> void simpleList<dataType>::clear()
{
    
}

// Give the current size of the list.
template <class dataType> unsigned long simpleList<dataType>::size()
{
    return listSize;
}
