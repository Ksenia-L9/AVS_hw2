#include <cstdio>
#include <cstdlib>
#include "Matrix.h"
#include "SqMatrix.h"
#include <iostream>

SqMatrix::SqMatrix(int rows, int columns) : Matrix(rows, columns) {
    mtrx = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        mtrx[i] = new double[columns];
    }
}

SqMatrix::~SqMatrix() {
    for (int i = 0; i < rows; ++i) {
        delete mtrx[i];
    }
    rows = 0;
    columns = 0;
}

void SqMatrix::fill(FILE *input_file) {
    if (rows <= 0 || columns <= 0) {
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (fscanf(input_file, "%lf", &mtrx[i][j]) != 1) {
                printf("Incorrect format");
                break;
            }
        }
    }
}

void SqMatrix::rndfill() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            mtrx[i][j] = rand() % 10000;
        }
    }
}

double SqMatrix::average() {
    double sum = 0;

    if (rows <= 0 || columns <= 0) {
        return -1;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum += mtrx[i][j];
        }
    }
    return sum / (rows * columns);
}

void SqMatrix::print(FILE *output_file) {
    if (rows <= 0 || columns <= 0) {
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            fprintf(output_file, "%.2lf ", mtrx[i][j]);
        }
        fprintf(output_file, "\n");
    }
}