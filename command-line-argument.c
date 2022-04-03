/**
 * @file command-line-argument.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to show use of command line arguments
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

int main(int argc, char** argv) {
    // argc -> total number of command line arguments
    // argv -> string array containing all the command line arguments
    // argv[0] -> name of the executable file
    
    // printf("Value of argc -> %d\n", argc);
    
    int i;

    // starting loop from 1 as 0th element in argv is name of 
    // the executable file. We are concerned with strings present
    // after the first string. First string is just the name of 
    // the exe file.

    // This loop prints whatever user inputs as command line argument.
    for (i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if ( i == argc - 1 ) {
            // it is last command line argument.
            printf("\n");
        }
        else {
            // it is not last command line argument.
            printf(" ");
        }
    }
    return 0;
}