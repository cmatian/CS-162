/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification file for the player class
 **
 ** PLAYER.HPP
 *****************************************************************/

#ifndef player_hpp
#define player_hpp

#include "validation.hpp"

class Player {
    
protected:
    string name;
    int life;
    
    
public:
    // Constructor
    Player();
    ~Player();
    
    // Setter
    string setName();
    
    // Getter
    string getName();
    int getLife();
    
    void reduceLife();
    
    
    
    
    
};

#endif /* player_hpp */
