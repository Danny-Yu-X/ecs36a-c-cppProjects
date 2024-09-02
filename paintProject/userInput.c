#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "paint.h"
#include "backend.h"

void print_help(){
    /*
    function prints the help text box
    */

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
    /*
    function checks if a number is at least zero
    @param num is the number being checked
    @returns if the number is at least zero
    */
    return num >= 0; 
}
void clearBuffer() {
    /*
    function clears the input buffer
    */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void userInput(struct Canvas *canvas) {
    /*
    function processes the user's input
    @param canvas is the canvas
    */
    char command;
    int startRow, startCol, endRow, endCol, pos, newRows, newCols;
    char type;
    char fileName[100];

    printf("Enter your command: ");
    scanf(" %c", &command);

    switch (command){
        case 'q':
            freeCanvas(canvas);
            exit(0);
        case 'h':
            print_help();
            break;
        case 'w':
            if(scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol) == 4) {
                if(isBigZero(startRow) && isBigZero(startCol) && isBigZero(endRow) && isBigZero(endCol)) {
                    makeLine(canvas, startRow, startCol, endRow, endCol);
                } else {
                    printf("Improper draw command.\n");
                }
            }else{
                printf("Improper draw command.\n");
            }
            break;
        case 'e':
            if (scanf("%d %d", &startRow, &startCol) == 2) {
                if(isBigZero(startRow) && isBigZero(startCol)){
                    eraseCell(canvas, startRow, startCol);
                }else{
                    printf("Improper erase command.\n");
                }
            }else{
                printf("Improper erase command.\n");
            }
            break;
        case 'r':
            if(scanf("%d %d", &newRows, &newCols) == 2) {
                if (isBigZero(newRows) && isBigZero(newCols)){
                    resize(canvas, newRows, newCols);
                }else{
                    printf("Improper resize command.\n");
                }
            }else{
                printf("Improper resize command.\n");
            }
            break;
        case 'a':
            if (scanf(" %c %d", &type, &pos) == 2) {
                if ((type == 'r' || type == 'c') && isBigZero(pos)) {
                    add(canvas, type, pos);
                } else {
                    printf("Improper add command.\n");
                }
            } else {
                printf("Improper add command.\n");
            }
            break;
        case 'd':
            if (scanf(" %c %d", &type, &pos) == 2) {
                if ((type == 'r' || type == 'c') && isBigZero(pos)) {
                    deleteRC(canvas, type, pos);
                } else {
                    printf("Improper delete command.\n");
                }
            } else {
                printf("Improper delete command.\n");
            }
            break;
        case 's':
            if (scanf("%s", fileName) == 1) {
                saveCanvas(canvas, fileName);
            } else {
                printf("Improper save command or file could not be created.\n");
            }
            break;
        case 'l':
            scanf("%s", fileName);
            loadCanvas(canvas, fileName);
            break;
        default:
            clearBuffer();
            break;    
    }

}