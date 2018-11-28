/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for queue class and functions
 **
 ** QUEUE.HPP
 *****************************************************************/

#ifndef queue_hpp
#define queue_hpp

#include "validation.hpp"

class Queue {
    
protected:
    
    struct QueueNode {
        
    public:
        QueueNode *next;
        QueueNode *prev;
        int value;
        
        // QueueNode Constructor
        QueueNode(int value, QueueNode *next = nullptr, QueueNode *prev = nullptr) {
            this->value = value;
        }
        
    };
    
    
    QueueNode *head;
    
    
public:
    // Queue Constructor
    Queue() {
        head = nullptr;
    }
    
    // Destructor
    ~Queue();
    
    
    // Queue Member Functions
    bool isEmpty();
    
    void addBack(int);
    
    int getFront();
    
    void removeFront();
    
    void printQueue();
    
    
    
    
};




#endif /* queue_hpp */
