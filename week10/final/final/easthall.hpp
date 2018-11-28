/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for easthall
 ** derived class and functions
 **
 ** EASTHALL.HPP
 *****************************************************************/

#ifndef easthall_hpp
#define easthall_hpp

#include "spaces.hpp"

class Easthall : public Space {
    
public:
    
    Easthall(string n);
    ~Easthall();
    
    void entrance();
    
    void observe();
    
    int menu();
    
    bool riddle();
    
    void showMap();
    
};


#endif /* easthall_hpp */
