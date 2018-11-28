/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Header specification file for count.hpp
 ************************************************************************/

#ifndef COUNT_HPP
#define COUNT_HPP

// Necessary Library and Namespace inclusions/declarations
#include <iostream>
#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void count_letters(ifstream&, int*);

void output_letters(ofstream&, int*);

#endif
