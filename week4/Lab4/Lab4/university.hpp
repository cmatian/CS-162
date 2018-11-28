/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification and function prototypes for University
 ** class and functions.
 **
 ** UNIVERSITY.HPP
 *****************************************************************/

#ifndef university_hpp
#define university_hpp

#include "validation.hpp"
#include "person.hpp"
#include "building.hpp"

class University {
private:
    string name = "Oregon State University";
    
public:
    // Vectors
    vector<Building *> buildings;
    
    vector<Person *> persons;
    
    // Constructor
    University();
    
    // Destructor
    ~University();
    
    // Getter
    string getUniName();
    
    
    
    
};


#endif
