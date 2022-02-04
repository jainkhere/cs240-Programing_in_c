/**
 * @file power_function.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to demonstrate functions in C. 
 *        We will define a function to calculate
 *        value of integer n raised to a positive
 *        integer of power m.
 *        For eg - power(2,5) = 2 raised to power 5 = 32.
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// Function declaration
// return-type function-name (parameter declaration, if any);
// Our function -> power: base raised to n-th power. 
// Return exponentiation value. Here n >= 0
// Syntax -> int power(int base, int n);

// Function definition - Define task of function using statements
// return-type function-name(parameters declaration) {
//      declarations;
//      statements;
//      return statement;
// }

// Logic to calculate exponentiation ->
// 2^5 = 1 * 2 * 2 * 2 * 2 * 2
// 2^n = 1 * 2 * 2 ... n times ... 2
int power(int base, int n) {
    
    int i;
    
    // Variable to hold value of exponentiation
    // Initial value one because anything raised to power 0 is 1.
    int p = 1; 
    
    for (i = 0; i < n; i++) {
        p = p * base;
    }

    // Function returns value of exponentiation.
    return p;
}

int main (void) {

    int i;
    
    for (i = 0; i <= 10; i++) {
        // Function call
        // function-name(arguments)
        // power(2, 5)
        printf("2 raised to power %d = %d\n", i, power(2, i));
    }
    
    return 0;
}








