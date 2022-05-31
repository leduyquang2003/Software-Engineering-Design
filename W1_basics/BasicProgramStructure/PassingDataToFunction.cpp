#include <iostream>
using namespace std;

//pass by value
void f1(int value);
//pass by reference
void f2(int* p);

int main1()
{
	int value = 5;
	f1(value);
	cout << "Value in main = " << value << endl;
	f2(&value);
	cout << "Value in main = " << value << endl;
	return 0;
}

void f1(int value)
{
	value = 10;
	cout << "Value in f1 = " << value << endl;
}

void f2(int* p)
{
	*p = 200;
	cout << "Value in f2 = " << * p << endl;
}