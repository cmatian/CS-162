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
 ** If a menu has 4 options (denoted [1] - [4]) the minimum boundary limit,
 ** and the maximum boundary limit. We then compare the value to the limits and
 ** return the input if its valid. Otherwise we make them re-enter the information.
 **
 *****************************************************************/
int validateBounds(int min, int max) {
    int input;
    bool isValid = false;
    
    while (!isValid) {
        if (cin >> input && input >= min && input <= max) {
            isValid = true;
            cin.ignore();
        } else {
            cout << "Please enter a value that corresponds with the menu item above." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return input;
}

/******************************************************************
 ** INPUT AND VALIDATION OF DOUBLE
 **
 ** This function will request the user to input a value with a
 ** decimal place and fail them if it's an int. Does a little more
 ** than the validation items above because this handles
 ** the cin.clear/ignoring and cout statements.
 ** Call this function when you need the user to input a double.
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
 ** INPUT AND VALIDATION OF INT
 **
 ** Requests an integer input from the user and checks the input
 ** using the validateOne(x) function above. If the input fails
 ** the check it will query the user again.
 **
 *****************************************************************/

int getInt() {
    int x;
    cin >> x;
    while (!validateOne(x)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, invalid input. Please enter a positive integer." << endl;
        cin >> x;
    }
    
    return x;
}

/******************************************************************
 ** EMPTY STRING VALIDATION
 **
 ** This function will prevent blank inputs.
 **
 *****************************************************************/

bool validString(string foo) {
    if(foo.length() >= 1) {
        return true;
    } else {
        cin.ignore();
        cin.clear();
        return false;
    }
}

