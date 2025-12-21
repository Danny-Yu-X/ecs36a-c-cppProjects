#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"


void outputCanvas(struct Canvas *canvas) {
    //printf("\n");

    for (int i = canvas->rows - 1; i >= 0; i--) {
        // Print row index on the left
        printf("%d ", i);
        
        // Print canvas content
        for (int j = 0; j < canvas->cols; j++) {
            printf("%c ", canvas->grid[i][j]);
        }
        printf("\n");
    }
    // Print column indices along the bottom
    printf("  ");
    for (int j = 0; j < canvas->cols; j++) {
        printf("%d ", j);
    }
    printf("\n");
}




void resize(struct Canvas *canvas, int newRows, int newCols) {
   
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
    if (type == 'r') { 
        addRow(canvas, position);
    } 
    else if (type == 'c') { 
        addCol(canvas, position);
    }
}
void deleteRow(struct Canvas *canvas, int position) {
    free(canvas->grid[position]);
       
    for (int i = position; i < canvas->rows - 1; i++) {
        canvas->grid[i] = canvas->grid[i + 1];
    }

    canvas->grid = (char **)realloc(canvas->grid, (canvas->rows - 1) * sizeof(char *));
        
    canvas->rows--;
}
void deleteCol(struct Canvas *canvas, int position) {
    for (int i = 0; i < canvas->rows; i++) {
        for (int j = position; j < canvas->cols - 1; j++) {
            canvas->grid[i][j] = canvas->grid[i][j + 1];
        }
    }

    // Resize each row to remove the last column
    for (int i = 0; i < canvas->rows; i++) {
        canvas->grid[i] = (char *)realloc(canvas->grid[i], (canvas->cols - 1) * sizeof(char));
    }
        canvas->cols--;

}
void deleteRC(struct Canvas *canvas, char type, int position) {
    if (type == 'r') { 
        deleteRow(canvas, position);
    } 
    else if (type == 'c') { 
        deleteCol(canvas, position);
    }
}

void saveCanvas(struct Canvas *canvas, const char *file_name) {
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
    FILE *file = fopen(file_name, "r");

    int rows, columns;
    fscanf(file, "%d %d", &rows, &columns); 
    canvas->grid = (char **)malloc(rows * sizeof(char *));
    

    canvas->rows = rows;
    canvas->cols = columns;

    for (int i = 0; i < rows; i++) {
        canvas->grid[i] = (char *)malloc(columns * sizeof(char));
        
        for (int j = 0; j < columns; j++) {
            fscanf(file, " %c", &canvas->grid[i][j]); //might have error
        }
    }

    fclose(file);
}



void freeCanvas(struct Canvas *canvas) {
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