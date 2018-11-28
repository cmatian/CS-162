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
#include <vector>
#include <fstream>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::getline;
using std::vector;

// Function Prototypes
bool validateOne(int);

int validateBounds(int, int);

bool validString(string);

int getInt();

double validateDouble();

#endif
