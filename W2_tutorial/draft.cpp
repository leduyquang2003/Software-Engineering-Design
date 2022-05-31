#include <iostream>

int main()
{
    int arr[5] = {1, 2, 3, 4 ,5};
    int *p = NULL;
    p = arr;
    for(int i = 0; i < 5; i++)
    {
        std::cout <<* (p + i) << std::endl;
    }


    return 0;
}