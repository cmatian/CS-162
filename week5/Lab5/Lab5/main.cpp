/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main file that controls the menu selection and recursive function calls
 **
 ** MAIN.CPP
 *****************************************************************/
// Source Citation:
// Substring Information: https://stackoverflow.com/questions/2477850/how-to-use-string-substr-function
// Cin Buffer Issues: https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer


#include "validation.hpp"
#include "recursions.hpp"

int main() {
    
    // String for Recursion Case 1
    string caseOneString;
    
    // Arrays for Recursion Case 2
    int arraySize;
    int *array;
    
    // Triangular Number Value
    int triNum;
    
    // Menu Option for input
    int menuOption;
    
    // Game Loop Boolean
    bool exitGame = false;
    
    
    do {
        // Display the Menu
        showMenu();
        
        // Validate the User's Menu Selection
        cin >> menuOption;
        while(!validateBounds(menuOption, 1, 4)) {
            cin.clear();
            cin.ignore();
            cout << "Incorrect input, please select an item within bounds." << endl;
            cin >> menuOption;
        }
        // Clear and ignore the cin buffer so that getline is using a clean stream state
        cin.clear();
        cin.ignore();
        
        // Switch Case for the Menu Selection
        switch (menuOption) {
            // Case 1
            case 1: {
                // Prompt user for string
                cout << "Please enter a string so that it can be reversed!" << endl;
                getline(cin, caseOneString);
                // If the user inputs nothing they will be prompted again.
                while(!validString(caseOneString)) {
                    cin.clear();
                    cin.ignore();
                    cout << "Empty inputs are not allowed - please enter a valid input." << endl;
                    getline(cin, caseOneString);
                }
                
                // Simultaneously pass in the argument to the reverse function and print it out
                cout << "The reverse string of " << caseOneString << " is: " << endl;
                cout << reverseString(caseOneString) << endl << endl;
                
                // Break out of the Switch statement
                break;
            }
            
            // Case 2
            case 2: {
                // Prompt user for Array Size
                cout << "Please enter the size of the array." << endl;
                cin >> arraySize;
                // Validate the integer that they entered
                while(!validateOne(arraySize)) {
                    cin.clear();
                    cin.ignore();
                    cout << "Empty inputs are not allowed - please enter a valid input." << endl;
                    cin >> arraySize;
                }
                
                // Declare and initialize Array AFTER determining the size above
                array = new int[arraySize];
                
                // Prompt User for inputs afterwards
                cout << "Please fill out the array with integers." << endl;
                for(int i = 0; i < arraySize; i++) {
                    cin >> array[i];
                    while(cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input (not an integer) - please enter an integer input." << endl;
                        cin >> array[i];
                    }
                }
                
                cout << "The sum of all the numbers in the array is: " << arraySum(array, arraySize) << endl << endl;

                // Delete the array before breaking out of the
                delete [] array;
                
                // Break out of the Switch statement
                break;
            }
                
            // Case 3
            case 3: {
                cout << "Please enter the triangular number." << endl;
                cin >> triNum;
                // Validate the integer that they entered
                while(!validateOne(triNum)) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input (not an integer) - please enter an integer input." << endl;
                    cin >> triNum;
                }
                
                cout << "The triangular number of " << triNum << " is: " << triangular(triNum) << endl << endl;
                
                // Break out of the Switch statement
                break;
            }
                
            // Case 4
            case 4: {
                cout << "Exiting the program." << endl;
                exitGame = true;
                break;
            }
        }
    } while (!exitGame);

    return 0;
}
