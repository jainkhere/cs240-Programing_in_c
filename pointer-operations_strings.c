/**
 * @file string-operations_pointer.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to perform string operations 
 *        using pointers.
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// strlen -> Reads character array one character
//           at a time and returns its length.
// Parameter -> character array s[].
// Returns -> Length of character array.

// First method - for loop with len variable
int strlen1(char s[]) {
    // Store length of array in len.
    int i, len = 0;
    // Loop through all elements of array
    // until End of string.
    printf("%s\n", s);
    for (i = 0; s[i] != '\0'; i++) {
        len++;
    }
    return len;
}

// Second method - empty for loop without 
// extra variable
int strlen2(char s[]) {
    int i;
    // Loop until s[i] = '\0'
    // i stores length of string
    for (i = 0; s[i]; i++)
        ;
    return i;
}

// Third method - Empty for loop with pointer
int strlen3(char* s) {
    char* cp;
    // For loop with pointer
    // Check if pointer pointing 
    // to null value. Increment pointer
    for (cp = s; *s; s++);
    // Subtract cp from s to get
    // length of string.
    return s - cp;
}

// Fourth method - Empty while loop with pointer
int strlen4(char* s) {
    // p initialized with s
    char* p = s;
    // loop condition -> *(p++)
    // Incresing pointer value 
    // just like above function.
    while(*p++);
    // Subtract extra one, because 
    // of postfix increment operator.
    return p - s - 1;
}

// strcpy -> Copy characters from one
//           array to another. Here we
//           will copy t to s.
// Parameters -> Character array s and t.
// Returns -> Nothing. Alters array s.

// First method - while loop with char array
void strcpy1(char s[], char t[]) {
    int i = 0;
    // Copy every character from t to s,
    // until the character is null.
    while((s[i] = t[i]) != '\0') {
        i++;
    }
}

// Second method - empty while loop with pointer
void strcpy2(char* s, char* t) {
    // s is a pointer pointing to s char array
    // t is a pointer pointing to t char array
    // Check if value at t is null. If null then end loop
    // If not null then, set *s = *t. Increment both pointer.
    while(*s++ = *t++);
    // Destructuring of above while loop
    // while (*t != '\0') {
    //      *s = *t;
    //      *s++;
    //      *t++;   
    // }
}

// strcmp -> Compare two strings. 
//           Return 0 if they are equal. 
//           Return 1 if first string appears after second in dictionary.
//           s -> bag
//           t -> dog - return -1
//           s -> zebra
//           t -> apple - return 1
//           Return -1 otherwise.
// Parameters -> Character array s and t.
// Returns -> Integer. 
//            0 if s and t equal
//            1 if s appears after t in dictionary
//           -1 if t appears after s in dictionary
// s -> a
// t -> ab
int strcmp(char* s, char* t) {
    while(1) {
        if (*s == '\0' || *t == '\0') {
            // loop should break in this condition
            if (*s == *t) {
                // both are equal and null character.
                return 0;
            }
            if (*s != 0) {
                // s appears after t
                return 1;
            }
            // here, s must appear before t
            return -1;
        }
        if (*s == *t) {
            // If both character are equal then 
            // go to next character.
            s++;
            t++;
        }
        else {
            if (*s < *t) {
                // string s appears before string t
                return -1;
            }
            else {
                return 1;
            }
        }
    }
}

int main() {
    // This is driver function. We call all function
    // from this driver function.
    
    // Uncomment the function that you want to run
    // and check the output for.

    // char arr1[] = "Hello world!";
    // char arr2[] = "";
    // strlen1(arr1);
    // strlen2(arr1);
    // strlen3(arr1);
    // strlen4(arr1);
    // strcpy1(arr2, arr1);
    // strcpy2(arr2, arr1);
    // strcmp(arr2, arr1);
    return 0;
}