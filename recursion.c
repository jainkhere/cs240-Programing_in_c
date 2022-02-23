/**
 * @file recursion.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief This program has 2 functions
 *          1. Factorial function
 *          2. Fibonacci number
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>


// n! = 1               if n = 0  (base case)
// n! = n * (n-1)!      otherwise (recursive case)

// Function to calculate factorial of n.
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
// Factorial using recursion is calculated like so:
// 6! = 6 * factorial(5)
//    = 6 * 5 * factorial(4)
//    = 6 * 5 * 4 * factorial(3)
//    = 6 * 5 * 4 * 3 * factorial(2)
//    = 6 * 5 * 4 * 3 * 2 * factorial(1)
//    = 6 * 5 * 4 * 3 * 2 * 1 * factorial(0)
//    = 6 * 5 * 4 * 3 * 2 * 1 * 1
//    = 6 * 5 * 4 * 3 * 2 * 1
//    = 6 * 5 * 4 * 3 * 2
//    = 6 * 5 * 4 * 6
//    = 6 * 5 * 24
//    = 6 * 120
// 6! = 720


// Finbonacci series -> 1, 1, 2, 3, 5, 8, 13, 21...
// fib(n) = 1                       if n = 1
// fib(n) = 1                       if n = 2
// fib(n) = fib(n-1) + fib(n-2)     otherwise

// Function to calculate nth fibonacci number
// using recursion
int fibonacci(int n) {
    if (n <= 2)
        return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

// Function to calculate nth fibonacci number
// without using recursion
int fibonacci_loop(int n) {
    if (n <= 2)
        return 1;
    int i;
    // Initialize second_last variable with the 
    // first element of the fibonacci series and 
    // last variable with second element of the
    // series.
    int last = 1;
    int second_last = 1;
    // Current variable to keep track of n-th
    // fibonacci number.
    int current;

    // Update last and second_last variable in 
    // each iteration of loop.
    // Set second_last variable equal to last and 
    // last equal to current variable.
    for (i = 3; i <= n; i++) {
        current = second_last + last;
        second_last = last;
        last = current;
    }

    // current element is n-th fibonacci number
    return current;
}

int main(void) {
    printf("Factorial of 5 -> %d\n", factorial(5));
    printf("7th number in Fibonacci series -> %d\n", fibonacci(7));
    printf("8th number in Fibonacci series -> %d\n", fibonacci_loop(8));
}