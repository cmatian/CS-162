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
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::vector;
// Uniform Distribution for more complex RNG
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

// Function Prototypes
bool validateOne(int);

bool validateBounds(int, int, int);

double validateDouble();

void showMenu();


#endif
