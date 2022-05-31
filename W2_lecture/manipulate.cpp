#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{   
    //Precision
    std::cout << 3.14159 << " " << 12.3456 << "\n";
    std::cout << "precision = 4: \n";
    std::cout.precision(4); 
    std::cout << 3.14159 << " " << 12.3456 << "\n\n";

    //Width
    std::cout << 10 << " " << 20 << "\n";
    std::cout << "width = 5: \n";
    std::cout.width(5); 
    std::cout << 10 << " " << 20 << "\n\n";

    //Fill & Width
    std::cout << "fill = 'x', width = 5: \n";
    std::cout.fill('x');
    std::cout.width(5); 
    std::cout << 10 << " " << 20 << "\n\n";

    //Set/Unset Format Flags
    std::cout << "setf left justification and showpos, width = 5: \n";
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.setf(std::ios::showpos);
    std::cout.width(5); 
    
    std::cout << 10 << " " << 20 << "\n\n";
    std::cout << "unsetf left justification and showpos, width = 5: \n";
    std::cout.unsetf(std::ios::left);
    std::cout.unsetf(std::ios::showpos);
    std::cout.width(5);
    std::cout << 10 << " " << 20 << "\n\n";

    return 0;
}