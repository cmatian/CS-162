/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification and function prototypes for Building class 
 ** and functions.
 **
 ** BUILDING.HPP
 *****************************************************************/

#ifndef building_hpp
#define building_hpp

#include "validation.hpp"

class Building {
    
private:
    string name;
    int size;
    string address;
    
public:
    // Constructor
    Building(string, int, string);
    
    // Destructor
    ~Building();
    
    string bName();
    int bSize();
    string bAddress();
    
};

#endif
