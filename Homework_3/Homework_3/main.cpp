#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> // used for pow function
#include <conio.h> //include for getch function
#include <iomanip> //include for setprecision command

void bubble(std::vector<int>* v, bool ascending);


/*Write a program that sorts a series of numbers in ascending or descending order. The program should 
prompt the user to enter a series of five different integers and ask whether the user wants the integers 
to be sorted in ascending or descending order. The sorting should only be done by a function or 
functions and the sorted list should be returned back to the user with the numbers displayed in 
ascending or descending order.*/

int main()
{
		std::vector<int> vec, sortedVec;
		int inputInt;
		char flag;
		bool ascending;

		//Promps the user for integer input
		do
		{
			std::cout << "Please give me an integer: ";
			std::cin >> inputInt;


			//TODO: prevent implicit typecast to int if a double is provided to cin
			while (std::cin.fail()) 
			{
				std::cout << "Error, please enter an integer." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> inputInt;
			}


			vec.push_back(inputInt);
		} while (vec.size() < 5);

		//Asks the user if they want their vector sorted in ascending or decending order
		do
		{
			std::cout << std::endl << "Ascending (a) or Decending (d) order?\n";
			flag = (char)_getch();
		} while (flag != 'a' && flag != 'd');

		if (flag == 'a')
		{
			ascending = true;
		} else {
			ascending = false;
		}

		bubble(&vec,ascending);
		 
		for (int i = 0; i < vec.size(); ++i)
		{
			std::cout << vec[i] << ' ';
		}
		_getch();
	return 0;
}

void bubble(std::vector<int>* v, bool _ascending)
{
	int temp;
	//Loops over the entire vector
	for (int i = 0; i < v->size(); ++i)
	{
		for (int j = 0; j < (v->size()- i - 1); ++j)
		{
			if (_ascending)
			{
				// If the _ascending bool is true, sorts in ascending order
				if ((*v)[j]>(*v)[j + 1])
				{
					temp = (*v)[j + 1];
					(*v)[j + 1] = (*v)[j];
					(*v)[j] = temp;
				}
				// If the _ascending bool is false, sorts in decending order
			}else{
				if ((*v)[j]<(*v)[j + 1])
				{
					temp = (*v)[j + 1];
					(*v)[j + 1] = (*v)[j];
					(*v)[j] = temp;
				}
			}//if (_ascending)
		}//for (int j = 0; j < (v->size()- i - 1); ++j)
	}//for (int i = 0; i < v->size(); ++i)
}
