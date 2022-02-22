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


// n! = 0               if n = 0  (base case)
// n! = n * (n-1)!      otherwise (recursive case)

// Function to calculate factorial of n.
int factorial(int n) {
}


// Finbonacci series -> 1, 1, 2, 3, 5, 8, 13, 21...
// fib(n) = 1                       if n = 1
// fib(n) = 1                       if n = 2
// fib(n) = fib(n-1) + fib(n-2)     otherwise

// Function to calculate nth fibonacci number
// using recursion
int fibonacci(int n) {
}

// Function to calculate nth fibonacci number
// without using recursion
int fibonacci_loop(int n) {
}

int main(void) {
    printf("Factorial of 5 -> %d\n", factorial(5));
    printf("Fibonacci of 7 -> %d\n", fibonacci(7));
    printf("Fibonacci of 7 -> %d\n", fibonacci_loop(7));
}