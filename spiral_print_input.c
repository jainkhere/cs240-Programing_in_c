/**
 * @file spiral_print_array.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to spiral print every word in a given input
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// print the word in spiral form in this function
void spiral_function(char input[], int length) {
    
    // Forward index. Use this variable to print
    // starting characters of the word. Initialize
    // with first character's position
    int i = 0;

    // Backward index. Use this variable to print
    // ending characters of the word. Initialize 
    // with last character's position
    int j = length - 1;
    
    // Run loop until forward index exceeds backwards
    // index.
    while(i <= j) {
        // If condition to prevent two time printing of
        // middle character in odd length word
        if (i == j) {
            printf("%c", input[i]);
            break;
        }
        // Print one character from start and one from end
        printf("%c%c", input[i], input[j]);
        // increment forward index
        i++;
        // decrement backward index
        j--;
    }
}

int main(void) {
    // Save words as we parse the input in this input array.
    // later on, we will send this array to spiral_function.
    char input[1000];
    
    // Use this index variable to save characters in input array
    // on desired location. 
    int index = 0;

    // Use this variable to get character from input
    int c;

    // Loop to read input character by character
    while((c = getchar()) != EOF) {
        // if character is blank
        if (c == ' ' || c == '\t' || c == '\n') {
            // Call spiral function because word just ended
            spiral_function(input, index);
            // reset the value of index
            index = 0;
            // print c
            printf("%c", c);
        }
        // if character is not blank
        else {
            // save c in input array
            input[index] = c;
            // increment the value of index.
            index++;
        }
    }
    // Call function after the loop one last time
    // for last word
    spiral_function(input, index);
}