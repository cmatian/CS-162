/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Main.cpp function file - runs the University simulation.
 **
 ** MAIN.CPP
 *****************************************************************/

#include "validation.hpp"
#include "university.hpp"
#include "person.hpp"

// Main
int main() {
    
    bool runLoop = true;
    int option;
    int doWork;
    
    // Create Uni object
    University uni;
    
    cout << uni.getUniName() << endl;
    
    // Make Buildings
    Building b1("Cascade Hall", 38765, "601 SW 17TH ST. CORVALLIS, OR 97331");
    Building b2("Fairbanks Hall", 37286, "220 SW 26TH ST CORVALLIS, OR 97331");
    Building b3("Energy Center", 21575, "3452 SW JEFFERSON WAY CORVALLIS, OR 97331");
    
    // Make Student
    Student s1("Jack", 21);
    
    // Make Instructor
    Instructor i1("Bill", 36);
    
    
    // Add Students/Instructors to Persons Vector
    uni.persons.push_back(&s1);
    uni.persons.push_back(&i1);
    
    
    // Add Buildings to Buildings Vector
    uni.buildings.push_back(&b1);
    uni.buildings.push_back(&b2);
    uni.buildings.push_back(&b3);
    
    // Do While Loop for the University Information System
    do {
        showMenu();
        cin >> option;
        while(!validateBounds(option, 1, 4)) {
            cin.ignore();
            cin.clear();
            cout << "Incorrect menu item, try again." << endl;
            cin >> option;
        }
        switch (option) {
            // Print Information about all buildings at the University
            case 1: {
                cout << "************[" << uni.getUniName() << "Buildings ]************" << endl << endl;
                for(int i = 0; i < uni.buildings.size(); i++) {
                    cout << "[" << i + 1 << "]: Name: " << uni.buildings[i]->bName() << endl;
                    cout << setw(5) << ' ' << "Size: " << uni.buildings[i]->bSize() << "(sqft)" << endl;
                    cout << setw(5) << ' ' << "Addr: " << uni.buildings[i]->bAddress() << endl;
                    cout << endl;
                }
                cout << "***********************************************************" << endl << endl;
                break;
            }
                
            // Print Information of every person at the University
            case 2: {
                cout << "*************[" << uni.getUniName() << "Persons ]*************" << endl << endl;
                for(int i = 0; i < uni.persons.size(); i++) {
                    cout << "[" << i + 1 << "]: ";
                    uni.persons[i]->showPerson();
                    cout << endl;
                }
                cout << "***********************************************************" << endl << endl;
                break;
            }
                
            // Choose a Person to do work
            case 3: {
                
                cout << "*************[" << uni.getUniName() << "Persons ]*************" << endl << endl;
                for(int i = 0; i < uni.persons.size(); i++) {
                    cout << "[" << i + 1 << "]: ";
                    uni.persons[i]->showPerson();
                    cout << endl;
                }
                cout << "***********************************************************" << endl << endl;
                cout << "Please enter the number of the person you would like to do work." << endl;
                cin >> doWork;
                // This little solution of mine uses the bounds validation function and sends the max value argument to the size of the vector
                // The user is unable to go out of bounds and input an invalid input with this function.
                while(!validateBounds(doWork, 1, uni.persons.size())) {
                    cin.clear();
                    cin.ignore();
                    cout << "Please select the number of the person you want to do work." << endl;
                    cin >> doWork;
                }
                cout<< endl;
                uni.persons[doWork - 1]->do_work();
                cout << endl;
                break;
            }
                
                
            // Exit the Program
            case 4: {
                cout << "Exiting the Program." << endl;
                runLoop = false;
                break;
            }
                
            default: {
                break;
            }
        }
    } while (runLoop);
    
    return 0;
}
