#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class Person
{
    public:
        std::string name;
        int age;

        Person()
        {
            // std::cout << "Default constructor of Person class is called" << std::endl;
        }

        // ~Person()
        // {
        //     std::cout << "Default destructor of Person class is called" << std::endl;
        // }
};

class Student: public Person
{
    public:
        int studentID;
        //inherited attribute: name, age


        Student()
        {
            // std::cout << "Default constructor of Student class is called" << std::endl;
        }

        // ~Student()
        // {
        //     std::cout << "Default destructor of Student class is called" << std::endl;
        // }   
};

class Staff: public Person
{
    public:
        int staffID;
        //inherited attribute: name, age

        Staff()
        {
            // std::cout << "Default constructor of Staff class is called" << std::endl;
        }

        // ~Staff()
        // {
        //     std::cout << "Default destructor of Staff class is called" << std::endl;
        // }
};

class Tutor: public Student, public Staff 
{
    public:
        //inherited attribute: name, age from Student class
        //inherited attribute: name, age from Staff class

        Tutor()
        {
            // std::cout << "Default constructor of Tutor class is called" << std::endl;
        }

        Tutor(int studentID, int staffID)
        {
            this->studentID = studentID;
            this->staffID = staffID;
        }
        Tutor(std::string staff_name, int staffID_val, int staff_age,
                std::string student_name, int studentID_val, int student_age)
        {
            Staff::name = staff_name;
            staffID = staffID_val;
            Staff::age = staff_age;

            Student::name = student_name;
            studentID = studentID_val;
            Student::age = student_age;                                 
        }

        std::string print_info()
        {
            std::stringstream sstr;
            sstr << "studentId = " << studentID << " staffID = " << staffID << std::endl;
            return sstr.str();
        }

        void consultation()
        {
            std::cout << "Consultation! " << std::endl;
        }

        void fullInfo()
        {
            std::cout << "> StaffID = " << staffID << std::endl 
                      << "> Staff name = " << Staff::name <<  std::endl
                      << "> Staff age = " << Staff::age << std::endl
                      << "> StudentID = " << studentID << std::endl
                      << "> Student name = " << Student::name << std::endl
                      << "> Student age = " << Student::age << std::endl;
        }
        // ~Tutor()
        // {
        //     std::cout << "Default destructor of Tutor class is called" << std::endl;
        // }
};

int main()
{
    /*a)	Create a Tutor object, and test access to all inherited attributes 
    (by assigning random values for them).*/
    Tutor tu1;
    #if 1
    tu1.studentID = 3927112;
    tu1.staffID = 20930;

    tu1.Student::name = "Nguyen An";
    tu1.Staff::name = "Tran Duc Linh";
    tu1.Student::age = 18;
    tu1.Staff::age = 34;

    tu1.fullInfo();
    #endif

    /*b)	Create default constructors and destructors for all classes, 
    both of which announce themselves to cout. Verify that for a Tutor object, 
    all three constructors and destructors are automatically called.  
    Explain the order in which the calls are made.*/
    std::vector<Tutor> tutors = {
        Tutor("Tran Duc Linh", 98323, 32,"Nguyen Tuong Khang", 3927112, 19),
        Tutor("Stanley", 82332, 35, "Do Phuong Linh", 3982321, 19),
        Tutor("Minh Bui", 78987, 40, "Le Duy Quang", 3983232, 19)
    };

    std::cout << "All information of students in the list: \n";
    for(Tutor &tutor: tutors)
    {
        tutor.fullInfo();
        std::cout << std::endl;
    }

    tutors.erase(tutors.begin() + 1);
    for(Tutor &tutor: tutors)
    {
        tutor.fullInfo();
        std::cout << std::endl;
    }


    /*c)	Write a parameterized constructor for the Tutor class to initialize its attributes. 
    Create a vector of 3 Tutor objects with random values. Print out all information 
    of 3 tutors using the range based for loop.*/
    
    #if 0
    std::cout <<"\n\n";
    std::cout <<"Write a parameterized constructor for the Tutor class to initialize its attributes." << std::endl;
    Tutor tu2(409239, 19);
    std::cout << tu2.print_info();
    std::cout <<"\n\n";
    std::vector<Tutor> vector_object(3);

    // Tutor tut_arr[3] = {
    //     Tutor(3982, 2093),
    //     Tutor(3982, 2093),
    //     Tutor(3982, 2093)
    // };

    vector_object[0] = Tutor(3982, 2093);
    vector_object[1] = Tutor(30923, 9823);
    vector_object[2] = Tutor(2983, 2093);
    for(Tutor &vector_object: vector_object)
    {
        std::cout <<vector_object.print_info();
    }

    //d)	Remove the second tutor from the vector, then print out all information again to check
    std::cout <<"\n\n";
    std::cout << "  d)	Remove the second tutor from the vector, then print out all information again to check" << std::endl;
    vector_object.erase(vector_object.begin() + 1);
    for(Tutor &vector_object: vector_object)
    {
        std::cout <<vector_object.print_info();
    }
    #endif

    


    return 0;

}



