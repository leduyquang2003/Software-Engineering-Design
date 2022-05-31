#include <iostream>
#include <math.h>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main()
{
    bool pizza_is_good = true;
    cout << boolalpha << pizza_is_good << endl;

    if(pizza_is_good)
    {
       pizza_is_good = false;
       cout << boolalpha << pizza_is_good << endl; 
    }

    return 0;
}