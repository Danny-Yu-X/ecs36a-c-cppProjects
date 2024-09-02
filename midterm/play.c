#include <stdio.h>
#include <stdbool.h>

void play_game(char** board, int numRows, int numCols, char blank_char, int player_turn, char* player_pieces, int neededToWin){
    int cur_player_turn = player_turn;
    const int num_players = 2;
    while(!is_game_over(board, numRows, numCols, blank_char, neededToWin)){
        current_player_take_turn(board, numRows, numCols, blank_char, player_pieces, cur_player_turn);
        switch_to_next_player();
    }
    announce_results();
}

void current_player_take_turn(char** board, int numRows, int numCols, char blank_space, int cur_player_turn, char cur_player_piece){
    int row, col;
    get_valid_player_spot_to_play(board, numRows, numCols, blank_space, cur_player_turn, &row, &col);
    board[row][col]= cur_player_piece;

}

void get_valid_player_spot_to_play(char** board, int numRows, int numCols, char blank_space, int cur_player_turn, int *row, int *col){
    int num_args_read;
    do{
        printf("Enter a column between 0 and %d: ", numCols-2);
        scanf("%d", col);
    }while(!is_valid_spot_to_play(board, numRows, numCols, blank_space, *row, *col, num_args_read));
}
bool is_valid_spot_to_play(char** board, int numRows, int numCols, char blank_space, int row, int col, int num_args_read){
    return isValidFormat(num_args_read, 1) && is_on_board(row, col, numRows, numCols) && board[row][col] == blank_space;
}
bool is_on_board(int row, int col, int numRows, int numCols){
    is_between(row, 0, numRows-2) && is_between(col, 0, numCols-2);
}
bool is_between(int value, int min_value, int max_value){
    return value >= min_value && value <= max_value;
}