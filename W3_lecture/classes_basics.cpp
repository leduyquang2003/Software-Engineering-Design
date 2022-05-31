/*
    FIRST EXAMPLE FOR CLASSES AND OBJECTS
*/

#if 0

#include <iostream>

class Dog {       // The class
  public:             // Access specifier
    int age;        // Attribute (int variable)
    bool hungry = true;
    bool happy = false;

    void eat() {
        hungry = false; happy = true;
    }

    void info() {
        std::cout   << "age = " << age
                    << " hungry = " << hungry
                    << " happy = " << happy << "\n";
    }
};

int main() {
    Dog Dog1, Dog2;  //Create objects of Dog

    //Access their variables and functions
    Dog1.age = 5;
    Dog1.eat(); 
    std::cout << "Dog 1's info: "; 
    Dog1.info();

    Dog2.age = 10;
    std::cout << "Dog 2's info: "; 
    Dog2.info();

    return 0;
}

#endif










/*
    CLASS METHOD DEFINED OUTSIDE
*/
#if 0

#include <iostream>

class car {
    public:
        int speed = 100; //default value is 100
        int add_speed(int num);
};

int car::add_speed(int num) {
    speed += num; //speed = speed + num;
    return speed;
}

int main() {
    car my_car; // Create an object of Car
    std::cout << "my_car's new speed: " << my_car.add_speed(200);
    return 0;
}


#endif











/*
    CONTRUCTOR METHOD
*/
#if 0

#include <iostream>

class car {        // The class
    public:          // Access specifier
        int speed;    // Attribute
        int price;

        car (int speed_val, int price_val) { // Constructor with parameters
            speed = speed_val;
            price = price_val;
        }
};


int main() {
    // Create Car objects and call the constructor with different values
    car car1(500, 10000);
    car car2(200, 5000);

    // Print values
    std::cout << "Car1: speed & price: " << car1.speed << " " 
                                         << car1.price << "\n";
    std::cout << "Car2: speed & price: "    << car2.speed << " " 
                                            << car2.price << "\n";
  return 0;
}

#endif












/*
    DATA ENSCAPSULATION
*/

#if 1

#include <iostream>

#define DEFAULT_VAL 100
#define PASSWORD_KEY 12345

class myclass {
    private: 
        int num = DEFAULT_VAL;    // Public access specifier

    public:
        int get_num(){ return num; }; //read the num value

        void set_num(int new_val){ //write the new value for num
            int pwd;
            std::cout << "Enter password: ";  std::cin >> pwd;
            if (pwd == PASSWORD_KEY) {
                num = new_val;
                std::cout << "Set new value successfully ! \n";
            } else {
                std::cerr << "Incorrect password ! \n"; 
            }
        }
};

int main() {
    myclass object1;
    // std::cout << object1.num --> cant not allowed

    std::cout   << "Current num value: " 
                << object1.get_num() << "\n";

    object1.set_num(200);
    std::cout   << "New num value: " 
                << object1.get_num();

    return 0;
}

#endif











/*
    C++ STRING CLASS
*/

#if 0

// comparing size, length, capacity and max_size
#include <iostream>
#include <string> //it is the class

int main (){

    #if 0
    std::string str ("Hello World"); 
    std::cout << str <<"\n";


    str = "ABC";
    std::cout << str <<"\n";

    str = str + " DE";
    std::cout << str <<"\n";

    // std::cout << "length: " << str.length() << "\n";

    // std::cout << "1st char: " << str[0] << "\n";
    // str[2] = '\0';
    // std::cout << str <<"\n";
    std::cout << ((str == "ABC DE") ? "YES \n" : "NO \n") ;
    std::cout << "sub str: " << str.substr(1, 3);
    #endif

    std::getline(std::cin, str); std::cout << str << "\n";

    return 0;
}

#endif











/*
    STRINSTREAM CLASS to extract string
*/


#if 1

#include <iostream>
#include <sstream>

int main() {
    std::string str = "15.40 1234 Hello World"; // create string
    std::stringstream ss;        // create a stringstream object   

    //std::cout << str; output the content of str string to console
    ss << str;              // put the content of string into the stringstream


    //Extract data from the stringstream 
    float myFloat; 
    int   myInt;
    char  myCharArray[20];


    //std::cin >> myFloat >> myInt >> myCharArray;
    ss >> myFloat >> myInt >> myCharArray; 

    std::cout << "myFloat = " <<  myFloat << "\n" 
     	 	  << "myInt   = " <<  myInt << "\n" 
     	 	  << "myCharArray = " <<  myCharArray << "\n";

    return 0;
}

#endif











/*
    ARRAY OF OBJECTS
*/
#if 1

#include <iostream>

class Car {       
    public: 
        std::string brand;         
        int speed, price;

        Car (std::string brand_info, int speed_val, int price_val) {
            brand =  brand_info; speed = speed_val; price = price_val;
        }
};


int main() {
    Car MyCars[3] = { Car("Audi", 500, 10000), 
                      Car("BMW", 400, 8000), 
                      Car("Ferrari", 800, 20000) };

    for (int i = 0; i < 3; i++) {
        std::cout << "Car" << i << "'s brand, speed & price: "
                  << MyCars[i].brand << " " 
                  << MyCars[i].speed << " "
                  << MyCars[i].price << "\n";
    }

  return 0;
}


#endif












/*
    C++ STRUCT
*/
#if 0

#include <iostream>

struct product {
  int weight;
  double price;
};

int main() {
    product pd1, pd2;
    pd1.weight = 100; pd1.price = 10.25;
    pd2.weight = 200; pd2.price = 20.7;
    std::cout << "Product 1's weight and price: " 
              << pd1.weight << " " << pd1.price << "\n";
    std::cout << "Product 2's weight and price: " 
              << pd2.weight << " " << pd2.price << "\n";
}

#endif







