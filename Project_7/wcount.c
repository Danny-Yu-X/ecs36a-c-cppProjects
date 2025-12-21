/*
Group: Ian Marwong, Danny Yu
This program counts the number of words in a given file
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int countWords(FILE *file) {
    /*
    Function counts the words in a given file using the whitespace
    @param *file is the file
    @returns the word count
    */
    int wordCount = 0;
    bool inWord = false;
    int character;
    while((character = fgetc(file)) != EOF){
        if(isspace(character)){
            if(inWord){    
                wordCount++;
                inWord = false; 
            }
        }else{
            inWord = true; 
        }
    }

    if(inWord){
        wordCount++; //counts last word in file if file doesn't end with a space
    }
    return wordCount;
}

void output(FILE * file, int wordCount){
    /*
    Function prints results and closes the file
    @param file is the file
    @param wordCount is the word count
    */

    printf("There are %d word(s).", wordCount);
    fclose(file);
}

int main(int argc, char *argv[]) {

    FILE *file = fopen(argv[1], "r");
    int wordCount = countWords(file);
    output(file, wordCount);
    return 0;
}
