/**
 * @file char_count.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to count input characters
 * @version 0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
int main(void) {

    int c; 
    int char_count = 0;

    while((c = getchar()) != EOF) {
        
        // ++ -> Increment operator. Increase value 
        // of variable by one.
        // ++char_count -> prefix increment. Increments 
        // variable before it is used.
        // char_count++ -> postfix increment. Increments
        // variable after it is used. 
        ++char_count;
    }
    printf("%d\n", char_count);

    return 0;
}