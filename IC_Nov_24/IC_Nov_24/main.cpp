#include<cmath>// include for math
#include<vector> // include for vector container
#include<conio.h>
#include<iostream> // include for IO stuff
#include <algorithm> // include for sort
#include <iomanip> //include for setprecision command

//function prototypes
double maxTemp(const std::vector<double> v);
double minTemp(const std::vector<double> v);
double meanTemp(const std::vector<double> v);
double medianTemp(const std::vector<double> v);


int main()
{
	std::vector<double> vec;
	double inputDouble;

	// Loops until there are 10 values in the vector collection
	do
	{
		std::cout << "Enter temp (celsius): ";
		std::cin >> inputDouble;
		vec.push_back(inputDouble);
	} while (vec.size() < 10);

	//sort the vector
	std::sort(vec.begin(), vec.end());

	// Performs all the required actions
	std::cout << "Maximum Temp = " << maxTemp(vec) << std::endl;
	std::cout << "Minimum Temp = " << minTemp(vec) << std::endl;
	std::cout << "Mean Temp = " << meanTemp(vec) << std::endl;
	std::cout << "Median Temp = " << medianTemp(vec) << std::endl;

	_getch();
	return 0;
}

double maxTemp(const std::vector<double> v)
{
	return v.back(); //return the last element of sorted array (the max)
}

double minTemp(const std::vector<double> v)
{
	return v.front(); // return the first element of sorted array (the min)
}

double meanTemp(const std::vector<double> v)
{
	double sum = 0;

	//sums up all the elements
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum / v.size(); // returns the sum divided by the number of elements in the vector
}

double medianTemp(const std::vector<double> v)
{
	double median;
	int size = v.size();

	//if there are an even number of items in the vector
	if (v.size() % 2 == 0)
	{
		// return the average of the two middle datapoints
		median = (v[(size/2)-1] + v[(size/2)]) / 2;
	}
	else{
		//return the center datapoint
		median = v[floor(size / 2)];
	}
	return median;
}