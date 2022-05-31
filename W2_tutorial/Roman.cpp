#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[])
{
    //char to int
    int num;
    // std::cout << argc << std::endl;
    if(argc == 1)
    {
        std::cout << "Input an integer: ";
        std::cin >> num;

    }
    else
    {
        for(int i = 0; argv[1][i] != '\0'; i++)
        {
            if(isdigit(argv[1][i]))
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        num = atoi(argv[1]);
        std::cout << num << std::endl; 
    }
    int dec_vals[]            = { 1,   4,    5,    9,  10,   40,  50,  90,   100, 400,  500, 900, 1000};
    const char *roman_symbs[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    
    std::cout << "> Converted Roman number: "; 
    for (int i = 12; i >=0; i--) {
        while (num >= dec_vals[i]) {
            std::cout << roman_symbs[i];
            num = num - dec_vals[i]; 
        }
    }
    
    return 0;   
}