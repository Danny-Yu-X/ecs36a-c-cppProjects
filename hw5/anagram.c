/*
Group: Ian Marwong, Danny Yu
This program compares two strings to see if they are an anagram of each other
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool Anagram(char word1[], char word2[]);
void Remove(char array[], int position);

void Remove(char array[], int position){
    /*
    This function removes a value from an array and shifts all other values to fill the gap
    @param array[] is the array that is going to have a value removed
    @param position is the position of the value in the array to be removed
    */
    for(int i = position; i < strlen(array)-1; i++){
        array[i] = array[i+1];
    }
    array[strlen(array)-1] = '\0';
}

bool Anagram(char word1[], char word2[]){
    /*
    This function compares the strings to determine if they have the same characters/are an anagram
    @param word1[] is the first string
    @param  word2[] is the second string
    @returns true or false if the strings are anagrams
    */
    char workword1[21], workword2[21];
    if (strlen(word1) != strlen(word2)){
        return false;
    }
    for(int i = 0; i < strlen(word1);++i){
        workword1[i] = toupper(word1[i]);
    }
    for(int i = 0; i < strlen(word2);++i){
        workword2[i] = toupper(word2[i]);
    }
    int i=0;
    while(i < strlen(workword1)){
        bool get_out = false;
        for(int j = 0; j < strlen(workword2); ++j){
            if(workword1[i] == workword2[j]){
                Remove(workword1, i);
                Remove(workword2, j);
                get_out = true;
                break;
            }
        } 
        if(!get_out){
            return false;
        }
    }
    return true;
}

int main(){
    char word1[21], word2[21];
    printf("Please enter the first word: ");
    scanf("%s", word1);
    printf("Please enter the second word: ");
    scanf("%s", word2);


    if(Anagram(word1, word2)){
        printf("%s is an anagram of %s", word1, word2);
    }else{
        printf("%s is NOT an anagram of %s", word1, word2);
    }
    return 0;
}