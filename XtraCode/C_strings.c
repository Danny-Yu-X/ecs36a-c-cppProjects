#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int my_stringlen(char str[]){
    int count = 0;
    while(str[count]!='\0'){
        count++;
    };
    return count;

}

void my_strcpy(char dest[], char src[]){
    for(int i = 0; true ; ++i){
        dest[i]=src[i];
        if(src[i] == '\0'){
            break;
        }
    }

}