/*************************************************************************************************
 ** Author: Chris Matian
 ** Date: 10/01/2017
 ** Description: This is the client main.cpp file that executes and runs the program. 
 *************************************************************************************************/

// Source Citation:
//
// Makefile References
// https://stackoverflow.com/questions/16886591/how-do-i-enable-c11-in-gcc
// http://mrbook.org/blog/tutorials/make/
// https://www.youtube.com/watch?time_continue=200&v=_r7i5X0rXJk
//
// 2d Array References
// https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
//


// Include Files and dependancies - namespaces are also declared in the header files. So no need to repeat them here.
// Note to Grader - if there's a cleaner / better way of organizing namespaces with multiple files please let me know.
#include "matrix.hpp"
#include "determinant.hpp"
#include <limits>

int main() {
    
    // Array Pointer Declaration
    int ** array;
    int choice;

    // Variable Declarations
    int size;
    
    // Menu Options
    cout << "*~~~~~~~*" << endl;
    cout << "MAIN MENU" << endl;
    cout << "*~~~~~~~*" << endl;
    cout << "What kind of Matrix would you like to generate?" << endl;
    cout << "[1]: 2x2 Matrix" << endl;
    cout << "[2]: 3x3 Matrix" << endl;
    cout << "[3]: Exit the Program" << endl;
        
    // Menu Choice
    cin >> choice;
    
    // Input validation for the menu
    // I only managed to do input validation for the menu itself - not the actual integer inputs when entering values
    // for the matrixes. Will sit down with a tutor and figure out a way to make this code better.
    while((choice < 1) || (choice > 3)) {
        
        cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        cout << "ERROR! Please select a valid menu number. [1 - 3]" << endl;
        cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
        
        // Re-display the Menu each time the user fails to input a value of 1 to 3
        cout << "*~~~~~~~*" << endl;
        cout << "MAIN MENU" << endl;
        cout << "*~~~~~~~*" << endl;
        cout << "What kind of Matrix would you like to generate?" << endl;
        cout << "[1]: 2x2 Matrix" << endl;
        cout << "[2]: 3x3 Matrix" << endl;
        cout << "[3]: Exit the Program" << endl;
        
        // Clear bad inputs and ask the user to re-enter a valid value
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cin >> choice;
    }
    
    // Conditional Block for determining the size of the matrix or whether the user wants to exit the function
    if(choice == 1) {
        // Size of the Matrix is set to 2
        size = 2;
    } else if(choice == 2) {
        // Size of the Matrix is set to 3
        size = 3;
    } else {
        // Exits the program if the user selects 3.
        return 0;
    }
        
    // Dynamic Memory Creation
    // If size = 2 it will create a 2d array with 2 columns and 2 rows.
    // If size = 3 it will create a 2d array with 3 columns and 3 rows.
    array = new int * [size];
    for (int i = 0; i < size; i++) {
        array[i] = new int[size];
    }
    
    // Call readMatrix function
    readMatrix(array, size);
    
    // Output results of the determinant function
    cout << "The determinant is " << determinant(array, size) << endl;
    
    // Dynamic Memory Deletion
    for (int i = 0; i < size; i++) {
        delete [] array[i];
    }
    delete [] array;
    

    return 0;
}
