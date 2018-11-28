/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for program input validation
 **
 ** VALIDATION.CPP
 *****************************************************************/

#include "validation.hpp"

/******************************************************************
 ** VALIDATION OF SINGLE INT INPUTS
 **
 ** This function will effectively return a true or false value
 ** based on whether or not the input is an int.
 **
 *****************************************************************/
bool validateOne(int value) {
    if (value > 0 && value % 1 == 0) {
        return true;
    } else {
        return false;
    }
}

/******************************************************************
 ** VALIDATION OF MENU ITEM BOUNDARIES
 **
 ** This function is used for when I need the user to input
 ** a menu item that is within the correct boundaries.
 ** If a menu has 4 options (denoted [1] - [4]), we pass in
 ** the input value, the minimum boundary limit, and the maximum
 ** boundary limit. We then compare the value to the limits and
 ** return whether or not it's true or false.
 **
 *****************************************************************/
bool validateBounds(int input, int min, int max) {
	
	if (input >= min && input <= max) {
			return true;
		} else {
			// Clears cin buffer
			cin.clear();
			cin.ignore();
			return false;
		}
}

/******************************************************************
 ** INPUT AND VALIDATION OF DOUBLE
 **
 ** This function will request the user to input a value with a 
 ** decimal place and fail them if it's an int. Does a little more
 ** than the validation items above because this handles
 ** the cin.clear/ignoring and cout statements.
 ** Call this function when you need the user to input something
 **
 *****************************************************************/

double getDouble() {
    double x;
    cin >> x;
    while ( x == int(x)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, invalid input. Please enter a number with a decimal place." << endl;
        cin >> x;
    }
    return x;	
}

/******************************************************************
 ** SHOW MENU ITEMS
 **
 ** Simple menu function that, when called, displays all of the
 ** associated menu options for the university simulation.
 ** There is usually 4 items altogether (not including EC - yet).
 **
 *****************************************************************/

void showMenu() {
    cout << "***************[ MAIN MENU ]****************" << endl;
    cout << setw(2) << ' ' << "[1] Building Directory" << endl;
    cout << setw(2) << ' ' << "[2] Persons Directory" << endl;
    cout << setw(2) << ' ' << "[3] Conscript Individual for Work" << endl;
    cout << setw(2) << ' ' << "[4] Exit the Program" << endl;
    cout << "********************************************" << endl;
    
}
