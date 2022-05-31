#include <iostream>
#include <string>
using namespace std;


/*4. Write a C++ program that takes in one user input argument from the command line 
and checks if it is valid hexadecimal number or not, then displays the hexadecimal 
number to the console.
• If the incorrect number of user input arguments is detected, the program must exit 
with an error
• Hexadecimal values between 0x00 and 0xFF are valid, other values should be 
rejected
• The letter "x" of number base can either be upper or lower case
• The hexadecimal digits can only contain upper case characters.*/

int main()
{
    //Check if the input is two digit and not !(A, B, C, D, E, F)
    char number[3];
    char base[] = "0123456789ABCDEF";
    cout << "Input a number: ";
    cin >> number;

    int check = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            
            if(number[i] == base[j])
            {
                check++;
            }
        }
    }

    if(check == 2)
    {
        cout << "It is hexdecimal number" << endl;
    }
    else
    {
        cout << "It is not hexdecimal number" << endl;
    }

    return 0;
}