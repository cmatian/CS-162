/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Function Prototypes for ant.cpp functions
 ************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#ifndef ANT_HPP
#define ANT_HPP

//enum Direction { north, east, south, west };

class Ant {
    
private:
    int xPos,
        yPos,
        direction;
    //Direction direction;
    
    class Board;
    
public:
    Ant();

    //void setDirection(Direction);
    void setX(int);
    void setY(int);
    
    //Direction getDirection();
    int getDirection();
    int getX();
    int getY();
    
    void move(char, int, int);
    
};



#endif
