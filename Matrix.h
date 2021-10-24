#ifndef AVS_HW2_MATRIX_H
#define AVS_HW2_MATRIX_H

#include <cstdio>

// Abstract class Matrix.
class Matrix {
protected:
    // Number of rows in matrix.
    int rows;
    // Number of columns in matrix.
    int columns;
    // Constructor.
    Matrix(int rows, int columns);

public:
    // Pure virtual destructor.
    virtual ~Matrix() {};
    // Pure virtual method that fill matrix from the input file.
    virtual void fill(FILE *input_file) = 0;
    // Pure virtual method that finds an average of matrix.
    virtual double average() = 0;
    // Pure virtual method that prints matrix to the output file.
    virtual void print(FILE *output_file) = 0;
    // Pure virtual method that fills matrix with random digits.
    virtual void rndfill() = 0;
};

#endif //AVS_HW2_MATRIX_H
