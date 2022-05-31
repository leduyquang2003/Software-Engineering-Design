
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>             

#define MAXSIZE 225
#define PROG 2
/*Write a C++ program which defines a class named Student with private attributes name (string) and scores (an array of 3 integers to hold scores of the students). Provide constructor for the class.
a)	Write two methods for the class
•	inputData(): ask the user to input data (name and scores) for the student
•	showInfo(): print out information of the student
Test them in main() with an object.  
b)	Overload the >> and << operators so that it can be used with Student objects as below
•	cin >> object    : it will call the inputData() function to input data
•	cout << object  : it will call the showInfo() function to print out info.
•	object1  > object2: return true if average score of object1 is larger than that of object2; return false otherwise.
•	float n  + object: return a result object that has same name, but all scores are increased by n. 
Test them all in main().  
c)	Create an array of 10 Student objects using dynamic memory allocation, and read all information from a file named data.txt (attached) to assign values for them.
Use range based for loop to find and print out info of the student with highest average score. Free up allocated memory at the end of the program
Hint: you may need to use getline() function with delimiter. 
*/


#if (PROG == 1)
class Student
{
    private:
        std::string name;

    public:
        int scores[3];

        Student(){};
        Student(std::string name, int scores[3])
        {
            this->name = name;
            this->scores[3] = scores[3];
        }

        //Input data
        Student inputData()
        {
            char str_temp[MAXSIZE];
            std::cout << "Input information for the student: " << std::endl;
            std::cout << " >Enter name: ";
       
             do {
                std::cin.getline(str_temp, sizeof(str_temp));
            } while(strlen(str_temp) == 0);
            this->name = str_temp;

            std::cout << " >Enter score: " << std::endl;
            for(int i = 0; i < 3; i++)
            {
                std::cout <<">>Score " << i + 1 << ": ";
                std::cin >> this->scores[i];
            }
            return *this;
        }

        //Average score
        float averageScore()
        {
            float average;
            float sum = 0;
            for(int i = 0; i < 3; i++)
            {
                sum = sum + this->scores[i];
            }
            average = sum / 3;
            return average;
        }

        //Show Info
        std::string showInfo()
        {
            std::stringstream sstr;
            sstr << "name = " << name << std::endl;
            for(int i = 0; i < 3; i++)
            {
                sstr << "Score " << i + 1 << ": " << scores[i] << "\n";
            }
            return sstr.str();
        }

        std::string get_name()
        {
            return name;
        }


        //Overload <<
        friend std::ostream &operator << (std::ostream &output,  Student &object)
        {
            output << object.showInfo();
            return output;
        }
        #if 0
        friend  std::istream &operator >> (std::istream &input ,Student &object)
        {
            input >> object.inputData();
            return input;
        }
        #endif
 

        /*•	object1  > object2: return true if average score of object1 is larger than that 
        of object2; return false otherwise.*/
        #if 1
        Student operator > (Student &object)
        {
            if(this->averageScore() > object.averageScore())
            {
                
                std::cout << "True" << std::endl;
                return *this;
            }
            else
            {
                std::cout << "False" << std::endl;
                return *this;

            }
        }
        #endif

        /*•	float n  + object: return a result object that has same name, 
        but all scores are increased by n. */
        friend Student operator + (float n, Student &object);
};
//Overload float + object
Student operator + (float n, Student &object)
{
    Student result;
    result.name = object.name;
    for(int i = 0; i < 3; i++)
    {
        result.scores[i] = object.scores[i] + 1;
    }
    return result;
}

