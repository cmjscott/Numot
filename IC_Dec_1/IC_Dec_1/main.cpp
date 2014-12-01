#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>

double matMult(std::vector<std::vector<double> > matrix1, std::vector<std::vector<double> > matrix2);
double det(std::vector<std::vector<double> > mat);

/*Write a program in C++ that uses 2 - D arrays to(a) compute the determinant of a 2 x 2 matrix and(b)
multiply two 2 x 2 matrices.The program should prompt the user to enter values for the matrix entries
and display the results back to the user.Your program should contain functions that compute the
determinant and do the matrix multiplication.*/


int main()
{
	std::vector<std::vector<std::vector<double> > > mats;
	std::vector<std::vector<double> > mat1, mat2;
	int matSize;
	double input;
	mats.push_back(mat1);
	mats.push_back(mat2);

	std::cout << "How large are your matrices? : ";
	std::cin >> matSize;
	std::cout << std::endl << std::endl;

	for (int k = 0; k < 2; ++k)
	{
		std::cout << "Enter data for matrix " << (k + 1) << std::endl;
		for (int i = 0; i < matSize; ++i)
		{
			std::cout << "Row " << (i + 1) << std::endl;
			for (int j = 0; j < matSize; ++j)\
			{
				std::cout << "Item " << (j + 1) << ": ";
				std::cin >> input;
				std::cout << std::endl;
				mats[k][i].push_back();
			}
		}
	}

	for (int k = 0; k < 2; ++k)
	{
		std::cout << "Enter data for matrix " << (k + 1) << std::endl;
		for (int i = 0; i < matSize; ++i)
		{
			std::cout << "Row " << (i + 1) << std::endl;
			for (int j = 0; j < matSize; ++j)\
			{
				std::cout << mats[k][i][j] << " , ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	}



	return 0;
}

double matMult(std::vector<std::vector<double> > matrix1, std::vector<std::vector<double> > matrix2)
{

	return 0;
}

double det(std::vector<std::vector<double> > mat)
{

	return 0;
}