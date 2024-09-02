#ifndef WIN_H
  #define WIN_H
	#include <stdbool.h>
	#include "board.h"

	bool is_game_over(int row_played_in, int col_played_in,
		                Board board, int dimensions, char blank_char, int amt);

	bool has_someone_won(int row_played_in, int col_played_in,
									 	   Board board, int dimensions, char blank_char, int amt);

	bool is_horizontal_win(int row_played_in, Board board, int dimensions, char blank_char, int amt);
  bool is_vertical_win(int col_played_in, Board board, int dimensions, char blank_char, int amt);
	bool diagonal_win(int row_played_in, int col_played_in, Board board, int dimensions, int amt);
	bool left_diagonal_win(int row_played_in, int col_played_in, Board board, int dimensions, int amt);
	bool right_diagonal_win(int row_played_in, int col_played_in, Board board, int dimensions, int amt);
	bool is_in_right_diagonal(int row, int col, int dimensions);

	bool is_tie(Board board, int dimensions);

	bool all_same(char* values, int length);
	char* get_column(int col_index, Board board, int dimensions);
  bool in_a_row(char* values, int length, int amt);

#endif