#include <iostream>


int main(int argc, char *argv[])
{   
    // standard output stream (1)
    std::cout << "This is cout\n"; 

    //standard error stream (2)
    std::clog << "This is clog\n";
    std::cerr << "This is cerr\n";

    return 0;
}