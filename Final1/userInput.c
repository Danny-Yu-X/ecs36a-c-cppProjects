#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "paint.h"
#include "backend.h"

bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line) {
    /*
    Checks to make sure user input in formatted properly
    @param num_args_needed: the number of arguments that should be present
    @param num_args_read: the number of arguments that was given by the user
    @param should_be_the_last_value_on_line: checks to see if last value on line should be new line
    @returns: whether the format is valid or not
    */
	 bool format_is_correct = num_args_read == num_args_needed;
	 if(should_be_last_value_on_line){
		char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && (should_be_newline == '\n' || should_be_newline == '\t');
	 }
	 return format_is_correct;
 }

void print_help(){

  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

bool isBigZero(int num) {
    return num >= 0; 
}

void clearBuffer() {
    while (getchar() != '\n');
}

void userInput(struct Canvas *canvas) {
    char command;
    int startRow, startCol, endRow, endCol, pos, newRows, newCols, num_args_read;
    char type;
    char fileName[100];

    printf("Enter your command: ");
    num_args_read = (scanf(" %c", &command));
    // if(!isValidFormat(1, num_args_read, false)){
    //     command = '1';
    // }
    switch (command){
        case 'q':
            freeCanvas(canvas);
            exit(0);
        case 'h':
            print_help();
            clearBuffer();
            break;
        case 'w':
            num_args_read = (scanf(" %d %d %d %d", &startRow, &startCol, &endRow, &endCol));
            if(isValidFormat(4, num_args_read, true)) {
                if(isBigZero(startRow) && isBigZero(startCol) && isBigZero(endRow) && isBigZero(endCol)) {
                    makeLine(canvas, startRow, startCol, endRow, endCol);
                } else {
                    printf("Please fix line 45 userInput.c");//error msg
                }
            }else{
                printf("Improper draw command.");//error
                clearBuffer();
            }
            break;
        case 'e':
            num_args_read = scanf(" %d %d", &startRow, &startCol);
            if( isValidFormat(2, num_args_read, true)) {
                if(isBigZero(startRow) && isBigZero(startCol)){
                    eraseCell(canvas, startRow, startCol);
                }else{
                    printf("56, userinput.c");
                }
            }else{
                printf("Improper erase command.");
                clearBuffer();
            }
            break;
        case 'r':
            num_args_read = scanf(" %d %d", &newRows, &newCols);
            if(isValidFormat(2, num_args_read, true)) {
                if (isBigZero(newRows) && isBigZero(newCols)){
                    resize(canvas, newRows, newCols);
                }else{
                    printf("67 userinput");
                }
            }else{
                printf("Improper resize command.");
                clearBuffer();
            }
            break;
        case 'a':
            if (scanf(" %c %d", &type, &pos) == 2) {
                if ((type == 'r' || type == 'c') && isBigZero(pos)) {
                    add(canvas, type, pos);
                } else {
                    printf("78 userinput");
                }
            } else {
                printf("81 userinput");
            }
            break;
        case 'd':
            num_args_read = scanf(" %c %d", &type, &pos);
            if( isValidFormat(2, num_args_read, true)) {
                if ((type == 'r' || type == 'c') && isBigZero(pos)) {
                    deleteRC(canvas, type, pos);
                } else {
                    printf("89 userinput");
                }
            } else {
                printf("Improper delete command.");
                clearBuffer();
            }
            break;
        case 's':
            if (scanf(" %s", fileName) == 1) {
                saveCanvas(canvas, fileName);
            } else {
                printf("99 userinput");
            }
            break;
        case 'l':
            scanf(" %s", fileName);
            loadCanvas(canvas, fileName);
            break;
        default:
            printf("Unrecognized command. Type h for help.");
            clearBuffer();
            break;    
    }

}