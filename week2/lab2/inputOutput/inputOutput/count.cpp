/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Function Prototypes for validation.cpp functions
 ************************************************************************/

#include "count.hpp"

void count_letters(ifstream &input, int *count) {
    // Variable Declarations...
    // Paragraph
    string p = "",
           line;
    
    // Character
    char letter;
    
    // Read the line of text
    while(getline(input, line)) {
        if (line.empty()) {
            // This will break out of the paragraph when it encounters an empty line
            break;
        } else {
            // Combines the paragraph and the line
            p += line + ' ';
        }
    }
    // White space removal
    p.erase(p.length() - 1);
    
    // Setting initial values to 0
    for(int i = 0; i < 26; i++) {
        count[i] = 0;
    }
    
    // This for loop will run through the frequency of each character and document it.
    for(int i = 0; i < p.length(); i++) {
        // Looking at the length of p and taking a single character per iteration
        letter = tolower(p[i]);
        
        if((int)letter >= 97 && (int)letter <= 122) {
            // Updating the count array
            count[(int)letter - 97] += 1;
        }
    }
}

void output_letters(ofstream &output, int *count) {
    for(int i = 0; i < 26; i++) {
        // Writing outputs to each file
        output << (char)(i + 97) << " = " << count[i] << endl;
    }
}
