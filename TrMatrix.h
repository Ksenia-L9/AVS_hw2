#ifndef AVS_HW2_TRMATRIX_H
#define AVS_HW2_TRMATRIX_H

// Class of bottom-triangle matrix.
class TrMatrix : public Matrix {
private:
    // Array represents the content of matrix.
    double *mtrx;

public:
    // Constructor of bottom-triangle matrix.
    TrMatrix (int rows, int columns);
    // Destructor of bottom-triangle matrix.
    ~TrMatrix() override;
    // Fills the matrix with data from the input file.
    void fill(FILE *input_file) override;
    // Fills bottom-triangle matrix with random digits.
    void rndfill() override;
    // Finds the average of bottom-triangle matrix.
    double average() override;
    // Writes the bottom-triangle matrix to the output file.
    void print(FILE *output_file) override;
};

#endif //AVS_HW2_TRMATRIX_H
