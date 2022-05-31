#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

/*2.	Define a class namely student with attributes are name (string) and score (integer). Both of them are public.
a.	Write a constructor for the class to initialize attributes’ values.
b.	Create two student objects and initialize values for them using class constructor. Print out all information of the two students.
c.	Create an array of three students and initialize values for all of them using class constructor. Print out information of the student with highest score.
*/

//a.	Write a constructor for the class to initialize attributes’ values.
class student
{
    //Additional: modify the program so that score is private, and make a method namely get_score() to provide reading access to it.
    private:
        int score_private;
        std::string pwd;
    public:
        std::string name;
        int score;

        //Constructor with parameters
        student(){} 
        student(std::string name_cons,int score_cons, int score_private_cons)
        {
            name = name_cons;
            score = score_cons;
            score_private = score_private_cons;
        }

        int get_score()
        {
            return score_private;
        }

        std::string get_pwd()
        {
            return pwd;
        }



        void change_pwd()
        {
            std::fstream myfile;
            std::string content;
            myfile.open(name + ".dat", std::ios::in);
            std::getline(myfile, content);
            myfile.close();                     


            if(content.length() == 0)
            {
                std::cout << "You haven't has password before. Please enter a new one: ";
                char temp[225];
                do
                {
                    std::cin.getline(temp, sizeof(temp));
                } while (strlen(temp) == 0);
                pwd = temp;
                myfile.open(name + ".dat", std::ios::out);
                myfile << pwd;
                std::cout << "Saved it successfully" << std::endl;
                myfile.close();
            }
            else
            {
                std::cout << "Enter your old password: ";
                std::string old_pass;
                std::getline(std::cin, old_pass);                
                if(old_pass == content)
                {
                    std::cout << "Please enter a new one: ";
                    char temp[225];
                    do
                    {
                        std::cin.getline(temp, sizeof(temp));
                    } while (strlen(temp) == 0);
                    pwd = temp;
                    myfile.open(name + ".dat", std::ios::out);
                    myfile << pwd;
                    std::cout << "Saved it successfully" << std::endl;
                    myfile.close();
                }
                else
                {
                    std::string str;
                    std::cout << "Password doesn't match" << std::endl;
                    std::cout << "Hack? Y/N: " << std::endl;
                    std::string choice;
                    std::getline(std::cin, choice);
                    std::string yes;
                    yes = "Y";
                    if(choice == yes)
                    {
                        myfile.open(name + ".dat", std::ios::in);
                        std::getline(myfile, str);
                        std::cout << "Password = " << str << std::endl;
                        myfile.close();
                    }
                    else
                    {
                        std::cout << "Sorry cannot change your password!" << std::endl;
                    }
                }
            }
        }

        
};

int main()
{
    /*b.	Create two student objects and initialize values for them using class constructor. Print out all information of the two students.*/
    student std1("Nguyen Tuong Khang", 98, 23);
    student std2("Pham Thi Ngoc", 75, 53);

    #if 0
    //print values
    std::cout << "Student info: " << std::endl;
    std::cout << std1.name << " " << std1.score  << " " << std1.get_score() << std::endl;
    std::cout << std2.name << " " << std2.score << std::endl;


    /*c.	Create an array of three students and initialize values for all of them using class constructor. Print out information of the student with highest score.*/
    std::cout <<"Array of 3: " << std::endl;
    student Arr[3] = { student("Nguyen Tuong Duy", 78, 25),
                       student("Nguyen Ngo Kha", 90, 32),
                       student("Mai Am Nhac", 59, 20)};

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
    #endif

    /*3.	From the student class in question 2, add another private attribute namely password. Write a method for the class namely change_pwd() 
    to allow people to change their password as below and test it in main function. 
a.	If there is no existing password, allow them to provide value for the password. Save it into a file namely 
name.dat (whereas name is student name).
b.	If there is an existing password, ask them to enter their previous password to check. If it is matched, 
save the new password into their file.
*/
    std1.change_pwd();

    return 0;
}