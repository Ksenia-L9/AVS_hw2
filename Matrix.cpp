#include "Matrix.h"

Matrix::Matrix(int rows, int columns) {
    if (rows <= 0 || columns <= 0 || rows != columns) {
        printf("Number of columns/rows cannot be zero, negative or different");
    } else {
        this->rows = rows;
        this->columns = columns;
    }
}

