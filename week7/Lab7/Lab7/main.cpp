/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main file for control of the program.
 **
 ** MAIN.CPP
 *****************************************************************/

#include "menu.hpp"
#include "queue.hpp"
#include "validation.hpp"


int main() {
    
    bool loopMenu = true;
    int value;
    
    Menu menu;
    
    Queue list;
    
    
    while(loopMenu) {
        
        // Switch Case using Bound Validation and menu display
        menu.showMenu(menu.mainMenu, "Main Menu");
        switch (validateBounds(1, 5)) {
                
                // Add a node to the back of the queue.
            case 1: {
                
                cout << "Please enter a value to add to the back of the queue" << endl;
                
                // Call getInt() and get the value.
                value = getInt();
                
                // Add the value to the back of the list.
                list.addBack(value);
                
                break;
                
            }
                
                // Display the front node value of the list
            case 2: {
                
                value = list.getFront();
                
                if(value != -9999) {
                    
                    cout << value << endl << endl;
                    
                }
                
                else {
                    
                    cout << "The list is empty. Please fill it with values first." << endl << endl;
                    
                }
                
                break;
            }
                
                // Remove the front node value from the queue list
            case 3: {
                
                list.removeFront();
                
                break;
                
            }
                
                // Display the queue
            case 4: {
                
                list.printQueue();
                
                break;
            }
                
                // Exit the program
            case 5: {
                cout << "Exiting the Program." << endl;
                loopMenu = false;
                break;
            }
        }
    }
    
    cout << endl;
    
    return 0;
}
