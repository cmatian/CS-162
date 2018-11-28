/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: main.cpp file for running the letter/paragraph counter
 ************************************************************************/

/* Source Citation Below: */
// Reference for ios:in||out for input /output streams https://stackoverflow.com/questions/28338775/what-is-iosiniosout
// c.str() debugging.... https://stackoverflow.com/questions/6323619/c-ifstream-error-using-string-as-opening-file-path
// Chapter 13 of the Textbook - Advanced File I/O Operations - referenced some file input/output operations

// LIBRARY / DEPENDANCIES LOCATED IN THE COUNT.HPP HEADER FILE
// No need to repeat code throughout the document after all.
#include "count.hpp"

int main() {
    // Variable Declarations
    ifstream fileInput;
    ofstream fileOutput;
    
    // Strings
    string inFile,
            outFile;
    
    // Count Array logs the count for each character - utilized my input/output functions
    int count[26] = { 0 },
        i = 1;
    
    // Prompt the user to first enter the name of the file to be opened (TBO)
    cout << "Hello, please enter the name of the file that you would like to open: " << endl;
    cin >> inFile;
    
    // Input is opened by the following line...
    // I had to use a .c_str() because of some strange makefile error. Not entirely too sure what was triggering it to begin with.
    // Compiling manually with g++ 11 worked without a hitch.
    fileInput.open(inFile.c_str());
    
    // If condition simply checks to make sure that you're inputting a valid file and proceeds as normal into the nested while loop block
    if(fileInput.good()) {
        // While loop to iterate through the file
        while(fileInput.good()) {
            
            //count_letters() function call
            count_letters(fileInput, count);
            
            // Output File Name Generation
            cout << "Please enter a name for the output file: " << i << endl;
            cin >> outFile;
            
            // Increment the i in preparation for the next file
            i++;
            
            // Open the output file
            fileOutput.open(outFile.c_str());
            
            //output_letters() function call
            output_letters(fileOutput, count);
            
            // close out the output file
            fileOutput.close();
        }
    } else {
        cout << "Sorry, the file could not be identified" << endl << endl;
    }
    
    // Close input file
    fileInput.close();
    
    cout << endl << endl;
    
    
    
    return 0;
}
