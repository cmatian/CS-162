/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for courtyard
 ** derived class and functions
 **
 ** COURTYARD.HPP
 *****************************************************************/

#ifndef courtyard_hpp
#define courtyard_hpp

#include "spaces.hpp"

class Courtyard : public Space {
    
public:
    Courtyard(string n);
    ~Courtyard();
    
    void entrance();
    
    void observe();
    
    int menu();
    
    bool riddle();
    
    void showMap();
    
};


#endif /* courtyard_hpp */
