#include "setup.h"

bool is_game_over(char** board, int dimensions, char blank_space){
    return has_a_player_won(board, dimensions, blank_space)||is_tie_game();
}
bool has_a_player_won(char** board, int dimensions, char blank_space){
    return has_a_player_won_horizontally(board, dimensions, blank_space) || has_a_player_won_vertically() || has_a_player_won_digonally();
}

bool has_a_player_won_horizontally(char** board, int dimensions, char blank_space){
    for(int i=0; i < dimensions; ++i){
        if(board[i][0] != blank_space && are_all_same(board[i], dimensions)){
            return true;
        }
    }
    return false;
}

bool has_a_player_won_vertically(char** board, int dimensions, char blank_space){
    for(int i=0; i < dimensions; ++i){
        char* cur_col = get_column(board, dimensions, i);
       bool is_win =board[0][i] != blank_space && are_all_same(board[i], dimensions);
       free(cur_col);
       if(is_win){
        return true;
       } 
    }
    return false;
}
bool has_a_player_won_digonally(char** board, int dimensions, char blank_space){
    char* left_digonal = get_left_diagonal(board, dimensions);
    char* right_digonal = get_right_diagonal(board, dimensions);
    bool is_win = contains_win(left_digonal, dimensions, blank_space)||contains_win(right_digonal, dimensions, blank_space);
    free(left_digonal);
    free(right_digonal);
    return is_win;
}
char* get_left_diagonal(char** board, int dimensions){
    char* diagonal = (char*)malloc(dimensions * sizeof(char));
    for(int i =0; i < dimensions; ++i){
        diagonal[i] = board[i][i];
    }
    return diagonal;
}
char* get_right_diagonal(char** board, int dimensions){
    char* diagonal = (char*)malloc(dimensions * sizeof(char));
    for(int row =0, col = dimensions-1; row < dimensions; ++row, --col){
        diagonal[row] = board[row][col];
    }
    return diagonal;
}
char* get_column(char** board, int dimensions, int colunm_index){
    char* cur_col = (char*)malloc(dimensions*sizeof(char));
    for(int i=0; i<dimensions; ++i){
        cur_col[i] = board[i][colunm_index];
    }
    return cur_col;
}
bool contains_win(char* sequence, int length, char blank_space){
    return ; ///////////////////////////////fffffffffffffffffffffffffffffffffffff
}
bool are_all_same(char* str, int len){
    for(int i =1; i<len; ++i){
        if(str[i]!= str[0]){
            return false;
        }

    }
    return true;
}

bool is_tie_game(char** board, int dimensions, char blank_space){
    bool contains_blanks = false;
    for(int i=0; i<dimensions; ++i){
        for(int j=0; j<dimensions; ++j){
            if(board[i][j]==blank_space){
                return false;
            }
        }
    }
    return !has_a_player_won(board, dimensions, blank_space);
}

void play_game(char** board, int dimensions, char blank_space, char* player_pieces, int cur_player_turn){
    while(!is_game_over(board, dimensions, blank_space)){
        current_player_take_turn(board, dimensions, blank_space, player_pieces, cur_player_turn);
        switch_to_next_player();
    }
    announce_results();
}

void current_player_take_turn(char** board, int dimensions, char blank_space, char player_pieces, int cur_player_piece){
    int row, col;
    get_valid_player_spot_to_play(board, dimensions, blank_space);
    board[row][col]= cur_player_piece;

}
void get_valid_player_spot_to_play(char** board, int dimensions, char blank_space *row, int *col){
    int num_args_read;
    do{
        printf("Enter a spot to play in the form row col: ");
        scanf("%d %d", row, col);
    }while(!is_valid_spot_to_play(board, dimensions, blank_space, *row, *col, num_args_read));
}
bool is_valid_spot_to_play(char** board, int dimensions, char blank_space, int row, int col, int num_args_read){
    return isValidFormat(num_args_read, 2) && is_on_board(row, col, dimensions) && board[row][col] == blank_space;
}
bool is_on_board(int row, int col, int dimensions){
    is_between(row, 0, dimensions-1) && is_between(col, 0, dimensions-1);
}
bool is_between(int value, int min_value, int max_value){
    return value >= min_value && value <= max_value;
}
int main(){
    setup_game(dimensions, blank_space);
    play_game(board, dimensions, blank_space);
    return 0;
}