#ifndef BACKEND_H
#define BACKEND_H

    struct Canvas {
        char **grid;
        int rows;
        int cols;
    };

    void outputCanvas(struct Canvas *canvas);
    void resize(struct Canvas *canvas, int new_rows, int new_cols);
    void addRow(struct Canvas *canvas, int position);
    void addCol(struct Canvas *canvas, int position);
    void add(struct Canvas *canvas, char type, int position);
    void deleteRow(struct Canvas *canvas, int position);
    void deleteCol(struct Canvas *canvas, int position);
    void deleteRC(struct Canvas *canvas, char type, int position);
    void saveCanvas(struct Canvas *canvas, const char *file_name);
    void loadCanvas(struct Canvas *canvas, const char *file_name);
    void freeCanvas(struct Canvas *canvas);
    void makeCanvas(struct Canvas *canvas, int rows, int cols);

#endif