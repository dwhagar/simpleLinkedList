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
 
 Class Definitions for the node class.
 
 Purpose:
 This class is defined to be a single node in a linked list.
 */

#include "node.hpp"

using namespace std;

#ifndef node_cpp
#define node_cpp

/*
 Default Constructor
 
 This will construct an empty node with null pointers for previous and next
 nodes.
 */
template <class dataType> node<dataType>::node()
{
    prevPtr = nullptr;
    nextPtr = nullptr;
}

/*
 Constructor with Pointers
 
 If two pointers are already provided, the constructor will simply set them.
 */
template <class dataType> node<dataType>::node(node *prv, node *nxt)
{
    prevPtr = prv;
    nextPtr = nxt;
}

// Destructor
template <class dataType> node<dataType>::~node()
{
    // Nothing to do here right now.
}

/*
 Obtain pointers to other items in the list.
 
 prev() provides the pointer to the previous object
 next() provides the pointer to the next object
 */
template <class dataType> node<dataType> *node<dataType>::prev()
{
    return prevPtr;
}
template <class dataType> node<dataType> *node<dataType>::next()
{
    return nextPtr;
}

/*
 Returns the data contents of the node.
 */
template <class dataType> dataType node<dataType>::data()
{
    return container;
}

/*
 Stores new data in the node, replacing the old data.  This is overloaded
 to provide simpler function calls.
 */
template <class dataType> void node<dataType>::data(dataType newData)
{
    container = newData;
}

#endif /* node_cpp */
