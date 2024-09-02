#include <stdlib.h>
#include <stdio.h>
#include "board.h"

char** make_grid(int rows, int cols, char blank_space){
    /*
    Make a N X N empty board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character (*)
    @returns the playing board
    */
    char** board = (char**)malloc(rows * sizeof(char*));
    for(int i = 0; i < rows; ++i){
        board[i] = (char*) malloc((cols+1) * sizeof(char)); 
        for(int j = 0; j < cols; ++j){
            board[i][j] = blank_space;
        }
        
    }

    return board;
}

void destroy_board(char** board, int dimensions){
    /*
    frees the board memory once program is done
    @param board is the board
    @param dimensions is the number of rows
    */
    for(int i = 0; i < dimensions; ++i){
        free(board[i]);
    }
    free(board);
}

void display_board(char** board, int rows, int cols){
    /*
    prints the board to the screen
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    */
    
    for(int i = 0; i < rows; ++i){
        printf("%d ", rows-(i+1));
        for(int j = 0; j < cols; ++j){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i = 0; i < cols;++i){
        printf("%d ", i);
    }
    printf("\n");
}

char* get_column(char** board, int dimensions, int column_index){
    /*
    retrieves a given column from the board
    @param board is the board
    @param dimensions is the number of rows
    @param column_index is which column is trying to be retrieved
    @returns the column as a sequence
    */
    char* cur_col = (char*)malloc(dimensions * sizeof(char));
    for(int i = 0; i < dimensions; ++i){
        cur_col[i] = board[i][column_index]; 
    }
    return cur_col;
}

char* get_left_diagonal(char** board, int rows, int cols, int indexRow, int indexCol){
    /* Get this diagonal pictured below 
        X
          X
            X
        @param board is the board
        @param rows is the number of rows
        @param cols is the number of columns
        @param indexRow is the row the diagonals starts on
        @param indexCol is the column the diagonals starts on
        @returns the left diagonal
    */
    int diagonal_length = (rows < cols) ? rows : cols;
    char* diagonal = (char*)malloc(diagonal_length * sizeof(char));
    int diagonal_index = 0;

    // Iterate over the diagonal elements
    while (indexRow < rows && indexCol < cols && diagonal_index < diagonal_length) {
        // Store the current diagonal element in the diagonal array
        diagonal[diagonal_index] = board[indexRow][indexCol];

        // Move to the next element along the diagonal
        indexRow++;
        indexCol++;
        diagonal_index++;
    }
    return diagonal;
}

char* get_right_diagonal(char** board, int rows, int cols, int indexRow, int indexCol){
    /* Get this diagonal pictured below 
            X
          X
        X
        @param board is the board
        @param rows is the number of rows
        @param cols is the number of columns
        @param indexRow is the row the diagonals starts on
        @param indexCol is the column the diagonals starts on
        @returns the right diagonal
    */
    int diagonal_length = (rows < cols) ? rows : cols;
    char* diagonal = (char*)malloc(rows * sizeof(char));
    int diagonal_index = 0;

    // Iterate over the diagonal elements
    while (indexRow < rows && indexCol >= 0 && diagonal_index < diagonal_length) {
        // Store the current diagonal element in the diagonal array
        diagonal[diagonal_index] = board[indexRow][indexCol];

        // Move to the next element along the diagonal
        indexRow++;
        indexCol--;
        diagonal_index++;
    }

    return diagonal;
}