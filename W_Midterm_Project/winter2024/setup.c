#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setup.h"
#include "input_validation.h"
#include "board.h"

char* pick_player_pieces(char blank_space) {
    /*
    function assigns x to player 1 and o to player 2
    @param blank_space is the blank space character (*)
    @returns the player's pieces
    */
    const int num_players = 2;
    char* player_pieces = (char*)malloc(num_players * sizeof(char));
    player_pieces[0] = 'X';
    player_pieces[1] = 'O';
    return player_pieces;
}

void setup_game(int rows, int cols, int win_pieces, char blank_space, char** *out_board, char* *out_player_pieces, int *out_starting_player){
    /*
    function makes the board, picks the player pieces, picks who goes first
        @param rows is the number of rows
        @param cols is the number of columns
        @param win_pieces is the number of pieces needed to win
        @param blank_space is the blank space character (*)
        @param *out_board is the pointer to the board
        @param *out_player_pieces is the pointer to the player's pieces
        @param *out_starting_player is the pointer to the starting player
    */
    *out_board = make_grid(rows, cols, blank_space);
    *out_player_pieces = pick_player_pieces(blank_space);
    *out_starting_player = 0;
}

void clean_up(char** board, int dimensions, char* player_pieces){
    /*
    frees memory when game is done
    @param board is the board
    @param dimensions is the number of rows in the board
    @param player_pieces are the pieces of the players
    */
    destroy_board(board, dimensions);
    free(player_pieces);
}