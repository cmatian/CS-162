/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for menu class and functions
 **
 ** NODES.HPP
 *****************************************************************/

#ifndef nodes_hpp
#define nodes_hpp

#include "validation.hpp"

// Numberlist Class
class Numberlist {
    
protected:
    // Nested Listnode Class
    class Listnode {
    public:
        int value;
        Listnode *next;
        Listnode *prev;
        
        // Nested Listnode Constructor
        Listnode(int value, Listnode *next = nullptr, Listnode *prev = nullptr) {
            this->value = value;
            this->next = next;
            this->prev = prev;
        }
        
    };
    
    Listnode *head;
    Listnode *tail;
    
    
public:
    Numberlist();
    ~Numberlist();
    
    void addHead(int);
    void addTail(int);
    void removeHead();
    void removeTail();
    void displayFirst();
    void displayLast();
    
    // Extra Credit Getters
    void getFirst();
    void getLast();
    
};




#endif /* nodes_hpp */
