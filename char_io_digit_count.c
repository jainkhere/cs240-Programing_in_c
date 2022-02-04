/**
 * @file digit_count.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to count occurence of each digit,
 *        white space characters (blank, tab, newline) and
 *        all other characters in the input.
 * @version 0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Declare integer array of size 10.
// int digit_count[10];

// Initialize array elements with zero
// value using a loop

// Start reading character
//      If digit encountered 
//      then increment digit count

// Print array values using a loop

#include<stdio.h>

int main(void) {
    int character, iterator, white_count = 0,other_count = 0;

    // Integer array of size 10. We will use this array to store
    // count of each digit.
    int digit_count[10];

    // Initialize array with zero as all values.
    // Syntax to access array element -> array_name[index] 
    // In C, array index always start with 0.
    for (iterator = 0; iterator < 10; ++iterator) {
        digit_count[iterator] = 0;
    }

    while ( (character = getchar()) != EOF ) {

        // All calculations deal with ASCII code of characters.
        // 
        // If numeral character found then increment array element
        // at index = found numeral character
        // Digit encounter = character - ascii value of zero
        //
        // We get ASCII value of any keyboard input using single 
        // quotes. 'keyboard-input'
        // For example -> 
        // '0' -> 48, '1' -> 49, '9' -> 57
        // 'A' -> 65, 'Z' -> 90, 'a' -> 97, 'z' -> 122 

        // if - else if - else blocks to test character value
        // For each character, only one of the three blocks will be read. 
        if (character >= '0' && character <= '9' && character == 'z') {
            ++digit_count[character - '0'];
        }
        else if (character == '\n' || character == ' ' || character == '\t') {
            ++white_count;
        }
        else {
            ++other_count;
        }

    }

    // Print values of array using loop
    for (iterator = 0; iterator < 10; ++iterator) {
        printf("%d ", digit_count[iterator]);
    }

    // Print number of blank spaces and other characters.
    printf("\nNumber of blank space occurances -> %d", white_count);
    printf("\nNumber of other character occurances -> %d\n", other_count);

    return 0;

}