/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Nguyen Tuong Khang
  ID: s3927112
  Compiler used: gcc 8.1.0
  Created  date: 5/7/2022 
  Acknowledgement: None
*/
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


/*Define a class namely RegularAcc for online shopping with attributes name (string), balance (double), and 
a method as below
• bool pay(double amount): to pay and deduct from the current balance (false if does not have 
enough money).
*/

class RegularAcc
{
    public:
        string name;
        double balance;

        //Constructor
        RegularAcc(){}
        RegularAcc(string name, double balance)
        {
            this->name = name; 
            this->balance = balance;
        }

        //method
        //bool pay and deduct from the current balance
        virtual bool pay(double amount)
        {
            if(amount <= balance)
            {
                balance = balance - amount;
                cout << "Balance = " << balance << "\n";
                return true;
            }
            else
            {
                cout << "False --> does not have enough money\n";
                return false;
            }
        }
};

/*Define another class GoldAcc inherits from the class RegularAcc, with an extra attribute namely 
bonusCoin (double). Override the pay method for GoldAcc so that 5% of paying amount will be rewarded to 
the bonusCoin.
Example: paying amount = $1000 → reduce $1000 from current balance and add $50 to the bonusCoin
value.*/
class GoldAcc: public RegularAcc
{
    public:
        double bonusCoin;

        //Constructor
        GoldAcc(){}
        GoldAcc(string name, double balance, double bonusCoin): RegularAcc(name, balance)
        {
            this->bonusCoin = bonusCoin;
        }

        //overwrite pay method  --> 5% of paying amount will be rewarded to the bonusCoin.
        bool pay(double amount)
        {
            if(amount <= balance)
            {
                balance = balance - amount;
                double bonusAmount = amount * 0.05;
                bonusCoin = bonusCoin + bonusAmount;
                cout << "Balance = " << balance << "\n";
                cout << "BonusCoin = " << bonusCoin << "\n";
                return true;
            }
            else
            {
                cout << "False --> does not have enough money\n";
                return false;
            }
        }

};


int main()
{
    //Provide suitable constructors and test pay() methods of both RegularAcc and GoldAcc classes in main().
    RegularAcc acc1("Khang", 3000), acc2("David", 1000);
    //test pay method 
    acc1.pay(3000);
    acc2.pay(2000);

    GoldAcc vipAcc1("Duy", 1000, 0);
    //test overwrite pay method & adding to bonusCoin
    vipAcc1.pay(1000);

}