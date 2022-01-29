/**
 * @file division_by_zero.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to show run time error.
 *        We will divide a number by zero 
 *        and see if there is any error.
 * @version 0.1
 * @date 2022-01-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
int main(void) {
    // Define three variables.
    // Divide a/b and store result in c.
    int a = 10;
    int b = 0;
    int c;

    // We have to use print statements to
    // track down where error exactly occured.
    printf("Before division\n");
    
    c = a/b;
    // Program execution ends as runtime error
    // encountered after division in above line.
    
    // Below print statement will not work.
    printf("%d\n", &c);
    printf("After division\n");
    return 0;
}