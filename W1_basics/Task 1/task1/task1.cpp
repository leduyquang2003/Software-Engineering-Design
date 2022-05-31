#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
    char base_hex[] = "0123456789ABCDEF";
    
    string input;
    cout << "Input a valid hexnumber between 0x00 and 0xFF: ";
    cin >> input;

    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    //cout << len << endl;

    if (len == 1)
    {
        int num = 0;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (isdigit(input[i]))
            {
                num = (input[i] - '0');
            }
            else if (input[i] == 'A')
            {
                num = 10;
            }
            else if (input[i] == 'B')
            {
                num = 11;
            }
            else if (input[i] == 'C')
            {
                num = 12;
            }
            else if (input[i] == 'D')
            {
                num = 13;
            }
            else if (input[i] == 'E')
            {
                num = 14;
            }
            else if (input[i] == 'F')
            {
                num = 15;
            }
            else
            {
                return 1;
            }
        }
        int decimal = 0;
        decimal = num;
    }
    else if (len == 2)
    {
        int num1 = 0;
        if (isdigit(input[0]))
        {
            num1 = (input[0] - '0') * 16;
        }
        else if (input[0] == 'A')
        {
            num1 = 10 * 16;
        }
        else if (input[0] == 'B') 
        {
            num1 = 11 * 16;
        }
        else if (input[0] == 'C')
        {
            num1 = 12 * 16;
        }
        else if (input[0] == 'D')
        {
            num1 = 13 * 16;
        }
        else if (input[0] == 'E')
        {
            num1 = 14 * 16;
        }
        else if (input[0] == 'F')
        {
            num1 = 15 * 16;
        }
        else
        {
            return 1;
        }

        int num2 = 0;
        if (isdigit(input[1]))
        {
            num2 = (input[1] - '0');
            cout << num2 << endl;
        }
        else if (input[1] == 'A')
        {
            num2 = 10;
        }
        else if (input[1] == 'B')
        {
            num2 = 11;
        }
        else if (input[1] == 'C')
        {
            num2 = 12;
        }
        else if (input[1] == 'D')
        {
            num2 = 13;
        }
        else if (input[1] == 'E')
        {
            num2 = 14;
        }
        else if (input[1] == 'F')
        {
            num2 = 15;
        }
        else
        {
            return 1;
        }
        int decimal = 0;
        decimal = num1 + num2;
        cout << input << " is hexnumber|Decimal = " << decimal <<". Therefore in range 0x00 and 0xFF" << endl;
    }
    else
    {
        cout << "Out range 0x00 and 0xFF";
    }
 
    return 0;
}


