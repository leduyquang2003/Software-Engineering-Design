#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //strcmp() example code:
    char str1[100] = "ABC";
    char str2[100] = "AEF gfgf";
    cout << "strlen of str1" << strlen(str1) << endl;

    cout << "strcmp = " <<strcmp(str1, str2) << endl;

    char *p = NULL;
    p = str1;
    p[5] = 'Y';
    cout << str1;

    // strcat(str1, str2);
    // cout << "str1 after strcat = " << str1 << endl;

    // strcpy(str1, str2);
    // cout << "str1 after strcpy = " << str1 << endl;


    return 0;
}