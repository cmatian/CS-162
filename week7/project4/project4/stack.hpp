/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for structured linked lists.
 **
 ** STACK.HPP
 *****************************************************************/

#ifndef stack_hpp
#define stack_hpp

#include "validation.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"

// Main Stack Class Object
class Stack {
    
protected:
    // Stack Node Ptr Object
    class StackNode {
    public:
        Character *character;
        StackNode *next;
        
        // Nested StackNode Constructor
        StackNode(Character *character, StackNode *next = nullptr) {
            
            this->character = character;
            this->next = next;
            
        }
        
    };
    
    StackNode *head;
    
public:
    
    
    // Constructor and Destructor
    Stack();
    ~Stack();
    
    void push(Character *);
    
    Character* pop();
    
};




#endif /* stack_hpp */
