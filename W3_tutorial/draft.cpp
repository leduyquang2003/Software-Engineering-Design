/*1.	Write a program to provide a menu for user to:
a.	Input a password (which is a string). Save it into a file namely "pwd.dat".
b.	Read the stored password from the file. Print it out to the console.
Example Run:
Password management program:
1. Save your password
2. Read your password
Your choice: 1
Enter the password: abc123
Saved to the file!
Additional: modify the program so that the password string may have spaces (e.g. “abc 123”).
*/
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>



int main()
{
    int choice;
    std::string str;
    char temp[225];
    std::string content;

    std::cout << "Password managment program: " << std::endl;
    std::cout << "1. Save your password" << std::endl;
    std::cout << "2. Read your password" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    if(choice != 1 && choice != 2)
    {
        std::cerr << "Invalid syntax" << std::endl;
        return -1;
    }

    std::fstream pwd;
    if(!pwd)
    {
        std::cerr << "Fail to create/open file" << std::endl;
        return -1;
    }

    pwd.open("pwd.dat", std::ios::in);
    std::getline(pwd, content);
    pwd.close();


    if(choice == 1)
    {
        pwd.open("pwd.dat", std::ios::out);
        do
        {   
            std::cin.getline(temp, sizeof(temp));
        } while (strlen(temp) == 0);
        str = temp;

        pwd << str;
        std::cout << "Save to the file!" << std::endl;
    }
    else if (choice == 2 && content.length() != 0)    
    {
        pwd.open("pwd.dat", std::ios::in);
        std::getline(pwd, str);
        pwd.close();
        std::cout << "Read your password: " << str << std::endl;
    }
    else
    {
        std::cout << "Cannot read your password" << std::endl;
    }
  
    
    return 0;
}