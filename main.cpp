#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "Container.h"

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct.
    if (argc != 3) {
        std::cout << "Incorrect command line\n";
    }

    // Open file stream for reading.
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == nullptr) {
        printf("Cannot access file\n");
    }

    // Open file stream for writing.
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == nullptr) {
        printf("Cannot access file\n");
    }

    // Length of the future Container.
    int len;
    // Reading the length from the file.
    if (fscanf(input_file, "%d", &len) != 1) {
        printf("Incorrect format");
    } else {
        // Initialising a Container.
        Container *container = new Container(len);

        srand(time(0));

        container->fill(input_file);
        container->printInf(output_file);
        container->print(output_file);
        container->sort();
        fprintf(output_file, "Sorted:\n");
        container->print(output_file);
    }

    return 0;
}
