#include <iostream>
#define ARRSIZE 5

/*2. Write a C++ program that takes in up to 5 integer numbers as user input arguments from the 
command line and stores them into an array of type int. Print out each value to the console.
A pointer should be used to access each element in the array (to store the user input argument, 
and output each value in the array to the console).
The program must exist with an error if:
• Incorrect number of user input arguments
• At least one user input argument is not valid integer number*/

//0 is fales; any value not 0 is true
bool is_valid_integer(char str[])
{
    //loop through and check each character
    if(!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
        return false;

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!isdigit(str[i]))
        {
            return false;
        }
    }

    //all characters are valid with checking above
    return 1;
}


int main(int argc, char *argv[])
{
    //size argc up to 6(5) --> <= 5
    //Check for number of cmd arguments
    if(argc < 2 || argc > ARRSIZE + 1)
    {
        std::cerr << "Invalid number of arguments\n";
        return -1;
    }
    
    //Check valid format for decimal for each argument
    for(int i = 1; i < argc; i++)
    {
        if(!is_valid_integer(argv[i]))
        {
            std::cerr << "At least one argument is not valid integer\n";
            return -2;
        }
        
    }

    //All argumentrs are valid integer after checking above;
    int arr[ARRSIZE];
    #if 0
    for(int i = 1; i < argc; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }
    #endif

    //pointer
    std::cout << "Got valid integer numebrs: ";
    int *p = NULL;
    p = arr;
    for(int i = 1; i < argc; i++)
    {
        *(p + i - 1) = atoi(argv[i]);
        std::cout << *(p + i - 1) <<" ";
    }
    
    return 0; //error code(0: no error)
}