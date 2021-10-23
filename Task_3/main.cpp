#include <iostream>
#include "Matrix.h"




int& da(int& gg)
{
	int* ptr = new int(gg);
	return *ptr;
}

int main()
{	
	///*
	Matrix mmx(4, 4);
	for (int i = 0; i < mmx.getRows(); i++)
    {
        for (int j = 0; j < mmx.getColumns(); j++)
        {
            mmx[i][j] = (i + 1) * (j + 1);
        }
    }
	std::cout << mmx << std::endl;
	Matrix mx(mmx * 2);
	std::cout << mx << std::endl;
	std::cout << (mx - (2 * mmx)) << std::endl;
}