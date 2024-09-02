#include <stdio.h>

// Function prototype
int foo(int N);

// Main function
int main() {
    // Replace 'N' with the desired input value
    int N; // Example input
    printf("Enter a value for n: ");
    scanf("%d", &N);
    printf("foo(%d) = %d\n", N, foo(N));
    return 0;
}

// Helper function to handle memoization
int fooHelper(int N, int memo[]) {
    // Base cases
    if (N == 0) return 3;
    if (N == 1) return 6;
    if (N == 2) return 2;
    if (N == 3) return 7;
    
    // Check if the value is already computed
    if (memo[N] != -1) return memo[N];
    
    // Recursive case with a single recursive call
    memo[N] = fooHelper(N - 1, memo) + fooHelper(N - 2, memo) + 
              fooHelper(N - 3, memo) - fooHelper(N - 4, memo) + 1;
    return memo[N];
}

// Function to initialize memoization array and call the helper function
int foo(int N) {
    int memo[N+1];
    for (int i = 0; i <= N; i++) {
        memo[i] = -1; // Initialize memoization array with -1
    }
    return fooHelper(N, memo);
}
