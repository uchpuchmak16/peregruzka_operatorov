#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Matrix {
private:
    int** data; // указатель на указатель
    unsigned int m, n;

public:
    Matrix(unsigned int rows, unsigned int cols);
    ~Matrix();

    int* operator[](unsigned int index);

    void fillRandom();

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    Matrix operator+(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other);
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
};

#endif
#pragma once
