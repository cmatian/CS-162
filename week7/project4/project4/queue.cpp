/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for structured linked lists.
 **
 ** QUEUE.CPP
 *****************************************************************/

#include "queue.hpp"

/******************************************************************
 ** Queue() Constructor
 **
 ** When a Numberlist is created, the head and the tail are
 ** initialized to nullptrs.
 **
 *****************************************************************/

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

/******************************************************************
 ** ~Queue() Destructor
 **
 ** When the program is closing, the destructor is called and
 ** runs through the Listnode - beginning from the head, and 
 ** deletes each nodePtr until it reaches a nullptr.
 **
 *****************************************************************/

Queue::~Queue() {
    QueueNode *nodePtr = head;
    
    while(nodePtr != nullptr) {
        
        QueueNode *garbage = nodePtr;
        
        nodePtr = nodePtr->next;
        
        delete garbage;
        
    }
    
}

/******************************************************************
 ** remove() Function
 **
 ** This function was created for use in a while loop. 
 ** It runs while the head is not equal to a nullptr, and it
 ** removes any existing nodes from the list.
 **
 *****************************************************************/

void Queue::remove() {
    
    QueueNode *nodePtr = head;
    
    // Check if the list is empty
    if(nodePtr == nullptr) {
        
        cout << "Cannot remove the head value because the list is empty. Please fill it with values first." << endl << endl;
        
    } else {
        
        // If the next node is not a nullptr, we set the head value to a nullptr.
        if (head->next != nullptr) {
            
            head->next->prev = nullptr;
            
        }
        
        // Check to see if it's the only value in the list - if that is the case the tail is set to a nullptr.
        if ( ( head->next == nullptr ) && ( tail->prev == nullptr ) ) {
            
            tail = nullptr;
            
        }
        
        // Change the head node to the next node (can either be a value or a nullptr)
        
        head = head->next;
        
        // Delete the nodePtr
        
        delete nodePtr;
        
    }
}




/******************************************************************
 ** push() Function
 **
 ** Simple add function that creates a new Listnode and inserts it 
 ** into the tail of the list.
 **
 *****************************************************************/
void Queue::push(Character *character) {
    
    QueueNode *nodePtr = new QueueNode(character);
    
    if ( head == nullptr ) {
        
        tail = head = nodePtr;
        
    } else {
        
        nodePtr->prev = tail;
        tail->next = nodePtr;
        tail = nodePtr;
        
    }
}

/******************************************************************
 ** pop() Function
 **
 ** The remove head function removes nodes in a list beginning
 ** at the head - more details within the code.
 **
 *****************************************************************/


Character* Queue::pop() {
    
    if (head != nullptr) {
        
        QueueNode* nodeptr = head;
        
        head = nodeptr->next;
        
        Character* copy = nodeptr->character;
        
        delete nodeptr;
        
        return copy;
    }
    
    else {
        
        return nullptr;
        
    }
    
}


/******************************************************************
 ** print() Function
 **
 ** Checks to see if the linked list is empty, otherwise
 ** it will print out each node until it reaches a nullptr. This
 ** display function will start at the head and end at the tail.
 **
 **
 *****************************************************************/

void Queue::print() {
    // Start at the head
    QueueNode *nodePtr = head;
    
    if(nodePtr == nullptr) {
        
        cout << "The list is empty. Please fill it with values first." << endl << endl;
        
        return;
        
    }
        
    while(nodePtr) {
        
        cout << "( " << nodePtr->character->getName() << " [" << nodePtr->character->getType() << "] )" << " ";
        
        nodePtr = nodePtr->next;
            
    }
        
    cout << endl << endl;
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
 ** getFirst Function
 **
 ** Simple getter function that prints out the first node (head)
 ** value. If the list is empty it will notify the user that the
 ** list is empty.
 **
 **
 *****************************************************************/

void Queue::getFirst() {
    
    QueueNode *nodePtr = head;
    
    if ( nodePtr == nullptr ) {
        cout << "There is no value in the first node to display - the list is empty." << endl << endl;
    }
    
    else {
        
        cout << "The first (head) node value is " << nodePtr->character->getName() << endl << endl;
        
    }
}

/******************************************************************
 ** getLast Function
 **
 ** Simple getter function that prints out the last node (tail)
 ** value. If the list is empty it will notify the user that the
 ** list is empty.
 **
 **
 *****************************************************************/

void Queue::getLast() {
    
    QueueNode *nodePtr = tail;
    
    if ( nodePtr == nullptr ) {
        cout << "There is no value in the last node to display - the list is empty." << endl << endl;
    }
    
    else {
        
        cout << "The last (tail) node value is " << nodePtr->character->getName() << endl << endl;
        
    }
}
