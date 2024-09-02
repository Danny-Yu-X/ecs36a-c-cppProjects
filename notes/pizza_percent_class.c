
/*
Figure out what percent of pizza we have eaten.

1. Get number of slices the pizza started with
2. Get number of slices we ate
3. Calculate the percent eaten: slices eaten/ slices started with

*/

#include <stdio.h>

int main(){
    int starting_slices, slices_eaten;
    printf("Enter the number of slices you started with");
    scanf("%d slices of pizza", &starting_slices);

    printf("Enter the number of slices eaten: ");
    scanf("%d slices of pizza", &slices_eaten);

    double percent_eaten = 100.0 * slices_eaten / starting_slices;

    printf("You ate %.2lf%% of your pizza\n", percent_eaten);

    return 0;
}