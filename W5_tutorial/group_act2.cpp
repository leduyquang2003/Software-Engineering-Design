#include <iostream>
#include <string.h>
#include <string>
#define NAMESIZE 225
#define PROG 2

/*Write a C++ program which defines a class named Juice with two attributes name (string) and price (integer). Provide constructor to initialize those attributes. 

a) Create an array of 3 Juice objects using dynamic memory allocation and initialize values for them (can assign randomly by yourself).
Use range-based for loop to print out all information*/

#if (PROG == 1)
class Juice
{
    public:
        std::string name;
        int *price;

        Juice()
        {
           price = new int; 
        };
        Juice(std::string name_val, int price_val)
        {
            this->name = name_val;
            this->price = new int(price_val);
        }

        std::string info()
        {
            return "Name of Juice = " + name + ". Price = " + std::to_string(*price);
        }

    /*b) Overload operators to support following operations with defined meaning as below

object--;   //reduce the price by one, and return a result object (postfix).
object + object;   //return a result object with price is total price if names are identical, 0 if they are different (name is “NA” in that case).
int n – object; // return a result object with price is reduced by n %.*/
        Juice operator --(int)
        {
            *price = *price - 1;
            return *this;  
        }

        #if 1
        Juice operator + (Juice &object)
        {
            Juice temp;

            if(this->name == object.name)
            {
                *temp.price = *price + *object.price;
                temp.name = object.name;
            }
            else
            {
                temp.name = "NA";
                *temp.price = 0;               
            }
            return temp;
        }
        #endif
        friend Juice operator - (int n, Juice &object);

};
#if 1
Juice operator - (int n, Juice &object)
{
    Juice result;
    float percent = (float) n/100;
    *result.price = *object.price - (*object.price * percent);
    return result;
}
#endif
int main()
{
    Juice *p = new Juice[3];


    Juice drink1("Orange", 10000);
    Juice drink2("Banana", 5000);
    Juice result = 20 - drink1;
    //Juice result("Orange", 10000);
    std::cout << result.info() << std::endl;



    #if 1
    char str_temp[NAMESIZE];
    for(int i: {0, 1, 2})
    {
        std::cout << "> Juice " << i + 1 << std::endl;
        
        //read a line
        do {
            std::cin.getline(str_temp, sizeof(str_temp));
        } while (strlen(str_temp) == 0);
        p[i].name = str_temp;

        std::cout << "price: ";
        std::cin >> *p[i].price;

    } 

    for(int i: {0, 1, 2})
    {
        std::cout << p[i].info() << std::endl;
    }
    #endif

    return 0;
}
#endif


#if (PROG == 2)
class Juice {
public:
    std::string name; 
    int *price; //Qc

    void mem_request_for_price() {
        price = new (std::nothrow) int;
        if (price == NULL) {
            std::cerr << "Fail to allocate memory for 'price'\n";
        }
    }

    Juice (){  //default constructor
        mem_request_for_price(); 
    };

    Juice (std::string name_val, int price_val){ //parameterized constructor
        mem_request_for_price(); 
        name = name_val;
        *price = price_val;
    };

    void showInfo() {
        std::cout << "name = " << name << ", price = " << *price << "\n";
    }

    //Operator overloand functions
    Juice operator -- (int) {
        Juice temp = *this; //to store previous values
        (* (this->price) ) --; //reduce price by 1
        return temp; //return previous values
    }


    Juice operator + (Juice &juice2) { //pass in second operand
        Juice temp;
        if (this->name != juice2.name ) { //diffrent names
            temp.name = "N/A";
            *(temp.price) = 0;
        } else {
            temp.name = this->name;
            *(temp.price) = *(this->price) + *(juice2.price);
        }
        
        return temp;
    }

    //Destructor
    ~Juice () {
        /* free up allocated memory */
        //delete price;  //you can TURN THIS ON when running on your computer
        
        /*  Note: with current version of g++ installed on your computer, there will be no problem.
            However, with the g++ version of replit, the program may crash when we free up memory in the destructor.
            The reason is as explained in class, it is due to copy constructor/ copy assignment operator --> learn it more in w8.
        */
    }

};



Juice operator - (int num, Juice &juice) { //external function: must pass in all operands  (num - juice)
    Juice temp = juice; 

    *(temp.price) = *(temp.price) * (100 - num) / 100;
    return temp;
}


int main() {
    //Qa. Define and initialize array of three juice objects with dynamic allocation
    Juice *juices = new Juice[3] {
        Juice ("Apple", 100),
        Juice ("Apple", 200),
        Juice ("Lemon", 300)
    };

    //Print out information with range based for loop  
    for (Juice eachJuice: {juices[0], juices[1], juices[2]} ) {
        eachJuice.showInfo();
    }

    //Qb
    Juice result;
    juices[0]--; 
  
    result = juices[0] + juices[1];
    result = 10 - result;
    std::cout << "Result: "; result.showInfo();


    delete juices;
    
    return 0;
}   
#endif