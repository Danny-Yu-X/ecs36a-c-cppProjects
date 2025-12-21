malloc;
calloc;
realloc;//pointer resizer

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define valueAt(x) (*x)
#define addressOf(x) (&x)

void append(char character, char* *str, int *len){
    valueAt(str) = (char*)realloc(valueAt(str), (valueAt(len) + 1)*sizeof(char));
    valueAt(str)[valueAt(len)]=character;
    valueAt(len) += 1;
}
char* read_str_any_len(const char* prompt){
    //1. read char
    //while not whitespace
       //2. append char to end
      //4. read next char
    //5.append null
    printf("%s", prompt);
    char* str = NULL;
    int len = 0;
    char letter;
    scanf(" %c", &letter);

    while(!isspace(letter)){
        append(letter, addressOf(str), addressOf(len));
        scanf("%c", letter);
    }
    append('\0', addressOf(str), addressOf(len));
}
int main(){
    char word;
    printf("Enter something");
    printf("\n\nYou entered %s", word);
    free(word);
    return 0;
}


sscanf();

/*
headers
    .h
    function and struct declaration
    #include any files they need declarations of
source files
    .c
    function definitions
    #include
*/

//typedef old new;
//typedef int age;
//age getOlder();

//Makefiles