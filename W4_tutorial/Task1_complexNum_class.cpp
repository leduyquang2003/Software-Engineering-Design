#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <math.h>

/*1. Write a program that defines a class called ComplNum for complex numbers with two private
attributes are real and imag (double). */
class ComplNum
{
    private:
        double real;
        double imagine;
    
    /*a) Provide two overloaded versions for the constructor: a default constructor, and another one 
with two arguments to initialize attributes (require to use this keyword)*/
    public:
        ComplNum(){}

        ComplNum(double real, double imagine)
        {
            this->real = real;
            this->imagine = imagine;
        }

        void showInfo()
        {
            std::cout << real << std::showpos << imagine <<"i "<< std::endl;
            std::cout << std::noshowpos << std::endl;
        }

        void showInfo(int *cnt)
        {
            *cnt = *cnt + 1;
            std::cout << "Complex number " << *cnt <<": ";
            std::cout << real << std::showpos << imagine <<"i "<< std::endl;
            std::cout << std::noshowpos << std::endl;
        }
        
     /*b) Overload - and -- operators to use for ComplNum objects as below:
        • object - object
        • object - double
        • double - object
        • object--;
        • --object;
        Test all cases above in main() functions.
        */
        
        //Overload - operator (object - object)
        ComplNum operator - (ComplNum &complex)
        {
            ComplNum temp;

            temp.real = this->real - complex.real;
            temp.imagine = this->imagine - complex.imagine;
            return temp;
        }

        /*object - double*/
        ComplNum operator - (double num)
        {
            this->real -= num;
            this->imagine -= num;
            return *this;
        }

        /*double - object*/
        
        

        /*object--*/
        ComplNum operator -- (int)
        {
            real--;
            imagine--;
            return *this;
        }

        /*--object*/
        ComplNum operator -- ()
        {
            real--;
            imagine--;
            return *this;
        }

        //Declare a non-member function is a Friend
        friend double r(ComplNum complex);
        
};

/*c) Write a non-member friend function which accepts an ComplNum object and return its 
absolute value. Test it in main() function.*/
double r(ComplNum complex)
{
    double length = sqrt(pow(complex.real, 2) + pow(complex.imagine, 2));
    return length;
}

    
int main()
{
    int cnt = 0;
    ComplNum complex1(3, -5);
    complex1.showInfo(&cnt);
    ComplNum complex2(4, 2);
    complex2.showInfo(&cnt);

    ComplNum result;

    std::cout << "Result of object - object: " << std::endl;
    result = complex1 - complex2;
    result.showInfo(&cnt);

    std::cout << "Result of object - double: " << std::endl;
    result = complex1 - 3;
    complex1.showInfo();

    #if 1
    std::cout << "Result of double - object: " << std::endl;
    result = 3 - complex1;
    complex1.showInfo();
    #endif

    std::cout << "Result of object--: " << std::endl;
    complex1--;
    complex1.showInfo();

    std::cout << "Result of --object: " << std::endl;
    --complex1;
    complex1.showInfo();

    std::cout << "Write a non-member friend function which accepts an ComplNum object and return its absolute value. Test it in main() function" << std::endl;
    std::cout << r(complex2) << std::endl;
  

    return 0;
}


