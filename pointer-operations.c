/**
 * @file pointer-operations.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to demonstrate various 
 *        pointer operations.
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

// Remember ->
// Always read * notation as Value at variable
// and read & notation as Address of variable.

int main(void) {
    int x = 2, y = 5;
    char a = 'a';
    int z[10];

    // At what places in memory are variables stored?
    // Use & operator to get address of variable.
    printf("At what places in memort are variables stored?\n");




    // How do you store address of variable?
    printf("How do you store address of variable?\n");
    
    // We can not use integer variables to store address
    // of variables.
    
    // Illegal. Following code produces warning.
    // int a;
    // a = &x;

    // Use pointer variables to store address of variables.
    // Declare integer pointer variable to store
    // address of integer variable.
    // Declare character pointer variable to store
    // address of character variable.
    


    // Use ip variable to store address of x
    


    // &x -> Address of x
    // ip -> pointer to int x
    
    // What does pointer point to or what is value at pointer ip? 
    printf("What is value at pointer ip?\n");
    // Value at pointer = *(pointer-variable)
    // *(ip) -> *(&x) -> Value at address of x -> Value of x
    // *ip is same as x.
    // * is also called indirection operator and is used to
    // dereference a pointer. 
    



    // How to change value of x using pointers?
    printf("Can we change value of x using pointer?\n");
    // As *ip is value at address of x, change in *ip 
    // means change in x.




    // What is a pointer to an array?
    printf("What is a pointer to an array?\n");
    // Pointer pointing to the first element of an array
    // is a pointer to an array



    // Another way of writing array pointer



    // Value of both ip and ap is same.



    // Incrementing pointers
    printf("What happens when we increment values at and of pointers?\n");
    // ip = &x;
    // printf("Value of  x -> %d\n", x);
    // printf("Value at ip -> %d\n", *ip);

    // Increment one in the value at pointer ip


    // Increment value at pointer ip 
    // use prefix increment operator
    // We will check value of x and value
    // at ip after incrementing pointer.
    

    // Increment value of pointer ip using
    // postfix increment operator
    // We will also check value of x and 
    // value at ip after incrementing pointer.


    // Increment value of pointer in arrays
    printf("Increment value of pointer in an array\n");

    // ip points to first element of the
    // integer array z



    // increment value of pointer


    // What happens when we increment the pointer?
    // When you increment a pointer, the address is 
    // incremented by the number of bytes used to store 
    // that type of variable.



    // This is easily visible in array as when we increment
    // pointer pointing to an array, the pointer then points
    // to next element in the array

    // If we know length of array then we can access all
    // elements of array using pointer.
    
    return 0;
}