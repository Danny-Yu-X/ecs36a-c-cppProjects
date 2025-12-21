#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct Matrix* read_matrix(const char *filename) {
    /*
    This function reads the input file into the matrix
    @param filename is the input file's name
    @returns the filled in matrix
    */
    FILE *file = fopen(filename, "r");
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    fscanf(file, "%d %d", &matrix->rows, &matrix->cols);
    matrix->values = malloc(matrix->rows * sizeof(double *));

    for (int i = 0; i < matrix->rows; i++) {
        matrix->values[i] = malloc(matrix->cols * sizeof(double));
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            fscanf(file, "%lf", &matrix->values[i][j]);
        }
    }
    fclose(file);
    return matrix;
}

void free_matrix(struct Matrix *matrix) {
    /*
    This function deletes the matrix when it is not needed
    @param matrix is the matrix to be deleted
    */
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->values[i]);
    }
    free(matrix->values);
    free(matrix);
}

double determinant(struct Matrix *matrix) {
    /*
    Function calculates the determinant by starting the recursive function
    @param matrix is the matrix to be used for calculations
    @returns the determinant
    */
    return determinant_smallmatrix(matrix, matrix->rows);
}

double determinant_smallmatrix(struct Matrix *matrix, int size) {
    /*
    Function calculates the derterminant by breaking down the matrix
    @param matrix is the original matrix
    @param size is the size of the matrix
    @returns the determinant of the orignal matrix
    */
    double deter = 0.0;
    if (size == 1) {
        return matrix->values[0][0];
    } else if (size == 2) {
        return matrix->values[0][0] * matrix->values[1][1] - matrix->values[0][1] * matrix->values[1][0];
    }

    struct Matrix *smallmatrix = malloc(sizeof(struct Matrix));

    smallmatrix->rows = size - 1;
    smallmatrix->cols = size - 1;
    smallmatrix->values = malloc(smallmatrix->rows * sizeof(double *));
    
    for (int i = 0; i < smallmatrix->rows; i++) {
        smallmatrix->values[i] = malloc(smallmatrix->cols * sizeof(double));
    }

    // Do Laplace expansion
    int sign = 1;
    for (int j = 0; j < size; j++) {
        int l = 0, m = 0;
        for (int i = 1; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (k == j) {
                    continue;
                }
                smallmatrix->values[l][m++] = matrix->values[i][k];
                if (m == size - 1) {
                    l++;
                    m = 0;
                }
            }
        }
        deter += sign * matrix->values[0][j] * determinant_smallmatrix(smallmatrix, size - 1);
        sign = -sign;
    }

    for (int i = 0; i < smallmatrix->rows; i++) {
        free(smallmatrix->values[i]);
    }
    free(smallmatrix->values);
    free(smallmatrix);

    return deter;
}
