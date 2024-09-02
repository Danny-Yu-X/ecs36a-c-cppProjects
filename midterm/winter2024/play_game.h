#ifndef PLAY_GAME_H
    #define PLAY_GAME_H
    #include <stdbool.h>
    void play_game(char** board, int rows, int cols, int win_pieces, char blank_space, char* player_pieces, int cur_player_turn);

    int switch_to_next_player(int cur_player_turn);
    void announce_results(char** board, int rows, int cols, char blank_space, int cur_player_turn, int win_pieces);
    void current_player_take_turn(char** board, int rows, int cols, char blank_space, int cur_player_turn, char cur_players_piece);
    void get_valid_player_spot_to_play(char** board, int rows, int cols, char blank_space, int cur_player_turn, int *col);
    bool is_valid_spot_to_play(char** board, int rows, int cols, char blank_space, int col, int num_args_read);
    bool is_on_board(int col, int cols);
    bool is_between(int value, int min_value, int max_value);
#endif 