/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Menu Specification File for Game of War
 *************************************************************************/

#include <time.h> // Needed for rand
#include <cstdlib> // Needed for rand
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


#ifndef menu_hpp
#define menu_hpp

// Converts the player's die choice to a string (purely for Main Menu printing/display
string playerDie(int);

// Validation Function Prototypes
bool validateOne(int);

// Exit Game Statement Function
void exitMsg();



#endif
