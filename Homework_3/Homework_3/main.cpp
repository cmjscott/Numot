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

		do
		{
			std::cout << "Please give me an integer: ";
			std::cin >> inputInt;
			vec.push_back(inputInt);
		} while (vec.size() < 5);

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


		//std::sort(vec.begin(), vec.end());
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

	for (int i = 0; i < v->size(); ++i)
	{
		for (int j = 0; j < (v->size()- i - 1); ++j)
		{
			if (_ascending)
			{
				if ((*v)[j]>(*v)[j + 1])
				{
					temp = (*v)[j + 1];
					(*v)[j + 1] = (*v)[j];
					(*v)[j] = temp;
				}
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
