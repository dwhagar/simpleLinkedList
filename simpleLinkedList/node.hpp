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
 
 Class Declarations for the node class.
 
 Purpose:
 This class is defined to be a single node in a linked list.
 */

#ifndef node_hpp
#define node_hpp

namespace std {
    template <class dataType>
    class node {
        template <class listType> friend class simpleList;
    private:
        node *prevPtr;
        node *nextPtr;
        dataType container;
    public:
        node();                             // Create a new, blank, node.
        node(node *prv, node *nxt);         // Create a new node with pointers.
        ~node();                            // Destroy the node.
        node *next();                       // Returns the next object pointer
        node *prev();                       // Returns the previous object pointer
        dataType data();                    // Returns the nodes data.
        void data(dataType);                // Stores data in the node.
    };
}

#endif /* node_hpp */
