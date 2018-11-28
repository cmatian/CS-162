/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable function for creating character's for each team.
 **
 ** SELECTION.CPP
 *****************************************************************/
#include "selection.hpp"

/******************************************************************
 ** charSelect() function
 **
 ** Function returns the character that is selected based on the
 ** user's input. It also takes in a string which allows the menu name
 ** to be mutated from inside the function.
 **
 *****************************************************************/

Menu menu;

Character *charSelect(string menuName) {
    
    Character *selection = nullptr;
    
    menu.showMenu(menu.charMenu, "Character Selection (" + menuName + ")");
    
    switch (validateBounds(1, 5)) {
        case 1: {
            cout << "Vampire has been added to " << menuName << endl << endl;
            selection = new Vampire;
            break;
        }
            
        case 2: {
            cout << "Barbarian has been added to " << menuName << endl << endl;
            selection = new Barbarian;
            break;
        }
            
        case 3: {
            cout << "Bluemen has been added to " << menuName << endl << endl;
            selection = new Bluemen;
            break;
        }
            
        case 4: {
            cout << "Medusa has been added to " << menuName << endl << endl;
            selection = new Medusa;
            break;
        }
            
        case 5: {
            cout << "Harry Potter has been added to " << menuName << endl << endl;
            selection = new Harrypotter;
            break;
        }
    }
    
    return selection;
}
