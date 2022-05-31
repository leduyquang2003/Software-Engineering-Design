#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::vector;
using std::endl;

/*Question 1 (11 pts)
Define a class namely Acc with an attribute is name (string), bill (total amount need to pay: 
double), and a method namely buyProduct(int price) which will add up the product’s price to the 
bill.
Define another class GoldAcc which inherits from the class Acc, with an extra attribute named 
discRate (discount rate: double). Override the buyProduct method for GoldAcc so that the price 
will be discounted by discRate before adding to the bill
Example: price = 1000, discRate = 15% → only add 1000*85% = 850 to the bill.
Provide suitable constructors and test buyProduct() methods of both Acc and GoldAcc classes in 
main().*/

//class Parent
class Acc
{
    public:
        string name;
        double bill;

        //Constructor
        Acc(){}
        Acc(string name, double bill)
        {
            this->name = name;
            this->bill = bill;
        }

        // add up the product’s price to the bill.
        virtual void buyProduct(int price)
        {
            bill = bill + price;
        }

        //show info
        void showinfo()
        {
            cout << "name = " << name << endl;
            cout << "bill = " << bill << endl;
        }

};

/*Define another class GoldAcc which inherits from the class Acc, with an extra attribute named 
discRate (discount rate: double). Override the buyProduct method for GoldAcc so that the price 
will be discounted by discRate before adding to the bill
Example: price = 1000, discRate = 15% → only add 1000*85% = 850 to the bill.*/

//derived class GoldAcc
class GoldAcc : public Acc
{
    public:
        double discRate;

        //Constructor
        GoldAcc(){}
        GoldAcc(string name, double bill, double discRate): Acc(name, bill)
        {
            this->discRate = discRate;
        }

        //overwrite buyProduct
        void buyProduct(int price)
        {
            double amount_sale;        
            amount_sale = (price * discRate)/100;
            price = price - amount_sale;
            bill = bill + price;
        }

        //showInfo
        void showInfo()
        {
            Acc::showinfo();
        }
};

int main()
{
    Acc acc1("Khang", 1999.99);
    acc1.showinfo();
    acc1.buyProduct(1000);
    acc1.buyProduct(3230);
    acc1.showinfo();

    GoldAcc acc2("David", 0, 15);
    acc2.buyProduct(1000);
    acc2.showInfo();

    return 0;
}