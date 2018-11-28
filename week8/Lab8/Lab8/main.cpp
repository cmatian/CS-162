/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main File for running the Lab 8 Program
 **
 ** MAIN.CPP
 *****************************************************************/

#include "sorting.hpp"

int main() {
    
    // Variable Declaration
    int target;
    
    // Vector Declarations
    vector<int> array1;
    vector<int> array2;
    vector<int> array3;
    vector<int> array4;
    
    // Read Values From File and place them into a vector
    fillVector(array1, "num.txt");
    fillVector(array2, "beg.txt");
    fillVector(array3, "mid.txt");
    fillVector(array4, "end.txt");
    
    // Simple Search Algorithm Call
    cout << endl;
    cout << "============== [ Simple Search ] ==============" << endl;
    cout << setw(3) << ' ' << "What value would you like to search for?" << endl;
    cout << "===============================================" << endl;
    cout << endl;
    
    target = integerValidation();
    // Clear the integerValidation() cin buffer
    cin.clear();
    cin.ignore();
    
    linearSearch(array1, target, "num.txt");
    linearSearch(array2, target, "beg.txt");
    linearSearch(array3, target, "mid.txt");
    linearSearch(array4, target, "end.txt");
    
    
    cout << endl;
    cout << "============== [ Bubble Sorting ] ==============" << endl;
    cout << setw(3) << ' ' << "Bubble Sort will now run..." << endl;
    cout << "================================================" << endl;
    cout << endl;
    
    cout << "Sorting num.txt vector..." << endl;
    bubbleSort(array1);
    cout << "Enter a name for the file (no file extension) to export the sorted 'num.txt' values." << endl;
    writeVector(array1, "num.txt");
    
    cout << endl;
    
    cout << "Sorting beg.txt vector..." << endl;
    bubbleSort(array2);
    cout << "Enter a name for the file (no file extension) to export the sorted 'beg.txt' values." << endl;
    writeVector(array2, "beg.txt");
    
    cout << endl;
    
    cout << "Sorting mid.txt vector..." << endl;
    bubbleSort(array3);
    cout << "Enter a name for the file (no file extension) to export the sorted 'mid.txt' values." << endl;
    writeVector(array3, "mid.txt");
    
    cout << endl;
    
    cout << "Sorting end.txt vector..." << endl;
    bubbleSort(array4);
    cout << "Enter a name for the file (no file extension) to export the sorted 'end.txt' values." << endl;
    writeVector(array4, "end.txt");
     
    
    cout << endl;
    cout << "================== [ Binary Search ] ==================" << endl;
    cout << setw(3) << ' ' << "Which value would you like to binary search for?" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    
    target = integerValidation();
    // Clear the integerValidation() cin buffer
    cin.clear();
    cin.ignore();
    
    cout << "Binary Search Prompt for first file..." << endl;
    binarySearch(target);
    
    cout << endl;
    
    cout << "Binary Search Prompt for second file..." << endl;
    binarySearch(target);
    
    cout << endl;
    
    cout << "Binary Search Prompt for third file..." << endl;
    binarySearch(target);
    
    cout << endl;
    
    cout << "Binary Search Prompt for fourth file..." << endl;
    binarySearch(target);
    
    cout << endl;
    
    
    return 0;
}
