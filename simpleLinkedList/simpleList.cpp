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

#ifndef simpleList_cpp
#define simpleList_cpp

#include <iostream>
#include "node.hpp"
// Notice that we include the class definition for node here, this is because
// it is a template class and the implementation must be declared before the
// object is intantiated.
#include "node.cpp"
#include "simpleList.hpp"

using namespace std;

/*
 Basic constructor, initialize an empty linked list.
 */
template <class dataType> simpleList<dataType>::simpleList()
{
    head = nullptr;
    tail = nullptr;
    currentPtr = nullptr;
    listSize = 0;
}

/*
 Basic destructor, clear all items from the list and reclaim the memory to
 prevent memory leaks.
 */
template <class dataType> simpleList<dataType>::~simpleList()
{
    clear();
}

// Appends data to the end of the list.
template <class dataType> void simpleList<dataType>::append(dataType newData)
{
    // Create a new pointer to a new node.
    node<dataType> *newNode = new node<dataType>;
    // Set the data to be stored in that node.
    newNode->container = newData;
    
    // Go about configuring the node to be inside the list.
    if (newNode == nullptr) {
        // Problem allocating memory!  We use standard error here so that
        // the output can be properly categorized by the OS.  One could
        // also replace this with some kind of debug output function.
        cerr << "Error allocating memory, append failed." << endl;
    } else {
        // If the list is empty, then it becomes a list of item, set the head
        // and tail to the new node.
        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
        // If the list is not empty, we make the new node, the new tail and
        // make sure that we link the previous tail to the new tail.
        } else {
            tail->nextPtr = newNode;
            newNode->prevPtr = tail;
            tail = newNode;
        }
        
        // Keep track of the number of nodes in the list.
        listSize++;
    }
}

/*
 Inserts new data to the element just before the current pointer.  If the
 current pointer is unset, it defaults to the head of the list.
 */
template <class dataType> void simpleList<dataType>::insert(dataType newData)
{
    // Since we use the current pointer a lot, if it is null, we need to
    // default it to the head of the list.
    if (currentPtr == nullptr) {
        currentPtr = head;
    }
    
    // Same as with the append function, create a new pointer and set the data
    node<dataType> *newNode = new node<dataType>;
    newNode->container = newData;
    
    // Check for allocation problems.
    if (newNode == nullptr) {
        cerr << "Error allocating memory, insert failed." << endl;
    // There is a special case to insert before the head of the list.
    // We need to reassign the head to a new pointer and make sure that
    // the list order is intact.
    } else if (currentPtr == head) {
        head = newNode;
        currentPtr->prevPtr = newNode;
        newNode->nextPtr = currentPtr;
        currentPtr = newNode;
        listSize++;
    // Otherwise operate as if we are in the middle of the list somewhere.
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
    // Basically this just goes forward in the list by a certain distance using
    // a for loop, this is similar in idea to the iterator in the STL.
    for(int x = 0; x < distance; x++) {
        // We need to keep going in the list until we either reach our
        // destination or until we reach the end of the list.  If we reach
        // the end of the list, just stop there.
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
    // The exact same thing as forward(), just a different direction.
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
 When the search term is not found, the current pointer is set to the list tail.
 */
template <class dataType> node<dataType>  *simpleList<dataType>::find(dataType searchData)
{
    // Originally this function did not use the current pointer and just
    // stopped at the first instance, "current" allows a function to call this
    // as many times is required to make sure the searchData does not appear
    // in the list more than once.
    while (currentPtr->nextPtr != nullptr) {
        // Of course this comparison means that the object type must have a
        // relational operator for == in the implementation.
        if (searchData == currentPtr->container) {
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
    
    // A place to store the pointer to what we want to delate.
    node<dataType> *toRemove = currentPtr;
    
    // Several different special casea are defined here.  The first is for when
    // the list has only one node, once that is gone the list is empty again.
    if (currentPtr == tail && currentPtr == head) {
        tail = nullptr;
        head = nullptr;
        currentPtr = nullptr;
    // If the tail node is being removed, we need to deal with the tail pointer.
    } else if (currentPtr == tail) {
        tail = currentPtr->prevPtr;
        tail->nextPtr = nullptr;
        currentPtr = tail;
    // If the head node is being removed, we need to deal with the head pointer.
    } else if (currentPtr == head) {
        head = currentPtr->nextPtr;
        head->prevPtr = nullptr;
        currentPtr = head;
    // All other cases, just set the pointers to avoid the node being deleted.
    } else {
        currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
        currentPtr = currentPtr->prevPtr;
    }
    
    // Actually delete the node from memory.
    delete toRemove;
    listSize--; // Keep track of number of nodes in the list.
}

// Removes all items from memory.
template <class dataType> void simpleList<dataType>::clear()
{
    // This simply walks the list removing each item.  Since remove() changes
    // the pointer to the item directly prior to the one which was deleted,
    // or to the new head / new tail, we can just keep calling remove() to
    // eventually clear all items.
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

#endif /* simpleList_cpp */
