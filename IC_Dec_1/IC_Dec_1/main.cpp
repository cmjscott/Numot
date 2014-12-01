#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
#include <string>
#include <fstream>


double matMult(std::vector<std::vector<double> > matrix1, std::vector<std::vector<double> > matrix2);
double det(std::vector<std::vector<double> > mat);
std::vector<std::vector<double> > getMatrix(int n);
void outputData(std::vector<std::vector<double> > vec, std::string _fileName);

/*Write a program in C++ that uses 2 - D arrays to(a) compute the determinant of a 2 x 2 matrix and(b)
multiply two 2 x 2 matrices.The program should prompt the user to enter values for the matrix entries
and display the results back to the user.Your program should contain functions that compute the
determinant and do the matrix multiplication.*/


int main()
{
	std::vector<std::vector<double> > mat1, mat2;
	int matSize;
	double input;


	std::cout << "How large are your matrices? : ";
	std::cin >> matSize;
	std::cout << std::endl << std::endl;

	std::cout << "Enter data for matrix 1" << std::endl;
	mat1 = getMatrix(matSize);
	std::cout << "Enter data for matrix 2" << std::endl;
	mat2 = getMatrix(matSize);



	
		

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


double matMult(std::vector<std::vector<double> > matrix1, std::vector<std::vector<double> > matrix2)
{

	return 0;
}

double det(std::vector<std::vector<double> > mat)
{

	return 0;
}

void outputData(std::vector<std::vector<double> > vec, std::string _fileName)
{
	std::ofstream outfile;
	std::string filePath = "C://Users//Colton Scott//Documents//" + _fileName + ".dat";

	// open file in write mode, overwriting if file exists.
	//Note: this could lead to loss of data and should be dealt with.
	outfile.open(filePath.c_str(), std::ios::out | std::ios::trunc);

	//just a double check if the file is open or not.
	//TODO: write in error handling if file doesnt open or isnt open.
	if (outfile.is_open())
	{
		std::cout << "Writing to the file" << std::endl;

		// write each line to the output file as column vectors
		for (int i = 0; i < vec[0].size(); ++i)
		{
			for (int j = 0; j < vec.size(); ++j)
			{
				outfile << vec[j][i] << ',';
			}
			outfile << std::endl;
		}
		outfile << std::endl;

		// close the opened file.
		outfile.close();
	}//if (outfile.is_open())

	//sucsess message
	std::cout << "Sucsess writing data to:" << std::endl << filePath << std::endl << std::endl;
}