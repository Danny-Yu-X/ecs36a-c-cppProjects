#include <stdio.h>
#include <stdbool.h>

char** make_grid(int dimensions, char blank_space){
    // nxn grid
    char** board = (char*)malloc(dimensions * sizeof(char*));
    for(int i = 0; i < dimensions; ++i){
        board[i] = (char*)malloc(dimensions * sizeof(char));
        for(int j=0; j < dimensions; ++j){
            board[i][j] = blank_space;
        }
    }
    return board;
}

char* pick_player_pieces(char blank_space){
    const int num_players = 2;
    char* player_pieces = (char*)malloc(num_players*sizeof(char));
    for(int i = 0; i < num_players; ++i){
        player_pieces[i] = pick_piece(blank_space, player_pieces, i);

    }
    return player_pieces;
}
char pick_piece(char blank_space, char* player_pieces, int num_player_pieces){
    char player_piece;
    int nar;
    do{
        printf("Player %d pick a piece: ");
        nar = scanf(" %c", &player_piece);
    }while(!is_valid_piece(nar, player_piece, blank_space, player_pieces, num_player_pieces));
    return player_piece;
}

bool is_valid_piece(int nar, char player_piece, char blank_space, char* player_pieces, int num_player_pieces){
    isValidFormat(nar, 1) &&
        player_piece != blank_space && !is_in(player_piece, player_pieces, num_player_pieces);
}

bool is_in(char letter, const char* str, int len){
    for(int i=0; i <len; ++i){
        if(str[i]==letter){
            return true;
        }
    }
    return false;
}
void setup_game(int dimensions,char blank_space){
    srand(3);
    char** board = make_grid(dimensions, blank_space);
    char* player_pieces = pick_player_pieces(blank_space);
    int starting_player = pick_starting_player();

}

int pick_starting_player(){
    // 0 = P1, 1 = P2
    return rand() % 2;
}