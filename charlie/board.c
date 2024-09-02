#include <stdlib.h>
#include <stdio.h>
#include "board.h"

Board build_board(int rows, int cols){
	//make the rows
	Board board = (Board)calloc(rows, sizeof(char*));
	for(int row = 0; row < rows; ++row){
		board[row] = (char*)calloc(cols, sizeof(char));
		for(int col = 0; col < cols; ++col){
			board[row][col] = '*';
		}
	}
	return board;
}

void print_board(Board board, int rows, int cols){

	for(int i = 0; i < rows; ++i){
		printf("%d ", i);
		for(int j = 0; j < cols; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

  printf("  ");
	for(int i = 0; i < cols; ++i){
		printf("%d ", i);
	}
	printf("\n");
}

void delete_board(Board board, int rows, int cols){
	for(int i = 0; i < rows; ++i){
		free(board[i]);
	}
	free(board);
}