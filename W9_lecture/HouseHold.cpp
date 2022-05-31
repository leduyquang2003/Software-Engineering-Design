/* Source file:  
*  Definitions of functions/ methods for the module
*/
#include <iostream>
#include "HouseHold.h"  //include header file
using std::string;
using std::cout;

//Constructor
HouseHold::HouseHold (string name) {this->name = name; }

//Method
void HouseHold::showinfo(){
    cout << "HouseHold's Name = " << name
         << "\n> purchasedPerson's Name = " << purchasedPerson->name << "\n";
};
