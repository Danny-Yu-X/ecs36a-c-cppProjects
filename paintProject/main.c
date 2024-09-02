/*
Group: Ian Marwong, Danny Yu
Program is a text based version of paint that updates a canvas based on user input
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "backend.h"
#include "userInput.h"

int main(int argc, char *argv[]) {
    bool defaultCanvas = false;
    struct Canvas *canvas = (struct Canvas *)malloc(sizeof(struct Canvas));
    if (argc == 3){
        if(atoi(argv[1])>=1){
            if(atoi(argv[2])>=1){
                int rows = atoi(argv[1]);
                int cols = atoi(argv[2]);
                makeCanvas(canvas, rows, cols);
            }else{
                printf("The number of columns is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                defaultCanvas = true;
            }
            
        }else{
            printf("The number of rows is less than 1.\n");
            printf("Making default board of 10 X 10.\n");
            defaultCanvas = true;
        }
    }else if(argc == 1){
        defaultCanvas = true;
    }else{
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        defaultCanvas = true;
    }
    if(defaultCanvas == true){
        makeCanvas(canvas, 10, 10);
    }
    while(true){
        outputCanvas(canvas);
        userInput(canvas);
    }
    return 0;
}
