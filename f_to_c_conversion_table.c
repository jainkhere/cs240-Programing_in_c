/**
 * @file f_to_c_conversion_table.c
 * @author your name (you@domain.com)
 * @brief Program to print f to c conversion table.
 *        Will start from f = 0 and go till f = 300
 *        Table will contain all F from 0, 20, 40... 300
 *        and its corresponding C value.
 * @version 0.1
 * @date 2022-01-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// We use symbolic constants for values that remain 
// same throughout the program.
#define LOWER 0
#define UPPER 300
#define COUNTER 20

#include<stdio.h>
int main(void) {

    // f - fahrenheit, c - celcius
    // Declare integer f and float c
    int f;
    float c; 

    // for loop to calculate celcius after every 
    // increment 20 fahrenheit
    // initialize f with LOWER value.
    // Run loop till f is less than UPPER value.
    // Increase f by COUNTER after each iternation of loop.
    for (f = LOWER; f <= UPPER; f = f + COUNTER) {
        
        // Because we need value of celcius till one decimal
        // point, we will use (5.0/9.0), to get result in 
        // floating point value.
        c = (f - 32)*(5.0/9.0);

        // %d       -> Format specifier to print integer.
        // %0.1f    -> Format specifier to print float till 1 decimal point.
        printf("%d \t %0.1f\n", f, c);
    }
    return 0;
}