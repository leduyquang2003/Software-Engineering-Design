#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
/*3. Write a function which accept an array of integers and its size then return the 
maximum value of its elements. Test by calling them in main()*/

int max_arr(int arr[], int SIZE)
{
    int max = arr[0];
    for(int i = 0; i < SIZE; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int const SIZE = 5;
    int arr[SIZE] = {5, 6, 3, 5, 10};
    int max = max_arr(arr, SIZE);
    cout << "Max value of this array is: " << max << endl;
    return 0;
}