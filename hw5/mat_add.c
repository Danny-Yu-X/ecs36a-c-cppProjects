/*
Group: Ian Marwong, Danny Yu
This program adds two matrices together
*/

#include <stdio.h>
void inputMatrix(int rows, int cols, int inMatrix[rows][cols]);
void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]);
void printMatrix(int rows, int cols, int result[rows][cols]);

void inputMatrix(int rows, int cols, int inMatrix[rows][cols]){
    /*
    Function recieves input to create an array
    @param rows is the number of rows
    @param cols is the number of columns
    @param inMatrix[rows][cols] is the matrix to be put into the array
    */
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            scanf("%d", &inMatrix[i][j]);
        }
    }
}

void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]){
    /*
    Function adds two matrices together
    @param rows is the number of rows
    @param cols is the number of columns
    @param matrixA[rows][cols] is the first matrix to be added
    @param matrixB[rows][cols] is the second matrix to be added
    */
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            result[i][j]= matrixA[i][j]+matrixB[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int result[rows][cols]){
    /*
    Function prints the result matrix
    @param rows is the number of rows
    @param cols is the number of columns
    @param result[rows][cols] matrix to be outputted
    */
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);

    int matrixA[rows][cols];
    int matrixB[rows][cols];
    int result[rows][cols];

    printf("Enter Matrix A\n");
    inputMatrix(rows, cols, matrixA);

    printf("Enter Matrix B\n");
    inputMatrix(rows, cols, matrixB);

    printf("A + B =\n");
    addMatrices(rows, cols, matrixA, matrixB, result);
    printMatrix(rows, cols, result);

    return 0;
}