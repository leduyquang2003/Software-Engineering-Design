#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

int main()
{
    /*a) Print 200 with and without a positive + sign.*/
    //with positive + sign
    std::cout << "> a) Print 200 with and without a positive + sign" << std::endl;
    std::cout << std::showpos << 200 << '\n';
    // to clear
    std::cout << std::noshowpos << 200 << std::endl;

    //b) Print 10 and 200 left justified with 5-character width.
    std::cout << "> b) Print 10 and 200 left justified with 5-character width." << std::endl;
    std::cout << std::left << std::setw(5) << 10;
    std::cout << std::left << std::setw(5) << 200 << '*' << std::endl;

    /*c) Read a hexadecimal value (preceded by 0x) into variable hex, then print out its decimal value.
         Input: 0x10
         -Output: 16*/
    #if 1
    std::cout << "> c) Read a hexadecimal value (preceded by 0x) into variable hex, then print out its decimal value."<< std::endl;
    int hex_num;
    std::cout << "Input: ";
    std::cin >> std::hex >> hex_num;
    std::cout << "Output: " << hex_num << std::endl;
    #endif

    /*d) Input decimal and output in hexadecimal form preceded by 0x.*/
    #if 1
    std::cout << "> d) Input decimal and output in hexadecimal form preceded by 0x." << std::endl;
    int dec_num;
    std::cout << "Input: ";
    std::cin >> std::resetiosflags(std::ios_base::hex) >> dec_num;
    std::cout << "Output: "<< std::hex << std::showbase << dec_num << std::endl;
    #endif
    //std::cout << std::hex << std::showbase << 100 <<"\n\n";

    /*e) Print 1.234 with 9-character width, padded by zeros.*/
    std::cout << std::right << std::setw(9) << std::setfill('0') << 1.234 << std::endl;
    
    /*f) Print 1.234 with precision is 2 digits of fractional part (after decimal point).*/
    std::cout << std::fixed << std::setprecision(2) << 1.235 << std::endl;

    /*g) Read a string from the console input, store the string in character array str. Then print out its 
all characters, separated by a space.*/
    char str[255];
    std::cin.get(str, 255);
    char *p = NULL;
    p = str;
    for(int i = 0; *(p + i) != '\0'; i++)
    {
        std::cout << std::right << std::setw(2) << std::setfill(' ') << *(p + i);
    }

    return 0;
}