#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c;
    // << = insertion 
    cout << "Enter a, b, c, d for equation ax^2 + bx + c = 0" << endl;
    // >> = extraction
    cin >> a >> b >> c;

    //!b mean b == 0
    if(a == 0)
    {
        if(b == 0)
        {
            if(c != 0)
            {
                cout << "There are no roots" << endl;
            }
            else
            {
                cout << "There are infinite solution" << endl;
            }
        }
        else
        {
            cout << "There is one root: x = " << -c/b << endl;
        }
    }
    else //ax^2 + bx + c = 0
    {
        double delta = pow(b, 2) - 4 * a * c;
        if(delta < 0)
        {
            cout << "There are no roots" << endl;
        }
        else if(delta > 0)
        {
            cout << "There are two roots "
                 << "x1 = " << (-b + sqrt(delta))/(2*a)
                 << " x2 = " << (-b - sqrt(delta))/(2*a)
                 << endl;

        }
        else //delta == 0
        {
            cout << "There are one root: "
                 << " x1 = x2 = " << (-b)/(2 * a); 
        }
    }

    return 0;
}