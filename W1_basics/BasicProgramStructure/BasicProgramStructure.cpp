#include <iostream>
using namespace std;

//Declaring Functions
void printmessage(int val);

#if 0
int main()
{
    //Declare and initialize variables
    float side1 = 0;
    float side2 = 0;
    float area = 0;

    printmessage(14);

    //request user input
    cout << "Enter the length of horizontal sideA: ";
    cin >> side1;
    cout << "Enter the length of vertical side: ";
    cin >> side2;

    if (side1 == 0 || side2 == 0)
    {
        cout << "Error in entering input data: ";
        return 1;
    }
    else
    {
        area = side1 * side2;
        cout << "The area is " << area << " m2" << endl;
    }

    //pointer
    int total = 32000;
    int* ptr;
    ptr = &total;
    cout << *ptr << endl;
    
    //Assignments can all be made via pointer operations
    *ptr = 1000;
    cout << total << endl;

    //Indexing a Pointer (Pointer Arithmetic)
    char str[80] = "This is a test";
    char* p = str;

    
    /*Using either pointer arithmetic or the array index, identical elements in array 
�str� can be accessed.*/
    str[4] = 'X';
    *(p + 5) = 'Y';
    for (; (*p) != '\0'; p++)
    {
        cout << *p;
    }
 
    return 0;
}
#endif


int main()
{
#if 0
    char a;
    int num;
    cout << "Enter a character and an int: ";
    cin >> a >> num;

    cout << "Character: " << a << endl;
    cout << "Integer: " << num << endl;
#endif
    for (int i = 1; i < 10; i++)
    {
        if (i == 5)
            continue;
        else if (i == 9)
            break;
        cout << i << ' ';
    }
    return 0;
}


void printmessage(int val)
{
    for (int i = 1; i <= val; i++)
    {
        cout << "function message number: " << i << endl;
    }
}
