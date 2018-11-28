/****************************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 ** Description: Re-useable functions for the zoo class and related objects
 ****************************************************************************/

#include "zoo.hpp"

/******************************************************************
 ** ZOO CONSTRUCTOR
 **
 ** Initializes the Zoo class when created
 **
 *****************************************************************/

zoo::zoo() {
    
    bank = 100000;
    bonus = 0;
    payoff = 0;
    
    // Count for tracking the total animals in each cage
    tigerCount = 0;
    turtleCount = 0;
    penguinCount = 0;
    
    // Object arrays
    tigers = new Tiger*[tigerCage];
    penguins = new Penguin*[penguinCage];
    turtles = new Turtle*[turtleCage];
    
    // Set the objects in each array to Null when the Zoo is constructed
    setNull();
    
}

/******************************************************************
 ** ZOO DESTRUCTOR
 **
 ** When the program is finished the zoo 
 ** destructor will delete the arrays 
 ** and reset the cages to 0
 **
 ****************************************************************/

zoo::~zoo() {
    // Delete Tigers
    for(int i = 0; i < tigerCage; i++) {
        delete tigers[i];
    }
    delete [] tigers;
    
    // Delete Penguins
    for(int i = 0; i < penguinCage; i++) {
        delete penguins[i];
    }
    delete [] penguins;
    
    // Delete Turtles
    for(int i = 0; i < turtleCage; i++) {
        delete turtles[i];
    }
    delete [] turtles;
    
    penguinCage = 0;
    tigerCage = 0;
    turtleCage = 0;
}

/******************************************************************
 ** NULL FUNCTION
 **
 ** Initializes the arrays to null
 **
 *****************************************************************/

void zoo::setNull() {
    for(int i = 0; i < baseSize; i++) {
        tigers[i] = NULL;
        penguins[i] = NULL;
        turtles[i] = NULL;
    }
}

/******************************************************************
 ** ADD FUNCTIONS
 **
 ** Add functions for the 3 animal types
 **
 *****************************************************************/

// TIGER ADD
void zoo::addTiger() {
    if(tigerCount == tigerCage) {
        resizeTiger();
    }
    
    for(int i = 0; i < 1; i++) {
            
        // We need to tell the for loop to skip over the objects we've added so far
        
        tigers[tigerCount + i] = new Tiger;
            
        // The first time we run addTiger we're letting the user set the amount of tigers to add when calling the addTiger function
        // We reset amount to 1 after the user has initialized the starting tigers and increment the tiger count
            
        tigerCount++;
    }
}

// PENGUIN ADD
void zoo::addPenguin() {
    
    if(penguinCount == penguinCage) {
        resizePenguin();
    }
    
    for(int i = 0; i < 1; i++) {
        
        // We need to tell the for loop to skip over the objects we've added so far
        
        penguins[penguinCount + i] = new Penguin;
        
        penguinCount++;
    }
}

// TURTLE ADD
void zoo::addTurtle() {
    
    if(turtleCount == turtleCage) {
        resizeTurtle();
    }
    
    for(int i = 0; i < 1; i++) {
        
        // We need to tell the for loop to skip over the objects we've added so far
        
        turtles[turtleCount + i] = new Turtle;
        
        turtleCount++;
    }
}

/******************************************************************
 ** REMOVE FUNCTIONS
 **
 ** Remove functions for the 3 animal types
 **
 *****************************************************************/

// TIGER REMOVE
void zoo::removeTiger() {
    
    if(tigerCount == 0) {
        cout << "There are no tigers to remove." << endl;
    } else {
        delete tigers[tigerCount - 1];
        tigers[tigerCount - 1] = NULL;
        
        tigerCount--;
    }
}

//PENGUIN REMOVE
void zoo::removePenguin() {
    
    if(penguinCount == 0) {
        cout << "There are no penguins to remove." << endl;
    } else {
        delete penguins[penguinCount - 1];
        penguins[penguinCount - 1] = NULL;
        
        penguinCount--;
    }
}

//TURTLE REMOVE
void zoo::removeTurtle() {
    
    if(turtleCount == 0) {
        cout << "There are no penguins to remove." << endl;
    } else {
        delete turtles[turtleCount - 1];
        turtles[turtleCount - 1] = NULL;
        
        turtleCount--;
    }
}

/******************************************************************
 ** RESIZE FUNCTIONS
 **
 ** Resize functions that resize the dynamic arrays
 **
 *****************************************************************/

// TIGER RESIZE
void zoo::resizeTiger() {
    // Increase the cage size by 10
    int oldSize = tigerCage;
    tigerCage += 10;
    
    // Create a new array
    Tiger **tempTiger = new Tiger*[tigerCage];
    
    // Set all of tempTiger to NULL before we copy over the code
    for (int i = 0; i < tigerCage; i++) {
        tempTiger[i] = NULL;
    }
    
    // Copy the Information from tigers index into newTigers
    for (int i = 0; i < oldSize; i++) {
        tempTiger[i] = tigers[i];
    }
    
    // Delete the initial array
    delete [] tigers;
    
    // Pass over
    tigers = tempTiger;
    
    // After Resize check memory address of the new tigers array
    cout << "MEMORY ADDRESSES AFTER RESIZING THE TIGERS ARRAY" << endl;
    for (int i = 0; i < tigerCage; i++) {
        cout << tigers[i] << endl;
    }
}

// PENGUIN RESIZE
void zoo::resizePenguin() {
    // Increase the cage size by 10
    int oldSize = penguinCage;
    penguinCage += 10;
    
    // Create a new array
    Penguin **tempPenguin = new Penguin*[penguinCage];
    
    // Set all of tempPenguin to NULL before we copy over the code
    for (int i = 0; i < penguinCage; i++) {
        tempPenguin[i] = NULL;
    }
    
    // Copy the Information from penguins index into newPenguins
    for (int i = 0; i < oldSize; i++) {
        tempPenguin[i] = penguins[i];
    }
    
    // Delete the initial array
    delete [] penguins;
    
    // Pass over
    penguins = tempPenguin;
}

// TURTLE RESIZE
void zoo::resizeTurtle() {
    // Increase the cage size by 10
    int oldSize = turtleCage;
    turtleCage += 10;
    
    // Create a new array
    Turtle **tempTurtle = new Turtle*[turtleCage];
    
    // Set all of tempTurtle to NULL before we copy over the code
    for (int i = 0; i < turtleCage; i++) {
        tempTurtle[i] = NULL;
    }
    
    // Copy the Information from penguins index into tempTurtle
    for (int i = 0; i < oldSize; i++) {
        tempTurtle[i] = turtles[i];
    }
    
    // Delete the initial array
    delete [] turtles;
    
    // Pass over
    turtles = tempTurtle;
}

