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
        node<dataType> *head;
        node<dataType> *tail;
        node<dataType> *currentPtr;
        unsigned long listSize;
    public:
        simpleList();
        ~simpleList();
        void append(dataType newData);
        void insert(dataType newData);
        void forward(unsigned long distance);
        void backwward(unsigned long distance);
        void toHead();
        void toTail();
        node<dataType> *find(dataType searchData);
        void remove();
        void clear();
        unsigned long size();
        node<dataType> *current();
    };
}

#endif /* simpleList_hpp */
