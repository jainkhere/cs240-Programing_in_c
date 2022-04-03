/**
 * @file function_call-by-reference.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to swap 2 pointers
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// Function to swap 2 pointers
// int** address_of_pa -> Address of first pointer variable.
// int** address_of_pb -> Address of second pointer variable.
void swap (int** address_of_pa, int** address_of_pb) {
    // address_of_p where p is an int pointer (int*) must be of type (int*)*
    // address of an int pointer must be of type int**
    
    // temporary variable to store value at address_of_pa
    // and set same value at address_of_pb
    int* temp;
    
    // swap two pointers as any other variable.
    temp = *address_of_pa;
    *address_of_pa = *address_of_pb;
    *address_of_pb = temp;

    // pa and pb is swapped after this.
    // Can be verified using print statements in main function.
}

int main(void) {
    // Declare 2 integers in this program. Then create
    // 2 pointer variables that point to the 2 integers.
    // The aim of the program is to swap the 2 pointers.
    
    int a = 7, b = 5;

    // pa is a pointer pointing to a
    // pb is a pointer pointing to b
    int* pa = &a;
    int* pb = &b;
    
    printf("Value at pointer pa -> %d\n", *pa);
    printf("Value of pointer pa -> %d\n", pa);
    printf("Address of pointer pa -> %d\n\n", &pa);

    printf("Value at pointer pb -> %d\n", *pb);
    printf("Value of pointer pb -> %d\n", pb);
    printf("Address of pointer pb -> %d\n", &pb);
    
    // Pass address instead of pointer variable.

    // &pa -> address of pa
    // &pb -> address of pb 
    swap(&pa, &pb);


    printf("\nAfter swap:\n");

    printf("Value at pointer pa -> %d\n", *pa);
    printf("Value of pointer pa -> %d\n", pa);
    printf("Address of pointer pa -> %d\n\n", &pa);

    printf("Value at pointer pb -> %d\n", *pb);
    printf("Value of pointer pb -> %d\n", pb);
    printf("Address of pointer pb -> %d\n", &pb);

    return 0; 
}