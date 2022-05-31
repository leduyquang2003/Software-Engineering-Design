#include <iostream>

int main()
{
    /*a.	Ask the user to enter two double values a and b for division. 
    Throw an exception if b is 0, and ask the user to re-enter value for b.*/
    int a, b;
    std::cout << "Enter a and b for division a/b: ";

    try
    {
        std::cin >> a >> b; 
        if(b == 0)
        {
            throw -1; //throw custom error
        }
    } 
    catch (int errorcode)
    {
        std::cerr << "b is 0 !!! Error code: " << errorcode << std::endl;
        do {
            std::cout << "Please enter the value for b again: ";
            std::cin >> b;
        } while (b == 0);
    }

    std::cout << "Result a/b = " << (float) a/b << "\n";

    /*b.	Write a loop that continuously request 1MB from the heap 
    (as an array of char). Catch the exception to stop the loop if allocation 
    fails and print out how much memory has been allocated.
    Check with physical size of RAM and Page file memories of your computer 
    (using dxdiag command). Does it makes sense ?*/

    int cnt = 0;
    std::cout << "\n\nRequest memory allocation.. \n";
    while(1)
    {
        //request memory allocation (1MB = 1024kb = 1024 * 1024 bytes)
        try
        {
            char *ip = new char[1024 * 1024]; //1mb
            cnt++;
        }
        catch(std::bad_alloc errorcode)
        {
            std::cerr << "\nbad_alloc exception caught!\n";
            std::cerr << "Total memory allocated: " << cnt << "MB\n";
            break;
        }
        
    }

    std::cout << "\nEnd of program!";
    return 0;
}