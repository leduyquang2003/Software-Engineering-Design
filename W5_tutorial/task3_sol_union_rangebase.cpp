#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#define STRSIZE 225

/*3.	Union and range-based loop. Write a program which define a union named 
Students with two attributes firstName and fullName. 
a.	Define an array of 3 students and initialize fullName for them.
b.	Use a range-based for loop to print out information of all students.
c.	Change the firstName of all three students to another name. Print out 
their fullName. What happens ? */


union Student
{
    char firstname[STRSIZE];
    char fullname[STRSIZE];
};

int main()
{
    //Qa
    Student stu_arr[3];

    std::cout << "Input full name of students: " << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "Student " << i + 1 << ":";
        do{
            std::cin.getline(stu_arr[i].fullname, sizeof(stu_arr[i].fullname));
        } while(strlen(stu_arr[i].fullname) == 0);
    } 

    //Qb: range based loop (access by value)
    int count = 0;
    for(Student stu: stu_arr)
    {
        std::cout << "Student " << ++count << " fullname: " << stu.fullname << std::endl;
    }

    //Qc Change the first name (access by value) --> need to access by reference
    for(Student &stu: stu_arr)
    {
        strcpy(stu.firstname, "NA");
    }

    count = 0;
    std::cout << "First names after being changed:\n";
    for(Student stu: stu_arr)
    {
        std::cout << "Student " << ++count << " first name: " << stu.firstname << std::endl;
    }

    count = 0;
    std::cout << "Fullnames after being changed:\n";
    for(Student stu: stu_arr)
    {
        std::cout << "Student " << ++count << " fullname: " << stu.fullname << std::endl;
    }
    return 0;
}