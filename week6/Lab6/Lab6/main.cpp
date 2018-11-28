/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main file for control of the program.
 **
 ** MAIN.CPP
 *****************************************************************/

#include "validation.hpp"
#include "menu.hpp"
#include "nodes.hpp"

int main() {
    
    bool loopMenu = true;
    int value;
    
    Menu menu;
    
    Numberlist list;
    
    while(loopMenu) {
        // Switch Case using Bound Validation and menu display
        menu.showMenu(menu.mainMenu, "Main Menu");
        switch (validateBounds(1, 9)) {
                
            // Add a node to the head of the list consisting of an integer that the user has input
            case 1: {
                cout << "Please enter a value to add to the head of the doubly linked list." << endl;
                
                // Call getInt() and get the value.
                value = getInt();
                
                // Add the value to the head of the list.
                list.addHead(value);
                break;
            }
                
            // Add a node to the tail of the list consisting of an integer that the user has input
            case 2: {
                cout << "Please enter a value to add to the tail of the doubly linked list." << endl;
                
                value = getInt();
                
                list.addTail(value);
                
                break;
            }
                
            // Remove the node from the head of the list.
            case 3: {
                list.removeHead();
                break;
            }
                
            // Remove the node from the tail of the list.
            case 4: {
                list.removeTail();
                break;
            }
               
            // Traverse through the list in reverse order.
            case 5: {
                list.displayLast();
                break;
            }
            
            // Print out the first node in the list (if it's not empty).
            case 6: {
                list.getFirst();
                break;
            }
              
            // Print out the last node in the list (if it's not empty).
            case 7: {
                list.getLast();
                break;
            }
             
            // Extra Credit case that creates a linked list using the values from a file - inserts them using the addHead() function
            case 8: {
                
                int x;
                
                ifstream fileName("numbers.txt");
                
                if (!fileName) {
                    cout << "Error opening the file 'numbers.txt'." << endl << endl;
                } else {
                    cout << "Creating a linked list using the values in the 'numbers.txt' file..." << endl << endl;
                    while (fileName >> x) {
                        
                        list.addHead(x);
                        
                    }
                    
                    cout << "Finished reading from file..." << endl << endl;
                    fileName.close();
                    
                }
                
                break;
            }
            
            // Exit the Program
            case 9: {
                cout << "Exiting the Program." << endl;
                loopMenu = false;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
