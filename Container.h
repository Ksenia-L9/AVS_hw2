#ifndef AVS_HW2_CONTAINER_H
#define AVS_HW2_CONTAINER_H

#include "iostream"
#include "Matrix.h"

class Container {
private:
    // Maximum capacity of Container.
    static int const MAX_CAPACITY = 10000;
    // Length of container instance.
    int length;
    // Array of matrices - the contents of Container.
    Matrix **matrices;

public:
    // Container constructor.
    Container(int len);
    // Container destructor.
    ~Container();
    // Deallocates the Container.
    void clear();
    // Fills Container with matrices from the input file/random.
    void fill(FILE *input_file);
    // Sorts matrices by the average.
    void sort();
    // Writes the length of Container to the output file.
    void printInf(FILE *output_file);
    // Writes the contents of Container to the output file.
    void print(FILE *output_file);
};

#endif //AVS_HW2_CONTAINER_H
