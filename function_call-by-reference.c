/**
 * @file function_call-by-reference.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to write a function to swap 2 numbers
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// Declare and define a function to swap two numbers
// Pointer variable -> Variable to store address of another variable.

// In this swap function, we will change the value of variable present
// at the memory location where pointer is pointing.
void swap (int *x, int *y) {

    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;

}

int main(void) {
    int a = 7, b = 5;
    
    printf("%d %d\n", a, b);
    
    // Pass address instead of variable.

    // Address of(&) -> Address of operator gives address of
    //                 the variable. 
    swap(&a, &b);

    // Values of a and b changes once address is passed as argument.
    printf("%d %d\n", a, b);

    return 0; 
}