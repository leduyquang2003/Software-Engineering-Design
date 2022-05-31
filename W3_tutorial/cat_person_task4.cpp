#include <iostream>
#include <string>
#include <string.h>

/*4.	Define a class namely Cat with public attributes are name (string), age (int). 
Define another class namely person with public attributes are cat (Cat class) and name (string).  
Each class must have their own constructors.
a.	Make an array of three persons, and initialize values for them.
b.	Print out the information of the person who has the cat with the highest age (also print out information of that cat).
*/
class Cat
{
    public:
        std::string name;
        int age;

        /* We may have multile versions of constructor */ 
        //default constructor with no paramters (needed for Person constructor)
        Cat(){}

        Cat(std::string name_val, int age_val)
        {
            name = name_val;
            age = age_val;
        }
};

class Person
{
    public:
        Cat cat;
        std::string name;

        Person(Cat cat_val, std::string name_val)
        {
            cat = cat_val;
            name = name_val;
        }
};



int main()
{
    Person people[3] = {
        Person(Cat("Cat1", 3), "David John"),
        Person(Cat("Cat2", 5), "John Cena"),
        Person(Cat("Cat3", 8), "KenKum Boi")
    };

    for(int i = 0; i < 3; i++)
    {
        std::cout << people[i].cat.name << std::endl;
    }

    Person person_temp = people[0];
    for(int i = 1; i < 3; i++)
    {
        if(person_temp.cat.age < people[i].cat.age)
        {
            person_temp = people[i];
        }
    }

    std::cout <<"Information of cat has highest age and the person who has that cat: " << std::endl;
    std::cout <<"Name of cat: " << person_temp.cat.name << ". Age is " << person_temp.cat.age 
                << ". Name of person: " << person_temp.name << std::endl;
    

    return 0;
}