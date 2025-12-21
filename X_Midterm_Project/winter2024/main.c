/*
Group: Ian Marwong, Danny Yu
This program allows the user to play connectn where the user can set the dimensions of the board and the win condition
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup.h"
#include "play_game.h"

int get_dimensions_from_command_line(int argc, char** argv, int* rows, int* cols, int* win_pieces) {
    /*
    Function gets the dimensions and win condition from the user/terminal
    @param argc is the number of arguments entered
    @param argv is the type of the arguments entered
    @param rows is the number of rows
    @param cols is the number of columns
    @param win_pieces is the number of pieces needed to win
    */
    if (argc < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if (argc > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    if (sscanf(argv[1], "%d", rows) != 1 || sscanf(argv[2], "%d", cols) != 1 || sscanf(argv[3], "%d", win_pieces) != 1) {
        printf("Invalid argument(s)\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    return 0;
}

int main(int argc, char** argv) {
    const char blank_space = '*';
    int rows, cols, win_pieces;
    
    get_dimensions_from_command_line(argc, argv, &rows, &cols, &win_pieces);

    char** board;
    char* player_pieces;
    int cur_player_turn;

    setup_game(rows, cols, win_pieces, blank_space, &board, &player_pieces, &cur_player_turn);
    play_game(board, rows, cols, win_pieces, blank_space, player_pieces, cur_player_turn);
    clean_up(board, rows, player_pieces);

    return 0;
}
