#ifndef PLAY_GAME_H
	#define PLAY_GAME_H

	#include <stdbool.h>
	#include "board.h"
	void play_tic_tac_toe();
	void play_game(Board board, int dimensions, char blank_char, char* player_pieces,
								int cur_player_turn);

	void get_valid_move(int *row, int *col, Board board, int dimensions, char blank_char);
	bool is_valid_move(int row, int col, Board board, int dimensions, char blank_char);
	bool is_on_board(int row, int col, int dimensions);
	void do_move(char piece, int row_played_in, int col_played_in, Board board);

	void change_turn(int *cur_player_turn);
	void announce_results(int player_num,
	 											int row_played_in, int col_played_in,
										 	  Board board, int dimensions, char blank_char);
#endif