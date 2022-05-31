/* Header file:  
*  Only contain declarations (prototypes) 
*  of classes/ functions/ user defined data types
*/

#include <iostream>
using std::string;
using std::cout;

class HouseHold{
public:
    string name;
    HouseHold *purchasedPerson = NULL;

    HouseHold (string name);
    void showinfo();
};
