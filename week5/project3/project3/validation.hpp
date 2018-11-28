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
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::getline;
using std::vector;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// Function Prototypes
bool validateOne(int);

int validateBounds(int, int);

bool validString(string);

double validateDouble();

#endif
