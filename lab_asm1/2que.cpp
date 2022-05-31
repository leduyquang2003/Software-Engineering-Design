/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Nguyen Tuong Khang
  ID: s3927112
  Compiler used: Compiler version (e.g. gcc 8.1.0)
  Created  date: 4/9/2022
  Acknowledgement: None
*/


#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>  
#define MAXSIZE 225

/*a) Defines a class namely EWallet with two private attributes are id (string) and 
balance
(double).
 Write constructor for it to initialize the attributes, and two methods as below:
- void deposit(double num): to add num amount of money into the ewallet.
- bool withdraw(double num): to take out num amount of money from the ewallet.
You should have appropriate message printing to screen when those methods are called.
Create an object by dynamic allocation in main() function and initialize its data using 
the constructor, then test all functions above. Free up allocated memory after that.*/
class EWallet
{
    private:
        std::string id;
        double balance;

    public:
        EWallet(){}
        EWallet(std::string id, double balance)
        {
            this->id = id;
            this->balance = balance;
        }

        void deposit(double num)
        {
            balance = balance + num;
        }

        bool withdraw(double num)
        {
            if(balance >= num)
            {
                balance = balance - num;
                return true;
            }
            else
            {
                return false;
            }
        }

        double set_balance(double num)
        {
            balance = num;
            return balance;
        }

        std::string get_id()
        {
            return id;
        } 

        double get_balance()
        {
            return balance;
        }
       
};

/*b) Define another class namely Customer with two attributes are name (string), 
pwd (string),
ew (EWallet object). Provide constructor for it, and three methods as below:
• bool verifyPass(): ask the user to input a password, and compare it with attribute 
pwd. Return true if match, and false if does not match with appropriate messages on 
screen.
• bool doDeposit(): call the method verifyPass() first to verify password. It success, 
allow user to input amount of money for depositing and add it into current balance of
the customer’s ew object (hint: must call deposit() method of the ew object)..
• bool doWithdraw(): call the method verifyPass() first to verify password. It success, 
allow user to input amount of money for withdrawing and subtract it from current 
balance of the customer’s ew object (hint: must call withdraw() method of ew object).*/

class Customer
{
    public:
        std::string name;
        std::string pwd;
        EWallet ew;

        Customer(){}
        Customer(std::string name, std::string pwd, EWallet ew)
        {
            this->name = name;
            this->pwd = pwd;
            this->ew = ew;
        }

        bool verifyPass()
        {
            std::cout << "Input your password: " << std::endl;
            char str[MAXSIZE];
            do
            {
                std::cin.getline(str, sizeof(str));
            } while (strlen(str) == 0);
            if(pwd == str)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /*c) Overload the >> operator so that we can do following operations
customerA >> customerB : all money of customerA will be transferred to customerB 
*/
        Customer operator >> (Customer &B)
        {
            B.ew.set_balance(this->ew.get_balance() + B.ew.get_balance());
            //this->ew.set_balance(0);
            this->ew.set_balance(0);
            return B, *this;
        }
/*
customerA++ (postfix): the current balance of customerA will be increased by 1000, but
return all previous value.*/
        Customer operator ++ (int)
        {
            int num = this->ew.get_balance() + 1000;
            this->ew.set_balance(num);
            return *this;
        }
};




int main()
{
    int num;
    EWallet *acc1 = new EWallet("3927112", 3000);
    std::cout << ">Add num to wallet\n";
    acc1->deposit(10000);
    std::cout << "Balance after add num to wallet: " << acc1->get_balance() << std::endl;
    std::cout << ">Withdraw\n";
    if(acc1->withdraw(10000) == false)
    {
        std::cout << "You dont have enough money" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Balance after withdraw: " << acc1->get_balance() << std::endl;
    }

    std::cout << ">Verify password:\n";
    Customer cus1("Khang", "sieunhantim", EWallet("3927112", 3000));
    Customer cus2("Duy", "kaila", EWallet("3981239", 4000));
    if(cus1.verifyPass() == true)
    {
        std::cout << "password verify!" << std::endl;
        std::cout << "Enter amount to deposit: ";
        std::cin >> num;
        cus1.ew.deposit(num);
        std::cout << "Balance after add num to wallet: " << cus1.ew.get_balance() << std::endl;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> num;
        cus1.ew.withdraw(num);
        std::cout << "Balance after withdraw: " << cus1.ew.get_balance() << std::endl;
    }
    else
    {
        std::cout << "password doens't match" << std::endl;
    }

    //test c:
    cus1 >> cus2;
    std::cout << "customerA >> customerB : "<< std::endl;
    std::cout << "Balance of cus2: "<< cus2.ew.get_balance() << std::endl;
    std::cout << "Balance of cus1: " << cus1.ew.get_balance() << std::endl; 



    cus1++;
    std::cout << ">Test cus1++: " << std::endl;
    std::cout << cus1.ew.get_balance() << std::endl;

    /*d) Create an array of four customers using dynamic allocation and initialize 
        values for them. 
Store all information into a text file (each customer per line, each information is 
separate by 
',' symbol). Find and print out the customer with second largest balance. Free up 
allocated 
memory at the end of the program*/
    Customer *cus_arr = new Customer[4]{
        Customer("Khang", "sieunhantim", EWallet("3927112", 50000)),
        Customer("Dung", "sieunhanhong", EWallet("3927113", 3003)),
        Customer("Thai", "sieunhanxanh", EWallet("3927114", 500000)),
        Customer("Tri", "sieunhanvang", EWallet("3927115", 30000)),
    };
    std::fstream myFile;
    myFile.open("cus.txt", std::ios::out);
    for(int i = 0; i < 4; i++)
    {
        myFile << cus_arr[i].name << ", " << cus_arr[i].pwd << ", "
        << cus_arr[i].ew.get_id() << ", " << cus_arr[i].ew.get_balance() << std::endl;
    }
    myFile.close();

    Customer highest = cus_arr[0];
    Customer second_highest;
    for(int i = 1; i < 4; i++)
    {
        if(highest.ew.get_balance() < cus_arr[i].ew.get_balance())
        {
            //highest.ew.set_balance(cus_arr[i].ew.get_balance());
            highest = cus_arr[i];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(cus_arr[i].ew.get_balance() != highest.ew.get_balance())
        {
            if(second_highest.ew.get_balance() <= cus_arr[i].ew.get_balance())
            {
                second_highest = cus_arr[i];
            }
        }
    }

    std::cout << "customer with largest balance is " << highest.name << " "<< highest.ew.get_balance() << std::endl;
    std::cout << "customer with second largest balance is " << second_highest.name << " "<< second_highest.ew.get_balance() << std::endl;


    delete[] acc1;
    delete[] cus_arr;
    return 0;
}