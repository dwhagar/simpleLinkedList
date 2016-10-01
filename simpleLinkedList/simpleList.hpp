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
 
 Class Declarations for the simpleList class.
 
 Purpose:
 This class is defined to be a linked list using the node class.
 */

#ifndef simpleList_hpp
#define simpleList_hpp

#include "node.hpp"

namespace std {
    using namespace std;
    template <class dataType>
    class simpleList {
    private:
        node<dataType> *head;       // Pointer to the first node.
        node<dataType> *tail;       // Pointer to the last node.
        node<dataType> *currentPtr; // Pointer to the current list position.
        unsigned long listSize;     // The number of nodes in the list.
    public:
        simpleList();   // Constructor
        ~simpleList();  // Destructor, this will call the clear() function.
        void append(dataType newData);  // Append data to the end of the list.
        void insert(dataType newData);  // Insert data into the list.
        void forward(unsigned long distance);   // Move the current pointer up.
        void backwward(unsigned long distance); // Move the current pointer back.
        void toHead();  // Set the current pointer to the head of the list.
        void toTail();  // Set the current pointer to the tail of the list.
        node<dataType> *find(dataType searchData);  // Search for data by value.
        void remove();  // Remove the current item in the list.
        void clear();   // Clear all nodes out of the list and relcaim memory.
        unsigned long size();       // Return the number of nodes in the list.
        node<dataType> *current();  // Return a pointer to the current node.
    };
}

#endif /* simpleList_hpp */
