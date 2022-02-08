/**
 * @file function_char_longest-line.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to read input line by line and 
 *        return longest line from the input.
 * This program uses functions, character I/O, 
 * and arrays that we learnt in past classes. This
 * single program sums it up all.
 * Assume maximum length of any line in input is 1000 characters.
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// while (there is another line)
//     if (it's longer than the previous longest)
//         save it
//         save its length
// print longest line

#include<stdio.h>

// Function to read input till new line character and 
// get length of line.
// Paramters - char array to store characters that are being read.
// Return - length of a line as integer
int getlinelength(char input[]) {
    // Read a character till new line or EOF.

    // If first character is new line then length of line = 1

    // Put null ('\0') character at the end of the array
    // to mark end of string of character.

    // Because length of line = number of characters read,
    // return i

    int character, i;

    // There are two test conditions with AND operator. 
    // Loop will stop if any one of the condition is false.
    //
    // Any changes in char input[] means changes in char line[],
    // because array passed is pointer to its beginning location.
    for (i = 0; (character = getchar()) != EOF && character != '\n'; ++i) {
        input[i] = character;
    }

    // Added new line character in the end of line as 
    // line with only new line character has length of one.
    if (character == '\n') {
        input[i] = character;
        ++i;
    }

    // Put character '\0' (null character) at the end of the array
    // to mark the end of the string of characters. 
    input[i] = '\0';
    
    // Return length of line which is also equal to number
    // of characters read
    return i;
}

// Function to copy characters from one char array to another
// This copies 'from' into 'to'.
// Parameter - char from[], char to[]
// Return - void
void copy(char from[], char to[]) {

    int i = 0;
    
    // Copy 'from' into 'to' one character at a time
    // until null character encountered.
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
    // Any changes in 'to' array means changes in longestline array.

    // This function does not return anything.
    // Such functions have "void" return type.
}

int main(void) {
    
    // Variable declarations

    // Variable len to hold length of each line.
    // Variable max to hold length of max line length.
    int len, max = 0;

    // Character array to store line from input.
    char line[1000];

    // Character array to store longest line.
    // We will copy char array line into char array 
    // longestline if lenght of line is greater 
    // than current max length.
    char longestline[1000];

    // Get length of each line using getlinelength function
        while ((len = getlinelength(line)) > 0) {
            // If length of line greater than current max length
            // then update max variable and copy line into
            // longestline.
            if (len > max) {
                max = len;
                copy(line, longestline);
            }
        }

    // If max length of any line read is greater than zero 
    // then print longestline.
    if (max > 0) {

        printf("Longest line in the input is -> ");
        // Two ways to print string in C.
        
        // First way - using loop
        
        // int i;
        // for (i = 0; i < max; i++) {
        //     printf("%c", longestline[i]);
        // }

        // Second way

        // %s -> Format specifier to print sequence of characters
        printf("%s", longestline);
        
        printf("\n");
    }

    return 0;
}
