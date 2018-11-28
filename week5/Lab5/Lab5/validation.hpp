/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Function prototypes for validation.cpp functions
 **
 ** VALIDATION.HPP
 *****************************************************************/

#ifndef validation_hpp
#define validation_hpp

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::getline;

// Function Prototypes
bool validateOne(int);

bool validateBounds(int, int, int);

bool validString(string);

double validateDouble();


void showMenu();

#endif
