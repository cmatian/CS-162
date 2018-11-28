/*************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Re-useable functions for program input validation
 *************************************************************************/

#ifndef validation_hpp
#define validation_hpp

#include <time.h> // Needed for rand
#include <ctime> // Needed for rand
#include <cstdlib> // Needed for rand
#include <iostream>
#include <string>
#include <random>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
// Uniform Distribution for more complex RNG
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


bool validateOne(int);

bool validateBounds(int, int, int);

#endif /* validation_hpp */
