#include <stdlib.h>
#include <stdbool.h>
#include "winning.h"
#include "board.h"

bool is_game_over(char** board, int rows, int cols, char blank_space, int win_pieces){
    /*
    checks to see if a player won or is a tie game
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character(*)
    @param win_pieces is the number of pieces needed to win
    @returns if the game is over
    */
    return has_a_player_won(board, rows, cols, blank_space, win_pieces) || 
           is_tie_game(board, rows, cols, blank_space, win_pieces);
}

bool has_a_player_won(char** board, int rows, int cols, char blank_space, int win_pieces){
    /*
    checks to see if a player has won horizontally, vertically, or diagonally
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character(*)
    @param win_pieces is the number of pieces needed to win
    @returns if a player has won
    */
    return has_a_player_won_horizontally(board, rows, cols, blank_space, win_pieces) ||
           has_a_player_won_vertically(board, rows, cols, blank_space, win_pieces) ||
           has_a_player_won_diagonally(board, rows, cols, blank_space, win_pieces); 
}

bool has_a_player_won_horizontally(char** board, int rows, int cols, char blank_space, int win_pieces){
    /*If any row has enough pieces in a row to win
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character(*)
    @param win_pieces is the number of pieces needed to win
    @returns if there is a horizontal win
    */
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(contains_win(board[i]+j, win_pieces, blank_space)){
                return true;
            }
        }
    }
    return false; 
}

bool has_a_player_won_vertically(char** board, int rows, int cols, char blank_space, int win_pieces){
    /*If any column has enough pieces in a row to win
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character(*)
    @param win_pieces is the number of pieces needed to win
    @returns is there is a vertical win
    */
    for(int i = 0; i < cols; ++i){
            char* cur_col = get_column(board, rows, i);
            bool is_win = false;
            for(int j = 0; j < rows; ++j){
                if(contains_win(cur_col + j, win_pieces, blank_space)){
                    is_win = true;
                    break;
                }
            }
            free(cur_col);
            if(is_win){
                return true;
            }
    }
    return false;
}

bool has_a_player_won_diagonally(char** board, int rows, int cols, char blank_space, int win_pieces){
    /* checks to see if any diagonal has enough pieces to win
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character(*)
    @param win_pieces is the number of pieces needed to win
    @returns if there is a diagonal win
    */
    bool is_win;
    for(int i = 0; i < (rows); ++i){
        for(int j = 0; j<cols; ++j){
            char* left_diagonal = get_left_diagonal(board, rows, cols, i, j);
            char* right_diagonal = get_right_diagonal(board, rows, cols, i, j);
            is_win =  contains_win(left_diagonal, win_pieces, blank_space) || 
                        contains_win(right_diagonal, win_pieces, blank_space);
            free(left_diagonal);
            free(right_diagonal);
            if(is_win){
                break;
            }
        }
        if(is_win){
            break;
            }
    }
    return is_win;
}

bool contains_win(char* sequence, int length , char blank_space){
    /*
    function checks if a given sequence is all the same and not the blank character
    @param sequence is the sequence being checked
    @param length is the length of the sequence
    @param blank_space is the blank space character(*)
    returns if the sequence wins or not
    */
    return are_all_same(sequence, length) && sequence[0] != blank_space;
}

bool are_all_same(char* str, int len){
    /*
    checks to see if all elements in a sequence is the same
    @param str is the sequence
    @param len is the length of the sequence
    @returns if they are all the same
    */
    for(int i = 1; i < len; ++i){
        if(str[i] != str[0]){
            return false;
        }
    }
    return true; 
}

bool is_tie_game(char** board, int rows, int cols, char blank_space, int win_pieces){
    /*If the board is full and no one has won
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character(*)
    @param win_pieces is the number of pieces needed to win
    @returns if it is a tie game
    */
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(board[i][j] == blank_space){
                return false;
            }
        }
    }
    return !has_a_player_won(board, rows, cols, blank_space, win_pieces);
}