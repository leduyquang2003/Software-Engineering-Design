
#include <iostream>
using namespace std;


int main()
{
    int arr[10] = {};
    int* p = arr;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter value for this element: ";
        cin >> *p;
        p++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}


