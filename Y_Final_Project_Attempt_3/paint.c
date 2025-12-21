#include <stdio.h>
#include <stdlib.h>
#include "backend.h"

void makeLine(struct Canvas *canvas, int start_row, int start_col, int end_row, int end_col) {
    /*
    Function makes a line based on user input
    @param canvas is the canvas
    @param start_row is the staring row of the line
    @param start_col is the starting column of the line
    @param end_row is the ending row of the line
    @param end_col is the ending column of the line
    */
    if(start_row==end_row && start_col == end_col){
        if(canvas->grid[start_row][start_col] == '/' ||canvas->grid[start_row][start_col] == '\\' ||canvas->grid[start_row][start_col] == '|' ||canvas->grid[start_row][start_col] == '+'){
            canvas->grid[start_row][start_col]= '+';
        }else{
            canvas->grid[start_row][start_col]= '-';
        }
    }
    if (start_row == end_row) { 
        char symbol = '-';
        int horz_start, horz_end;
        if (start_col < end_col){
            horz_start = start_col;
            horz_end = end_col;
        }else if(start_col > end_col){
            horz_start = end_col;
            horz_end = start_col;
        }
        for (int j = horz_start; j <= horz_end; j++) {
            if (canvas->grid[start_row][j] == '/' ||canvas->grid[start_row][j] == '\\'||canvas->grid[start_row][j] == '|'||canvas->grid[start_row][j] == '+') { // Check if the line intersects with another line
                canvas->grid[start_row][j] = '+';
            } else {
                canvas->grid[start_row][j] = symbol;
            }
        }
        
    } else if (start_col == end_col) {
        char symbol = '|';
        int vert_start, vert_end;
        if (start_row < end_row){
            vert_start = start_row;
            vert_end = end_row;
        }else if(start_row > end_row){
            vert_start = end_row;
            vert_end = start_row;
        }
        for (int i = vert_start; i <= vert_end; i++) {
            if (canvas->grid[i][start_col] == '/' || canvas->grid[i][start_col] == '\\' || canvas->grid[i][start_col] == '-'|| canvas->grid[i][start_col] == '+'){ // Check if the line intersects with another line
                canvas->grid[i][start_col] = '+';
            } else {
                canvas->grid[i][start_col] = symbol;
            }
        }
    } else if (abs(start_row - end_row) == abs(start_col - end_col)) { 
        char symbol;
        if (start_row < end_row) {
            if (start_col < end_col) {
                symbol = '/';
            } else { 
                symbol = '\\';
            }
        
        } else {
            if (start_col < end_col) {
                symbol = '\\';
            } else {
                symbol = '/';
            }
        }
        int row = start_row;
        int col = start_col;
        while (row != end_row && col != end_col) {
            if ((canvas->grid[row][col] == '-' || canvas->grid[row][col] == '|'|| canvas->grid[row][col] == '+')) { // Check if the line intersects with another line
                canvas->grid[row][col] = '+';
            }else if(symbol == '/' && canvas->grid[row][col]=='\\'){
                canvas->grid[row][col] = '+';
            }else if(symbol == '\\' && canvas->grid[row][col]=='/'){
                canvas->grid[row][col] = '+';
            }else {
                canvas->grid[row][col] = symbol;
            }
            row += (end_row > start_row) ? 1 : -1;
            col += (end_col > start_col) ? 1 : -1;
        }
        if ((canvas->grid[row][col] == '-' || canvas->grid[row][col] == '|'|| canvas->grid[row][col] == '+')) { // Check if the line intersects with another line
                canvas->grid[row][col] = '+';
            }else if(symbol == '/' && canvas->grid[row][col]=='\\'){
                canvas->grid[row][col] = '+';
            }else if(symbol == '\\' && canvas->grid[row][col]=='/'){
                canvas->grid[row][col] = '+';
            }else {
                canvas->grid[row][col] = symbol;
            }
    } else {
        printf("Improper draw command");
    }
}


void eraseCell(struct Canvas *canvas, int row, int col) {
    /*
    Function erases a point in the canvas
    @param canvas is the canvas
    @param row is the row coordinate to be erased
    @param col is the column coordinate to be erased
    */
 
    if (row < 0 || row >= canvas->rows || col < 0 || col >= canvas->cols) {
        printf("Invalid coordinates for erasing a cell.\n");
        return;
    }

    canvas->grid[row][col] = '*';
}