int main()
{
    Student stu1, stu2, stu3;
    stu1.inputData();
    stu2.inputData();
    std::cout << stu1.showInfo() << std::endl;

    stu1 > stu2;
    
    Student result;
    result = 3 + stu1;
    std::cout << result.showInfo() << std::endl;

    //Question c
    Student *stu_arr = new Student[10];

    std::ofstream myfile;
    myfile.open("data.txt", std::ios::out);

    if(!myfile)
    {
        std::cerr << "Fail to open file\n";
        return -1;
    }

    for(int i: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
    {   
        stu_arr[i].inputData();
        myfile << stu_arr[i].get_name() << ", " << stu_arr[i].scores[0] << ", "
                                          << stu_arr[i].scores[1] << ", "
                                          << stu_arr[i].scores[2] << std::endl;
    }

    Student highest = stu_arr[0];
    float highest_average;
    for(int i: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
    {
        if(highest.averageScore() < stu_arr[i].averageScore())
        {
            highest_average = stu_arr[i].averageScore();
        }
    }
    std::cout << highest_average<< std::endl;


    myfile.close();

    delete stu_arr;
    return 0;
}
#endif


#if (PROG == 2)
class Student 
{
    private:
        std::string name;
        int scores[3];
    
    public:
        Student(){}

        Student(std::string name_val, int scores_val[])
        {
            name = name_val;
            for(int i = 0; i < 3; i++)
            {
                scores[i] = scores_val[i];
            }
        }

        void setName(std::string name_val)
        {
            name = name_val;
        }

        //input a integer array
        void setScore(int scores_val[])
        {
            for(int i = 0; i < 3; i++)
            {
                scores[i] = scores_val[i];
            }
        }

        //input a string
        void setScore(std::string score_val)
        {
            std::stringstream sstr;
            sstr << score_val;
            for(int i = 0; i < 3; i++)
            {
                sstr >> scores[i];
            }
        }

        void inputData()
        {
            std::cout << "\nInput name: ";
            char str[MAXSIZE];
            do
            {
                std::cin.getline(str, sizeof(str));
            } while (strlen(str) == 0);
            name = str;

            std::cout << "Input scores: ";
            for(int i = 0; i < 3; i++)
            {
                std::cin >> scores[i];
            }

        }

        double avgScore()
        {
            int sum = 0;
            for(int i = 0; i < 3; i++)
            {
                sum += scores[i];   
            }
            return (double) sum / 3;
        }

        void showInfo()
        {
            std::cout << name << " "
                      << scores[0] << " "
                      << scores[1] << " "
                      << scores[2] << "\n";
            std::cout << ", avg = " << this->avgScore() << std::endl;
            
        }

        bool operator > (Student &stu2)
        {
            if(this->avgScore() > stu2.avgScore())
            {
                return true;
            }
            return false;
        }

        friend Student operator + (float n, Student &stu);

};

//cin >> object
std::istream &operator >> (std::istream &is, Student &stu)
{   
    stu.inputData();
    return is;
}

//cout << object
std::ostream &operator << (std::ostream &os, Student &stu)
{
    stu.showInfo();
    return os;
}

//float n + object:
Student operator + (float n, Student &stu)
{
    Student result = stu;
    for(int i = 0; i < 3; i++)
    {
        stu.scores[i] += n;
    }
    return result;
}
int main()
{
    //Qa
    Student stu1;
    stu1.inputData();
    std::cout << "> Qa. Student 1's info: ";
    stu1.showInfo();

    //Qb
    Student stu2;
    std::cin >> stu2;
    std::cout << "> Qb. Student 2's info: ";
    std::cout << stu2;


    if(stu1 > stu2)
    {
        std::cout << "\n> Student 1 has higher average score than Student 2\n";
    }
    else
    {
        std::cout << "\n> Student 1 has lower or equal average score than Student 2\n";
    }

    Student stu3 = 10 + stu2;
    std::cout << "\n> Student 3's info: ";
    stu3.showInfo();

    //Qc
    Student *stuArr = new Student[10];

    std::fstream myFile;
    myFile.open("data.txt", std::ios::in);

    //read  in information from the text file
    for(int i = 0; i < 10; i++)
    {
        std::string str;

        //read the name (up to the delimeter ',')
        std::getline(myFile, str, ',');
        stuArr[i].setName(str);

        //read the values (up to the end of the line)
        std::getline(myFile, str);
        stuArr[i].setScore(str);
    }
    myFile.close();

    std::cout << "\n> Qc. All information read from the file: \n";
    for(int i = 0; i < 10; i++)
    {
        stuArr[i].showInfo();
    }   

    Student bestStu = stuArr[0];
    for(int i = 1; i < 10; i++)
    {
        if(bestStu.avgScore() < stuArr[i].avgScore())
        {
            bestStu = stuArr[i];
        }
    }
    
    std::cout << "\n > Student with highest average score: \n";
    
    bestStu.showInfo();
    delete[] stuArr;
    return 0;
}
#endif