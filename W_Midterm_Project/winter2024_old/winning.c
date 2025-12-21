#include <stdlib.h>
#include "winning.h"
#include "board.h"

bool is_game_over(char** board, int dimensions, char blank_space){
    return has_a_player_won(board, dimensions, blank_space) || is_tie_game();
}

bool has_a_player_won(char** board, int dimensions, char blank_space){
    return has_a_player_won_horizontally(board, dimensions, blank_space) ||
           has_a_player_won_vertically(board, dimensions, blank_space) ||
           has_a_player_won_diagonally(board, dimensions, blank_space); 
}

bool has_a_player_won_horizontally(char** board, int dimensions, char blank_space){
    //If any of the rows are filled entirely with 1 player’s piece

    for(int i = 0; i < dimensions; ++i){

        if(contains_win(board[i], dimensions, blank_space)){
            return true;
        }
    }
    return false; 

}

bool has_a_player_won_vertically(char** board, int dimensions, char blank_space){
    //If any of the columns are filled entirely with 1 player’s piece

    for(int i = 0; i < dimensions; ++i){
        char* cur_col = get_column(board, dimensions, i);
        bool is_win = contains_win(cur_col, dimensions, blank_space);
        free(cur_col);
        if(is_win){
            return true;
        }
    }

    return false;
}

bool has_a_player_won_diagonally(char** board, int dimensions, char blank_space){
    //If any of the two main diagonals are filled entirely with 1 player’s piece
    char* left_diagonal = get_left_diagonal(board, dimensions);
    char* right_diagonal = get_right_diagonal(board, dimensions);
    bool is_win =  contains_win(left_diagonal, dimensions, blank_space) || 
                   contains_win(right_diagonal, dimensions, blank_space);
    free(left_diagonal);
    free(right_diagonal);
    return is_win;
}



// bool has_a_player_won_vertically_alt(char** board, int dimensions, char blank_space){
//     //If any of the columns are filled entirely with 1 player’s piece
//     bool all_same;
//     for(int col = 0; col < dimensions; ++col){
//         all_same = true;
//         if(board[0][col] == blank_space){
//             continue;
//         }
//         for(int row = 1; row < dimensions; ++ row){
//             if(board[row][col] != board[0][col]){
//                 all_same = false
//                 break;
//             }
//         }
//         if(all_same){
//             return true;
//         }
//     }
//     return false; 
      
// }



bool contains_win(char* sequence, int length , char blank_space){
    return sequence[0] != blank_space && are_all_same(sequence, length);
}

bool are_all_same(char* str, int len){
    for(int i = 1; i < len; ++i){
        if(str[i] != str[0]){
            return false;
        }
    }
    return true; 
}

bool is_tie_game(char** board, int dimensions, char blank_space){
    //If the board is full and no one has won
    for(int i = 0; i < dimensions; ++i){
        for(int j = 0; j < dimensions; ++j){
            if(board[i][j] == blank_space){
                return false;
            }
        }
    }
    return !has_a_player_won(board, dimensions, blank_space);
}