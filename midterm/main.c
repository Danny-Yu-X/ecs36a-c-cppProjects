#include <stdio.h>
#include <stdbool.h>
#include "validation.h"
#include "setup.h"

int main(){
    int numRows, numCols, neededToWin;
    char blank_char = '*';
    char** board;
    char* player_pieces;
    int player_turn;
    int num_args_read = scanf("%d, %d, %d", &numRows, &numCols, &neededToWin);
    if(isValidFormatExit(3, num_args_read, true)&& numRows >0 && numCols >0 && neededToWin >0){
        setup_game(numRows, numCols, blank_char, &board, &player_turn, &player_pieces);
        play_game(board, numRows, numCols, blank_char, player_turn, player_pieces, neededToWin);
    }else if(num_args_read<3){
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(1);
    }else if(num_args_read>3){
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(1);
    }else{
        printf("Invalid number\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(1);
    }

    clean_up(board, numRows, numCols, player_pieces);
    
    return 0;
}