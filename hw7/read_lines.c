#include <stdlib.h>
#include <stdio.h>
#include "read_lines.h"

void read_lines(FILE* fp, char*** lines, int* num_lines) {
    /*Group: Ian Marwong, Danny Yu
        read all of the lines in fp into lines and set num_lines to be the total number of lines in the file.
        @fp: a file pointer opened in read mode
        @lines: a pointer indicating where the lines should be placed. If there are no lines in a file, lines
                will be set to NULL
        @num_lines: a pointer to the number of lines. set to the number of lines contained within lines
        @modifies: lines, num_lines
    */
    int character;
    *num_lines = 0;
    while ((character = fgetc(fp)) != EOF) {
        if (character == '\n') {
            (*num_lines)++;
        }
    }
    if (ftell(fp) != 0 || (*num_lines) > 0) {
        (*num_lines)++;
    }
    fseek(fp, 0, SEEK_SET);
    if(*num_lines > 1){
      (*num_lines)--;
    }
    if (*num_lines == 0) {
        *lines = NULL;
        return;
    }

    *lines = (char**)malloc((*num_lines) * sizeof(char*));

    size_t length = 0;
    char* line = NULL;
    int index = 0;

    while ((character = fgetc(fp)) != EOF) {
        if (line == NULL) {
            line = (char*)malloc(1); 
        }

        if (character == '\n') {
            line[length] = '\0'; 
            (*lines)[index++] = line;
            line = NULL; 
            length = 0;
        } else {
            line = realloc(line, (length + 2) * sizeof(char));
            line[length++] = character;
        }
    }
    if (length > 0) {
        line = realloc(line, (length + 1) * sizeof(char));
        line[length] = '\0';
        (*lines)[index++] = line;
    } else {
        free(line);
    }
}
