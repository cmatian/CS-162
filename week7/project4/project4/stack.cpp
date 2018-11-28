/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for structured linked lists.
 **
 ** STACK.CPP
 *****************************************************************/

#include "stack.hpp"

/******************************************************************
 ** Stack Constructor
 **
 ** Initializes the head to a nullptr when first created.
 **
 *****************************************************************/

Stack::Stack() {
    
    head = nullptr;
    
}

/******************************************************************
 ** Stack Destructor
 **
 ** Goes through the stack and deletes garbage nodes until
 ** it hits a nullptr value.
 **
 *****************************************************************/

Stack::~Stack(){
    
    StackNode *nodeptr = head;
    
    while (nodeptr != nullptr){
        
        StackNode *garbage = nodeptr;
        
        nodeptr = nodeptr->next;
        
        delete garbage;
        
        garbage = nullptr;
        
    }
}

/******************************************************************
 ** push() function
 **
 ** Pushes Character's into the stack
 **
 *****************************************************************/

void Stack::push(Character *character) {
    
    StackNode *nodeptr = new StackNode(character);
    
    // No elements in the stack
    
    if (head == nullptr) {
        
        nodeptr->next = nullptr;
        
    } else {
        
        nodeptr->next = head;
        
    }
    
    head = nodeptr;
    
}

/******************************************************************
 ** pop() function
 **
 ** Pop's Character's out of the stack (from the top) 
 ** and returns them to the variable that's calling it.
 **
 *****************************************************************/


Character* Stack::pop() {
    
    // If stack isn't empty...
    
    if (head != nullptr) {
        
        StackNode *nodeptr = head;
        
        head = head->next;
        
        Character *copy = nodeptr->character;
        
        delete nodeptr;
        
        return copy;
        
    } else {
        
        return nullptr;
        
    }
}



