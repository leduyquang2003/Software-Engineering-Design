#include <iostream>
#include <vector>
#include <string>



int main()
{
    int i = 1;
    std::vector<int> myVec = {1, 2, 3};
    myVec.erase(myVec.begin() + 1);
    for(auto print: myVec)
    {
        std::cout << print << " ";
    }
    
    return 0;
}