#include <iostream>
#include <cmath>
#include <vector>


std::vector<std::vector<double> > getMatrix(int n);
std::vector<double> gauss(std::vector<std::vector<double> > mat);

/*Write a C++ program that uses 2-D arrays to solve two simultaneous equations (e.g. x + y = 2 and 5x + 7y
= 6) using Gaussian elimination. The program should prompt the user to enter the coefficients for each
equation and display the results for the unknown variables (e.g. x and y). */


int main()
{
	int nUnknowns;

	std::cout << "How many unknowns? : ";
	std::cin >> nUnknowns;
	std::cout << std::endl << std::endl;

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



}