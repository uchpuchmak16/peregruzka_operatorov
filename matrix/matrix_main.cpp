#include "Matrix.h"

class Matrix;
int main() {
  
    
    Matrix mat1(3, 3);  // матрица 1
    mat1.fillRandom(); // заполняем обе матрицы случайными числами

    Matrix mat2(3, 3); // матрица 2
    mat2.fillRandom(); // заполняем обе матрицы случайными числами


    std::cout << "Matrix 1:" << std::endl << mat1;
    std::cout << "Matrix 2:" << std::endl << mat2;

    Matrix sum = mat1 + mat2;
    std::cout << "Sum of matrices:" << std::endl << sum;

    mat1 += mat2;
    std::cout << "Matrix 1 after adding Matrix 2 in place:" << std::endl << mat1;

    Matrix diff = mat1 - mat2;
    std::cout << "Difference of matrices:" << std::endl << diff;

    mat1 -= mat2;
    std::cout << "Matrix 1 after subtracting Matrix 2 in place:" << std::endl << mat1;

    Matrix prod = mat1 * mat2;
    std::cout << "Product of matrices:" << std::endl << prod;

    if (mat1 == mat2) {
        std::cout << "Matrix 1 is equal to Matrix 2." << std::endl;
    }
    else {
        std::cout << "Matrix 1 is not equal to Matrix 2." << std::endl;
    }

    if (mat1 != mat2) {
        std::cout << "Matrix 1 is not equal to Matrix 2." << std::endl;
    }
    else {
        std::cout << "Matrix 1 is equal to Matrix 2." << std::endl;
    }

    return 0;
}