#include <cstdio>
#include <cstdlib>
#include "Matrix.h"
#include "TrMatrix.h"

TrMatrix::TrMatrix(int rows, int columns) : Matrix(rows, columns) {
    mtrx = new double[rows * columns];
}

TrMatrix::~TrMatrix() {
    delete mtrx;
    rows = 0;
    columns = 0;
}

void TrMatrix::fill(FILE *input_file) {
    if (rows <= 0 || columns <= 0) {
        return;
    }

    for (int i = 0; i < rows * columns; ++i) {
        if (fscanf(input_file, "%lf", &mtrx[i]) != 1) {
            printf("Incorrect format");
            break;
        }
    }
}

void TrMatrix::rndfill() {
    for (int i = 0; i < rows * columns; ++i) {
        if (i % columns <= i / rows) {
            mtrx[i] = rand() % 10000;
        } else {
            mtrx[i] = 0;
        }
    }
}

double TrMatrix::average() {
    double sum = 0;

    if (rows <= 0 || columns <= 0) {
        return -1;
    }

    for (int i = 0; i < rows * columns; ++i) {
        sum += mtrx[i];
    }
    return sum / (rows * columns);
}

void TrMatrix::print(FILE *output_file) {
    if (rows <= 0 || columns <= 0) {
        return;
    }

    int iter = 0;
    while (iter < rows * columns) {
        for (int i = 0; i < columns; ++i) {
            fprintf(output_file, "%.2lf ", mtrx[iter]);
            ++iter;
        }
        fprintf(output_file, "\n");
    }
}