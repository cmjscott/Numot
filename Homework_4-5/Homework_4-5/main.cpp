#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <functional>
#include <cstring>
#include <iomanip>

//for prob 1
std::vector<std::vector<double> > getMatrix(int n);
std::vector<double> gauss(std::vector<std::vector<double> > mat);
void printMat(double element);
void printVec(std::vector<double> vec);
void prob1();

// for problem 2
double yPrime(double currY, double t);
double euler(double t, double dt);
void prob2();

int main()
{
	//prob1();
	prob2();
	return 0;
}

void prob1()
{
	std::vector<std::vector<double> > equations;
	std::vector<double> answers;
	int nUnknowns;
	
	std::cout << "Problem 1:" << std::endl;
	std::cout << "How many unknowns? : ";
	std::cin >> nUnknowns;
	std::cout << std::endl << std::endl;
	equations = getMatrix(nUnknowns);
	printVec(gauss(equations));
	_getch();
}

std::vector<std::vector<double> > getMatrix(int n)
{
	std::vector<std::vector<double> > mat;
	std::vector<double> row;
	double input;

	for (int i = 0; i < n; ++i)
	{
		row.clear();
		row.resize(0);
		std::cout << "Equation " << (i + 1) << std::endl;

		// gets inputs for each unknown
		for (int j = 0; j < n; ++j)
		{
			std::cout << "x" << (j + 1) << ": ";
			std::cin >> input;
			row.push_back(input);
		}
		// gets what they equal
		std::cout << "= ";
		std::cin >> input;
		row.push_back(input);

		// collects the equation into a system of equations
		mat.push_back(row);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return mat;
}

std::vector<double> gauss(std::vector<std::vector<double> > mat)
{

	std::vector<double>::iterator iter, reduceIter;
	std::vector<double> results;
	double reduceScaleFactor;
	int rowCounter;
	
	for (int i = 0; i < mat.size(); ++i)// go through each row systematically
	{
		reduceScaleFactor = 1/mat[i][i]; //get the 1st non-zero element of the i'th vector
		rowCounter = 0;

		iter = mat[i].begin() + i; // sets the iterator to the i'th element of the i'th row
		std::transform(iter, mat[i].end(), iter, std::bind1st(std::multiplies<double>(),reduceScaleFactor));
		
		//for_each(mat[i].begin(), mat[i].end(), printMat);
		std::cout << "Operation: " << i +1 << std::endl;

		do
		{
			if (rowCounter != i) // ignore the i'th row of data, since you are pivoting over that item
			{
				reduceIter = mat[rowCounter].begin() + i; // gets the iterator corrisponding to the i'th element of the row
				reduceScaleFactor = 1/mat[rowCounter][i]; // gets the reduce scale factor for the row

				// multiplies the row by the reduce scale factor so the leading element is equal to 1
				std::transform(reduceIter, mat[rowCounter].end(), reduceIter, std::bind1st(std::multiplies<double>(), reduceScaleFactor));

				// subtracts the i'th row from the current row to complete the pivot
				std::transform(reduceIter, mat[rowCounter].end(), iter, reduceIter, std::minus<double>());
			}
			
			for_each(mat[rowCounter].begin(), mat[rowCounter].end(), printMat);// prints out the row
			std::cout << std::endl;
			++rowCounter;
		} while (rowCounter < mat.size());
		std::cout << std::endl;
	}

	//collects the answers
	for (int i = 0; i < mat.size(); ++i)
	{
		results.push_back(mat[i].back());
	}
	return results;
}

void printMat(double element) {  //function for printing out an element
	std::cout << std::fixed << std::setprecision(3) << ' ' << element;
}

//prints out the results
void printVec(std::vector<double> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << "x" << (i + 1) << " = " << vec[i] << std::endl;
	}
}



//##########################################################################################
//
// PROBLEM 2 CODE
//
//##########################################################################################


void prob2()
{
	double times[4] = { .1, .2, .3, .4 };
	double timeSteps[3] = { .1, .05, .025 };
	double t, dt;

	std::cout << "Problem 2:\n-----------------------------" << std::endl;
	for (int i = 0; i < 4; ++i) //for each t value
	{
		std::cout << "For t = " << times[i] << ":" << std::endl;
		for (int j = 0; j < 3; ++j) // loop through each step
		{
			std::cout << "Using dt = " << timeSteps[j] << ": f(t) =	" << euler(times[i], timeSteps[j]) << std::endl;
		}
		std::cout << "-----------------------------" << std::endl;
	}
	std::cout << std::endl << "Now you try!" << std::endl << "Enter a time value > 0: ";
	std::cin >> t;
	std::cout << std::endl << "Enter a dt value > 0 but smaller than your time: ";
	std::cin >> dt;
	std::cout << "Using dt = " << dt << ": f(t) =	" << euler(t, dt) << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << std::endl << "Problem 2 complete. Press any key to exit.";
	_getch();
}



double euler(double t, double dt)
{
	double y(1);
	int cycles;

	cycles = t / dt;

	for (int i = 0; i < cycles; ++i)
	{
		y = y + dt * yPrime(y, i*dt);
	}
	return y;
}

double yPrime(double currY, double t)
{
	return .5 - t + 2 * currY;
}