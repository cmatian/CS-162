/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function file for various sorting algorithms.
 **
 ** SORTING.CPP
 *****************************************************************/

#include "sorting.hpp"

/******************************************************************
 ** linearSearch Function
 **
 ** Accepts a vector, target value, and file name as arguments
 ** and uses that information to search the passed in array for the
 ** value.
 **
 ** SOURCE: N/A - I created this myself
 *******************************************************************/

void linearSearch(vector<int> array, int valueToFind, string file) {
    
    bool flag = false;
    
    for ( int i = 0; i < array.size(); i++) {
        
        if ( array[i] == valueToFind ) {
            
            flag = true;
            
            break;
            
        }
        
    }
    
    if ( flag ) {
        
        cout << file << ": Search value was found." << endl;
        
    } else {
        
        cout << file << ": Search value was not found." << endl;
        
    }
}

/******************************************************************
 ** bubbleSort function
 **
 ** Takes in the vector as a reference and uses bubble sorting 
 ** to re-arrange the values in each file in ascending order.
 **
 ** SOURCE: Starting out with C++ Early Objects - Textbook Page 615
 *******************************************************************/

void bubbleSort (vector<int> &array) {
    
    bool swap;
    
    do {
        
        swap = false;
        
        for (int i = 0; i < array.size() - 1; i++) {
            
            if (array[i] > array[i + 1]) {
                
                int temp = array[i];
                
                array[i] = array[i + 1];
                
                array[i + 1] = temp;
                
                swap = true;
                
            }
        }
        
    } while (swap);
    
    printVector(array);
    
};

/******************************************************************
 ** binarySearch Function
 **
 ** Binary search function does several things. It holds a temp
 ** vector which we push values into using fstream. I did this because I 
 ** don't know how to manipulate text files other than reading / writing 
 ** to them. After I pass the values into the vector, I use the 
 ** built-in C++ algorithm for binary search to find the target value.
 **
 ** SOURCE: http://www.cplusplus.com/reference/algorithm/binary_search/
 *******************************************************************/

void binarySearch(int target) {
    
    vector<int> array;
    fstream file;
    string openFile;

    do {
        
        cout << "Please enter the name of the file you would like to open (including the file extension)" << endl;
        getline(cin, openFile);
        
        file.open(openFile.c_str());  //Opens the input file into the stream
        if(file.fail()) {
            cout << "Error finding the file, try again.\n";
            continue;
        }
        
        break;
        
    } while ( true );
    
    // Fill the temp vector
    fillVector(array, openFile);
    
    file.close();
    
    if ( binary_search(array.begin(), array.end(), target)) {
        
        cout << openFile << ": Search value was found." << endl;
        
    } else {
        
        cout << openFile << ": Search value was not found." << endl;
        
    }

    cout << endl;
    
    
}


/******************************************************************
 ** writeVector Function
 **
 ** Pulls in the vector and file name. Write vector function 
 ** essentially creates a new file, fills it with the array data
 ** and then reads the information from the function.
 **
 *******************************************************************/

void writeVector(vector<int> array, string name) {
    
    ofstream writeFile;
    ifstream readFile;
    string newFile;
    int i;

    getline(cin, newFile);
    
    newFile += ".txt";
    
    // Write the sorted values to the file
    
    writeFile.open(newFile.c_str());
    
    for ( int i = 0; i < array.size(); i++) {
        
        writeFile << array[i] << " ";
        
    }
    
    writeFile.close();
    
    // Read the file to console
    
    readFile.open(newFile.c_str());
    
    cout << "The sorted values in \"" << newFile << "\" are as follows: ";
    
    while ( readFile >> i ) {
        
        cout << i << " ";
        
    }
    
    cout << endl;
    
    readFile.close();
    
}



/******************************************************************
 ** fillVector
 **
 ** Takes in the vector and file name as arguments and uses fstream
 ** to fill the vector with values.
 **
 *******************************************************************/

void fillVector(vector<int> &array, string file ) {
    
    int num;
    
    fstream in(file);
    
    while( in >> num ) {
        
        array.push_back(num);
        
    }
    
    
}

/******************************************************************
 ** printVector function
 **
 ** Prints out the information contained within the vector that's
 ** passed in as an argument.
 **
 *******************************************************************/

void printVector(vector<int> array) {
    
    for(int i = 0; i < array.size(); i++) {
        
        cout << array[i] << " ";
        
    }
    
    cout << endl;
    
}
