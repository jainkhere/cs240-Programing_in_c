/**
 * @file line_count.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to count input lines
 * @version 0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

int main(void) {

    int character;
    int line_count = 0;

    while ( (character = getchar()) != EOF ) {

        // if (expression) {
        //      execute statement if expression True  
        // } else {
        //      execute statement if expression False
        // }
        //
        // '\n' -> Character constant for new line
        if (character == '\n') {
            ++line_count;
        }
    }

    printf("%d", line_count);

    return 0;
}