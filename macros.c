/**
 * @file macros.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to demonstrate macros
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

#define STATE 1

// Macros may not work as expected when
// defined without brackets.
#define SQUARENB(A) (A*A)      // Macro without brackets around expression
#define SQUARE(A) ((A)*(A))    // Macro with brackets around expression 

// Use backslash (\) to write macro definition in two line.
// Following macro swaps value of x and y. t is data type int.
#define EXCHG(t, x, y) { t d; d = x; x = y;\
         y = d;}


// This function shows how to
// use macros without arguments.
void test_macro_no_arg() {
    if (STATE) {
        printf("Macro substitution works!");
    }
}

// This function shows how to 
// using macro with arguments.
void test_macro_arg() {
    int n = 9;
    n = SQUARENB(n + 1);    // Substitution -> (n + 1*n + 1)
    printf("Value of n when no brackets in Macro definition -> %d\n", n);
    n = 9;
    n = SQUARE(n + 1);      // Substitution -> ((n + 1)*(n + 1))
    printf("Value of n brackets in Macro definition -> %d\n", n);
}

// Using EXCHG macro to swap
// values of two variables.
void test_macro_exchg() {
    int a = 5, b = 7;
    printf("Value of a and be is %d and %d respectively\n", a, b);
    EXCHG(int, a, b);
    // Above macro expands as follows
    // Shown in multiple lines for clarity
    // {
    //     int d;
    //     d = u;
    //     u = v;
    //     v = d;    
    // }
    // In above expansion, d is defined locally within block.
    printf("Value of a and be is %d and %d respectively\n", a, b);
}

// An example of conditional macros
void test_conditional_inclusion() {
    
    // Evaluates to true if STATE macro is defined
    #ifdef STATE
        printf("State macro is defined\n");
    
    // This runs if above condition false
    #else
        printf("State macro is not defined\n");
    
    // Always remember to end conditional macros
    #endif
}

int main(void) {

    // This is driver function. We call all function
    // from this driver function.
    
    // Uncomment the function that you want to run
    // and check the output for.

    // test_macro_no_arg();
    // test_macro_arg(); 
    // test_macro_exchg();
    // test_conditional_inclusion();

    return 0;
}