bool is_game_over(char** board, int numRows, int numCols, char blank_char, int neededToWin){
    return has_a_player_won(board, numRows, numCols, blank_char, neededToWin)||is_tie_game();
}

bool has_a_player_won(char** board, int numRows, int numCols, char blank_space, int neededToWin){
    return has_a_player_won_horizontally(board, numRows, numCols, blank_space, neededToWin) || 
        has_a_player_won_vertically(board, numRows, numCols, blank_space, neededToWin) || 
        has_a_player_won_digonally(board, numRows, numCols, blank_space, neededToWin);
}

bool has_a_player_won_horizontally(char** board, int numRows, int numCols, char blank_space, int neededToWin){
    for(int i=0; i < numRows-1; ++i){
        if(board[i][0] != blank_space && are_all_same(board[i], dimensions)){
            return true;
        }
    }
    return false;
}