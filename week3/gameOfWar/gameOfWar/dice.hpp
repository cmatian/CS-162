/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Header specification files for dice functions
 *************************************************************************/

#include <time.h> // Needed for rand
#include <cstdlib> // Needed for rand
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#ifndef dice_hpp
#define dice_hpp

// Die Class
class Die {
    
protected:
    string type;
    int sides;
    
public:
    // Constructor
    Die(int);
    
    // Regular Die Roll
    virtual int roll();
    
    string getType();
    int getSide();
    
};


// Loaded Die Class (Inherits from Die)
class loadedDie : public Die {
    
public:
    // Constructor
    loadedDie(int);
    
    // Loaded Die Roll
    int roll();
};

#endif
