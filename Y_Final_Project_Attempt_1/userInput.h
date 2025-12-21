#ifndef USERINPUT_H
#define USERINPUT_H
    #include "backend.h"
    #include <stdbool.h>
    bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line);
    void print_help();
    bool isBigZero(int num);
    void clearBuffer();
    void userInput(struct Canvas *canvas);

#endif