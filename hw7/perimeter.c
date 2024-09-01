/*
Group: Ian Marwong, Danny Yu
This program finds the perimeter of an arbitrary, convex shape.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    /*
    Struct representing a point in a 2D space
    int x is the x coordinate
    int y is the y coordinate
    */
    int x;
    int y;
} Point;

double Distance(Point point1, Point point2) {
    /*
    Function is the distance formula
    @param point1 is the first point
    @param point2 is the second point
    @returns the distance between the two points
    */
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

double Perimeter(Point *points, int numPoints) {
    /*
    Function finds the perimeter of the given points
    @param points is the points
    @param numPoints is the number of points
    @returns the perimeter of the shape
    */
    double perimeter = 0.0;
    int i;

    for (i = 0; i < numPoints - 1; i++) {
        perimeter += Distance(points[i], points[i + 1]);
    }
    perimeter += Distance(points[numPoints - 1], points[0]);

    return perimeter;
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");
    int numPoints;
    fread(&numPoints, sizeof(int), 1, file);
    Point *points = (Point *)malloc(numPoints * sizeof(Point));
    fread(points, sizeof(Point), numPoints, file);
    fclose(file);

    double perimeter = Perimeter(points, numPoints);
    printf("The perimeter is %.2lf\n", perimeter);
    free(points);
    return 0;
}