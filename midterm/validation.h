#ifndef VALIDATION_H
    #define VALIDATION_H
    #include <stdbool.h>

    bool isValidFormatExit(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line);
    bool isValidFormat(const int numArgsRead, const int numArgsNeed);

#endif