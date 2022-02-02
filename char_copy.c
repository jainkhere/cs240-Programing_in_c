/**
 * @file char_copy.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to copy its input to its output
 *        one character at a time.
 * @version 0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
int main(void) {
    
    // Why int?
    // We must declare c to be big enough to hold any
    // value that getchar returns.
    int c;

    // Variable Initialization
    c = getchar();

    // Variable Initialization;
    // While (test_condition) { 
    //      statement;
    //      Counter statement;
    // }
    // 
    // We evaluate the test_condition at the begining and
    // then at every iteration of the loop.
    //
    // Unlike for loop, we are not using any counter variable
    // inside loop brackets. 
    // We will use counter variable in while loop generally 
    // with other statements that we want to execute in loop.
    //
    // EOF -> Integer defined in <stdio.h>
    while ( c != EOF) {

        putchar(c);
        
        // Counter statement
        c = getchar();
    }

    return 0;
}
