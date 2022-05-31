/*1.	Class with dynamic memory allocation
Write a C++ program which defines a class named Book with two attributes name (string) and price (integer). 
Provide constructor to initialize those attributes.
*/
#include <iostream>
#include <string.h>
#include <string>
#define PROG 1 2

/*a)	Create a Book object using dynamic memory allocation and initialize values for them through the constructor. 
You should check for NULL pointer to detect whether the allocation is succeeded or not.
Print out all information of the object, and free up memory space after that.*/

#if (PROG == 1)
class Book
{
    public:
        std::string name;
        int price;

        Book(){};
        Book(std::string name, int price)
        {
            this->name = name;
            this->price = price;
        }

        std::string info()
        {
            return "Name of the book = " + name + ". Price = " + std::to_string(price);
        }

        #if 1
        void get_info()
        {
            std::cout << "> Enter name of book: "; 
            std::getline(std::cin.ignore(1000, '\n'), this->name);

            std::cout << "> Enter price of " << this->name << ": ";
            std::cin >> this->price;
        }
        #endif

};


int main()
{ 
    Book *ptr = new(std::nothrow) Book("Book of life", 100000);
    if (ptr == nullptr) {
        std::cerr << "Allocation failed\n";
        return -1;
    }
    std::cout << "Allocation succeeded" << std::endl;
    std::cout << ptr->info() << std::endl;

    /*b)	Ask the user to enter a number n. Create an array of n Book objects with random values using dynamic memory 
    allocation. Print out the most expensive book. Free up memory space after that.*/
    int n;
    std::cout << "Enter a number n of book: ";
    std::cin >> n;
    Book *p = new Book[n];

    for(int i = 0; i < n; ++i)
    {
        std::cout << "Book" << i + 1 << std::endl;
        p[i].get_info();
    } 

    for(int i = 0; i < n; ++i)
    {
        std::cout << p[i].info() << std::endl;
    }

    std::cout << "The most expensive book is ";
    Book temp = p[0];
    for(int i = 1; i < n; ++i)
    {
        if(temp.price < p[i].price)
        {
            temp = p[i];
        }
    }
    std::cout << temp.name << std::endl;

    /*c)	Modify the program so that name attribute is dynamically allocated in heap area 
    (instead of stack). Write a destructor to free up memory allocated for it 
    (when a Book object is destroyed).*/


    delete[] ptr;
    delete[] p;

    return 0;
}
#endif

#if (PROG == 2)
class Book
{
    public:
        int price;
        std::string *str;

        Book(){};
        Book(std::string str, int price)
        {
            this->price = price;
            this->str = new std::string(str);
        }

        std::string info()
        {
            return "Name of the book = " + *str + ". Price = " + std::to_string(price);
        }

        #if 1
        void get_info()
        {
            std::string temp;
            std::cout << "> Enter name of book: "; 
            std::getline(std::cin.ignore(1000, '\n'), temp);
            this->str = new std::string(temp);

            std::cout << "> Enter price: ";
            std::cin >> this->price;
        }
        #endif

        #if 1
        ~Book()
        {
            delete[] str;
        }
        #endif

};


int main()
{ 
    Book *ptr = new(std::nothrow) Book("Book of life", 100000);
    if (ptr == nullptr) {
        std::cerr << "Allocation failed\n";
        return -1;
    }
    std::cout << "Allocation succeeded" << std::endl;
    std::cout << ptr->info() << std::endl;

    /*b)	Ask the user to enter a number n. Create an array of n Book objects with random values using dynamic memory 
    allocation. Print out the most expensive book. Free up memory space after that.*/
    int n;
    std::cout << "Enter a number n of book: ";
    std::cin >> n;
    Book *p = new Book[n];

    for(int i = 0; i < n; ++i)
    {
        std::cout << "Book" << i + 1 << std::endl;
        p[i].get_info();
    } 

    for(int i = 0; i < n; ++i)
    {
        std::cout << p[i].info() << std::endl;
    }

    std::cout << "The most expensive book is ";
    Book temp = p[0];
    for(int i = 1; i < n; ++i)
    {
        if(temp.price < p[i].price)
        {
            temp = p[i];
        }
    }
    std::cout << *(temp.str) << std::endl;

    /*c)	Modify the program so that name attribute is dynamically allocated in heap area 
    (instead of stack). Write a destructor to free up memory allocated for it 
    (when a Book object is destroyed).*/


    delete[] ptr;
    delete[] p;
    return 0;
}
#endif