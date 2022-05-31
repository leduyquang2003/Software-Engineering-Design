#include <iostream>
#include <math.h>
#include <climits>
#include <float.h>
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;
using std::fixed;

int main()
{
    long double a = 10.0/3;
    a = a * 10000000000;
    double b = 7.7E10;
    long double c;

    cout << fixed << a << endl;
    // trustworthy digit float 6 double 16 long double 18
    cout << LDBL_DIG << endl;
    cout << sizeof(a) << endl;

    return 0;
}