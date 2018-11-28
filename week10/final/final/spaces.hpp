/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for spaces abstract class.
 ** Serves only as a space for pure virtual functions that the derived
 ** classes can override.
 **
 ** SPACES.HPP
 *****************************************************************/

#ifndef spaces_hpp
#define spaces_hpp

#include "validation.hpp"

class Space {
    
protected:
    string name;
    
public:
    Space(string);
    virtual ~Space();
    
    virtual void entrance() = 0;
    
    virtual void observe() = 0;
    
    virtual int menu() = 0;
    
    virtual bool riddle() = 0;
    
    virtual void showMap() = 0;
    
    // Getter
    string getRoom();
};


#endif /* spaces_hpp */
