/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for Queue class and functions
 **
 ** QUEUE.HPP
 *****************************************************************/

#ifndef nodes_hpp
#define nodes_hpp

#include "validation.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

// Numberlist Class
class Queue {
    
protected:
    // Nested Listnode Class
    class QueueNode {
    public:
        Character *character;
        QueueNode *next;
        QueueNode *prev;
        
        // Nested Listnode Constructor
        QueueNode(Character *character, QueueNode *next = nullptr, QueueNode *prev = nullptr) {
            this->character = character;
            this->next = next;
            this->prev = prev;
        }
        
    };
    
public:
    QueueNode *head;
    QueueNode *tail;
    
    
    Queue();
    ~Queue();
    
    void push(Character *);
    
    Character* pop();
    
    void remove();
    bool isEmpty();
    void print();
    void getFirst();
    void getLast();
    
};




#endif /* nodes_hpp */
