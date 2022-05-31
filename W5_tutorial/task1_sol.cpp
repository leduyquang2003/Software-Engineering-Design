 #include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#define STRSIZE 225

/*c)	Modify the program so that name attribute is dynamically allocated in 
heap area (instead of stack). Write a destructor to free up memory allocated 
for it (when a Book object is destroyed).*/

class Book
{
    public:
        std::string *name;
        int price;
        
        //constructor
        Book()
        {
            name = new (std::nothrow) std::string;
            if(name == NULL)
            {
                std::cerr << "Fail to allocate memory\n";
            }
        };
        Book(std::string name_val, int price_val)
        {
            this->name = new (std::nothrow) std::string(name_val);
            if(this->name == NULL)
            {
                std::cerr << "Fail to allocate memory\n";
            }
            this->price = price_val;
        }

        //A function to return a string of info
        std::string toString()
        {
            std::stringstream sstr;
            sstr << "name = " << *name << " Price = " << price;
            return sstr.str(); //to get the string object in sstr class
        }

    
        //Destructor
        ~Book()
        {
            delete name;
        }
};

int main()
{
    /*a)	Create a Book object using dynamic memory allocation and 
    initialize values for them through the constructor. You should check for 
    NULL pointer to detect whether the allocation is succeeded or not.
    Print out all information of the object, and free up memory space 
    after that.*/
    //std::nothrow ignore the error and continue to run the program
    Book *book1 = new(std::nothrow) Book("Harry Potter", 100);

    //When it fail to allocate it crash your program
    if(book1 == NULL)
    {
        std::cerr << "Fail to allocate memory\n";
        return -1;
    }

    std::cout << "Info of book1: " << book1->toString() << std::endl;
    std::cout << "Info of book1: " << (*book1).toString() << std::endl;

    //free up memory
    delete book1;

    //Input values for books from the user
    char str_temp[STRSIZE];
    int size;
    std::cout << "Enter numbers of books: ";
    std::cin >> size;
    Book *book_arr = new(std::nothrow) Book[size];

    std::cout << "\nInput information for the books: ";
    for(int i = 0; i < size; i++)
    {
        std::cout << "Book " << i + 1 << "'s name: ";
        // book_arr[i].name = (book_arr + i)->name

        //Making a loop to geline until the string is not empty
        do {
            std::cin.getline(str_temp, sizeof(str_temp));
        } while(strlen(str_temp) == 0);
        *book_arr[i].name = str_temp;

        std::cout << "Price: ";
        std::cin >> book_arr[i].price;
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << book_arr[i].toString() << std::endl;
    }

    //Check and print out the most expensive book
    #if 0
    Book most_exp = book_arr[0]; //assume that first book is most expensive
    for(int i = 1; i < size; i++)
    {
        if (most_exp.price < book_arr[i].price)
        {
            most_exp = book_arr[i];
        }
    }
    std::cout << "Most Expensive book: " << most_exp.toString() << std::endl;
    #endif

    Book *most_exp = &book_arr[0];
    for(int i = 1; i < size; i++)
    {
        if(most_exp->price < book_arr[i].price)
        {
            most_exp = &book_arr[i];
        }
    }
    std::cout << "Most Expensive book: " << most_exp->toString();



    return 0;
}