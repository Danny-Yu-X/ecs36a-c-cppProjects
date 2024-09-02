/*
Group: Ian Marwong, Danny Yu
This function gives every permutation of a given binary string
*/

#include <stdio.h>
#include <stdlib.h>

int lengthString(const char *str) {
    /*
    Function finds the length of the inputted string
    @param *str is the address of the string
    @returns the length of the string
    */
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void makeStrings(char *input, int index, int length) {
    /*
    Function makes each permutation of the string using recursion
    @param *input is the input string
    @param index is the index position of the string
    @param length is the length of the input string
    */
    if (index == length) {
        printf("%s\n", input);
        return;
    }

    if (input[index] == 'X'|| input[index]=='x') {
        input[index] = '0';
        makeStrings(input, index + 1, length);
        input[index] = '1';
        makeStrings(input, index + 1, length);
        input[index] = 'X';
    } else {
        makeStrings(input, index + 1, length);
    }
}

char *allocate_memory(const char *input, int length) {
    /*
    This function allocates memory
    @param *input is the input string
    @param length is the length of the input string
    @returns the address of the allocated memory
    */
    char *input_copy = (char *)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length + 1; i++) {
        input_copy[i] = input[i];
    }
    return input_copy;
}

int main(int argc, char *argv[]) {

    char *input = argv[1];
    int length = lengthString(input);

    char *input_copy = allocate_memory(input, length);
    makeStrings(input_copy, 0, length);
    free(input_copy);

    return 0;
}
