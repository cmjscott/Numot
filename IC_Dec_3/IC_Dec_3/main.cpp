#include <cmath>
#include <iostream>
#include <conio.h>

double funct(double _currY, double t);
int main()
{
	double dt(.1), y(1);

	for (int i = 0; i < 5; ++i)
	{
		y = y + dt * funct(y, i*dt);
		std::cout << "for t = " <<  i*dt << "     y = " << y << std::endl;
	}
	_getch();

	return 0;
}

double funct(double _currY, double t)
{
	return 2 - exp(-4 * t) - 2 * _currY;
}