#pragma once
#include <iostream>

class MatrixException
{
public:
    MatrixException(std::string error)
    {
        std::cerr << error << std::endl;
    }
};

class SizeException:public MatrixException
{
public:
    SizeException(std::string error) : MatrixException(error) {}
};