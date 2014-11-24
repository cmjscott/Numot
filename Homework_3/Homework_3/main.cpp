#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> // used for pow function
#include <conio.h> //include for getch function
#include <iomanip> //include for setprecision command


std::vector<int> sillySortingFUnction(std::vector<int>*);

/*Write a program that sorts a series of numbers in ascending or descending order. The program should 
prompt the user to enter a series of five different integers and ask whether the user wants the integers 
to be sorted in ascending or descending order. The sorting should only be done by a function or 
functions and the sorted list should be returned back to the user with the numbers displayed in 
ascending or descending order.*/

int main()
{
		std::vector<int> vec, sortedVec;
		int inputInt;

		do
		{
			std::cout << "Please give me an integer: ";
			std::cin >> inputInt;
			vec.push_back(inputInt);
		} while (vec.size() < 5);

		std::sort(vec.begin(), vec.end());

		//sortedVec = sillySortingFUnction(vec);
		
		for (int i = 0; i < vec.size(); ++i)
		{
			std::cout << vec[i] << ' ';
		}

		_getch();
	return 0;
}


std::vector<int> sillySortingFUnction(std::vector<int> _sortVector)
{
	std::vector<int> sortVector = _sortVector;
	std::sort(sortVector.begin(), sortVector.end());
	return sortVector;
}