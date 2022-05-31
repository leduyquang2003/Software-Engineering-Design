#include <iostream>
#include <string>
#include <string.h>


union u_type
{
    int intNum;
    char charArr[4];
};

int main()
{
   u_type myUnion;
   std::cout << "Size = " << sizeof(u_type) << std::endl;

   myUnion.intNum = 0x00434241;

   std::cout << myUnion.charArr << "\n";
   std::cout << myUnion.charArr[0] << "\n";
   std::cout << myUnion.charArr[1] << "\n";
   std::cout << myUnion.charArr[2] << "\n";
//    std::cout << myUnion.charArr[3] << "\n";


    return 0;
}