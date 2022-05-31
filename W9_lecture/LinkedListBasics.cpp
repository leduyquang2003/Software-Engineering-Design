/*
*   Singly Linked List
*/
#if 1

#include <iostream>
using std::string;
using std::cout;

class HouseHold{
public:
    string name;
    HouseHold *purchasedPerson = NULL;

    HouseHold (string name) {this->name = name; }
};


int main(){
    /* Initialize nodes */
    HouseHold hh1("HouseHold 1"), hh2("HouseHold 2"), hh3("HouseHold 3");
   
    /* Save reference of first node in head (orginal HouseHold)*/
    HouseHold *origHouseHold = &hh1;

    /* Connect nodes */
    hh1.purchasedPerson = &hh2; //hh2 bought the house from hh1
    hh2.purchasedPerson = &hh3; //hh3 bought the house from hh2

    /* Loop through the linked list */
    printf("\nLinked Households are: \n");
    HouseHold *temp = origHouseHold;
    while (temp != NULL) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson; //access next node
    }
}


#endif














/*
*   Doubly Linked List
*/
#if 1

#include <iostream>
using std::string;
using std::cout;

class HouseHold{
public:
    string name;
    HouseHold *purchasedPerson = NULL; //pointer to next node
    HouseHold *soldPerson = NULL; //pointer to previous node

    HouseHold (string name) {this->name = name; }
};


int main(){
    
    /* Initialize nodes */
    HouseHold hh1("HouseHold 1"), hh2("HouseHold 2"), hh3("HouseHold 3");
   
    /* Save reference of first node in head (orginal HouseHold)*/
    

    /* Connect nodes (record transactions)*/
    HouseHold *origHouseHold = &hh1; //head (first HouseHold)

    hh1.purchasedPerson = &hh2; //hh1 sell to house to hh2
    hh2.soldPerson = &hh1; //hh1 is a soldperson of hh2

    hh2.purchasedPerson = &hh3;
    hh3.soldPerson = &hh2;

    HouseHold *lastHouseHold = &hh3; //tail (last HouseHold)

    /* Loop through the linked list (go from head to tail) */
    printf("\nLinked Households (next buyers) are: \n");
    HouseHold *temp = origHouseHold;
    while (temp != NULL) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson; //access next node
    }

    /*go from tail to head*/
    printf("\n\nLinked Households (previous owners) are: \n");
    temp = lastHouseHold;
    while (temp != NULL) {
        cout << temp->name << " --> ";
        temp = temp->soldPerson; //access next node
    }

    //Quick question: Print out name of person sell the house to hh3
    std::cout << "\n\nQuick question: Print out name of person sell the house to hh3: ";
    std::cout << hh3.soldPerson->name ;

    //Quick question: Print out name of person bought the house from hh2
    std::cout <<"\n\nQuick question: Print out name of person bought the house from hh2: ";
    std::cout << hh2.purchasedPerson->name << std::endl;

}


#endif

/*SINGLY LOOP*/
#if 0

#include <iostream>
using std::string;
using std::cout;

class HouseHold{
public:
    string name;
    HouseHold *purchasedPerson = NULL;

    HouseHold (string name) {this->name = name; }
};


int main(){
    /* Initialize nodes */
    HouseHold hh1("HouseHold 1"), hh2("HouseHold 2"), hh3("HouseHold 3");
   
    /* Save reference of first node in head (orginal HouseHold)*/
    HouseHold *origHouseHold = &hh1;

    /* Connect nodes */
    hh1.purchasedPerson = &hh2; //hh2 bought the house from hh1
    hh2.purchasedPerson = &hh3; //hh3 bought the house from hh2
    hh3.purchasedPerson = &hh1;

    /* Loop through the linked list */
    printf("\nLinked Households are: \n");
    HouseHold *temp = origHouseHold;
    while (temp != NULL) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson; //access next node

        // stop if go back to the head
        if(temp == origHouseHold)
        {
            break;
        }
    }
}


#endif









/*
*   RANDOM GENERATOR
*/
#if 1

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

int main() {
    // intialize the random generator (based on current time)
    srand(time(NULL));
        
    // Generate a random integer from 0 to N
    int const N = 10;
    int num = rand() % (N + 1);

    std::cout << "num is " << num;

    char ch;
    ch = rand() % ('Z' - 'A') + 'A';
    std::cout << "char = " << ch;
}

#endif
