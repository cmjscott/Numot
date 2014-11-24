#include<cmath>
#include<vector>
#include<conio.h>
#include<iostream>
#include <algorithm>
#include <iomanip> //include for setprecision command


double maxTemp(const std::vector<double> v);
double minTemp(const std::vector<double> v);
double meanTemp(const std::vector<double> v);
double medianTemp(const std::vector<double> v);


/*Write a C++ program that prompts the user to enter 10 temperature measurements in degrees C and
computes the maximum temperature, the minimum temperature, the mean temperature, and the
median temperature. The measurements should be read into an array and the array should be passed
into a minimum of three distinct functions that compute the parameters of interest (ie. mean, median,
etc.). Results should be displayed back to the user
*/

int main()
{
	std::vector<double> vec, sortedVec;
	double inputDouble;
	char flag;
	bool ascending;

	do
	{
		std::cout << "Enter temp (celsius): ";
		std::cin >> inputDouble;
		vec.push_back(inputDouble);
	} while (vec.size() < 10);

	std::sort(vec.begin(), vec.end());


	std::cout << "Maximum Temp = " << maxTemp(vec) << std::endl;
	std::cout << "Minimum Temp = " << minTemp(vec) << std::endl;
	std::cout << "Mean Temp = " << meanTemp(vec) << std::endl;
	std::cout << "Median Temp = " << medianTemp(vec) << std::endl;

	_getch();
	return 0;
}

double maxTemp(const std::vector<double> v)
{
	return v.back();
}

double minTemp(const std::vector<double> v)
{
	return v.front();
}

double meanTemp(const std::vector<double> v)
{
	double sum = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum / v.size();
}

double medianTemp(const std::vector<double> v)
{
	double median;
	if (v.size() % 2 == 0)
	{
		median = v[v.size() / 2];
	}
	else{
		median = (v[floor(v.size() / 2)] + v[ceil(v.size() / 2)]) / 2;
	}
	return median;
}