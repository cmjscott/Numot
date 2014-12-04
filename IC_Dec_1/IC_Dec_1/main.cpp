 #include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
#include <string>
#include <fstream>


std::vector<std::vector<double> > matMult(std::vector<std::vector<double> > m1, std::vector<std::vector<double> > m2);
double det(std::vector<std::vector<double> > mat);
std::vector<std::vector<double> > getMatrix(int n);
void displayMat(std::vector<std::vector<double> > mat);
std::vector<std::vector<double> > randMat(int n);


int main()
{
	std::vector<std::vector<double> > mat1, mat2, multResult;
	int matSize;
	double input ;


	std::cout << "How large are your matrices? : ";
	std::cin >> matSize;
	std::cout << std::endl << std::endl;

	std::cout << "Enter data for matrix 1" << std::endl;
	mat1 = randMat(matSize);
	//mat1 = getMatrix(matSize);
	std::cout << "Enter data for matrix 2" << std::endl;
	mat2 = randMat(matSize);
	//mat2 = getMatrix(matSize);


	std::cout << "Matrix 1:\n";
	displayMat(mat1);
	std::cout << std::endl << std::endl;

	std::cout << "Matrix 2:\n";
	displayMat(mat2);
	std::cout << std::endl << std::endl;

	std::cout << "Matrix 1 * Matrix 2:\n";
	displayMat(matMult(mat1, mat2));

	std::cout << std::endl << "Det(Matrix 1) = " << det(mat1);
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
			std::cout << "Row " << (i + 1) << std::endl;

			for (int j = 0; j < n; ++j)
			{
				std::cout << "Item " << (j + 1) << ": ";
				std::cin >> input;
				std::cout << std::endl;
				row.push_back(input);
			}
			mat.push_back(row);
			std::cout << std::endl;
		}
	std::cout << std::endl;
	return mat;
}


std::vector<std::vector<double> > matMult(std::vector<std::vector<double> > m1, std::vector<std::vector<double> > m2)
{
	std::vector<std::vector<double> > mat;
	std::vector<double> row;
	double sum(0);

	//get your loops right, count yo shit
	for (int i = 0; i < m1.size(); ++i)
	{//loop over the rows of matrix 1
		row.clear();
		row.resize(0);

		for (int j = 0; j < m2[i].size(); ++j)
		{//loops over the i'th column of matrix 2
			for (int k = 0; k < m1[i].size(); ++k)
			{
				sum += m1[i][k] * m2[k][j];
			}
			row.push_back(sum);
			sum = 0;
		}
		mat.push_back(row);
	}
	return mat;
}

void displayMat(std::vector<std::vector<double> > mat)
{
	for (int i = 0; i < mat.size(); ++i)//loop over the rows of matrix 1
	{
		for (int j = 0; j < mat[1].size(); ++j)//loops over the i'th column of matrix 2
		{
			if (mat[1].size() == j + 1)
				std::cout << mat[i][j];
			else
				std::cout << mat[i][j] << " , ";
		}
		std::cout << std::endl;
	}
}


double det(std::vector<std::vector<double> > mat)
{
	std::vector<std::vector<double> > subMat;
	std::vector<double> row;
	double sum(0);
	int colCounter;

	if (mat.size() == 2)
	{
		return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
	}
	else
	{
		for (int i = 0; i < mat.size(); ++i)//for each item in the first row
		{
			if (mat[0][i] != 0)
			{
				subMat.clear();
				subMat.resize(0);
				for (int j = 1; j < mat.size(); ++j)//loop through remaining rows
				{
					row.clear();
					row.resize(0);
					colCounter = 0;
					do
					{
						if (colCounter != i) // ignore the i'th column of data, since you are expanding over that item
						{
							row.push_back(mat[j][colCounter]);
						}
						++colCounter;
					} while (row.size() < mat.size() - 1);
					subMat.push_back(row);
				}
				sum += mat[0][i] * (pow((-1), i) * det(subMat));
			}
		}
		return sum;
	}
}

std::vector<std::vector<double> > randMat(int n)
{
	std::vector<std::vector<double> > mat;
	std::vector<double> row;

	for (int i = 0; i < n; ++i)
	{
		row.clear();
		row.resize(0);
		for (int j = 0; j < n; ++j)
		{
			row.push_back(std::rand() % 10);
		}
		mat.push_back(row);
	}
	return mat;
}