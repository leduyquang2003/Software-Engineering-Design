/*
    FUNCTION OVERRIDING
*/
#if 1
#include <iostream>
using std::cout;
class Animal { // parent base class
public:
    int average_age = 10;
    void eat() {
        cout << "I can eat! \n";
    }
};
class Dog : public Animal { // child derived class
public:
    int average_age = 20;
    void eat() { //function overriding
        cout << "The dog eat in his own way \n";
    }
    void bark() {
        cout << "I can bark! Woof woof!! \n";
    }
};
int main() {
    Dog dog1;
    dog1.Animal::eat();  //call method of the base class
    
    dog1.eat();  //call method of the derived class
    std::cout << dog1.average_age;
    dog1.bark(); //call method of the derived class
    return 0;
}
#endif