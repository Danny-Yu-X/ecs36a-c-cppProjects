/*
Group: Ian Marwong, Danny Yu
Program multiplys two complex numbers and shows the result
*/

#include <stdio.h>

int main(){

    int a;
    int b;
    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d i + %d", &a, &b);

    int c;
    int d;
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d i + %d", &c, &d);

    printf("(%di + %d) * (%di + %d) = %di + %d", a, b, c, d, (a*d)+(b*c),(b*d)-(a*c));

    return 0;
}