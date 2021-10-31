#include "Exception.h"
#include <iostream>

MatrixException::MatrixException(std::string error)
{
    std::cerr << error << std::endl;
}

SizeException::SizeException(std::string error) : MatrixException(error) {}

IndexException::IndexException(std::string error) : MatrixException(error) {}