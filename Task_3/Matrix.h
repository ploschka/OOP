#pragma once
#include <iostream>
#include <cmath>
#include "Exception.h"

class Matrix
{
private:
    int** matrix;
    int rows;
    int columns;

    void erase();
public:
    Matrix(int rows, int columns);
    Matrix(int size);
    Matrix(Matrix& mtx);
    ~Matrix();
    int getRows() const;
    int getColumns() const;
    int* operator[](int index);
    Matrix& operator*(int value);
    friend Matrix& operator*(int value, Matrix& matrix);
    Matrix& operator-(Matrix& other);
    friend std::ostream& operator<< (std::ostream& out, Matrix& matrix);

    double average();
    int mostUnaverage();
    Matrix& transpon();
    Matrix& mirrorSecondary();
};