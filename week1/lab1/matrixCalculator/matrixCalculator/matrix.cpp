/*************************************************************************************************
 ** Author: Chris Matian
 ** Date: 10/01/2017
 ** Description: This is the FUNCTION file for the readMatrix function
 *************************************************************************************************/

#include "matrix.hpp"

void readMatrix(int ** array, int size) {
    cout << "Please enter " << size * size << " integers." << endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> array[i][j];
        }
    }
    
    // Render the Matrix
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
