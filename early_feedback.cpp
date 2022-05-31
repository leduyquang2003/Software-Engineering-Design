/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Nguyen Tuong Khang
  ID: s3927112
  Compiler used: Compiler version (e.g. gcc 8.1.0)
  Created  date: 20/3/2022
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>
#define PROG 2

#if (PROG == 1)
class BankAcc
{
    public:
        std::string name;
        float amount;

        BankAcc(std::string self_name, float self_amount)
        {
            name = self_name;
            amount = self_amount;
        }

        float Withdraw(float withdraw)
        {
            if(withdraw <= amount)
            {
                amount = amount - withdraw;
                return amount;
            }
            else
            {
                std::cerr << "Error message" << std::endl;
                return -1;
            }
        }
};



int main(int argc, char *argv[])
{
    //a) Write a class constructor to initialize those attributes. Test it in main by creating three bank account objects and use the constructor to initialize data for them. Then print out all information. (2pt)
    BankAcc Acc1("Nguyen Tuong Khang", 20000.23);
    BankAcc Acc2("Nguyen Tuong Duy", 10000.24);
    BankAcc Acc3("Nguyen Tuong Linh", 5000.32);
    std::cout << Acc1.name <<" " << Acc1.amount << std::endl
              << Acc2.name <<" " << Acc2.amount << std::endl
              << Acc3.name <<" " << Acc3.amount << std::endl;

    /*b) Write a public method for the class namely withdraw(float num) which allow a user to withdraw money from his/her account: (2pt)
        If current amount >= num: subtract amount value by num
        If current amount < num: return an error code, and print out an error message.
        Test the method inside the main function.*/
    Acc1.Withdraw(30000);
    std::cout << Acc1.amount << std::endl;
    Acc1.Withdraw(1000);
    std::cout << Acc1.amount << std::endl;

    /*c) Modify the program above so that it can save all data (one line for each account) into a file, whose filename is given from the command line argument (at the end of the program). If the user does not give the command line argument, don’t save data. (1pt)
        Example Run: ./a.exe data_file.dat*/
    char file_name[225];
    strcpy(file_name, argv[1]);
    std::cout << file_name << std::endl;

    std::fstream myfile;
    myfile.open(file_name, std::ios::out);
    if(!myfile)
    {
        std::cerr << "Cannot open the file";
        return -1;
    } 
    myfile << Acc1.name << " " << Acc1.amount << "\n";
    myfile << Acc2.name << " " << Acc2.amount << "\n";
    myfile << Acc3.name << " " << Acc3.amount << "\n";
    myfile.close();

    return 0;
}
#endif


#if (PROG == 2)
/*Define a class namely BankAcc with two public attributes are name (string) and amount (float).*/
/*a) Write a class constructor to initialize those attributes. Test it in main by 
creating three bank account objects and use the constructor to initialize data for them. 
Then print out all information. (2pt)*/

class BankAcc
{
    public:
        std::string name;
        float amount;

        BankAcc(){}
        BankAcc(std::string name, float amount)
        {
            this->name = name;
            this->amount = amount;
        }

        //infor
       std::string showInfo()
       {
           std::stringstream ss;
           ss << "Name = " << name << ". Amount = " << amount;
           return ss.str();
       }
       /*b) Write a public method for the class namely withdraw(float num) which allow a user to 
       withdraw money from his/her account: (2pt)
            If current amount >= num: subtract amount value by num
            If current amount < num: return an error code, and print out an error message.
            Test the method inside the main function.*/ 

        void withdraw(float num)
        {
            if(amount >= num)
            {
                amount = amount - num;
                std::cout << amount << std::endl;
            }
            else
            {
                std::cerr << "Error code" << std::endl;
            }
        }

};

int main(int argc, char * argv[])
{
    
    #if 0
    BankAcc Account[3]{
        BankAcc ("Khang", 2000),
        BankAcc ("Linh", 3000),
        BankAcc ("Chau Anh", 1500)
    };

    for(int i = 0; i < 3; i++)
    {
        std::cout << Account[i].showInfo() << std::endl;
    }

    //b
    float num;
    std::cout << "Enter num of withdraw: ";
    std::cin >> num;
    std::cout << "Amount after withdraw: ";
    #if 1
    Account[0].withdraw(num);
    if(Account[0].amount < num)
    {
        return -1;
    }
    #endif
    #endif
    /*c) Modify the program above so that it can save all data (one line for each account) 
    into a file, whose filename is given from the command line argument (at the end of the 
    program). If the user does not give the command line argument, don’t save data*/
    char filename[225];
    strcpy(filename, argv[1]);
    std::cout << filename << std::endl;





    return 0;
}
#endif