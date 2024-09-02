#ifndef SETUP_H
  #define SETUP_H

	#include <stdbool.h>
	#include "board.h"


	void setup_game(int dimensions, char blank_char,
									Board *out_board,
								  char* *out_player_pieces,
								  int *out_cur_player_turn);

	char* players_pick_pieces(int num_players_in_the_game, char blank_char);
	char player_pick_piece(int player_num, char* player_pieces, char blank_char);
	bool is_valid_piece(char piece, char* player_pieces, int num_players, char blank_char);
	bool is_one_of(char piece, char* player_pieces, int num_players);
	int pick_who_goes_first();
#endif