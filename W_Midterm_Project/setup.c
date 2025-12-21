#include <stdio.h>
#include <stdlib.h>
#include "setup.h"

char* pick_player_pieces(){
    const int num_players = 2;
    char* player_pieces = (char*)malloc(num_players*sizeof(char));
    player_pieces[0] = 'X';
    player_pieces[1] = 'O';
    return player_pieces;
}

char** make_grid(int numRows, int numCols){
    // nxn grid
    numRows += 1;
    numCols += 1;
    char** board = (char*)malloc(numRows * numCols * sizeof(char*));
    for(int i = 0; i < numRows-1; ++i){
        board[i] = (char*)malloc(numRows * sizeof(char));
        for(int j = 1; j < numCols; ++j){
            board[i][j] = '*';
        }
    }
    for(int i = 0; i < numRows-1;++i){
        board[0][i] = numRows - (i+2);
    }
    for(int i = 1; i < numCols;++i){
        board[numRows][i] =(i-2);
    }
    board[numRows][0]= NULL;
    return board;
}

int get_start_player_turn(){
    return 0;
}

void setup_game(int numRows, int numCols, char blank_char, char** *out_board, int *out_start_player_turn, char* *out_player_pieces){
    char** board = make_grid(numRows, numCols);
    int player_turn = get_start_player_turn();
    char* player_pieces = pick_player_pieces();
    *out_board = board;
    *out_start_player_turn = player_turn;
    *out_player_pieces = player_pieces;
}