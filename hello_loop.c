/**
 * @file hello.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Introduction to loop and variables.
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
int main(void) {
    
    // i -> This is the iterator variable in loop
    // num -> Number of times that we want to run the loop
    // Notice that i is declared and num is defined in
    // same statement. This will work as long as every
    // variable is seperated by a comma.
    int i, num = 8;

    // for (A; B; C) { statement }
    //
    // A is the initialization point of the loop.
    //
    // B is test condition of the loop. 
    //
    // C is the counter or the speed by which we want to
    // progress in our loop.
    for ( i = 0; i < num; i = i + 1) {

        // Send two argument to print anything other 
        // than characters and string.
        // %d -> Format specifier to print integer
        printf("%d. ", i + 1);

        // Prints Hello cs240! followed by a
        // new line character.
        printf("Hello cs240!\n");
    }
    return 0;
}