#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"


void outputCanvas(struct Canvas *canvas) {
    /*
    Function prints canvas to the screen
    @param canvas is the canvas
    */
    for (int i = canvas->rows - 1; i >= 0; i--) {
        printf("%d ", i);
        
        for (int j = 0; j < canvas->cols; j++) {
            printf("%c ", canvas->grid[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int j = 0; j < canvas->cols; j++) {
        printf("%d ", j);
    }
    printf("\n");
}




void resize(struct Canvas *canvas, int newRows, int newCols) {
   /*
   function resizes the canvas
   @param canvas is the canvas
   @param newRows is the new number of rows that are needed
   @param newCols is the new number of columns that are needed
   */
    char **newGrid = (char **)malloc(newRows * sizeof(char *));

    for (int i = 0; i < newRows; i++) {
        newGrid[i] = (char *)malloc(newCols * sizeof(char));
        for (int j = 0; j < newCols; j++) {
            newGrid[i][j] = '*'; 
        }
    }

    int minRows = (canvas->rows < newRows) ? canvas->rows : newRows; 
    int minCols = (canvas->cols < newCols) ? canvas->cols : newCols;
    for (int i = minRows - 1; i >= 0; i--) {
        for (int j = 0; j < minCols; j++) {
            if(newRows< canvas->rows){
                newGrid[newRows - minRows + i][j] = canvas->grid[i][j];
            }else if(newRows > canvas->rows){
                newGrid[newRows - (minRows -i+3)][j] = canvas->grid[i][j];
            }
        }
    }
    
    for (int i = 0; i < canvas->rows; i++) {
        free(canvas->grid[i]);
    }
    free(canvas->grid);
    
    canvas->rows = newRows;
    canvas->cols = newCols;
    canvas->grid = newGrid;
}

void addRow(struct Canvas *canvas, int position) {
    /*
    function adds a row at a given spot
    @param canvas is the canvas
    @param position is where the new row is to be added
    */

        canvas->grid = (char **)realloc(canvas->grid, (canvas->rows + 1) * sizeof(char *));
        
        for (int i = canvas->rows; i > position; i--) {
            canvas->grid[i] = canvas->grid[i - 1];
        }
        canvas->grid[position] = (char *)malloc(canvas->cols * sizeof(char));
         
        for (int j = 0; j < canvas->cols; j++) {
            canvas->grid[position][j] = '*';
        }
        canvas->rows++;
}

void addCol (struct Canvas *canvas, int position) {
    /*
    function adds a column at the given spot
    @param canvas is the canvas
    @param position is where the column is going to be added
    */
    
        for (int i = 0; i < canvas->rows; i++) {
            canvas->grid[i] = (char *)realloc(canvas->grid[i], (canvas->cols + 1) * sizeof(char));

            for (int j = canvas->cols; j > position; j--) {
                canvas->grid[i][j] = canvas->grid[i][j - 1];
            }
     
            canvas->grid[i][position] = '*';
        }
        canvas->cols++;
}

void add(struct Canvas *canvas, char type, int position) {
    /*
    function adds a row or column to the canvas
    @param canvas is the canvas
    @param type is either a row or a column
    @param position is where the thing is to be added
    */
    if (type == 'r') { 
        addRow(canvas, position);
    } 
    else if (type == 'c') { 
        addCol(canvas, position);
    }
}

void deleteRow(struct Canvas *canvas, int position) {
    /*
    function deletes a row
    @param canvas is the canvas
    @param postions is which row should be deleted
    */
    free(canvas->grid[position]);
       
    for (int i = position; i < canvas->rows - 1; i++) {
        canvas->grid[i] = canvas->grid[i + 1];
    }

    canvas->grid = (char **)realloc(canvas->grid, (canvas->rows - 1) * sizeof(char *));
    canvas->rows--;
}

void deleteCol(struct Canvas *canvas, int position) {
    /*
    function deletes a col
    @param canvas is the canvas
    @param postions is which row should be deleted
    */
    for (int i = 0; i < canvas->rows; i++) {
        for (int j = position; j < canvas->cols - 1; j++) {
            canvas->grid[i][j] = canvas->grid[i][j + 1];
        }
    }

    for (int i = 0; i < canvas->rows; i++) {
        canvas->grid[i] = (char *)realloc(canvas->grid[i], (canvas->cols - 1) * sizeof(char));
    }
        canvas->cols--;

}
void deleteRC(struct Canvas *canvas, char type, int position) {
    /*
    function deletes a row or column to the canvas
    @param canvas is the canvas
    @param type is either a row or a column
    @param position is where the thing is to be deleted
    */
    if (type == 'r') { 
        deleteRow(canvas, position);
    } 
    else if (type == 'c') { 
        deleteCol(canvas, position);
    }
}

void saveCanvas(struct Canvas *canvas, const char *file_name) {
    /*
    function saves the canvas to a file
    @param canvas is the canvas
    @param file_name is the file where the canvas is to be saved
    */
    FILE *file = fopen(file_name, "w");
    fprintf(file, "%d %d\n", canvas->rows, canvas->cols);

    for (int i = 0; i < canvas->rows; i++) {
        for (int j = 0; j < canvas->cols; j++) {
            fprintf(file, "%c", canvas->grid[i][j]);
        }
        fprintf(file, "\n"); 
    }
    fclose(file);
}

void loadCanvas(struct Canvas *canvas, const char *file_name) {
    /*
    function loads the canvas from a file
    @param canvas is the canvas
    @param file_name is the file where the canvas is to be loaded from
    */
    FILE *file = fopen(file_name, "r");

    int rows, columns;
    fscanf(file, "%d %d", &rows, &columns); 
    canvas->grid = (char **)malloc(rows * sizeof(char *));
    
    canvas->rows = rows;
    canvas->cols = columns;

    for (int i = 0; i < rows; i++) {
        canvas->grid[i] = (char *)malloc(columns * sizeof(char));
        
        for (int j = 0; j < columns; j++) {
            fscanf(file, " %c", &canvas->grid[i][j]);
        }
    }
    fclose(file);
}

void freeCanvas(struct Canvas *canvas) {
    /*
    function deletes the canvas and frees memory
    @param canvas is the canvas to be deleted
    */
    if (canvas == NULL) {
        return; 
    }
    for (int i = 0; i < canvas->rows; i++) {
        free(canvas->grid[i]);
    }
    free(canvas->grid);
    free(canvas);
}

void makeCanvas(struct Canvas *canvas, int rows, int columns) {
    /*
    function creates the canvas
    @param canvas is the canvas
    @param rows is the number of rows to be created
    @param columns is the number of columns to be created
    */
    canvas->rows = rows;
    canvas->cols = columns;
    canvas->grid = (char **)malloc(rows * sizeof(char *));
    
    for (int i = 0; i < rows; i++) {
        canvas->grid[i] = (char *)malloc(columns * sizeof(char));
        for (int j = 0; j < columns; j++) {
            canvas->grid[i][j] = '*'; 
        }
    }
}