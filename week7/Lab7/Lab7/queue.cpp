/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for circular, doubly linked queue data
 ** structures
 **
 ** QUEUE.CPP
 *****************************************************************/

#include "queue.hpp"

/******************************************************************
 ** Queue::~Queue()
 **
 ** Simply checks to see if the list is not empty. If it is the
 ** destructor has nothing to delete, otherwise the destructor
 ** will call the removeFront() function and delete each item
 ** in the list until there's nothing left in the list.
 **
 *****************************************************************/

Queue::~Queue() {
    
    while(this->isEmpty() == false) {
        
        removeFront();
        
    }
    
}

/******************************************************************
 ** Queue::isEmpty()
 **
 ** Returns a true or false based on whether the head is a nullptr.
 ** If true the list is empty, otherwise the list is not empty.
 **
 *****************************************************************/

bool Queue::isEmpty() {
    
    if(head == nullptr) {
        
        return true;
        
    }
    
    else {
        
        return false;
        
    }
}

/******************************************************************
 ** Queue::addBack(int)
 **
 ** Function adds items to the back of the queue list. 
 ** It reassigns the head->next / head->prev values based
 ** each time an item is added to the list. See details below.
 **
 *****************************************************************/

void Queue::addBack(int value_in) {
    
    QueueNode *nodeptr = new QueueNode(value_in);
    
    // Empty list
    if(this->isEmpty()) {
        
        head = nodeptr;
        head->next = head->prev = head;
        
    }
    
    // List is not empty
    else {
    
        // Create a tail node that is set to the head->prev node
        QueueNode *tail = head->prev;
        
        // nodeptr->prev is set to the tail which is the head->prev value. The tail node changes each time we add to the list.
        nodeptr->prev = tail;
        // nodeptr->next is set to always equal the head.
        nodeptr->next = head;
        
        // tail->next (aka head->prev) is set to the nodeptr we created.
        tail->next = nodeptr;
        
        // head->prev is set to the nodeptr we created.
        head->prev = nodeptr;
        
    }
}

/******************************************************************
 ** Queue::getFront()
 **
 ** Function returns either -9999 if the list is empty, or
 ** it returns that value at the head (front) of the list.
 **
 *****************************************************************/


int Queue::getFront() {
    
    if (this->isEmpty()) {
        
        return -9999;
        
    }
    
    else {
        
        return head->value;
        
    }
    
}

/******************************************************************
 ** Queue::removeFront()
 **
 ** Function removes the first node in the list. It first runs
 ** a check to see if the list is empty. Then it checks to see if
 ** there is only one node in the list. Otherwise, it runs normally
 ** and creates a temp node and reassigns the head to the next
 ** node in the list. After that it reassigns the head's previous
 ** node to the head node, and finally deletes the temp node from
 ** memory.
 **
 *****************************************************************/

void Queue::removeFront() {
    
    // Is the list Empty?
    if (this->isEmpty()) {
        
        cout << "The list is empty. Please fill it with values first." << endl << endl;
        
        return;
        
    }
    
    // Only one node in the list? Determined by checking to see if the head is equal to the head (head->next)
    else if ( head == head->next ) {
        
        // Delete the head
        delete head;
        
        // Set the head to a nullptr
        head = nullptr;
        
    }
    
    // More than one node in the list?
    else {
      
        // Create a temp node pointer that is defined as the head node
        QueueNode *temp = head;
        
        //Reassign the head to the next node in the list
        head = head->next;
        
        // The new head has it's previous node set to the original head's previous node.
        head->prev = temp->prev;
        
        // The previous node of the head has its next node reassigned to the new head node
        head->prev->next = head;
        
        
        // Delete the temp node
        delete temp;
        
    }

}



/******************************************************************
 ** Queue::printQueue()
 **
 ** Function prints out the queue. Checks to see if it's empty first.
 ** If it's not empty it will run through each node item and display
 ** the value until it reaches the node which is assigned as the head.
 ** That means we've reached the end of the list.
 **
 *****************************************************************/

void Queue::printQueue() {
    // Start at the head
    QueueNode *nodeptr = head;
    
    if(head == nullptr) {
        
        cout << "The list is empty. Please fill it with values first." << endl << endl;
        
        return;
        
    }
    
    // Have to use a do-while loop because we're checking to see if the head has been reached.
    
    do {
        
        cout << nodeptr->value << " ";
        
        nodeptr = nodeptr->next;
        
    } while ( nodeptr != head );
    
    cout << endl << endl;
}
