#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <functional>
#include <cstring>
#include <iomanip>

std::vector<std::vector<double> > getMatrix(int n);
std::vector<double> gauss(std::vector<std::vector<double> > mat);
void printMat(double element);


/*Write a C++ program that uses 2-D arrays to solve two simultaneous equations (e.g. x + y = 2 and 5x + 7y
= 6) using Gaussian elimination. The program should prompt the user to enter the coefficients for each
equation and display the results for the unknown variables (e.g. x and y). */


int main()
{
	std::vector<std::vector<double> > equations;
	std::vector<double> answers;
	int nUnknowns;

	/*
	std::cout << "How many unknowns? : ";
	std::cin >> nUnknowns;
	std::cout << std::endl << std::endl;

	equations = getMatrix(nUnknowns);
	*/

	equations = { { 2, 1, -1, 8 }, { -3, -1, 2, -11 }, { -2, 1, 2, -3 } };
	answers = gauss(equations);
	_getch();

	return 0;
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

		for (int j = 0; j < n; ++j)
		{
			std::cout << "x" << (j + 1) << ": ";
			std::cin >> input;
			std::cout << std::endl;
			row.push_back(input);
		}
		std::cout << "= ";
		std::cin >> input;
		row.push_back(input);

		mat.push_back(row);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return mat;
}

std::vector<double> gauss(std::vector<std::vector<double> > mat)
{


	std::vector<double>::iterator iter, reduceIter; //= mat.begin() + i;
	std::vector<double> results;
	double reduceScaleFactor;
	int rowCounter;
	

	//NOTE: mat.size() is the number of equations/unknowns. Mat[1].size() is one larger
	for (int i = 0; i < mat.size(); ++i)// go through each row systematically
	{
		reduceScaleFactor = 1/mat[i][i]; //get the 1st non-zero element of the i'th vector
		rowCounter = 0;

		iter = mat[i].begin() + i; // sets the iterator to the i'th element of the i'th row
		std::transform(iter, mat[i].end(), iter, std::bind1st(std::multiplies<double>(),reduceScaleFactor));
		
		

		//for_each(mat[i].begin(), mat[i].end(), printMat);
		//std::cout << std::endl << std::endl;

		do
		{
			if (rowCounter != i) // ignore the i'th row of data, since you are pivoting over that item
			{
				reduceIter = mat[rowCounter].begin() + i;
				reduceScaleFactor = 1/mat[rowCounter][i];
				std::transform(reduceIter, mat[rowCounter].end(), reduceIter, std::bind1st(std::multiplies<double>(), reduceScaleFactor));
				std::transform(reduceIter, mat[rowCounter].end(), iter, reduceIter, std::minus<double>());
			}
			
			//for_each(mat[rowCounter].begin(), mat[rowCounter].end(), printMat);
			//std::cout << std::endl;
			++rowCounter;
		} while (rowCounter < mat.size());
	
		results.push_back(mat[i].back());
		//std::cout << std::endl;
	}

	return results;
}

void printMat(double element) {  // function:
	std::cout << std::fixed << std::setprecision(2) << ' ' << element;
}

