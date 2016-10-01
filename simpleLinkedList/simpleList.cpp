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
    currentPtr = nullptr;
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
    newNode->container = newData;
    if (newNode == nullptr) {
        cerr << "Error allocating memory, append failed." << endl;
    } else {
        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->nextPtr = newNode;
            newNode->prevPtr = tail;
            tail = newNode;
        }
        listSize++;
    }
}

/*
 Inserts new data to the element just before the current pointer.  If the
 current pointer is unset, it defaults to the head of the list.
 */
template <class dataType> void simpleList<dataType>::insert(dataType newData)
{
    if (currentPtr == nullptr) {
        currentPtr = head;
    }
    
    node<dataType> *newNode = new node<dataType>;
    newNode->container = newData;
    if (newNode == nullptr) {
        cerr << "Error allocating memory, insert failed." << endl;
    } else if (currentPtr == head) {
        head = newNode;
        currentPtr->prevPtr = newNode;
        newNode->nextPtr = currentPtr;
        currentPtr = newNode;
        listSize++;
    } else {
        currentPtr->prevPtr->nextPtr = newNode;
        newNode->nextPtr = currentPtr;
        newNode->prevPtr = currentPtr->prevPtr;
        currentPtr->prevPtr = newNode;
        currentPtr = newNode;
        listSize++;
    }
}

/*
 Advance the current pointer distance spaces, or as many spaces as possible if
 distance would place the current pointer beyond the size of the list.
 */
template <class dataType> void simpleList<dataType>::forward(unsigned long distance)
{
    for(int x = 0; x < distance; x++) {
        if (currentPtr->nextPtr != nullptr) {
            currentPtr = currentPtr->nextPtr;
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
        if (currentPtr->prevPtr != nullptr) {
            currentPtr = currentPtr->prevPtr;
        } else {
            break;
        }
    }
}

// Reset the current pointer back to the beginning of the list.
template <class dataType> void simpleList<dataType>::toHead()
{
    currentPtr = head;
}

// Reset the current pointer to the end of the list.
template <class dataType> void simpleList<dataType>::toTail()
{
    currentPtr = tail;
}

/*
 Returns a pointer to where searchData is within the linked list.  If the data
 is not found, a null pointer is returned.
 
 When the search term is found, the current pointer is set to its location.
 When the search term is not found, the current pointer is not moved.
 */
template <class dataType> node<dataType>  *simpleList<dataType>::find(dataType searchData)
{
    node<dataType> *searchPtr = head;
    
    while (searchPtr->nextPtr != nullptr) {
        if (searchData == searchPtr->container) {
            currentPtr = searchPtr;
            return currentPtr;
        }
    }
    
    return nullptr;
}

/*
 Removes the node that resides at the current pointer.  If the current pointer
 is unset, defaults to the last item in the list.
 
 If the head is removed, the current pointer is set to the new head.
 If the tail is removed, the current pointer is set to the new tail.
 Otherwise the current pointer is set to the node immidiately prior to the
 one that was deleted.
 */
template <class dataType> void simpleList<dataType>::remove()
{
    if (currentPtr == nullptr) {
        currentPtr = tail;
    }
    
    node<dataType> *toRemove = currentPtr;
    
    if (currentPtr == tail && currentPtr == head) {
        tail = nullptr;
        head = nullptr;
        currentPtr = nullptr;
    } else if (currentPtr == tail) {
        tail = currentPtr->prevPtr;
        tail->nextPtr = nullptr;
        currentPtr = tail;
    } else if (currentPtr == head) {
        head = currentPtr->nextPtr;
        head->prevPtr = nullptr;
        currentPtr = head;
    } else {
        currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
        currentPtr = currentPtr->prevPtr;
    }
    
    delete toRemove;
    listSize--;
}

// Removes all items from memory.
template <class dataType> void simpleList<dataType>::clear()
{
    if (listSize > 0 && head != nullptr && tail != nullptr) {
        currentPtr = head;
        
        while (listSize > 0) {
            remove();
        }
    }
}

// Give the current size of the list.
template <class dataType> unsigned long simpleList<dataType>::size()
{
    return listSize;
}

// Return the current pointer.
template <class dataType> node<dataType> *simpleList<dataType>::current()
{
    return currentPtr;
}
