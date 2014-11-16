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


int pTriples(int maxL);
int piCalc(double accuracy);
using namespace std;

/*Question 1: A right triangle can have sides that are all integers. The set of three integer values for the 
sides of a right triangle is called a Pythagorean triple. These three sides must satisfy the Pythagorean 
Theorem. Find all Pythagorean triples for side1, side2, and the hypotenuse all no larger than 500 and 
output the number of triples found. Use a triple nested ‘for’ loop that tries all possibilities. This is an 
example of “brute force” computing, but illustrates how for loops can be nested.*/



int _tmain(int argc, _TCHAR* argv[])
{
	int found;
	double acc1(.009), acc2(.000009);

	//found = pTriples(500);

	cout << piCalc(acc1) << endl << piCalc(acc2) << endl;

	cout << (piCalc(acc2)-piCalc(acc1))<< endl;

	//cout << M_PI << endl;

	//printf("End of loops, number of non-unique triples found = %i\n", found);
	_getch();


	return 0;
}


int pTriples(int maxL)
{
	int found(0);

	for (int hyp = 1; hyp <= maxL; ++hyp) // loops through all hypotinuse values between 1 and maxL
	{
		for (int a = 1; a <= hyp; ++a) // for each hypotinuse value, loops through all b values 
		{
			for (int b = 1; b <= hyp; ++b)
			{
				if (sqrt(pow(a, 2) + pow(b, 2)) == hyp)
				{
					++found;
				}

			}

		}

	}
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