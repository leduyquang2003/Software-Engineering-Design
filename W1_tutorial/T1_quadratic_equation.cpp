#include <iostream>
#include <math.h>
using namespace std;
/*. Write a C++ program to ask the user input coefficient values a b c of a quadratic 
equation, then print out all roots.
ax2 + bx + c = 0*/

int main()
{
    double a, b, c;
    double discriminant;
    double root1, root2;
    double real1, real2;
    double complex1, complex2;
    cout << "Input coefficient values a b c: ";    
    cin >> a >> b >> c;
    discriminant = pow(b, 2) - 4 * a * c;
    if(discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant))/(2 * a);
        root2 = (-b - sqrt(discriminant))/(2 * a);
        cout << "Discriminant > 0. Root1 = " << root1
        <<". Root2 = " << root2 << endl;
    }
    else if(discriminant == 0)
    {
        root1 = -b/(2 * a);
        root2 = -b/(2 * a);
        cout << "Discriminant = 0. Root1 = " << root1
        <<". Root2 = " << root2 << endl;
    }
    else
    {   
        real1 = -b/(2 * a);
        real2 = -b/(2 * a);
        complex1 = sqrt(pow(b,2) * -1 + 4 * a * c)/(2 * a);
        complex2 = sqrt(pow(b,2) * -1 + 4 * a * c)/(2 * a);
        cout << "Discriminant < 0. Root1 = " << real1 <<" + "
        << complex1 << "i ." << " Root2 = " << real2 <<" - "
        << complex2 << "i ." << endl;
    }

    return 0;
}