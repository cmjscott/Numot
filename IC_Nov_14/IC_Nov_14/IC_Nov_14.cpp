// IC_Nov_14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h> //include for getch function
#include <cmath> // used for pow function
#include <iomanip> //include for setprecision command

using namespace std;


double funct(double x);
double deriv(double x);
double newton(int  n, double guess);

const double accuracy = .0000001;

int main()
{

	// declare variables used in main
	double initialGuess, result;
	int iter;
	
	// basic input stuff
	cout << "Enter initial guess: ";
	cin >> initialGuess;
	cout << endl << "Iterate how many times: ";
	cin >> iter;

	//start the fun
	try
	{
		result = newton( iter, initialGuess);
	}
	catch (double err)
	{
		printf("No root was found using initial guess: %f\nAfter %i iterations\n", initialGuess, iter);
		printf("Closest guess is: %f\nWith a value of: %f\n", err, funct(err));
	}

	printf("Root found at x = %f\n", result);
	cout << "done" << endl;

	_getch();

	return 0;
}

double newton(int  n, double guess)
{

	/*###########################################################
	IF YOU CHANCE BELOW TO n-- IT WILL NOT COUND DOWN PROPERLY
	BECAUSE IT SETS nextIer TO n BEFORE DECREMENTING n AND 
	THEN PASSES nextIter AS n TO THE RECURSION. THIS WILL NOT
	PROPERLY DECREMENT n.	
	############################################################*/
	int nextIter = --n;
	double fguess, derivGuess, nextGuess;
	fguess = funct(guess);
	derivGuess = deriv(guess);

	//cout << "n = " << n << endl;//<< "fguess = " << fguess << endl;

	if (fguess == 0) // check if the guess is a root
	{
		//printf("Start Root found at x = %f\n", start);
		return guess;
	}
	if (fabs(fguess) < accuracy)
	{
		return guess;
	}

	nextGuess = guess - (fguess / derivGuess);

	if (fabs(nextGuess - guess) < accuracy)
	{
		return nextGuess;
	}
	if (n == 0)
	{
		throw guess;
	}

	return newton(nextIter, nextGuess);
}

double funct(double x)
{
	double temp = 0;
	temp = pow(x, 6) - x - 1;
	return temp;
}

double deriv(double x)
{
	double temp = 0;
	temp = 6 * pow(x, 5) - 1;
	return temp;
}