#include <iostream>
#include <string>
#include <vector>

class Department{
private:
    std::string name;
public:
    Department(){}
    Department(std::string name){
        this->name = name;
    }
    void showInfo(){
        std::cout << "Name of Department = " << name << "\n";
    }
};

class AcadDept: public Department {
private:
    int numOfCourses;
public:
    AcadDept(){}
    AcadDept(std::string name, int numOfCourses)
        : Department(name) { //call constructor of base class
        this->numOfCourses = numOfCourses;
    }

    void showInfo() {
        Department::showInfo(); //call method of base class
        std::cout << "Num of Courses = " << numOfCourses << "\n";
    }
};

int main(){
    AcadDept sset("SSET", 25);
    sset.showInfo();

    return 0;
}




