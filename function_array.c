/**
 * @file function_array.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to demonstrate how functions
 *        work with arrays as arguments.
 *        Given an integer array, we will increase 
 *        all elements of array by one using function.
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// Function to print array.
// Parameters - array, length of array.
// Returns - void
void printa(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to increase all elements in an array by one
// Parameters - array, length of array
// Returns - void
void increase_by_one(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = arr[i] + 1;
    }
}

int main(void) {
    
    int i;
    // Array declared of two values.
    int arr[2] = {1, 2};

    // Print array before calling function.
    // printa function expects two arguments - array and length of array
    printf("Initial array values\n");
    printa(arr, 2);

    // Function called to increase value
    // increase_by_one expects one argument - array
    //
    // Notice that function is not returning any value.
    // When array is passed as an argument, the value passed to the 
    // function is the address of the beginning of the array.
    // All changes to array in function will be seen here as well.
    increase_by_one(arr, 2);

    // When array is printed after calling increase_by_one function,
    // Values of array are incremented even though function did not
    // return updated array.
    printf("Final Array values\n");
    printa(arr, 2);

    return 0;

}