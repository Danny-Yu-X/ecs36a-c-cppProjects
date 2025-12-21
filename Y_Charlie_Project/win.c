#include <stdbool.h>
#include <stdlib.h>

#include "board.h"
#include "win.h"

bool is_game_over(int row_played_in, int col_played_in,
	Board board, int dimensions, char blank_char, int amt){
	return has_someone_won(row_played_in, col_played_in, board, dimensions, blank_char, amt) ||
	 is_tie(board, dimensions);
}

 bool has_someone_won(int row_played_in, int col_played_in,
	 Board board, int dimensions, char blank_char, int amt){
	 return is_horizontal_win(row_played_in, board, dimensions, blank_char, amt) ||
	 				is_vertical_win(col_played_in, board, dimensions, blank_char, amt) ||
					diagonal_win(row_played_in, col_played_in, board, dimensions, amt);
 }

bool is_horizontal_win(int row_played_in, Board board, int dimensions, char blank_char, int amt){
	return in_a_row(board[row_played_in], dimensions, amt);
}

bool is_vertical_win(int col_played_in, Board board, int rows, int cols, char blank_char, int amt){
	char* column = get_column(col_played_in, board, rows, cols);
	bool win_found = in_a_row(column, rows, cols, amt);
	free(column);
	return win_found;
}

bool in_a_row(char* values, int length, int amt){
  int count = 0;
  for (int i = 0; i < length; i++){
    if (values[i] == values[i + 1]){
      count++;
    }
    if (count == amt){
      return true;
    }
  }
  return false;
}

char* get_column(int col_index, Board board, int rows, int cols){
	char* column = (char*)calloc(rows, sizeof(char));
	for(int i = 0; i < cols; ++i){
		column[i] = board[i][col_index];
	}
	return column;
}

bool diagonal_win(int row_played_in, int col_played_in, Board board, int rows, int cols, int amt){
	return left_diagonal_win(row_played_in, col_played_in, board, rows, cols, amt) ||
				 right_diagonal_win(row_played_in, col_played_in, board, rows, cols, amt);
}

bool left_diagonal_win(int row_played_in, int col_played_in, Board board, int rows, int cols, int amt){
	/* Left diagonal win looks like
    X
		  X
			  X
          X
            X
              X
	*/
  int count = 0;
  bool stop = false;
  
  for (int i = row_played_in; i < rows && !stop; i--){
    for (int j = col_played_in; j < cols && !stop; j--){
      if (board[row_played_in][col_played_in] == board[row_played_in-1][col_played_in-1]){
        count++;
      }
      else {
        stop = true;
      }
    }
  }
  
  stop = false;
  
  for (int i = row_played_in; i < rows && !stop; i++){
    for (int j = col_played_in; j < cols && !stop; j++){
      if (board[row_played_in][col_played_in] == board[row_played_in+1][col_played_in+1]){
        count++;
      }
      else{
        stop = true;
      }
    }
  }
  
  if (count >= amt) {
    return true;
  }
  
  return false;
}

bool right_diagonal_win(int row_played_in, int col_played_in, Board board, int rows, int cols, int amt){
	/* right diagonal win looks like
        X
		  X
		X
	*/

  int count = 0;
  bool stop = false;
  
  for (int i = row_played_in; i < rows && !stop; i--){
    for (int j = col_played_in; j < cols && !stop; j++){
      if (board[row_played_in][col_played_in] == board[row_played_in-1][col_played_in+1]){
        count++;
      }
      else {
        stop = true;
      }
    }
  }
  
  stop = false;
  
  for (int i = row_played_in; i < rows && !stop; i++){
    for (int j = col_played_in; j < cols && !stop; j--){
      if (board[row_played_in][col_played_in] == board[row_played_in+1][col_played_in-1]){
        count++;
      }
      else{
        stop = true;
      }
    }
  }
  
  if (count >= amt) {
    return true;
  }
  
  return false;

	if(is_in_right_diagonal(row_played_in, col_played_in, dimensions)){ // if we played in right digaonl
		const char upper_right_corner = board[0][dimensions - 1];
		for(int i = 0; i < dimensions; ++i){
			if(board[i][dimensions - i - 1] != upper_right_corner){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

bool is_in_right_diagonal(int row, int col, int dimensions){
	return row + col == dimensions - 1;
}

bool is_tie(Board board, int rows, int cols){
	/*
   check if there is a tie. You must check if someone won first before calling
	 this function!!! If you don't and the final piece played fills up the board
	 but also wins, this function will incorrectly detect it as a tie.
	*/
  
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			if(board[i][j] == '*'){
				return false;
			}
		}
	}
  
	return true;
}