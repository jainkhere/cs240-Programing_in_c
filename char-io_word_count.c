/**
 * @file word_count.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to count number of words in a given
 *        input. We assume for this program that word is
 *        any sequence of of characters that does not
 *        contain a blank, tab or newline. 
 *        Along with word count we will also keep line
 *        count and character count.
 * @version 0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

#define IN 1    // inside a word
#define OUT 0   // outside a word

int main(void) {

    int character, line_count, word_count, char_count, state;

    // initially state is out of any word.
    state = OUT;

    // all counts are set to zero at the begining of the program
    line_count = word_count = char_count = 0;

    while ((character = getchar()) != EOF) {

        // Increment character count on every loop iteration.
        ++char_count;

        // If encountered character is new line character
        // then increase line_count.
        if (character == '\n') {
            ++line_count;
        }

        // If character is either blank space, or tab space or 
        // new line character, state is out of any word.

        // OR opertor ( || ) -> Any one expression needs to be true for
        //                      test condition to be true.
        if ( character == ' ' || character == '\t' || character == '\n' ) {
            state = OUT;
        } 

        // If current state is out of word and neither blank space,
        // nor tab space or new line character is encountered, then
        // we can conclude that character must be first character 
        // of a word.
        else if (state == OUT) {
            
            // Set state in a word. Increment word_count.
            state = IN;
            ++word_count;
        }

    }

    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);
    printf("Char count: %d\n", char_count);

    return 0;
}
