#include "Matrix.h"

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

Matrix::Matrix(int size) : Matrix(size, size) {}

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
    return (index >= 0) ? (matrix[index]) : (throw IndexException("Invalid index"));
}

std::ostream& operator<< (std::ostream& out, Matrix& matrix)
{
    int rws = matrix.getRows();
    int cls = matrix.getColumns();
    for (int i = 0; i < rws; i++)
    {
        for (int j = 0; j < cls; j++)
        {
            out << matrix[i][j] << '\t';
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
    if ((this->rows == other.rows) && (this->columns == other.columns))
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
    else
    {
        throw SizeException("Different sizes");
    }
}

Matrix& Matrix::transpon()
{
    Matrix* mtx = new Matrix(columns, rows);
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            (*mtx)[i][j] = matrix[j][i];
        }
    }
    return *mtx;
}

Matrix& Matrix::mirrorSecondary()
{
    if (rows == columns)
    {
        Matrix* mtx = new Matrix(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                (*mtx)[i][j] = matrix[rows - 1 - j][columns - 1 - i];
            }
        }
        return *mtx;
    }
    else
    {
        throw SizeException("Not a square matrix");
    }
}