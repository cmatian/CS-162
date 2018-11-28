/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for structured linked lists.
 **
 ** NODES.CPP
 *****************************************************************/

#include "nodes.hpp"

/******************************************************************
 ** Numberlist() Constructor
 **
 ** When a Numberlist is created, the head and the tail are
 ** initialized to nullptrs.
 **
 *****************************************************************/

Numberlist::Numberlist() {
    head = nullptr;
    tail = nullptr;
}

/******************************************************************
 ** ~Numberlist() Destructor
 **
 ** When the program is closing, the destructor is called and
 ** runs through the Listnode - beginning from the head, and 
 ** deletes each nodePtr until it reaches a nullptr.
 **
 *****************************************************************/

Numberlist::~Numberlist() {
    Listnode *nodePtr = head;
    
    while(nodePtr != nullptr) {
        
        Listnode *garbage = nodePtr;
        
        nodePtr = nodePtr->next;
        
        delete garbage;
    }
}

/******************************************************************
 ** addHead Function
 **
 ** Simple add function that creates a new Listnode and inserts it
 ** into the head of the list.
 **
 *****************************************************************/

void Numberlist::addHead(int value) {
    
    // Create a new Listnode for the nodePtr
    Listnode *nodePtr = new Listnode(value);
    
    // Set the nodePtr value
    //nodePtr->value = value;
    
    // Check if there are no values in the list
    if ( tail == nullptr ){
        
        head = tail = nodePtr;
        
    } else {
        
        // Set the next node equal to head, the previous node to the nodePtr, and finally set the head to the nodePtr.
        
        nodePtr->next = head;
        head->prev = nodePtr;
        head = nodePtr;
        
    }
    // Call the display function
    this->displayFirst();
}

/******************************************************************
 ** addTail Function
 **
 ** Simple add function that creates a new Listnode and inserts it 
 ** into the tail of the list.
 **
 *****************************************************************/
void Numberlist::addTail(int value) {
    
    Listnode *nodePtr = new Listnode(value);
    
    nodePtr->value = value;
    
    if ( head == nullptr ) {
        
        tail = head = nodePtr;
        
    } else {
        
        nodePtr->prev = tail;
        tail->next = nodePtr;
        tail = nodePtr;
        
    }
    
    this->displayFirst();
    
}

/******************************************************************
 ** removeHead Function
 **
 ** The remove head function removes nodes in a list beginning
 ** at the head - more details within the code.
 **
 *****************************************************************/

void Numberlist::removeHead() {
    
    Listnode *nodePtr = head;
    
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
        
        // Display the list
        this->displayFirst();
        
    }
}

/******************************************************************
 ** removeTail Function
 **
 ** The remove tail function removes nodes in a list beginning
 ** at the tail. The operation is the complete same as the above
 ** except the values have been adjusted for tail nodes.
 **
 *****************************************************************/

void Numberlist::removeTail() {
    
    Listnode *nodePtr = tail;
    
    if ( nodePtr == nullptr ) {
        
        cout << "Cannot remove the tail value because the list is empty. Please fill it with values first." << endl << endl;
        
    } else {
        
        if (tail->prev != nullptr) {
            
            tail->prev->next = nullptr;
            
        }
        
        if ( ( head->next == nullptr ) && ( tail->prev == nullptr ) ) {
            
            head = nullptr;
            
        }
        
        
        tail = tail->prev;
        
        delete nodePtr;
        
        this->displayFirst();
    
    }
}


/******************************************************************
 ** displayFirst Function
 **
 ** Checks to see if the linked list is empty, otherwise
 ** it will print out each node until it reaches a nullptr. This
 ** display function will start at the head and end at the tail.
 **
 **
 *****************************************************************/

void Numberlist::displayFirst() {
    // Start at the head
    Listnode *nodePtr = head;
    
    if(nodePtr == nullptr) {
        
        cout << "The list is empty. Please fill it with values first." << endl << endl;
        
        return;
        
    }
        
    while(nodePtr) {
        
        cout << nodePtr->value << " ";
        
        nodePtr = nodePtr->next;
            
    }
        
    cout << endl << endl;
}

/******************************************************************
 ** displayLast Function
 **
 ** Checks to see if the linked list is empty, otherwise
 ** it will print out each node until it reaches a nullptr. This 
 ** display function will start at the tail and end at the head.
 **
 **
 *****************************************************************/

void Numberlist::displayLast() {
    // Start at the tail
    Listnode *nodePtr = tail;
    
    if(nodePtr == nullptr) {
        
        cout << "The list is empty. Please fill it with values first." << endl << endl;
        
        return;
        
    }
        
    while(nodePtr) {
        
        cout << nodePtr->value << " ";
        
        nodePtr = nodePtr->prev;
        
    }
        
    cout << endl << endl;
    
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

void Numberlist::getFirst() {
    
    Listnode *nodePtr = head;
    
    if ( nodePtr == nullptr ) {
        cout << "There is no value in the first node to display - the list is empty." << endl << endl;
    }
    
    else {
        
        cout << "The first (head) node value is " << nodePtr->value << endl << endl;
        
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

void Numberlist::getLast() {
    
    Listnode *nodePtr = tail;
    
    if ( nodePtr == nullptr ) {
        cout << "There is no value in the last node to display - the list is empty." << endl << endl;
    }
    
    else {
        
        cout << "The last (tail) node value is " << nodePtr->value << endl << endl;
        
    }
}
