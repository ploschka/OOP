#include <fstream>
#include "Matrix.h"
#include "GeneralPrint.h"

void printMatrix(Matrix& matrix)
{
    std::ofstream fout("Matrix.txt");
    printMatrix(fout, matrix);
    fout.close();
}