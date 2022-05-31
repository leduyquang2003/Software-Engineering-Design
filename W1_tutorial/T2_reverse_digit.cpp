#include <iostream>
#include <math.h>
using namespace std;
/*2. Write a C++ program to reverse the digits of a given integer.
Sample Input: 123
Sample Output: 321*/

int len_of_input(int input)
{
    int length = 0;
    while(input >= 1)
    {
        input = input / 10;
        length++;
    }
    return length;
}

void recursive_invert(int input)
{
    if(input == 0)
    {
        return;
    }
    printf("%d", input % 10);
    recursive_invert(input / 10);
}

int main()
{
    int input = 0;
    int output = 0;
    cout << "Input: ";
    cin >> input;

    recursive_invert(input);

    #if 0
    //length 
    int length = len_of_input(input);
    while(input >= 1)
    {
        output = (input % 10) * pow(10, length - 1) + output;
        length--;
        input = input / 10;
    }
    cout << "Ouput: " << output;
    #endif

    return 0;
}

