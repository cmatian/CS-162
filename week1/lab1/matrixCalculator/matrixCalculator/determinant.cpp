/*************************************************************************************************
 ** Author: Chris Matian
 ** Date: 10/01/2017
 ** Description: This is the FUNCTION file for the determinant function
 *************************************************************************************************/

#include "determinant.hpp"

int determinant(int ** array, int size) {
    
    if(size == 2) {
        
        // Organized Indexing for a 2x2 Array
        int a = array[0][0];
        int b = array[0][1];
        int c = array[1][0];
        int d = array[1][1];
        
        int result = a * d - b * c;
        return result;
        
    } else if (size == 3) {
        
        
        // Organized Indexing for a 3x3 Array
        int a = array[0][0];
        int b = array[0][1];
        int c = array[0][2];
        int d = array[1][0];
        int e = array[1][1];
        int f = array[1][2];
        int g = array[2][0];
        int h = array[2][1];
        int i = array[2][2];
        
        
        // Make calculations based on the determinant formula.
        int valA = a * ((e * i) - (f * h));
        int valB = b * ((d * i) - (f * g));
        int valC = c * ((d * h) - (e * g));
        
        int result = valA - valB + valC;
        return result;
    }
    
    return 0;
}
