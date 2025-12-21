#ifndef USERINPUT_H
#define USERINPUT_H
    #include "backend.h"
    #include <stdbool.h>

    void print_help();
    bool isBigZero(int num);
    void clearBuffer();
    void userInput(struct Canvas *canvas);

#endif