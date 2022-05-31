/*You are involved in development of a software for school management. The following details are as follows: 
Each staff are managed by his/her name and department. He/she can belong to one or none of department. It is possible for a staff to 
join or leave a department in some cases (e.g. leave or change to another department).
The system allows to manage each department by its name and location, each of which needs to have at least one staff. 
For the academic department, its number of courses will be recorded. Whereas, for non-academic department, the number of services is monitored.
*/

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

//Class Prototype
//(declare Department class to use this data type in Staff class)
class Department;

class Staff
{
    private:
        string name;
        string deptName;
    public:
        Staff(){}
        Staff(string name, string deptName)
        {
            this->name = name;
            this->deptName = deptName;
        }

        //Methods: declare first, define later
        void joinDept(Department &dept);
        void leaveDept(Department &dept);

        friend class Department; // grant access
};

//Define Department class here
class Department
{
    private:
        string name;
        string location;
        vector<Staff*> staffs;
    public:
        //Constructors
        Department(){}
        Department(string name, string location, vector<Staff*> staffs)
        {
            this->name = name;
            this->location = location;
            this->staffs = staffs;
        }

        void showInfo()
        {
            cout << "\nDept Name = " << name 
                 << "\n> Location = " << location
                 << "\n> Current Staffs: \n";

            for(auto eachStaff: staffs)
            {
                cout << "\t" << eachStaff->name << "\n";
            } 
        }

        friend class Staff;
};

//Define join and leave methods of Staff class
void Staff::joinDept(Department &dept)
{
    //insert current staff into the list
    dept.staffs.push_back(this);
}
void Staff::leaveDept(Department &dept)
{
    //find and remove current staff from the list
    for(int i = 0; i < dept.staffs.size(); i++)
    {
        if(dept.staffs[i] == this)
        {
            dept.staffs.erase(dept.staffs.begin() + i);
        }
    }
}

//Academic Deparment (subtype of Department)
class AcadDept: public Department
{
    private:
        int numOfCourses;
    public:
        AcadDept(){}

        //parameterized constructor: reuse the constructor of Deparment class
        AcadDept(string name, string location, vector<Staff*> staffs, int numOfCourses): Department(name, location, staffs)
        {
            this->numOfCourses = numOfCourses;
        }

        void showInfo()
        {
            Department::showInfo();
            cout << "> numOfCourses = " << numOfCourses << endl;
        }
};

//Non-academic Department(subtype of Department)
class NonAcadDept: public Department
{

    private:
        int numOfServices;
        string name;

    public:
        NonAcadDept(){}
        
        //parameterized constructor: reuse the constructor of Deparment class
        NonAcadDept(string name, string location, vector<Staff*> staffs, int numOfServices): Department (name, location, staffs) 
        {
            this->numOfServices = numOfServices;
        }

        void showInfo() 
        {
            Department::showInfo();
            cout << "> numOfServices = " << numOfServices << "\n";
        }
};


int main()
{
    Staff staff1("staff1", "");
    Staff staff2("staff1", "");
    Staff staff3("staff1", "");

    AcadDept dept1("SSET", "Building 2", vector<Staff*>{}, 10);
    NonAcadDept dept2("ITS",  "Building 1", vector<Staff*>{}, 5);

    staff1.joinDept(dept1);
    staff2.joinDept(dept2);
    staff3.joinDept(dept1);
    dept1.showInfo();
    dept2.showInfo();

    return 0;
}

