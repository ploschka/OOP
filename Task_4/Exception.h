#pragma once

class MatrixException
{
public:
    MatrixException(std::string error);
};

class SizeException:public MatrixException
{
public:
    SizeException(std::string error);
};

class IndexException:public MatrixException
{
public:
    IndexException(std::string error);
};