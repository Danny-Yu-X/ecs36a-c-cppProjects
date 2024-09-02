#ifndef BOARD_H
  #define BOARD_H
	typedef char** Board;
	Board build_board(int num_rows, int num_cols);
	void print_board(Board board, int num_rows, int num_cols);
	void delete_board(Board board, int num_rows, int num_cols);
#endif