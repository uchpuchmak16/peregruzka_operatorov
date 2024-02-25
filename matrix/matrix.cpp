#include "Matrix.h"




 Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
  data = new int* [m];
  for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
       }
 }

    Matrix::~Matrix() { // деструктор 
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    int* Matrix::operator[](unsigned int index) {
        return data[index];
    }

    void Matrix::fillRandom() {  // заполение числами массива
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix Matrix::operator+(const Matrix& other) {
        if (m != other.m || n != other.n) { // если матрицы не равны по размеру то в консоль выводятся просто матрицы без выполнения дальнейшних действий
            throw std::invalid_argument("Matrices must have the same dimensions for addition");
        }

        
            
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& Matrix::operator+=(const Matrix& other) { // оператор +=
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix& other) { // оператор -
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix& Matrix::operator-=(const Matrix& other) { // оператор -=
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix Matrix::operator*(const Matrix& other) {
        if (n != other.m || m != other.n) { // если матрицы не равны по размеру то в консоль выводятся просто матрицы без выполнения дальнейшних действий
            throw std::invalid_argument("Matrices must have the same dimensions for addition");
        }
        // оператор умножения
        //операция умножения двух матриц выполнима только в том случае,
        //если число столбцов в первом сомножителе равно числу строк во втором
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool Matrix::operator==(const Matrix& other) const { // логический оператор равенства
        if (m != other.m || n != other.n) return false;

        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) return false;
            }
        }

        return true;
    }

    bool Matrix::operator!=(const Matrix& other) const { // оператор не равенства двух значений
        return !(*this == other);
    }


