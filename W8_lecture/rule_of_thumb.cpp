#include <iostream>

class Juice {
public:
    int *price; 

    void mem_request_for_price() {
        price = new (std::nothrow) int;
    }

    //default Constructor
    Juice (){
        std::cout << "default Constructor \n";
        mem_request_for_price(); 
    }

    //parameterized Constructor
    Juice (int price_val){
        std::cout << "parameterized Constructor \n";
        mem_request_for_price();
        *price = price_val;
    }


    /* Copy Constructor */
    Juice (Juice &oldJuice){
        std::cout << "Copy Constructor \n";
        mem_request_for_price(); 
        *price = *(oldJuice.price);
    }

    /* Assignment Operator */
    Juice operator = (Juice &oldJuice){
        std::cout << "Assignment Operator \n";
        *price = *(oldJuice.price);
        return *this; //to allow multiple "=" operators used together
    }

    //Destructor
    ~Juice () {
        std::cout << "Destructor \n";
        delete price;
    }
};


int main() {
    Juice juice1;       //default contructor
    Juice juice2(100);  //parameterized constructor

    Juice juice3 = juice2;  //Copy constructor 
    juice1 = juice3;        //Copy Assignment operator is called

    return 0;
}