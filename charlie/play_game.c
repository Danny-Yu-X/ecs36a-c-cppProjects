#include "input_validation.h"
#include "play_game.h"
#include "board.h"
#include "win.h"

void play_tic_tac_toe(){

	Board board;
	char* player_pieces;
	int cur_player_turn, num_rows, num_cols, amt;

  scanf(" %d", &num_rows);
  scanf(" %d", &num_cols);
  scanf(" %d", &amt);
  
  
	setup_game(num_rows, num_cols, &board, &player_pieces, &cur_player_turn);
	play_game(board, dimensions, player_pieces, cur_player_turn);
	delete_board(board, dimensions);
}

void play_game(Board board, int rows, int cols, char* player_pieces,
							int cur_player_turn){
	int row_played_in, col_played_in;
	do{
		print_board(board, dimensions);
		get_valid_move(&row_played_in, &col_played_in, board, dimensions);
		do_move(player_pieces[cur_player_turn - 1], row_played_in, col_played_in, board);
		change_turn(&cur_player_turn);
	}while(!is_game_over(row_played_in, col_played_in, board, dimensions));
	print_board(board, dimensions);
	change_turn(&cur_player_turn); // make it go back to the player's turn that ended the game
	announce_results(cur_player_turn, row_played_in, col_played_in, board, dimensions);
}

void get_valid_move(int *row, int *col, Board board, int dimensions, char blank_char){
	int num_args_read;
	const int num_args_needed = 2;
	do{
		printf("Enter a move in the form row, col: ");
		num_args_read = scanf("%d , %d", row, col);
	}while(!(isValidFormat(num_args_read,num_args_needed) &&
					 is_valid_move(*row,  *col, board, dimensions, blank_char)));
}

bool is_valid_move(int row, int col, Board board, int dimensions, char blank_char){
	return is_on_board(row, col, dimensions) && board[row][col] == blank_char;
}

bool is_on_board(int row, int col, int dimensions){
	return row >= 0 && row < dimensions && col >= 0 && col < dimensions;
}

void do_move(char piece, int row_played_in, int col_played_in, Board board){
	board[row_played_in][col_played_in] = piece;
}

void announce_results(int player_num,
											int row_played_in, int col_played_in,
											Board board, int dimensions, char blank_char){
	if(has_someone_won(row_played_in, col_played_in, board, dimensions, blank_char)){
		printf("Player %d won!\n", player_num);
	}else{
		printf("Tie game.\n");
	}
}