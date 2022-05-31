#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <typeinfo>
#define PROG 2
/*Question 1 (40 pts)

Write a C++ program which take a number as an argument from the command line, 
which is one of following data type:
•	an integer number (e.g. 12)
•	a floating-point number (e.g. 3.14)
•	a hexadecimal number which must be preceded by "0x" (e.g. 0x19, 0xAC).

a)	Write a function named doubleVal() with multiple overloaded versions that 
accept an integer, a floating-point number or a string represented a 
hexadecimal number, and return a doubled value (with integer/ double data type).

b)	Use that function inside main() to print out the doubled value. Format the 
I/O stream so that the precision is two digits after the decimal point for floating point value, and it prints outs in hexadecimal format (with 0x prefix) for hexadecimal value
Note: Assume that the user always enters valid data with positive value only.
Hint: You may need to use stringstream with I/O formatting to convert from any 
numerical string to integer/ double.

Sample Run:
./a.exe 12
24
./a.exe 12.1235
24.25
./a.exe 0xAC
0x158
*/


#if (PROG == 1)
float check_intFloat(std::string str)
{

    std::stringstream sss;
    sss << str;

    float float_val;
    sss >> float_val;

    return float_val;
}

//Overload
int doubleVal(int num)
{
    return num*2;
}

float doubleVal(float num)
{
    return num*2;
}

int doubleVal(std::string str)
{
    std::stringstream ss;
    ss << str;
    int hex;
    ss >> std::hex >> hex;
    hex = hex * 2;
    return  hex;
}

int main(int argc, char *argv[])
{
    if(argv[1][0] == '0' && argv[1][1] == 'x')
    {
        int hex;
        hex = doubleVal(argv[1]);
        std::cout << std::hex << std::showbase << hex;
    }
    else
    {   

        if((int)(check_intFloat(argv[1])) == check_intFloat(argv[1]))
        {
            std::cout << doubleVal(check_intFloat(argv[1]));
        }
        else
        {
            std::cout << std::fixed << std::setprecision(2) << doubleVal(check_intFloat(argv[1]));
        }
    }
    return 0;
}
#endif

#if(PROG == 2)

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define HEXA_TYPE 2

//first version with int input
int doubleVal(int num)
{
    return num*2;
}

//second version with floating input
float doubleVal(float num)
{
    return num*2;
}

//third version with input is tring
int doubleVal(char hexaStr[])
{
    int val;
    std::stringstream sstr;
    //hexaStr in format of hexanumber
    sstr << std::hex << hexaStr; //Input the string insize the stringstream
    sstr >> val; // extract value from the stringstream(with int format)
    return val * 2;
}

int checkType(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'x' || str[i] == 'X')
        {
            std::cout << "hexa\n";
            return HEXA_TYPE;
        }
    }


    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '.')
        {
            std::cout << "floating\n";
            return FLOAT_TYPE;
        }
    }

    return INT_TYPE;
}


#if 0
std::string doubleVal(char hexaStr[])
{
    int val;
    std::stringstream sstr;
    sstr << std::hex << hexaStr; 
    sstr >> val;
    
    sstr << val * 2;
    return sstr.str();
}
#endif

int main(int argc, char *argv[])
{
    int type = checkType(argv[1]);
    if(type == HEXA_TYPE)
    {
        std::cout << std::showbase << std::hex << doubleVal(argv[1]);
    }
    else if(type == FLOAT_TYPE)
    {
        std::cout << std::fixed << std::setprecision(2) << doubleVal(std::stof(argv[1]));
    }
    else 
    {
        std::cout << doubleVal(std::stoi(argv[1]));
    }



    return 0;
}
#endif