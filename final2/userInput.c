#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "paint.h"
#include "backend.h"

struct Input {
    char type;  // 'i' for integer, 'c' for character
    int value;  // Value if type is integer, ASCII value if type is character
};

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
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void userInput(struct Canvas *canvas) {
    char command;
    int startRow, startCol, endRow, endCol, pos, newRows, newCols;
    char type;
    char fileName[100];

    struct Input inputs[100];
    

    char input[50];
    printf("Enter your command: ");
    int input_count = 0;
    while (input_count < 100) {
        if (!fgets(input, sizeof(input), stdin) || input[0] == '\n') {
            break; // Exit loop if input is not read or 'q' or new line is entered
        }

        // Find the first non-whitespace character
        int i = 0;
        while (isspace(input[i])) {
            i++;
        }

        if (isdigit(input[i]) || (input[i] == '-' && isdigit(input[i + 1]))) {
            // Input is an integer
            inputs[input_count].type = 'i';
            inputs[input_count].value = atoi(input + i); // Convert only after skipping whitespace
        } else if (isalpha(input[i])) {
            // Input is a character
            inputs[input_count].type = 'c';
            inputs[input_count].value = input[i];
        }

        input_count++;
    }

    if(!(inputs[0].type = 'c')){
        command = '1';
    }else{
        command = inputs[0].value;
    }

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
                    printf("Please fix line 45 userInput.c");//error msg
                }
            }else{
                printf("Fix line 48, userinput.c");//error
            }
            break;
        case 'e':
            if (scanf("%d %d", &startRow, &startCol) == 2) {
                if(isBigZero(startRow) && isBigZero(startCol)){
                    eraseCell(canvas, startRow, startCol);
                }else{
                    printf("56, userinput.c");
                }
            }else{
                printf("59 userinput.c");
            }
            break;
        case 'r':
            if(scanf("%d %d", &newRows, &newCols) == 2) {
                if (isBigZero(newRows) && isBigZero(newCols)){
                    resize(canvas, newRows, newCols);
                }else{
                    printf("67 userinput");
                }
            }else{
                printf("70 userinput");
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
            if (scanf(" %c %d", &type, &pos) == 2) {
                if ((type == 'r' || type == 'c') && isBigZero(pos)) {
                    deleteRC(canvas, type, pos);
                } else {
                    printf("89 userinput");
                }
            } else {
                printf("92 user input");
            }
            break;
        case 's':
            if (scanf("%s", fileName) == 1) {
                saveCanvas(canvas, fileName);
            } else {
                printf("99 userinput");
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