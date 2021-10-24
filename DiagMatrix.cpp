#include <cstdio>
#include <cstdlib>
#include "Matrix.h"
#include "DiagMatrix.h"

DiagMatrix::DiagMatrix(int rows, int columns) : Matrix(rows, columns) {
    mtrx = new double[rows * columns];
}

DiagMatrix::~DiagMatrix() {
    delete mtrx;
}

void DiagMatrix::fill(FILE *input_file) {
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

void DiagMatrix::rndfill() {
    for (int i = 0; i < rows * columns; ++i) {
        if (i % columns == i / rows) {
            mtrx[i] = rand() % 10000;
        } else {
            mtrx[i] = 0;
        }
    }
}

double DiagMatrix::average() {
    double sum = 0;

    if (rows <= 0 || columns <= 0) {
        return -1;
    }

    for (int i = 0; i < rows * columns; ++i) {
        sum += mtrx[i];
    }
    return sum / (rows * columns);
}

void DiagMatrix::print(FILE *output_file) {
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