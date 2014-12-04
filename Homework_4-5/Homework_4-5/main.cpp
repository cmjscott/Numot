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
void printVec(std::vector<double> vec);

int main()
{
	std::vector<std::vector<double> > equations;
	std::vector<double> answers;
	int nUnknowns;

	std::cout << "How many unknowns? : ";
	std::cin >> nUnknowns;
	std::cout << std::endl << std::endl;
	equations = getMatrix(nUnknowns);
	printVec(gauss(equations));
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

