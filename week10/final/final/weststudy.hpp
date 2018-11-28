/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for weststudy 
 ** derived class and functions
 **
 ** WESTSTUDY.HPP
 *****************************************************************/

#ifndef weststudy_hpp
#define weststudy_hpp

#include "spaces.hpp"

class Weststudy : public Space {
    
public:
    
    Weststudy(string n);
    ~Weststudy();
    
    void entrance();
    
    void observe();
    
    int menu();
    
    bool riddle();
    
    void showMap();
    
};

#endif /* weststudy_hpp */
