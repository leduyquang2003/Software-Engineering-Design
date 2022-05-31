#include <iostream>
#include "HouseHold.h" //include header file of the module

using std::string;
using std::cout;

int main(){
 
    HouseHold hh1("HouseHold 1"), hh2("HouseHold 2");
    hh1.purchasedPerson = &hh2;    //hh2 bought the house from hh1

    hh1.showinfo();

    return 0;
}