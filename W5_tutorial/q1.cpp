#include <iostream>
#include <string>

// Helper preprocessor macro
#define endl '\n'
#define debug(x) std::cout << #x << ": " << x << endl;

#define SIZE 3

class Juice
{
private:
    std::string name;
    int *price;

public:
    // Default constructor
    Juice() {}

    // Constructor
    Juice(std::string name, int price)
    {
        this->name = name;
        this->price = new int(price);
    }


    // Utility functions
    void printInfo()
    {
        std::cout << "Name: " << name << endl;
        std::cout << "Price: " << *price << endl;
    }

    // Getters
    std::string getName()
    {
        return name;
    }

    int getPrice()
    {
        return *price;
    }

    // Setters
    void setName(std::string name)
    {
        this->name = name;
    }

    void setPrice(int price)
    {
        this->price = new int(price);
    }

    /* b. Part 1: Reduce the current price by one by modifying the current object, then return it */
    Juice operator--(int)
    {
        this->price--;
        return *this;
    }

    /* b. Part 2: Return a result object with price is total price if names are identical, 0 if they are different (name is “NA” in that case) */
    friend Juice operator+(Juice juice1, Juice juice2);

    // b. Part 3: Return a result object with price is reduced by n %
    friend Juice operator-(int n, Juice juice);

    ~Juice()
    {
        std::cout << "Destructor called for " << name << endl;

        // Free memory
        delete &name;
        delete price;
    }
};

// Return the result with the total price is their name are identical, if they are different.
Juice operator+(Juice juice1, Juice juice2)
{
    Juice result;

    if (juice1.name != juice2.name)
    {
        result.name = "NA";
        *result.price = 0;
        return result;
    }

    result.name = juice1.name;
    *result.price = *juice1.price + *juice2.price;

    return result;
}

// Return the result with reduced price by n%
Juice operator-(int n, Juice juice)
{
    Juice result;

    result.name = juice.name;
    *result.price = *juice.price * (1 - n / 100.0);

    return result;
}

// Program entry point
int main()
{
    /*
        a. Part 1: nitialize an array of 3 Juice objects using
        dynamic memory allocation and initialize values
    */

    // Initialize an array of 3 Juice objects
    Juice *juices = new Juice[SIZE];

    // Initialize values
    juices[0].setName("Apple");
    juices[0].setPrice(10);

    juices[1].setName("Orange");
    juices[1].setPrice(20);

    juices[2].setName("Grape");
    juices[2].setPrice(30);

    /*
        a. Part 2: Print out all information of each juice object
    */

    for (int i = 0; i < SIZE; i++)
        juices[i].printInfo();

    // Free memory
    delete[] juices;

    return 0;
}