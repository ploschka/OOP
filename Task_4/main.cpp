#include <iostream>
#include "Matrix.h"
#include "PrintMatrix.h"

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
	printMatrix(B);
}