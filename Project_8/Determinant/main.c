/*
Group: Ian Marwong, Danny Yu
Program finds the determinant of a given matrix
*/
#include <stdio.h>
#include "matrix.h"

int main(int argc, char *argv[]) {

    const char *filename = argv[1];

    struct Matrix *matrix = read_matrix(filename);

    double deter = determinant(matrix);
    printf("The determinant is %.2lf.\n", deter);

    free_matrix(matrix);
    return 0;
}
