#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "input_validation.h"
#include "setup_game.h"


void setup_game(int dimensions,
								Board *out_board,
							  char* *out_player_pieces,
							  int *out_cur_player_turn){
	const int num_players = 2;
	*out_board = build_board(dimensions);
	
}

bool is_one_of(char piece, char* player_pieces, int num_players){
	for(int i = 0; i < num_players; ++i){
		if(piece == player_pieces[i]){
			return true;
		}
	}
	return false;
}
