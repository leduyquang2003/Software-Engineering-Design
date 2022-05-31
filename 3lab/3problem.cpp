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
using std::vector;
using std::string;

/*Write a simple C++ program to help manage a retail shop as below:
The shop and name, list of selling products, and need to record its total revenue. Each product has name
(string), ID (string) and price (double).
The shop has a function to calculate the bill for each customer with given list of product IDs.
Each customer also have name and ID, current bill and total spend ammount.
Implement classes with suitable attributes and methods to satisfy the above requirement. Test them in 
main() with appropriate output messages.*/

//class prototype (to be use as data type inside Product class)
class Shop;
class Acc;

//class Product
class Product
{
    public:
        string name;
        string ID;
        double price;
        Shop *shop; //reference to shop that sells the product

        //constructors
        Product(){}
        Product(string name, string ID, double price){
            this->name = name; 
            this->ID = ID;
            this->price = price;
        }
};

//Create a function to remove an element from the vector
void removeElement(vector<Product*> &vect, Product *delElement){
    for (int i = 0; i < vect.size(); i++){
        if (vect[i] == delElement){
            vect.erase(vect.begin() + i);
        }
    }
}

//Class for Custermer Acc 
//Each customer also have name and ID, current bill and total spend ammount.
class Acc
{
    public:
        string name;
        string ID;
        double bill;
        double total_spend_amount;
        vector<Product*> boughtProducts; //list of bought product

        Acc(){}
        Acc(string name, string ID, double bill, double total_spend_amount)
        {
            this->name = name;
            this->ID = ID;
            this->bill = bill;
            this->total_spend_amount = total_spend_amount;
        }

        //method BuyProduct
        void BuyProduct(Product *pd);

        void ShowInfo()
        {
            cout << "Name = " << name << " ID = " << ID << "\n";
            cout << "Bill = " << bill << "$ Total spend amount = " << total_spend_amount << "$\n";
        }

        //method to check if User can pay for this bill
        bool pay()
        {
            if(bill <= total_spend_amount)
            {
                total_spend_amount = total_spend_amount - bill;
                bill = 0;// reset bill because alreadly purchased
                cout << "Total spend amount has changed = " << total_spend_amount << "$\n";
                return true;
            }
            else
            {
                cout << "Does not have enough money to pay for this bill\n";
                return false;
            }
        }

};


/*The shop and name, list of selling products, and need to record its total revenue.
  The shop has a function to calculate the bill for each customer with given list of product IDs.*/
class Shop
{
    public:
        string name;
        vector<Product*> sellProducts; //list of selling Products
        vector<Acc*> customers;
        
        Shop(){}
        Shop(string name)
        {
            this->name = name;
        }
        
        void addProduct(Product *pd){
            sellProducts.push_back(pd); //add to selling list
            pd->shop = this; //record reference to the shop
        }

        //method to add Customers
        void addID(Acc *customerObjects)
        {
            customers.push_back(customerObjects);
        }

        //method to calculate bill for customers
        void Bill_cal()
        {
            for(auto eachCusObject : customers)
            {
                for(auto eachProObject : eachCusObject->boughtProducts)
                {
                    eachCusObject->bill = eachCusObject->bill + eachProObject->price;

                }
            }

        }
        
        void showInfo()
        {
            cout << "Shop name is " << name << "\n";
            cout << "List of Product names: ";
            for(auto each : sellProducts)
            {
                cout << each->name << "\n";
            }
            cout << "List of ID customers: ";
            for(auto each : customers)
            {
                cout << each->ID << "\n";
            }
            cout << "\n";
        }



};

//method to buy Product
void Acc::BuyProduct(Product *pd)
{
    boughtProducts.push_back(pd);
    removeElement(pd->shop->sellProducts, pd);
}

int main()
{
    Acc user1("Khang", "s3927112",0, 3999.9);

    //Create Shop & Add Products
    Product pd1("Mac", "ase3982" ,3999.9), pd2("Ipad", "asd9832", 2333.3);
    Shop shop1("Apple");
    shop1.addProduct(&pd1);
    shop1.addProduct(&pd2);
    shop1.addID(&user1);
    shop1.showInfo();
    cout << "\n";

    //Test user bought products and check product in shop lists is removed
    user1.BuyProduct(&pd1);
    user1.ShowInfo();
    shop1.showInfo();

    //Test calculate Bill method in Shop
    shop1.Bill_cal();
    cout << "Bill of user1 after is caculated by shop1\n";
    user1.ShowInfo();

    //Check if User can pay for this bill
    user1.pay();
    user1.ShowInfo();

    return 0;
}