/*
Group: Ian Marwong, Danny Yu
This program returns a value after an input is passed through a mathmatical function
*/
#include <stdio.h>

int foo_helper(int n, int n3, int n2, int n1, int n0) {
    /*
    Function calculates foo.
    @param n: The index for which the foo value is being calculated.
    @param n3: The value of foo(n-3).
    @param n2: The value of foo(n-2).
    @param n1: The value of foo(n-1).
    @param n0: The value of foo(n) for the previous step (n-1).
    @returns the value of foo.
    */
    if (n == 0)
        return n0;
    else if (n == 1)
        return n1;
    else if (n == 2)
        return n2;
    else if (n == 3)
        return n3;
    else
        return foo_helper(n - 1, - n0 + n1 + n2 + n3 + 1, n3, n2, n1);
}

int foo(int n) {
    /*
    Function sets the base cases to find foo.
    @param n is the number of foo we are trying to find.
    @returns value of foo.
    */
    return foo_helper(n , 7, 2, 6, 3); // Adjusted initial values for n3, n2, n1, n0
}

int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    printf("Foo(%d) = %d\n", n, foo(n));
    return 0;
}
