#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::cin;

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

//Declare Product class to use this datatype in the Acc
class Shop;

//Declare class Product
class Product
{
    public:
        string name;
        double price;
        vector<string> nameOfShops;
        string Shop_user_choose;
        vector<Shop*> ListOfShops;

        //method
        Product(){};
        Product(string name, double price)
        {
            this->name = name;
            this->price = price;
        }
        //show Product
        void showProduct()
        {
            cout << "Name of Product = " << name << ". Price of product = " << price << "$\n";
            cout << "The shop that has this product is:\n";

            #if 1
            for(auto eachShopName: nameOfShops)
            {
             
                cout << "\t" << eachShopName << "\n";
            }
            #endif

            for(auto ShopsObject: ListOfShops)
            {
                cout << "\t" << ShopsObject << "\n";
            }

            cout << "\n\n";
        }
};

//class Shop to show the show has list of Product
bool once = true;
class Shop
{
    public:
        string name;
        vector<Product*> listProducts; 

    //Method
    Shop(){}
    Shop(string name, vector<Product*> listProducts)
    {
        this->name = name;
        this->listProducts = listProducts;


    }

    //show Shop name and list of product
    void showInfo()
    {
        cout << "Shop name is: " << name << "\n";
        for(auto eachProduct : listProducts)
        {
            cout << "\t" << eachProduct->name << ". Price: " << eachProduct->price << "$\n";           
            
            eachProduct->nameOfShops.push_back(name); //Insert shopname to Product (Debug)
            eachProduct->ListOfShops.push_back(this); //Insert shopObject to Product
             
        }
        cout << "\n\n";
        
    }

    //
};
//class Parent 
class Acc 
{
    public:
        string name;
        double bill;
        //For each customer account, besides total bill value, we also need to manage list of bought products. 
        vector<Product*> listProducts;

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

        //add object Product to listProducts
        void AddProduct(Product* newProduct)
        {
            //Decide the shop you buy the Product form
            cout << "List of shops have " << newProduct->name << ":\n";
            int cnt = 1;
            int choice = 0;
            string nameShopChoice;
            for(auto eachShopNames: newProduct->nameOfShops)
            {
                cout << "\t" << cnt << ") " << eachShopNames << "\n";
                cnt++;
            }
            cout << "Choose the shop you want to buy " << newProduct->name << ": ";
            cin >> choice;
            cnt = 1; //reset

            for(auto eachShopNames: newProduct->nameOfShops)
            {
                if(choice == cnt)
                {
                    //assign where the product is bought
                    newProduct->Shop_user_choose = eachShopNames;
                    nameShopChoice = eachShopNames; //store the shop name you bought the product
                    listProducts.push_back(newProduct);

                }
                cnt++; 
            }


            //Remove Product in Shop
            for(auto ShopObjects: newProduct->ListOfShops)
            {
                int i = 0;
                for(auto ProductObjects: ShopObjects->listProducts)
                {
                    if(ProductObjects->name == newProduct->name && ShopObjects->name == nameShopChoice)
                    {
                        ShopObjects->listProducts.erase(ShopObjects->listProducts.begin() + i);
                    }
                }
                i++;
            }
        }

        //return Product
        /*can return the product (which will be charged with a fee 10% for the product price for normal accounts. 
        to the shop that sell that product.*/
        virtual void ReturnProduct(Product* returnProduct)
        {
            //Delete the Product in AccProduct List
            for(auto eachProduct : listProducts)
            {
                int i = 0;
                if(eachProduct->name == returnProduct->name)
                {
                    listProducts.erase(listProducts.begin() + i);
                }
                i++;
            }

            //Add the Product to Shop.listProducts
            for(auto ShopObjects : returnProduct->ListOfShops)
            {
                //Check if the Shop name is equal to Shop User choose
                if(returnProduct->Shop_user_choose == ShopObjects->name)
                {
                    //Insert Product object to ListProducts of Shop
                    ShopObjects->listProducts.push_back(returnProduct);
                }
            }

            //Charge a fee of 10%
            bill = bill + returnProduct->price - ((returnProduct->price) * 10)/100;
        }

        //show info
        void showinfo()
        {
            cout << "Name user = " << name << endl;

            //show list Product
            for(auto eachProduct : listProducts)
            {
                cout << "\t" << eachProduct->name << ". Price: " << eachProduct->price << "$\n";

                //Print name of shop product bought form
                cout << "Bought form shop: " << eachProduct->Shop_user_choose << "\n";
                
                //Calculate sum of price of products
                buyProduct(eachProduct->price);
            }
            cout << "Total bill = " << bill << "$\n"; 
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

        /*In addition, the customer can return the product (which will be charged with a fee 10% 
for the product price for normal accounts, but only 5% for gold accounts) to the shop that sell that 
product.*/


};

/*The investor of the app requires that it must manage each product with name and price. The app 
also need to manage the shop who selling the products (shop’s name and list of selling products).
For each customer account, besides total bill value, we also need to manage list of bought 
products. 

In addition, the customer can return the product (which will be charged with a fee 10% 
for the product price for normal accounts, but only 5% for gold accounts) to the shop that sell that 
product.*/





int main()
{
    #if 0
    Acc acc1("Khang", 0);
    acc1.showinfo();
    acc1.buyProduct(1000);
    acc1.buyProduct(3230);
    acc1.showinfo();

    GoldAcc acc2("David", 0, 15);
    acc2.buyProduct(1000);
    acc2.showInfo();
    #endif

    Acc user1("Khang", 0);
    user1.buyProduct(0);

    GoldAcc vipUser1("David", 0, 15);
    vipUser1.buyProduct(1000);

    //Create Shop with Product lists
    Product product1("Laptop- Predator Helios 300", 3999.99),
            product2("Headphone- HS70 Corsair", 232.52),
            product3("Keyboard- Newmen k31", 155.55),
            product4("Wireless Mouse- MSI", 53.33),
            product5("Webcam- 4kHDEO", 399.99);
    
    Shop shop1("GearVn", vector<Product*>{&product1, &product2, &product3});
    Shop shop2("PhongVu", vector<Product*>{&product1, &product2, &product3, &product4, &product5});

    product1.showProduct();


    //show Product lists and name of that shop
    shop1.showInfo();
    shop2.showInfo();

    //test shopname of product
    product1.showProduct();

    //Test AddProduct and ShowInfo of Acc
    #if 1
    cout << "User1 add Product:\n";
    user1.AddProduct(&product1);
    user1.AddProduct(&product2);
    user1.AddProduct(&product4);
    user1.AddProduct(&product5);
    // user1.AddProduct(&product3);
    user1.showinfo();
    #endif

    //Check product lists of shop1 after user bought products here
    shop1.showInfo();
    shop2.showInfo();

    //Test return Product to shop1
    cout << "User1 return Product(return laptop Helios 300):\n";
    cout << "Total bill of user before return laptop Helios 300: " <<user1.bill << "$\n";
    user1.ReturnProduct(&product1);
    shop1.showInfo();
    shop2.showInfo();
    shop1.showInfo();
    shop1.showInfo();
    cout << "Toal bill after user return laptop Helios 300 to shop: " << user1.bill << "$\n";


    //Test goldAcc
    cout << "\n----------------Test Gold Acc----------------\n";
    product1.showProduct();
    vipUser1.AddProduct(&product1);
    vipUser1.showInfo();


    return 0;
}