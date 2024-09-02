#ifndef PAINT_H
#define PAINT_H
    #include "backend.h"

    void makeLine(struct Canvas *canvas, int start_row, int start_col, int end_row, int end_col);
    void eraseCell(struct Canvas *canvas, int row, int col);

#endif