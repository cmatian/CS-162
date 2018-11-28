/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Function Prototypes for Board.cpp functions
 ************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#ifndef BOARD_HPP
#define BOARD_HPP

#include "ant.hpp"

class Board {
    
private:
    int height, width, antX, antY, moves;
    
    char **board;
    
    char black, white, ant;
    
    // An ant is always produced each time a board is created
    Ant tony;
    
public:
    Board(int, int, int, int, int);
    void run();
    
    void fill(char **);
    void display();
    
    void updateAnt();
    void recolor(char **, int, int);

};



#endif
