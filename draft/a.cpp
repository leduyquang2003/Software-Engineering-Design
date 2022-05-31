#include <iostream>
#include <math.h>

int main()
{
    double x;
    std::cout << "Input x: ";
    std::cin >> x;

    double check = sqrt(x);
    
    if(check - (int)check == 0)
    {
        std::cout << "So Chinh Nguyen" << std::endl;
    }
    else
    {
        std::cout << "Khong phai so Chinh Nguyen" << std::endl;
    }
 
    return 0;
}