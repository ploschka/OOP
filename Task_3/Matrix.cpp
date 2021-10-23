#include "Matrix.h"
#define WRONG_SIZE -1

void Matrix::erase()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns)
{
    if (rows > 0 && columns > 0)
    {
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[columns];
        }
    }
    else
    {
        throw SizeException("Invalid size");
    }
}

Matrix::Matrix(int size) : rows(size), columns(size)
{
    if (size > 0)
    {
        matrix = new int*[size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
        }
    }
    else
    {
        throw SizeException("Invalid size");
    }
}

Matrix::Matrix(Matrix& mtx) : rows(mtx.getRows()), columns(mtx.getColumns())
{
    if (rows > 0 && columns > 0)
    {
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = mtx[i][j];
            }
        }
    }
    else
    {
        throw SizeException("Invalid size");
    }
}

Matrix::~Matrix()
{
    erase();
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getColumns() const
{
    return columns;
}

int* Matrix::operator[](int index)
{
    return matrix[index];
}

std::ostream& operator<< (std::ostream& out, Matrix& matrix)
{
    int rws = matrix.getRows();
    int cls = matrix.getColumns();
    for (int i = 0; i < rws; i++)
    {
        for (int j = 0; j < cls; j++)
        {
            out << matrix[i][j] << ' ';
        }
        out << std::endl;
    }
    return out;
}

double Matrix::average()
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }
    }
    int count = rows * columns;
    return (sum / count);
}

int Matrix::mostUnaverage()
{
    double aver = average();
    double dist = 0;
    int result;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (std::abs(matrix[i][j] - aver) > dist)
            {
                result = matrix[i][j];
                dist = std::abs(matrix[i][j] - aver);
            }
        }
    }
    return result;
}

Matrix& Matrix::operator*(int value)
{
    Matrix* mtx = new Matrix(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            (*mtx)[i][j] *= value;
        }
    }
    return *mtx;
}

Matrix& operator*(int value, Matrix& matrix)
{
    return (matrix * value);
}

Matrix& Matrix::operator-(Matrix& other)
{
    Matrix* mtx = new Matrix(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            (*mtx)[i][j] -= other[i][j];
        }
    }
    return *mtx;
}

Matrix& Matrix::transpon()
{
    Matrix* mtx = new Matrix(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            (*mtx)[i][j] = matrix[j][i];
        }
    }
    return *mtx;
}