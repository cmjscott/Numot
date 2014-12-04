#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <functional>
#include <cstring>


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


	std::vector<double>::iterator iter; //= mat.begin() + i;
	double reduceScaleFactor;

	//NOTE: mat.size() is the number of equations/unknowns. Mat[1].size() is one larger
	for (int i = 0; i < mat.size(); ++i)// go through each row systematically
	{
		reduceScaleFactor = mat[i][i];
		
		for (int j = i; j < mat.size(); ++j)
		{
			iter = mat[j].begin() + i; // sets the iterator to the i'th element of the i'th row
			std::transform(iter, mat[j].end(), iter, std::bind1st(std::divides<double>(),reduceScaleFactor));
		}
		

		for_each(mat[i].begin(), mat[i].end(), printMat);
		std::cout << std::endl;
		/*
		do
		{
			if (colCounter != i) // ignore the i'th column of data, since you are expanding over that item
			{
				row.push_back(mat[j][colCounter]);
			}
			++colCounter;
		} while (row.size() < mat.size() - 1);
		*/



	}


	return mat[1];
}

void printMat(double element) {  // function:
	std::cout << ' ' << element;
}