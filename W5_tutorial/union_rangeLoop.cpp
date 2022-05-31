/*3.	Union and range-based loop. Write a program which define a union named Students with 
two attributes firstName and fullName. 
a.	Define an array of 3 students and initialize fullName for them.*/
#include <iostream>
#include <string>
#include <string.h>
#define MAXSIZE 225

union Students
{
    // std::string firstName;
    // std::string fullName;
    char firstName[MAXSIZE];
    char fullName[MAXSIZE];
    
};

int main()
{
    Students group[3];
    std::cout << "Size = " << sizeof(Students) << "\n";


    /*b.	Use a range-based for loop to print out information of all students.*/
    for(int i : {0, 1, 2})
    {
        std::cout << "Initialize full name of student " << i + 1 << ": ";
        std::cin.getline(group[i].fullName, sizeof(group[i].fullName));
    }
    
    for(int i : {0, 1, 2})
    {
        std::cout << group[i].fullName << std::endl;
    }

    /*c.	Change the firstName of all three students to another name. 
    Print out their fullName. What happens ? */
    for(int i: {0, 1, 2})
    {
        std::cout << "Initialize full name of student " << i + 1 << ": ";
        std::cin.getline(group[i].firstName, sizeof(group[i].firstName));
    }
    for(int i : {0, 1, 2})
    {
        std::cout << group[i].fullName << std::endl;
    }
    /*Change firstName of student making full name changing to*/


    return 0;
}