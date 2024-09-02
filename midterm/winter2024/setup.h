#ifndef SETUP_H
    #define SETUP_H
    #include <stdbool.h>
    void setup_game(int rows, int cols, int win_pieces, char blank_space, char** *out_board, char* *out_player_pieces, int *out_starting_player);
    void clean_up(char** board, int dimensions, char* player_pieces);
    char* pick_player_pieces(char blank_space);
#endif