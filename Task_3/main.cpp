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
	std::cout << (mmx * 2) << std::endl;
	//*/
	/*
	Matrix mmx(4, 4);
	for (int i = 0; i < mmx.getRows(); i++)
    {
        for (int j = 0; j < mmx.getColumns(); j++)
        {
            mmx[i][j] = (i + 1) * (j + 1);
        }
    }

	Matrix mx(mmx);
	std::cout << mmx << std::endl;
	std::cout << mx << std::endl;
	*/
}