#include <iostream> // for cin/cout
#include <conio.h> // for getch function
#include <cmath> // for exp function
#include <iomanip> // include for setprecision command

// function prototype declarations
double trapz(double lBound, double uBound, int n);
double funct(double x);

using namespace std;

int main()
{
	double lBound, uBound;
	int n,ending(0);

	// do while loop used for running 3 times. Tried to terminate program based on keypress, but it wasn't working and I got frustrated. 
	// will learn and fix later.
	do{
		// basic input stuff
		cout << "Enter lower bound: ";
		cin >> lBound;
		cout << "Enter upper bound: ";
		cin >> uBound;
		cout << "Enter number of sections: ";
		cin >> n;

		printf("Trapezoidal estimation of the integral 4*exp(-x) from %.2f to %.2f\nusing %i sections is: %f\n\n", lBound, uBound, n,trapz(lBound, uBound, n));
		
		++ending;
	} while (ending < 3);

	_getch();
	return 0;
}


/* Performes the trapezoid rule on the given function
 from the lower bound to the uppper bound using n trapezoids.
 uses: integral(F(x)| blound - ubound = deltaX/2 * (F(lbound) + F(ubound) ...
 + 2 * sum(F(lbound + i * deltaX)) from i = 1 to i = n-1
 */
double trapz(double lBound, double uBound, int n)
{
	double dx, sum(0); // define required variables
	dx = (uBound - lBound) / n; //calculate step size

	// sum the 2nd through penultimate function value and multiply by 2
	for (int i = 1; i < n; ++i)
	{
		sum += (2 * funct(lBound + (i * dx)));
		//cout << i << endl;
	}
	
	sum += (funct(lBound) + funct(uBound));// add the first and last function value to the sum
	sum = sum * dx / 2; // multiply entire thing by base/2 (deltaX / 2)  

	return sum;
}

// because I'm lazy and didn't want to type the entire function out each time.
double funct(double x)
{
	return 4 * exp(-x);
}