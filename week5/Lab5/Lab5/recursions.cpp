/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for recursion calls
 **
 ** RECURSIONS.CPP
 *****************************************************************/

#include "recursions.hpp"

/******************************************************************
 ** REVERSE STRING FUNCTION
 **
 ** This function accepts a parameter as an argument and sets a
 ** base case where once it reaches only 1 char in the parameter
 ** it will exit the function. It uses recursion to output the 
 ** reversed string that is passed in. 
 **
 *****************************************************************/
string reverseString(string param) {
    
    //Base Case
    // Only one character left in the string so we exit the function and return the param
    if (param.length() == 1) {
        return param;
    }
    
    // Substring takes in two arguments (the character position and the length) and appends the first character as the last
    return reverseString(param.substr(1, param.length())) + "\n" + param.at(0);
}


/******************************************************************
 ** ARRAY SUM FUNCTION
 **
 ** This function passes in an array and its size, and uses 
 ** those variables to return the first index of the array plus
 ** the recursive function call. The recursive function call
 ** uses the array index + 1, and the size of the array - 1.
 **
 *****************************************************************/

int arraySum(int array[], int size) {
    if(size == 1) {
        // Break Case
        return array[0];
    } else {
        // Go through the stack (LIFO) and return the first value in the array + the arraySum index at 1 (size is subtracted by 1)
        return array[0] + arraySum(array + 1, size - 1);
    }
}

/******************************************************************
 ** TRIANGULAR NUMBER FUNCTION
 **
 ** The triangular function accepts and integer value and 
 ** first checks the base case. If not true it will skip and go into
 ** the else condition where it will return the num plus the recursive
 ** function. The recursive function calls num - 1 each time it's called.
 ** If the input is 3, the recursive function does 3 + 2 + 1 
 ** which is equal to 6. An input of 6 results in 21 because 6 + 5
 ** + 4 + 3 + 2 + 1 is equal to 21. 
 **
 *****************************************************************/

int triangular(int num) {
    if(num == 1) {
        return num;
    } else {
        return num + triangular(num - 1);
    }
}

