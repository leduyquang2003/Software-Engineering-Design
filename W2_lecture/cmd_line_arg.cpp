#include <iostream>


//Get and print out all command-line arguments
int main(int argc, char *argv[])
{   
    for(int i = 1; i < argc; i++)
    {
        std::cout << "Hello " << argv[i] << std::endl;
    }

    return 0;
}