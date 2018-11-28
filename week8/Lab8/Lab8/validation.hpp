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
#include <algorithm>

using std::binary_search;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::getline;
using std::vector;

// Validation Function Prototypes

bool validateOne(int);

int validateBounds(int, int);

int getInt();

int intOverZero();

int integerValidation();

string getInput();

bool validString(string);

double validateDouble();

#endif
