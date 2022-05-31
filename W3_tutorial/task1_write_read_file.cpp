#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

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
*/


int main()
{
    char str[225];

    std::cout << "Password management program: " << std::endl;
    std::cout << "1. Save your password" << std::endl;
    std::cout << "2. Read your password" << std::endl;
    int choice = 0;
    std::cout << "Your choice: ";
    std::cin >> choice;

    
    if(choice != 1 && choice != 2)
    {
        std::cerr << "Invalid syntax\n";
        return -1;
    }

    std::fstream pwd;
    if(!pwd)
    {
        std::cerr << "Fail to create/open file\n";
        return -1;
    }
    //write and save it password to the file using << to write to the file
    if(choice == 1)
    {
        //Create and open a file(use write mode only to create file)
        pwd.open("pwd.dat", std::ios::out);

        #if 0
        std::cout << "Enter the password: ";
        std::cin >> str;
        #endif

        //modify to get space 
        #if 1
        do {
            std::cin.getline(str, sizeof(str));
        } while (strlen(str) == 0);
        #endif

        pwd << str;
        pwd.close();
        std::cout << "Save to the file!" << std::endl; 
    }
    //Open for reading >> to read the file
    if(choice == 2)
    {
        pwd.open("pwd.dat", std::ios::in);

        pwd.getline(str, sizeof(str));
        pwd.close();

        std::cout << "Read your password: " << str << std::endl;
    }
    return 0;
}