#ifndef SETUP_H
    #define SETUP_H
    #include <stdbool.h>

    char* pick_player_pieces();
    char** make_grid(int numRows, int numCols);
    int get_start_player_turn();
    void setup_game(int numRows, int numCols, char blank_char, char** *out_board, int *out_start_player_turn, char* *out_player_pieces);

#endif