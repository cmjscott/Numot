#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> // used for pow function
#include <conio.h> //include for getch function
#include <iomanip> //include for setprecision command
#include <cctype> // for istype functions


void bubble(std::vector<int>* v, bool ascending);

int man()
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

			//checks if the stream encountered a fatal error (ie. a char was entered)
			if (std::cin.fail()) 
			{
				std::cin.clear(); // clears the error
			}

			// clear out any additional input from the stream until the end of the line
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

			// if the ignore cleared out more than one character (the null terminator)
			// assume that bad data was passed to the input stream
			// because otherwise the stream would be clear, since all the data was placed into inputInt
			if (std::cin.gcount() > 1)
			{
				std::cout << "Error, non integer data entered" << std::endl;
			} else {
				vec.push_back(inputInt);
			}

		} while (vec.size() < 5);

		//Asks the user if they want their vector sorted in ascending or descending order
		do
		{
			std::cout << std::endl << "Ascending (a) or Descending (d) order?\n";
			flag = (char)_getch();
		} while (flag != 'a' && flag != 'd');

		// converts the flag char to a boolean
		if (flag == 'a')
		{
			ascending = true;
		} else {
			ascending = false;
		}

		bubble(&vec,ascending);
		
		std::cout << "Sorted Array:\n[ ";
		for (int i = 0; i < vec.size(); ++i)
		{
			std::cout << vec[i] << ' ';
		}
		std::cout << "]\n";
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
				// If the _ascending bool is false, sorts in descending order
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
