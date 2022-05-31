#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

class ComplNum
{
    private:
        double real;
        double img;

    public:
        ComplNum(){}

        ComplNum(double real, double img)
        {
            //this is pointer to current object(address of the current object)
            this->real = real;
            this->img = img;
        }

        /*Better use string to print info for IO the file*/
        std::string info()
        {
            std::stringstream sstr;
            sstr << real <<  ((img >= 0)?" + " : " ")<< img << "i";
            return sstr.str(); //get the string content in the stringstream
        }

        //Overload the - operator for object - object
        ComplNum operator - (ComplNum num)
        {
            ComplNum result;
            result.real = this->real - num.real;
            result.img = this->img - num.real;
            return result;
        }

        //Overload the - operator for object - double
        ComplNum operator - (double real)
        {
            ComplNum result;
            result.real = this->real - real;
            result.img = this->img;
            return result;
        }

        //Overload the - operator for double - object
        //declare friend external
        friend ComplNum operator - (double real, ComplNum num);

        //prefix
        ComplNum operator --()
        {
            //object = object - 1
            --(this->real);
            return *this;
        } 

        //postfix
        ComplNum operator --(int)
        {
            ComplNum result = *this;
            //object = object - 1
            --(this->real);
            return result;
        }     

        friend double abs_val(ComplNum num);

};

//Overload the - operator for double - object
ComplNum operator - (double real, ComplNum num)
{
    ComplNum result;
    result.real = real - num.real;
    result.img = - num.img;
    return result;
}

double abs_val(ComplNum num)
{
    return sqrt(num.real * num.real + num.img * num.img);
}

int main()
{
    ComplNum num1(100, 200), num2(5, 10), num3(10, 10);
    std::cout <<"num1 = " << num1.info() << std::endl;
    std::cout <<"num2 = " << num2.info() << std::endl;

    ComplNum result =  20 - num1;
    std::cout <<"result = " << result.info() << std::endl;

    --num1;
    std::cout <<"num1: " << num1.info() << std::endl;
    
    //postfix num1-- --> result = 100 + 200i num1 = 99 + 200i
    //result = num1
    //num1--;

    result = num2--;
    std::cout <<"result = " << result.info() << std::endl;

    std::cout << "absolute value of num1: " << abs_val(num1) << std::endl;
    return 0;
}