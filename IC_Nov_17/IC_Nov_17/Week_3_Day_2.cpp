#include <iostream>
#include <conio.h>

using namespace std;

//Prototype
void swapIntegers(int, int);

int main()
{
	int a, b;		//Step 1
	cout << "Enter two integer values : ";
	cin >> a >> b;		//Step 2
	cout << "Before swap : \n a is " << a << "b is" << b << endl;

	//Call swap integers
	swapIntegers(a, b);	//Step 3

	cout << "After swap : \n a is " << a << "b is" << b << endl;

	_getch();

	//Exit
	return 0;
}

void swapIntegers(int a, int b)
{
	//Define temp variable
	int hold = a;	//Step 4
	//Swap values
	a = b;		//Step 5
	b = hold;	//Step 6
	//Exit void function
	return;
}