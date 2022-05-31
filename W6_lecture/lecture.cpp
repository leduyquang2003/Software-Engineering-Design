#define PROG 1 2 3 4 5


/*-------------------------BASIC INHERITANCE---------------------------*/
#if PROG == 1
#include <iostream>
using namespace std
;
//parent base class
class Animal
{
    public:
        int age;
        void eat()
        {
            cout << "I can eat!" << endl;
        }
};

//child dervied class
class Dog: public Animal
{
    public:
        void bark()
        {
            cout << "I can bark! Woof woof!!" << endl;
        }
};


int main()
{

    Dog dog1;
    dog1.age = 10;
    dog1.eat();
    dog1.bark();

    return 0;
}
#endif
/*-------------------------BASIC INHERITANCE---------------------------*/


/*-------------------------MULTILEVEL & MULTIPLE INHERITANCE---------------------------*/
#if PROG == 2
#include <iostream>
//Base class(grandfather)
class GrandFather
{
    public:
        void grandFunct()
        {
            std::cout << "A method from grandfather class" << std::endl;
        }
};

//Derived class(father)
class Father: public GrandFather
{
    public:
        void fatherFunct()
        {
            std::cout << "A method from father class" << std::endl;
        }
};

//Another base class(mother)
class Mother
{
    public:
        void motherFunct()
        {
            std::cout << "A method from mother class" << std::endl;
        }
};

//Derived class (child)
class Child: public Father, public Mother
{
     public:
        void childFunct()
        {
            std::cout << "A method from child class" << std::endl;
        }
};

int main()
{
    Child child1;
    child1.grandFunct();
    child1.fatherFunct();
    child1.motherFunct();

    return 0;
}
#endif
/*-------------------------MULTILEVEL & MULTIPLE INHERITANCE---------------------------*/


/*-------------------------------------VECTOR------------------------------------------*/
#if PROG == 3
#include <vector>
#include <iostream>
void Intialization_Methods()
{
    //Initialization with list(1 - 5)
    std::vector<int> vectorA = {1, 2, 3, 4, 5};
    std::vector<int> vectorB {1, 2, 3, 4, 5};

    //Uniform intialization --> 5 elements with values all 12
    std::vector<int> vectorC(5, 12);
}

int main()
{
    std::vector<int> numVt {1, 2, 3, 4, 5};

    numVt.push_back(60); //add value 60 at the end
    numVt.push_back(70); //add value 70 at the end
    std::cout << "First element: " << numVt[0] << std::endl;
    std::cout << "Last element: " << numVt[numVt.size() - 1] << std::endl;

    numVt.pop_back(); //remove last element
    std::cout << "Last element after removing: " << numVt[numVt.size() - 1] << std::endl;


    //Print out all elements with range based for loop
    std::cout << "All element: ";
    for(int &num: numVt) //loop by reference --> faster 
    {
        std::cout << num << " ";
    }

    return 0;
}

#endif
/*-------------------------------------VECTOR------------------------------------------*/


/*-------------------------CONSTRUCTOR WITH MEMBER INTIALIZER LIST-----------------------------*/
#if PROG == 4
#include <iostream>
class BankAcc
{
    public:
        std::string name;
        int amount;

        BankAcc(){} //Default Constructor

        //Parameterized Constructor: Previous way
        BankAcc(std::string name_val, int amount_val)
        {
            name = name_val;
            amount = amount_val;
        }

        //Parameterized Constructor with member intializer list
        BankAcc(std::string name_val, int amount_val): 
            name(name_val), amount(amount_val){}
};

#endif
/*-------------------------CONSTRUCTOR WITH MEMBER INTIALIZER LIST-----------------------------*/

/*-------------------------OBJECT COPY OPERATIONS (RULE OF THREE)-----------------------------*/
#include <iostream>
#if PROG == 5
class Juice
{
    public:
        std::string name;
        int *price;

        Juice()
        {
            this->price = new int; //request memmory allocation
        }

        Juice(std::string name_val, int price_val)
        {
            this->name = name_val;
            this->price = new int(price_val); //request memmory allocation

            std::cout << "\n\nConstructor is called, name = " << name << ", price = " << *price << std::endl;
        }

        #if 1
        //Copy constructor --> for new object
        Juice(const Juice &Juice)
        {
            this->name = Juice.name;
            this->price = new int(*Juice.price); //allocate new memory allocation
        }
        #endif

        //Copy Assignment operator --> for existing object
        Juice operator = (Juice *od_obj)
        {
            //statements to copy content from old_obj to current obj;
            return *this; //return current object (so that multiple "=" operators can be used together)
        }

        //Display method
        void display()
        {
            std::cout << "Juice: " << name << std::endl;
            std::cout << "Price: " << *price << std::endl;
            std::cout << std::endl;
        }

        //Overload operators --
        Juice operator -- (int)
        {
            Juice temp = *this; //Copy constructor: price of temp got same address with current object
            std::cout << "address of this->price: " << (void *) this->price << std::endl;
            std::cout << "address of temp->price: " << (void *) temp.price << std::endl;

            temp.name = "TempJuice";
            *(this->price) -= 1;

            /*when we return, it will call destructor of temp and delete its price
                --> will make the price of current object fails to work*/
            return temp; //return previous value (before decreasing)
        }

        //Destructor
        ~Juice()
        {
            std::cout << "Destructor is called, name = " << name << ", price = " << *price << std::endl;
            delete price;
        }

};

int main()
{
    Juice juice1("Juice1", 100);
    Juice juice2("juice2", 200);

    //Test --operator
    juice2 = juice1--;
    juice2.display();


    return 0;
}
#endif

/*-------------------------OBJECT COPY OPERATIONS (RULE OF THREE)-----------------------------*/
