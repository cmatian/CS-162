/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for westhall 
 ** derived class and functions
 **
 ** WESTHALL.HPP
 *****************************************************************/

#ifndef westhall_hpp
#define westhall_hpp

#include "spaces.hpp"

class Westhall : public Space {
    
public:
    
    Westhall(string n);
    ~Westhall();
    
    void entrance();
    
    void observe();
    
    int menu();
    
    bool riddle();
    
    void showMap();
    
};

#endif /* westhall_hpp */
