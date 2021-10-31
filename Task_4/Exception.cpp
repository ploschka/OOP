#include "Exception.h"

MatrixException::MatrixException(std::string error)
{
    std::cerr << error << std::endl;
}

SizeException::SizeException(std::string error) : MatrixException(error) {}

IndexException::IndexException(std::string error) : MatrixException(error) {}