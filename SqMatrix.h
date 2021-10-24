#ifndef AVS_HW2_SQMATRIX_H
#define AVS_HW2_SQMATRIX_H

#include <cstdio>
#include "Matrix.h"

// Class of square matrix.
class SqMatrix : public Matrix{
private:
    // Array represents the content of matrix.
    double **mtrx;

public:
    // Constructor of square matrix.
    SqMatrix(int rows, int columns);
    // Destructor of square matrix.
    ~SqMatrix() override;
    // Fills the matrix with data from the input file.
    void fill(FILE *input_file) override;
    // Fills square matrix with random digits.
    void rndfill() override;
    // Finds the average of square matrix.
    double average() override;
    // Writes the square matrix to the output file.
    void print(FILE *output_file) override;
};

#endif //AVS_HW2_SQMATRIX_H
