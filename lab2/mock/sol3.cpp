#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

#define ACC_RETURN_FEE      0.1 //10%
#define GOLDACC_RETURN_FEE  0.05 //5%

//class prototype (to be use as data type inside Product class)
class Shop;

class Product{
private:
    string name;
    double price;
    Shop *shop;  //reference to shop that sells the product

public:
    //constructors
    Product(){}
    Product(string name, double price){
        this->name = name; 
        this->price = price;
    }

    friend class Shop;
    friend class Acc;
    friend class GoldAcc;
};

class Shop {
private:
    string name;
    vector<Product*> sellProducts;  //list of selling products

public:
    //constructors
    Shop(){}
    Shop(string name){this->name = name;};

    void addProduct(Product *pd){
        sellProducts.push_back(pd); //add to selling list
        pd->shop = this; //record reference to the shop
    }

    friend class Acc;
    friend class GoldAcc;
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
class Acc {
protected:
    string name;
    double bill;
    const double returnFee = ACC_RETURN_FEE; //standard return charge fee

    vector<Product*> boughtProducts; //list of bought product

public:
    Acc(){}
    Acc(string name, double bill){
        this->name = name;
        this->bill = bill;
    }

    //method to buy product
    virtual void buyProduct(Product *pd){
        bill += pd->price;   //add to bill
        boughtProducts.push_back(pd);       //add to bought list
        removeElement(pd->shop->sellProducts, pd); //remove from shop's selling list
    }

    //method to return product
    virtual void returnProduct(Product *pd){
        bill -=  pd->price*(1 - returnFee);     //substract from bill (and charge fee)
        removeElement(boughtProducts, pd);      //remove from bought list
        pd->shop->sellProducts.push_back(pd);   //add back to shop's selling list
    }


    void showInfo(){
        cout << "\nname = " << name
             << ", bill = " << bill << "\n";
        
        cout << "List of bought products: \n";
        for (Product *pd: boughtProducts){
            cout    << "name = " << pd->name 
                    << ", price = " << pd->price
                    << ", shop name = " << pd->shop->name << "\n";
        }
    }
};

//Class for Custermer GoldAcc
class GoldAcc : public Acc {
private:
    double discRate;
    const double returnFee = GOLDACC_RETURN_FEE; //override attribute

public:
    GoldAcc(){}
    GoldAcc(string name, double bill, double discRate)
        : Acc(name, bill){
        this->discRate = discRate;
    }

    //method to buy product
    void buyProduct(Product *pd){
        bill += pd->price*(1 - discRate);   //add to bill
        boughtProducts.push_back(pd);       //add to bought list
        removeElement(pd->shop->sellProducts, pd); //remove from shop's selling list
    }

    //method to return product
    void returnProduct(Product *pd){
        bill -=  pd->price*(1 - discRate)*(1 - returnFee); //substract from bill (and charge fee)
        removeElement(boughtProducts, pd);      //remove from bought list
        pd->shop->sellProducts.push_back(pd);   //add back to shop's selling list
    }
};

int main(){
    //Create some shops and add products
    Shop shop1("Shop1");
    Product pd1("Shoe", 1000);
    shop1.addProduct(&pd1); 

    Shop shop2("Shop2");
    Product pd2("Car", 20000);
    shop2.addProduct(&pd2); 

    //Create two customers
    Acc acc1("Peter", 0);
    GoldAcc goldAcc1("John", 0, 0.2);

    //Test buying/ returning
    acc1.buyProduct(&pd1);
    acc1.buyProduct(&pd2);
    acc1.returnProduct(&pd1);
    acc1.showInfo();

    goldAcc1.buyProduct(&pd1);
    goldAcc1.returnProduct(&pd1);
    goldAcc1.showInfo();

    return 0;
}