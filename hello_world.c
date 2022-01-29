/**
 * @file hello_world.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief First program in C. 
 *        Print "Hello world" on terminal.
 * @version 0.1
 * @date 2022-01-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * This is an example of multiline comment.
 */

// C Preprocessor directive
// Instructs compiler to do required
// preprocessing before actual compilation.
// Here we are including standard input output 
// header file. This file has function definition
// of printf().
#include<stdio.h>

// Execution in C starts from 
// main function.
// int -> return type of function
// main -> name of the function
// () -> Everything inside () is parameter of the function
//       In our case it is empty, therefore void.
// {} -> Everything inside {} is function body. Write code
//       for what you want the function to do.
int main(void) {

    // printf() -> A function defined in standard I/O header
    //             file. Prints string on terminal and printers.
    // \n -> New line character constant in c.
    printf("Hello world\n");

    // Return statement of function.
    // No return statement required for return type void.
    return 0;
}