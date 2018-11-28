/*************************************************************************
 Name: Christopher Matian
 OID: 933308644
 Description: Reuseable functions for Ant class
 *************************************************************************/

#include "ant.hpp"

Ant::Ant() {
    direction = 1;
}

// Sets the X Coordinate of the Ant
void Ant::setX(int x) {
    xPos = x;
}

// Sets the Y Coordinate of the Ant

void Ant::setY(int y) {
    yPos = y;
}


// This is a left over function from when I was working with an enumerator to structure the compass/direction.
// I've opted for a more verbose strategy though because it allowed me to quickly increment/decrement the direction of the ant
// I will likely return to this section and alter the code to use an enumerator.

//Direction Ant::getDirection() {
//    return direction;
//}


// Function Utilized to output the direction the ant is traveling (helpful for debugging)
int Ant::getDirection() {
    return direction;
}

// Returns the X Coordinate of Tony the Ant
int Ant::getX() {
    return xPos;
}

// Returns the Y Coordinate of Tony the Ant
int Ant::getY() {
    return yPos;
}


// The function essentially controls the ant's movement across the board. Essentially, when we check the direction of the ant
// (which is initialized to 1 by the constructor) we increment either the xPos or the yPos based on the direction and the ant's
// container. If the Ant attempts to move beyond the container, it'll push/pull the Ant to the opposite edge of the board and
// continue normally.
//
// The majority of the project was spent trying to figure out the control logic. 

void Ant::move(char cellColor, int height, int width) {
    
    // WHEN WE HIT / START ON A WHITE TILE
    if (cellColor == ' '){
        // FACING NORTH
        if (direction == 1) {
            // TRAVELING EAST
            xPos++;
            
            if(xPos >= width) {
                xPos = 0;
            }
            
        }
        
        
        // FACING EAST
        if (direction == 2) {
            // TRAVELING SOUTH
            yPos++;
            
            if(yPos >= height) {
                yPos = 0;
            }
        }
        
        // FACING SOUTH
        if (direction == 3) {
            // TRAVELING WEST
            xPos--;
            
            if(xPos < 0) {
                xPos = width - 1;
            }
            
        }
        
        // FACING WEST
        if (direction == 4) {
            // TRAVELING NORTH
            yPos--;
            
            if(yPos < 0) {
                yPos = height - 1;
            }
            
        }
        
        direction++;
        if (direction == 5) {
            direction = 1;
        }
    }
    // WHEN WE HIT A BLACK TILE
    else if (cellColor == '#') {
        // FACING: NORTH
        if (direction == 1) {
            // MOVING: WEST
            xPos--;
            
            if(xPos < 0) {
                xPos = width - 1;
            }
        }
        
        // FACING: WEST
        if (direction == 4) {
            // MOVING: SOUTH
            yPos++;
            
            if(yPos >= height) {
                yPos = 0;
            }
        }
        
        // FACING: SOUTH
        if (direction == 3) {
            // MOVING: EAST
            xPos++;
            
            if(xPos >= width) {
                xPos = 0;
            }
        }
        
        // FACING: EAST
        if (direction == 2) {
            // MOVING: NORTH
            yPos--;
            
            if (yPos < 0) {
                yPos = height - 1;
            }
        }
        
        direction--;
        if (direction == 0) {
            direction = 4;
        }
    }
    
}
