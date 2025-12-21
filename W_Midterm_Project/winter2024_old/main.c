
#include "setup.h"
#include "winning.h"


void play_game(char** board, int dimensions, char blank_space, char* player_pieces, int cur_player_turn){
    while(!is_game_over(board, dimensions, blank_space)){
        current_player_take_turn(board, dimensions, blank_space, cur_player_turn, player_pieces[cur_player_turn]);
        switch_to_next_player(cur_player_turn);
    }
    announce_results();
}

int switch_to_next_player(int cur_player_turn){
    if(cur_player_turn ==0){
        return 1;
    }else{
        return 0;
    }
    
}

void current_player_take_turn(char** board, int dimensions, char blank_space, int cur_player_turn, char cur_players_piece){
    /*
        Player chooses an empty spot on the grid
        Player places their piece on the chosen spot
    */
    int row, int col;
    get_valid_player_spot_to_play(board, dimensions, blank_space, cur_player_turn, &row, &col);
    board[row][col] = cur_players_piece; 

}

void  get_valid_player_spot_to_play(char** board, int dimensions, char blank_space, int cur_player_turn, int *row, int *col, ){
    int num_args_read;
    do{
        printf("Player %d enter a spot to play in the form row col: ", cur_player_turn);
        num_args_read = scanf("%d %d", row, col);
    }while(!is_valid_spot_to_play(board, dimensions, blank_space, *row, *col, num_args_read));
}

bool is_valid_spot_to_play(char** board, int dimensions, char, blank_space, int row, int col, int num_args_read){
    return isValidFormat(num_args_read, 2) && 
           is_on_board(row, col, dimensions) && board[row][col] == blank_space
}

bool is_on_board(int row, int col, int dimensions){
    return is_between(row, 0, dimensions - 1) && is_between(col, 0, dimensions -1);
}

bool is_between(int value, int min_value, int max_value){
    /*
        check if value is in [min_value, max_value], both inclusive
    */
    return value >= min_value && value <= max_value;
}
int get_dimensions_from_command_line(int argc, char** argv){
    int dimensions = 3;
    int num_args_read;
    char should_be_empty;
    if(argc != 2){
        return dimensions;
    }

    num_args_read = sscanf(argv)
}
int main(int argc, int** argv){
    char blank_space = '*';
    int dimensions = get_dimensions_from_command_line();
    char** board;
    char* 
    setup_game(dimensions, blank_space);
    play_game(board, dimensions, player_pieces, cur_player_turn);
    return 0;
}