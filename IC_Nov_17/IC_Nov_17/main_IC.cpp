#include <iostream>
#include <conio.h> //include for getch function
#include <cmath> // used for pow function
#include <iomanip> //include for setprecision command


double trapz(double lBound, double uBound, int n);
double funct(double x);

using namespace std;


/*Write a program that determines an estimate of the integral (between two specified points) of the 
following equation:
y = 4e^(−x)
The program should contain a function that utilizes the trapezoidal rule to calculate the area under the 
curve. The inputs to the function should be the interval endpoints and number of trapezoids (as entered 
by the user). The main() portion of the program should not involve any calculations of area. These 
should all be contained in your function. Your main() code should only contain statements that call for 
inputs, call the area function, and output the results back to the user. Demonstrate the functionality of 
your program over the interval between 0 and 1 with 5, 50, and 100 trapezoids*/

int main()
{
	double lBound, uBound;
	int n;

	// basic input stuff
	cout << "Enter lower bound: ";
	cin >> lBound;
	cout << "Enter upper bound: ";
	cin >> uBound;
	cout << endl << "Enter number of sections: ";
	cin >> n;
	
	cout << trapz(lBound, uBound, n) << endl;

	_getch();

	return 0;
}

double trapz(double lBound, double uBound, int n)
{
	double dx, sum(0);
	dx = (uBound - lBound) / n;

	for (int i = 1; i < n; ++i)
	{
		sum += (2 * funct(lBound + (i * dx)));
		cout << i << endl;
	}
	sum += (funct(lBound) + funct(uBound));
	sum = sum * dx / 2;

	return sum;
}

double funct(double x)
{
	return 4 * exp(-x);
}