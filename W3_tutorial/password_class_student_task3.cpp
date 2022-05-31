#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

/*3.	From the student class in question 2, add another private attribute namely password. Write a method for the class namely change_pwd() to allow people to change their password as below and test it in main function. 
a.	If there is no existing password, allow them to provide value for the password. Save it into a file namely name.dat (whereas name is student name).
b.	If there is an existing password, ask them to enter their previous password to check. If it is matched, save the new password into their file.*/
int EXISTING  = 0;
#define MAXSIZE 100

class student
{
    //Additional: modify the program so that score is private, and make a method namely get_score() to provide reading access to it.
    private:
        int score_private;
        std::string password = ""; 

    public:
        std::string name = "";
        int score;

        //Constructor with parameters
        student(std::string name_cons,int score_cons, int score_private_cons, std::string password_cons)
        {
            name = name_cons;
            score = score_cons;
            score_private = score_private_cons;
            password = password_cons;
        }

        int get_score()
        {
            return score_private;
        }

        std::string get_pwd()
        {
            return password;
        }

        int change_pwd()
        {
            /*Check if there is an existing password or not*/
            //Open the file to read the user previous password
            char prev_pwd[MAXSIZE];
            char new_pwd[MAXSIZE];
            char in_pwd[MAXSIZE];
            std::fstream myfile;

            myfile.open(name + ".dat", std::ios::in); //open for reading
            myfile.getline(prev_pwd, sizeof(prev_pwd)); //get a line from the file
            myfile.close();

            //check that the password got from the file is empty or not
            if(strlen(prev_pwd) == 0)
            {
                /*No existing Passwrod*/
                std::cout << "No existing Password. Please set your password" << std::endl;
                std::cin.getline(new_pwd, sizeof(new_pwd));

                //Store into the file
                myfile.open(name + ".dat", std::ios::out); //open or create the file
                myfile << new_pwd;
                myfile.close();
                return 0;
            }
            else
            {
                /*There is an existing Password*/
                std::cout << "Enter your previous pasword: ";
                std::cin.getline(in_pwd, sizeof(in_pwd));

                if(strcmp(prev_pwd, in_pwd) == 0)
                {
                    std::cout << "Please set your password: " << std::endl;
                    std::cin.getline(new_pwd, sizeof(new_pwd));

                    //Store into the file
                    myfile.open(name + ".dat", std::ios::out); //open or create the file
                    myfile << new_pwd;
                    myfile.close();

                    std::cout << "Saved your password!" << std::endl;
                    return 0;
                }
                else
                {
                    std::cerr << "Wrong password\n";
                    return -1;
                }
            }

        }

};

int main()
{
    /*b.	Create two student objects and initialize values for them using class constructor. Print out all information of the two students.*/
    student std1("Nguyen Tuong Khang", 98, 23, "");
    student std2("Pham Thi Ngoc", 75, 53, "");

    //print values
    std::cout << "Student info: " << std::endl;
    std::cout << std1.name << " " << std1.score  << " " << std1.get_score() << std::endl;
    std::cout << std2.name << " " << std2.score << std::endl;


    /*c.	Create an array of three students and initialize values for all of them using class constructor. Print out information of the student with highest score.*/
    std::cout <<"Array of 3: " << std::endl;
    student Arr[3] = { student("Nguyen Tuong Duy", 78, 25, ""),
                       student("Nguyen Ngo Kha", 90, 32, ""),
                       student("Mai Am Nhac", 59, 20, "")};

    //print values
    std::cout << "Student info: " << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << Arr[i].name << " " << Arr[i].score << std::endl;
    }

    #if 0
    //check highest score
    int highest = Arr[0].score;
    std::string name_of_highest = Arr[0].name;
    for(int i = 0; i < 3; i++)
    {
        if(highest < Arr[i].score)
        {
            highest = Arr[i].score;
            name_of_highest = Arr[i].name;
        }
    }
    std::cout << "Student highest score is " << name_of_highest << " with " << highest << std::endl;
    #endif

    //check highest score teacher solution
    student best_stu = Arr[0]; // assume that the first student has highest score
    for(int i = 1; i < 3; i++) //check with other students
    {
        if(best_stu.score < Arr[i].score)
        {
            best_stu = Arr[i];
        }
    }
    std::cout << "Student with highest score ";
    std::cout << best_stu.name << " " << best_stu.score << std::endl;

    //Ex3
    student stu("David", 87, 30, "khangsdasd");
    std::cout << stu.get_pwd();
    // stu.change_pwd();

    


    return 0;
}