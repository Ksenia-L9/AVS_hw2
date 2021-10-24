#include <cstdio>
#include <cstdlib>
#include "Container.h"
#include "Matrix.h"
#include "SqMatrix.h"
#include "TrMatrix.h"
#include "DiagMatrix.h"

Container::Container(int len) {
    if (len <= 0 || len > MAX_CAPACITY) {
        printf("Length cannot be zero, negative or more than 10000");
    } else {
        length = len;
        matrices = new Matrix *[len];
    }
}

Container::~Container() {
    clear();
}

void Container::clear() {
    delete[] matrices;
    length = 0;
}

void Container::fill(FILE *input_file) {
    for (int i = 0; i < length; ++i) {
        if (length >= 20) {
            int type_number = rand() % 3;
            int r;
            int c;
            r = c = rand() % 15 + 1;
            switch (type_number) {
                case 0:
                    matrices[i] = new SqMatrix(r, c);
                    matrices[i]->rndfill();
                    break;
                case 1:
                    matrices[i] = new TrMatrix(r, c);
                    matrices[i]->rndfill();
                    break;
                case 2:
                    matrices[i] = new DiagMatrix(r, c);
                    matrices[i]->rndfill();
                    break;
                default:
                    printf("Something went wrong");
            }
        } else {
            int type_number;
            if (fscanf(input_file, "%d", &type_number) != 1) {
                printf("Invalid type of Matrix");
            } else {
                int r;
                int c;
                if (fscanf(input_file, "%d", &r) != 1 || fscanf(input_file, "%d", &c) != 1) {
                    printf("Incorrect format of rows/columns number");
                } else {
                    switch (type_number) {
                        case 1:
                            matrices[i] = new SqMatrix(r, c);
                            matrices[i]->fill(input_file);
                            break;
                        case 2:
                            matrices[i] = new TrMatrix(r, c);
                            matrices[i]->fill(input_file);
                            break;
                        case 3:
                            matrices[i] = new DiagMatrix(r, c);
                            matrices[i]->fill(input_file);
                            break;
                        default:
                            printf("Incorrect Matrix type");
                    }
                }
            }
        }
    }
}

void Container::sort() {
    double sum_av = 0;
    for (int i = 0; i < length; ++i) {
        if (matrices[i]->average() == -1) {
            return;
        }
        sum_av += matrices[i]->average();
    }
    double average = sum_av / length;

    int iter = 0;
    for (int i = 0; i < length - iter; ++i) {
        if (matrices[i]->average() > average) {
            ++iter;
            for (int j = 0; j < length - 1; ++j) {
                Matrix *tmp = matrices[j];
                matrices[j] = matrices[j + 1];
                matrices[j + 1] = tmp;
            }
            --i;
        }
    }
}

void Container::printInf(FILE *output_file) {
    fprintf(output_file, "Length: %d\n", length);
}

void Container::print(FILE *output_file) {
    for (int i = 0; i < length; ++i) {
        matrices[i]->print(output_file);
        fprintf(output_file, "\n");
    }
}
