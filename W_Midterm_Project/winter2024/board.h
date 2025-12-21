#ifndef BOARD_H
    #define BOARD_H
    char** make_grid(int rows, int cols, char blank_space);
    void destroy_board(char** board, int dimensions);
    void display_board(char** board, int rows, int cols);
    char* get_left_diagonal(char** board, int rows, int cols, int indexRow, int indexCol);
    char* get_right_diagonal(char** board, int rows, int cols, int indexRow, int indexCol);
    char* get_column(char** board, int dimensions, int column_index);

#endif