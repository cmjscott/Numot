// Homework_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES // required to access the constant approximation of pi in the cmath library
#include <math.h>
#include <cmath> // used for pow function
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h> //include for getch function
#include <iomanip> //include for setprecision command

const double acc1(.009), acc2(.000009);

int pTriples(int maxL);
int piCalc(double accuracy);
double funct(double x);


using namespace std;

/*Question 1: A right triangle can have sides that are all integers. The set of three integer values for the 
sides of a right triangle is called a Pythagorean triple. These three sides must satisfy the Pythagorean 
Theorem. Find all Pythagorean triples for side1, side2, and the hypotenuse all no larger than 500 and 
output the number of triples found. Use a triple nested ‘for’ loop that tries all possibilities. This is an 
example of “brute force” computing, but illustrates how for loops can be nested.*/



int _tmain(int argc, _TCHAR* argv[])
{
	int found;
	
	
	printf("PROBLEM 1:\n");
	found = pTriples(500);
	printf("Number of Unique triples found = %i\n\n",found );

	printf("PROBLEM 2:\n");
	printf("Number of cycles required for 3 significant digits: %i\n", piCalc(acc1));
	printf("Number of cycles required for 6 significant digits: %i\n", piCalc(acc2));
	printf("Cycles required to add 3 significant figures of pi: %i\n\n", piCalc(acc2) - piCalc(acc1));

	printf("PROBLEM 3:\n");



	_getch();

	return 0;
}


int pTriples(int maxL)
{
	int found(0), cycles(0);

	for (int hyp = 1; hyp <= maxL; ++hyp) // loops through all hypotinuse values between 1 and maxL
	{
		for (int a = 1; a <= hyp; ++a) // for each hypotinuse value, loops through all b values 
		{
			for (int b = 1; b <= a; ++b)
			{
				if (sqrt(pow(a, 2) + pow(b, 2)) == hyp)
				{
					++found;
				}
				++cycles;
			}
		}
	}
	printf("pTriples complete after %i cycles.\n", cycles);
	return found;
}

int piCalc(double accuracy)
{
	int i(1);
	double approx(4);
	
	while (fabs( approx - M_PI) > accuracy)
	{
		approx += pow(-1, i) * 4 / (3 + 2 * (i-1));
		//cout << fabs(approx - M_PI) << endl;
		//printf("i = %i, approx = %f\n", i, approx);
		++i;
	}
	return  i;
}

/*Approximate the value of the root of f(x) = 2x + x sin(x + 3) – 5 between 2.4 and 3.5. You 
may use either method shown in class. Discuss why you chose that particular method and the 
advantages of that particular method over the alternate choice. Show output results after 5, 50, and 
500 iterations. */


void bisection(int n, double start, double end)
{
	// declare and set variables used in function
	int temp = n - 1;
	double mid, fstart, fend, prod;
	mid = (start + end) / 2;
	fstart = funct(start);
	fend = funct(end);
	prod = fstart * fend;


	if (fstart == 0 ||fend == 0 ) // check if the start point is a root
	{
		printf("Root found at x = %f\n", start);
		return;
	}

	// checks if the difference between your roots falls within the accuracy and if their product is negative (a root is between them)
	else if (fabs(fstart - fend) < .0000001 && prod < 0)
	{
		printf("Root found at x = %f\n", mid);
		return;
	}
	else if (n == 0) // if you're out of iterations, exit
	{
		return;
	}

	// if you pass all the other checks above, recurse after bisecting the interval
	bisection(temp, start, mid);
	bisection(temp, mid, end);
}


double funct(double x)
{
	return 2 * x + x*sin(x + 3) - 5;
}
