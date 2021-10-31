#include <iostream>
#include "Matrix.h"

void printMatrix(std::ostream& out, Matrix& matrix)
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
}