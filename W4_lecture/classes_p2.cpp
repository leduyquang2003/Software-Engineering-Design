/* 
    FUNCTION OVERLOADING
*/


#if 1

#include <iostream>

class BankAcc{
public:
    std::string name = "";
    int amount = 0;

    BankAcc(){}; //Default Constructor (No Arguments)

    BankAcc(std::string name_val) { //one argument
        name = name_val;
    }

    BankAcc(int amount_val) {  //one argument
        amount = amount_val;
    }

    BankAcc(std::string name_val, int amount_val) {  //two arguments
        name = name_val;
        amount = amount_val;
    }

    void showInfo() {
        std::cout << "Name = " << name 
                  << ", Amount = " << amount << "\n";
    }
};



int main(){
    BankAcc myacc1("Techcombank");  
    myacc1.showInfo();

    BankAcc myacc2("Vietcombank", 1000000);
    myacc2.showInfo();

    return 0;
}

#endif












/* 
    "THIS" KEYWORD
*/

#if 1

#include <iostream>

class BankAcc{
public:
    std::string name = "";
    int amount = 0;

    BankAcc(); //Default Constructor (No Arguments)

    BankAcc(std::string name) { //one argument
        this->name = name; //this->name is the attribute
    }

    BankAcc(int amount) {  //one argument
    	this->amount = amount;
    }

    BankAcc(std::string name, int amount) {  //two arguments
    	this->name = name;
    	this->amount = amount;
    }

    void showInfo() {
        std::cout << "Value of this pointer: " << this << "\n";


        std::cout << "Name = " << name 
                << ", Amount = " << amount << "\n";
    }
};



int main(){
    BankAcc myacc1("Techcombank");  
    myacc1.showInfo();

    BankAcc myacc2("Vietcombank", 1000000);
    myacc2.showInfo();

    return 0;
}
#endif



















/* 
    OVERLOADING UNARY OPERATOR
*/
#if 1

#include <iostream>

class BankAcc {
public:
    std::string name = "";
    int amount = 0;

    BankAcc(){};
    BankAcc(std::string name, int amount) {
    	this->name = name;
    	this->amount = amount;
    }

    std::string toString() {
        return "Name = " + name + ", Ammount = " + std::to_string(amount);
    }

    // Overload ++ when used as prefix
    BankAcc operator ++ () {
        amount++;
        return *this;
    }

    // Overload ++ when used as postfix
    BankAcc operator ++ (int) {
        amount++;
        return *this;
    }
};

int main() {
    BankAcc acc1("TCB", 1000), acc2("ACB", 2000), result;

    // Use the overloaded operator ++ as prefix
    result = ++acc1;
    std::cout << result.toString() << "\n";

    // Use the overloaded operator ++ as suffix
    result = acc2++;
    std::cout << result.toString() << "\n";;

    return 0;
}


#endif










/* 
    OVERLOADNG BINARY OPERATOR
*/

#if 1

#include <iostream>

class BankAcc {
public:
    std::string name = "";
    int amount = 0;

    BankAcc(){};
    BankAcc(std::string name, int amount) {
    	this->name = name;
    	this->amount = amount;
    }

    std::string toString() {
        return "Name = " + name + ", Ammount = " + std::to_string(amount);
    }

    // Overload + operator (object + object)
    BankAcc operator + (BankAcc &acc2) {
        BankAcc temp;

        //Same name: add ammounts
        if (this->name == acc2.name) {
            temp.name = this->name;
            temp.amount = this->amount + acc2.amount;
            return temp;
        } 

        //Name is different: return an object with empty attributes
        std::cerr << "Cannot add accounts: names are different !\n";
        return temp;
    }


    // Overload + operator (object + int)
    BankAcc operator + (int num) {
        this->amount += num;
        return *this;
    }
};



int main() {
    BankAcc acc1("TCB", 1000), acc2("TCB", 2000), acc3("ACB", 5000);
    BankAcc result;

    // Use the overloaded operator +   (object + object)
    result = acc1 + acc2;
    std::cout << result.toString() << "\n\n";

    // Use the overloaded operator +   (object + object)
    result = acc2 + acc3;
    std::cout << result.toString() << "\n\n";



    // Use the overloaded operator +   (object + int)
    result = acc2 + 10000;
    std::cout << result.toString() << "\n\n";

    // Use the overloaded operator +   (int + object)
    //result = 10000 + acc2;  /* ERROR: not supported !*/

    return 0;
}

#endif
















/* 
    FRIEND FUNCTION
*/


#if 1

#include <iostream>

class Distance {
private:
	int meter;

public:
	Distance() : meter(0) {}
    
    //Declare a non-member function is a Friend
	friend int addFive(Distance d);
};


//Definition of the function
int addFive(Distance d) {
    //Access private members from the friend function
    d.meter += 5;
    return d.meter;
}

int main() {
    Distance dist;
    std::cout << "> Distance: " << addFive(dist);
    return 0;
}

#endif












/* 
    OVERLOADING OPERATOR AS A FRIEND FUNCTION
*/

#if 0
#include <iostream>

class Point2D {  
    int x, y; // 2D coordinates

public:
    Point2D() {x = 0; y = 0;};  //default constructor
    Point2D(int x, int y) {this->x = x; this->y = y;};

    //Declare operator overloading functions as Friends
    friend Point2D operator +(Point2D point, int num);  //allows Point2D + int 
    friend Point2D operator +(int num, Point2D point);  //allows int + Point2D 

    std::string toString() {
        return "x = " + std::to_string(x) + ", y = " + std::to_string(y);
    }
};

//Define the operator overloading function for Point2D + int
Point2D operator +(Point2D point, int num) {
   Point2D temp;
   temp.x = point.x + num;
   temp.y = point.y + num; 
   return temp;
}

Point2D operator +(int num, Point2D point) {
   return point + num;
}


int main(){
    Point2D pointA(100, 200), pointB;

    pointB = 20 + pointA;
    std::cout << "\nValue of pointB: "
              << pointB.toString();

    pointB = pointA + 30;
    std::cout << "\nValue of pointB: "
              << pointB.toString();

    return 0;
}


#endif

















/* 
    FRIEND CLASS
*/
#if 1


#include <iostream>

class ClassA {
private:
    int numA = 10;

public:
    //Declare another class is a Friend
    friend class ClassB;
};


class ClassB {
private:
    int numB = 20;

public:
    //Access private members of classA from the friend class
    int add(ClassA obj_a) {
        return obj_a.numA + this->numB;
    }
};


int main() {
    ClassB objB;
    ClassA objA;

    std::cout << "> Sum: " << objB.add(objA);
    return 0;
}


#endif
























/* 
    STATIC CLASS MEMBER
*/
#if 0
#include <iostream>
 
using namespace std;

class Car {
public:
    std::string name; 
    int price;

    static int objCount; //static attribute
    static int getCount() { //static member function
        return objCount;
    }

    Car(std::string name, int price) {
        this->name = name; 
        this->price = price;
        objCount++;
    }
};

// Initialize static attribute
int Car::objCount = 0;

int main(void) {
   cout << "Number of Car objects: " << Car::objCount << endl;
   Car car1("BWM", 10000), car2("Ferrari", 50000);
   cout << "Number of Car objects: " << Car::getCount() << endl;

   return 0;
}

#endif