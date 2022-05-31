#include <iostream>
#include <string>
#define PROG 2
/*2.	Try-Catch statement. Write a program to
a.	Ask the user to enter two double values a and b for division. Throw an exception if b is 0, 
and ask the user to re-enter value for b.
*/
#if (PROG == 1)
int main()
{
    double b;
    double a;
    double result;
    try
    {
        std::cout << "Input a: "; std::cin >> a;
        std::cout << "Input b: "; std::cin >> b;
        if(b == 0)
        {
            throw (b);
        }
        else
        {
            result = a/b;
            std::cout << "Result of a/b = " << result << std::endl;
        }

    }
    catch(double b)
    {
        std::cout << "Cannot divide please re-enter new value for b: "; 
        std::cin >> b;
        result = a/b;
        std::cout << "Result of a/b = " << result << std::endl;
    }
    
    return 0;
}
#endif

/*b.	Write a loop that continuously request 1MB from the heap (as an array of char). 
Catch the exception to stop the loop if allocation fails and print out how much 
memory has been allocated.*/

int main()
{
    unsigned long long i = 0;
    try
    {
        while(true)
        {
            int *p = new int;
            i++;
        }
    }
    catch(std::bad_alloc& ex)
    {
        std::cerr << sizeof(char) * i  << "bytes: out of memory!";
        std::cin.get();
        exit(1);
    }
    
    



    return 0;
}
