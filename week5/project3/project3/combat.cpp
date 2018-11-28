/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable function file for simulating combat between
 ** two characters.
 **
 ** COMBAT.CPP
 *****************************************************************/

#include "combat.hpp"

/******************************************************************
 ** Combat Function
 **
 ** This function controls the game simulation and runs within the do-while loop.
 ** We pass in the attacker, defender, and round information. Then we use a recursive 
 ** function to determine if the defender boolean function is set to false.
 ** If it's false we know that the defender has died and we can exit the loop.
 ** We also swap the places of the attacker and the defender when calling the function
 ** recursively.
 **
 **
 *****************************************************************/

void combat(Character *att, string attacker, Character *def, string defender, int round) {
    
    cout << endl << "================[ Start of Round " << round << " ]================"<< endl << endl;
    cout << attacker << " (" << att->getType() << ") " << " attacks: " << endl << endl;
    
    if (def->defend(att->attack()) == true) {
        cout << endl << "================[  End of Round " << round << "  ]================"<< endl << endl;
        round++;
        combat(def, defender, att, attacker, round);
    }
    else {
        cout << endl << "================[  End of Round " << round << "  ]================"<< endl << endl << endl;
        cout << attacker << " (" << att->getType() << ") is the victor!" << endl << endl;
        cout << "End of Simulation Health Statistics." << endl;
        cout << attacker << " (" << att->getType() << ") " << " health: " << att->getStrength() << endl;
        cout << defender << " (" << def->getType() << ") " << " health: " << def->getStrength() << endl << endl;;
    }
}
