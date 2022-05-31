#define PROG 1 2 3 4 5 6  //select program you want to enable (others will be disabled)



/*
*  DYNAMIC MEMORY ALLOCATION
*/
#if (PROG == 1)

#include <iostream>

class Student {
public:
    int score;
};

int main() {
    int size;
    std::cout << "Enter total number of students: ";
    std::cin >> size;
    
    //memory allocation for an array
    Student* ptr = new Student[size];

    //store and read values
    std::cout << "Enter scores of students:" << "\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Student" << i + 1 << ": ";

        std::cin >> ptr[i].score; //store values
        std::cout << "> Stored: " << ptr[i].score << "\n"; //read values
    }

    //free up memory location (allocated for ptr before)
    delete[] ptr;

    return 0;
}


#endif













/*
*  DECOSNTRUCTOR
*/
#if (PROG == 4)

#include <iostream>

class Data {
private:
    std::string name;
    int* arr;

public:
    Data(std::string name) { // constructor
        //std::cout << "Constructor of " << name << " is called \n";
        this->name = name;
        arr = new int[1000]; //dynamic memory allocation
    }; 

    ~Data() { // destructor
        //std::cout << "Destructor of " << name << " is called \n\n";
        delete[] arr; //comment out this one will cause Memory Leak (computer hang)
    }; 
};
 

//A function with local object to test
void myFunc(int i){
    std::string name = "data" + std::to_string(i);
    Data myData(name); //create a local object
}


int main() {
    //call the function many times
    for (int i = 0; i < 10000000000; i++) {
        myFunc(i); 
    }
    
    return 0;
}

#endif


















/*
*  TRY-CATCH TO HANDLE EXCEPTIONS
*/

#if (PROG == 5)

#include <iostream>

int main() {

    try { // all code you want to handle possible exceptions

        //request memory allocation (very large size will throw bad_alloc exception)
        int *ip = new int[10000];

        int age;
        std::cout << "Enter age: ";  std::cin >> age;
        if (age <= 16) {
            throw 101; //throw a custom error code (here is an integer value)
        }
    }

    catch (std::bad_alloc& ba) { //Handles std::bad_alloc exception
        std::cerr << "bad_alloc exception caught: " << ba.what() << '\n';
    }

    catch (int errorCode) { // Handles custom exception
        std::cerr << "Access denied (16+). Error Code: " << errorCode;
    }
    
    catch (...) { // Handles all other generic exeptions
        std::cerr << "Generic Exceptions !\n";
    }

    return 0;
}


#endif














/*
*  RANGE-BASED FOR LOOP
*/

#if (PROG == 6)

#include <iostream>

int main() {
    // Iterate through a braced list (by value)
    for (int i : {0, 1, 2, 3, 4, 5}) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Iterate through the array (by value).
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int x : arr) {  // Access by value
        std::cout << x << " ";
    }
    std::cout << "\n";




    // Iterate through a string (by value).
    // "auto" keyword: type is automatically inferred from the range
    std::string str1 = "Hello!";
    for (auto ch : str1) { 
        std::cout << ch << ' ';
    }
    std::cout << "\n";


    // Iterate through a string (by reference).
    // Use when modify is needed
    std::string str2 = "Hello!";
    for (auto &ch : str2) {
        if (ch == 'l') {
            ch = 'L';
        }
    }
    std::cout << str2 << "\n";    

    return 0;
}


#endif
















/*
*  UNIONS
*/

#if (PROG == 7)

#include <iostream>

union u_type {
  int  intNum; 
  char charArr[4]; 
};

int main() {
    u_type myUnion;
    std::cout << "Size = " << sizeof(u_type) << "\n";

    //Access intNum elements
    myUnion.intNum = 0x00434241; //0x41-43 is Ascii values of 'A'-'D'

    //Access charArr elements
    std::cout << myUnion.charArr << "\n";
    std::cout << myUnion.charArr[0] << "\n";
    std::cout << myUnion.charArr[1] << "\n";
    std::cout << myUnion.charArr[2] << "\n";
    std::cout << myUnion.charArr[3] << "\n";

    return 0;
}

#endif


