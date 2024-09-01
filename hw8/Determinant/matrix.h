#ifndef MATRIX_H
#define MATRIX_H

struct Matrix {
    int rows;
    int cols;
    double **values;
};

struct Matrix* read_matrix(const char *filename);
void free_matrix(struct Matrix *matrix);
double determinant(struct Matrix *matrix);
double determinant_smallmatrix(struct Matrix *matrix, int size);

#endif
