#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "play_game.h"
#include "winning.h"
#include "input_validation.h"

int switch_to_next_player(int cur_player_turn){
    /*
    Function switches player's turn
    @param cur_player_turn is the current player's turn
    @returns the next player's turn
    */
    if(cur_player_turn == 0){
        return 1;
    }else{
        return 0;
    }
}

void announce_results(char** board, int rows, int cols, char blank_space, int cur_player_turn, int win_pieces){
    /*
    Function shows the board, then says why the game ended
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param blank_space is the blank space character (*)
    @param cur_player_turn is the current player's turn
    @param win_pieces is the number of pieces needed to win    
    */
    display_board(board, rows, cols);
    if(has_a_player_won(board, rows, cols, blank_space, win_pieces)){
        if(cur_player_turn == 0){
            printf("Player 1 Won!");
        }else{
            printf("Player 2 Won!");
        }
    }else{
        printf("Tie game!");
    }
}

void play_game(char** board, int rows, int cols, int win_pieces, char blank_space, char* player_pieces, int cur_player_turn){
    /*
    Function plays the connect n game
    @param board is the board
    @param rows is the number of rows
    @param cols is the number of columns
    @param win_pieces is the number of pieces needed to win
    @param blank_space is the blank space character (*)
    @param player_pieces is the pieces of the players
    @param cur_player_turn is the current player's turn
    */
    while(true){
        current_player_take_turn(board, rows, cols, blank_space, cur_player_turn, player_pieces[cur_player_turn]);
        if(is_game_over(board, rows, cols, blank_space, win_pieces)){
            break;
        }
        cur_player_turn = switch_to_next_player(cur_player_turn);
    }
    announce_results(board, rows, cols, blank_space, cur_player_turn, win_pieces);
}

void current_player_take_turn(char** board, int rows, int cols, char blank_space, int cur_player_turn, char cur_players_piece){
    /*
        Player chooses an empty column on the grid
        Player places their piece on the lowest empty spot in the column
        @param board is the board
        @param rows is the number of rows
        @param cols is the number of columns
        @param blank_space is the blank space character (*)
        @param cur_player_turn is the current player's turn
        @param cur_player_piece is the piece of the current player
    */
    int col;
    int row;
    display_board(board, rows, cols);
    get_valid_player_spot_to_play(board, rows, cols, blank_space, cur_player_turn, &col);
    for (row = rows - 1; row >= 0; --row) {
        if (board[row][col] == blank_space) { 
            board[row][col] = cur_players_piece; 
            break; 
        }
    }
}

void  get_valid_player_spot_to_play(char** board, int rows, int cols, char blank_space, int cur_player_turn, int *col){
    /*
    checks to see if column chosen is valid to play
        @param board is the board
        @param rows is the number of rows
        @param cols is the number of columns
        @param blank_space is the blank space character (*)
        @param cur_player_turn is the current player's turn
        @param *col is the column chosen by the player
    */
    int num_args_read;
    do{
        printf("Enter a column between 0 and %d to play in: ", cols - 1);
        num_args_read = scanf("%d", col);
    }while(!is_valid_spot_to_play(board, rows, cols, blank_space, *col, num_args_read));
}

bool is_valid_spot_to_play(char** board, int rows, int cols, char blank_space, int col, int num_args_read){
    /* checks to see if valid spot to play
        @param board is the board
        @param rows is the number of rows
        @param cols is the number of columns
        @param blank_space is the blank space character (*)
        @param col is the column chosen by the player
        @param num_args_read is the number of arguments read
        @returns if the spot is valid
    */
    if (!isValidFormat(num_args_read, 1) || !is_on_board(col, cols)) {
        return false;
    }
    if (board[0][col] != blank_space) {
        return false;
    }
    return true;
}

bool is_on_board(int col, int cols){
    /*
    checks to see if spot is on the board
    @param col is the chosen column
    @param cols is the total number of columns
    @returns if the spot is on the board
    */
    return is_between(col, 0, cols-1);
}

bool is_between(int value, int min_value, int max_value){
    /*
        check if value is in [min_value, max_value], both inclusive
        @param value is the value that needs to between 2 numbers
        @param min_value is the lower bound
        @param max_value is the upper bound
        @returns if the value is between the two bounds
    */
    return value >= min_value && value <= max_value;
}