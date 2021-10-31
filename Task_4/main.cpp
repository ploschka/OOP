#include <iostream>
#include "Matrix.h"

int main()
{
	std::cout << "Matrix size = ";
	int size;
	std::cin >> size;
	std::cout << std::endl;
	if (std::cin.fail())
	{
		return -1;
	}
	Matrix B(size);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			B[i][j] = (i+1) * (j+3);
		}
	}

	std::cout << "B = \n"
	<< B << std::endl
	<< "Average in B = \n"
	<< B.average() << std::endl << std::endl
	<< "Most different from average in B = \n"
	<< B.mostUnaverage() << std::endl << std::endl
	<< "Mirrored B = \n"
	<< B.mirrorSecondary() << std::endl;

	Matrix C(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			C[i][j] = (i+2) * (j+1);
		}
	}

	std::cout << "C = \n"
	<< C <<std::endl
	<< "2B - C^T = \n"
	<< (2 * B - (C.transpon())) << std::endl;
}