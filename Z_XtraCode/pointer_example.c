#include<stdlib.h>
#include<stdio.h>

#define addressOf(x) (&x)
#define valueAt(x) (*x)

void swap(int *x, int *y){
    int temp = valueAt(x);
    valueAt(x) = valueAt(y);
    valueAt(y) = temp;
}

void swapPointer(int* *x, int* *y){
    int* temp = valueAt(x);
    valueAt(x) = valueAt(y);
    valueAt(y) = temp;
}



int main(){

    int a = 10, b = 5;
    int* p1 = addressOf(a);
    int* p2 = addressOf(b);
    printf("a = %d, b = %d\n", a, b);

    swap(addressOf(a), addressOf(b));
    printf("a = %d, b = %d\n", a, b);

    printf("p1 = %p, p2 = %p\n", p1, p2);
    swapPointer(addressOf(p1), addressOf(p2));
    printf("p1 = %p, p2 = %p\n", p1, p2);
}