#ifndef AVS_HW2_DIAGMATRIX_H
#define AVS_HW2_DIAGMATRIX_H

// Class of diagonal matrix.
class DiagMatrix : public Matrix {
private:
    // Array represents the content of matrix.
    double *mtrx;

public:
    // Constructor of diagonal matrix.
    DiagMatrix(int rows, int columns);
    // Destructor of diagonal matrix.
    ~DiagMatrix() override;
    // Fills the matrix with data from the input file.
    void fill(FILE *input_file) override;
    // Fills diagonal matrix with random digits.
    void rndfill() override;
    // Finds the average of diagonal matrix.
    double average() override;
    // Writes the diagonal matrix to the output file.
    void print(FILE *output_file) override;
};

#endif //AVS_HW2_DIAGMATRIX_H
