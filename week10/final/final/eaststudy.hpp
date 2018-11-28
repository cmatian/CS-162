/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for east study 
 ** derived class and functions
 **
 ** EASTSTUDY.HPP
 *****************************************************************/

#ifndef eaststudy_hpp
#define eaststudy_hpp

#include "spaces.hpp"

class Eaststudy : public Space {
    
public:
    
    Eaststudy(string n);
    ~Eaststudy();
    
    void entrance();
    
    void observe();
    
    int menu();
    
    bool riddle();
    
    void showMap();
    
};


#endif /* eaststudy_hpp */
