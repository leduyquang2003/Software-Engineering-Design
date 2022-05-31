#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>

/*2. Write a program that ask the user to input two strings str1, str2 which may contain whitespace 
characters from the console.
a) Reserve str1 and print it out. 
For example, "Good Morning” → “gninroM dooG”
b) Convert all characters of str2 from lowercase to uppercase and vice versa, and print it out.
For example, "Hello World” → “hELLO wORLD”
Do the above tasks with character array (C-type string) and C++ string class, then convert to the 
other.
*/


class str
{
    public:
        std::string str1;
        std::string str2;

    void Input()
    {
        std::cout <<"Input str1: ";
        std::getline(std::cin, str1);
        std::cout <<"Input str2: ";
        std::getline(std::cin, str2);
    }

    void showInfo()
    {
        std::cout << "str1: " << str1 <<"\n" << "str2: " << str2 << std::endl;
    }

    /*a) Reserve str1 and print it out. For example, "Good Morning” → “gninroM dooG”*/
    std::string reverse_str()
    {
        for(int i = 0; i < str1.length()/2; i++)
        {
           char tmp = str1[i];
           str1[i] = str1[str1.length() - (i + 1)];
           str1[str1.length() - (i + 1)] = tmp;
        }
        return str1;
    }

    /*b) Convert all characters of str2 from lowercase to uppercase and vice versa, and print it out.
For example, "Hello World” → “hELLO wORLD”*/
    std::string low_up()
    {
        for(int i = 0; i < str2.length(); i++)
        {
            if(isupper(str2[i]))
                str2[i] = str2[i] + 32;
            else if(islower(str2[i]))
                str2[i] = str2[i] - 32;
        }
        return str2;
    }
};


int main()
{
    str obj1;
    obj1.Input();
    obj1.showInfo();
    obj1.reverse_str();
    obj1.low_up();
    obj1.showInfo();
    return 0;
}