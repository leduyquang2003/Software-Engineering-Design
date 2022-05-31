/*Write a C++ program that takes in up to 5 integer numbers as user input arguments from the 
command line and stores them into an array of type int. Print out each value to the console.
A pointer should be used to access each element in the array (to store the user input argument, 
and output each value in the array to the console).
The program must exist with an error if:
• Incorrect number of user input arguments
• At least one user input argument is not valid integer number
Additional: Edit the code to take in up to 10 floating-point numbers as user input arguments from 
the command line and stores them into an array of type float. The pointer type will be need to be 
changed to float*/
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <string>
#include <typeinfo>
int main(int argc, char *argv[])
{

    int cnt = 0;

    for(int i = 1; i < argc; i++)
    {
        char str_num[225];
        strcpy(str_num, argv[i]);
        for(int j = 0; str_num[j] != '\0'; j++)
        {
            if(!isdigit(str_num[j]))
            {
                return 1;
            }
        }
        cnt++;
    }

    if(cnt == 5)
    {
        for(int i = 1; i < argc; i++)
        {
            // std::cout <<"Count: " << cnt << std::endl;
            char str_num[225];
            int arr[5];
            int value = 0;
            int *p = NULL;
            p = arr;

            strcpy(str_num, argv[i]);

            #if 1
            for(int j = 0; str_num[j] != '\0'; j++)
            {
                if(!isdigit(str_num[j]))
                {
                    return 1;
                }
            }
            #endif

            *(p + value) = std::stoi(str_num);

            std::cout << *(p + value) << std::endl;
            value++;
        }
    }
    else
    {
        return 1;
    }

    return 0;
}