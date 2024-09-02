#include <stdlib.h>
#include "board.h"

char* get_column(char** board, int dimensions, int column_index){
    char* cur_col = (char*)malloc(dimensions * sizeof(char));
    for(int i = 0; i < dimensions; ++i){
        cur_col[i] = board[i][column_index]; 
    }
    return cur_col;
}

char* get_left_diagonal(char** board, int dimensions){
    /* Get this diagonal pictured below 
        X
          X
            X
    */
    char* diagonal = (char*)malloc(dimensions * sizeof(char));
    for(int i = 0; i < dimensions; ++i){
        diagonal[i] = board[i][i];
    }
    return diagonal;
}

char* get_right_diagonal(char** board, int dimensions){
    /* Get this diagonal pictured below 
            X
          X
        X
    */
    char* diagonal = (char*)malloc(dimensions * sizeof(char));
    for(int row = 0, col = dimensions - 1; row < dimensions; ++row, --col){
        diagonal[row] = board[row][col];
        // board[row][dimensions - row - 1]
    }
    return diagonal;
}

void destroy_board(char** board, int dimensions){
    for(int i = 0; i<dimensions; ++i){
        
    }
}

//gcc -mm *.c

debug:
    gdb --tui tictactoe.out