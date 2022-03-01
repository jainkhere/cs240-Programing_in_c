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
// Read * notation as Value at variable
// and read & notation as Address of variable.

int main(void) {
    int x = 2, y = 5;
    char a = 'a';
    int z[10];

    // At what places in memory are variables stored?
    // Use & operator to get address of variable.
    printf("At what places in memory are variables stored?\n");
    printf("Address of x -> %d\n", &x);
    printf("Address of y -> %d\n", &y);
    printf("Address of a -> %d\n", &a);
    int i;
    for (i = 0; i < 10; i++) {
        printf("Address of z[%d] -> %d\n", i, &z[i]);
    }


    // How do you store address of variable?
    printf("How do you store address of variable?\n");
    
    // We can not use integer variables to store address
    // of variables.

    // int* ip = &x;
    
    // Illegal. Following code produces warning.
    // int l;
    // l = &x;

    // Use pointer variables to store address of variables.

    // Declare integer pointer variable to store
    // address of integer variable.
    // Declare character pointer variable to store
    // address of character variable.
    int* ip;
    char* cp;

    // Use ip variable to store address of x
    ip = &x;
    cp = &a;
    
    // &x -> Address of x
    // ip -> Value of ip is address of x
    //       This is also called as pointer to int x
    printf("Value of integer pointer ip -> %d\n", ip);
    printf("Value of character pointer cp -> %d\n", cp);
    
    // What does pointer point to or what is value at pointer ip? 
    printf("What is value at pointer ip?\n");
    // Value at pointer = *(pointer-variable)
    // *(ip) -> *(&x) -> Value at address of x -> Value of x
    // *ip is same as x.
    // * is also called indirection operator and is used to
    // dereference a pointer. 
    printf("Value at ip -> %d\n", *ip);

    // How to change value of x using pointers?
    printf("Can we change value of x using pointer?\n");
    // As *ip is value at address of x, change in *ip 
    // means change in x.
    *ip = 0;
    printf("Value of x -> %d\n", x);


    // What is a pointer to an array?
    printf("What is a pointer to an array?\n");
    // Pointer pointing to the first element of an array
    // is a pointer to an array
    ip = &z[0];

    // Another way of writing array pointer
    // ap also points to first element of z, as array
    // name returns address of first element of array.
    int* ap;
    ap = z;

    // Value of both ip and ap is same.
    printf("Value of ip -> %d\n", ip);
    printf("Value of ap -> %d\n", ap);
    printf("Value of z -> %d\n", z);


    // Incrementing pointers
    printf("What happens when we increment value of pointer?\n");
    ip = &x;
    printf("Value of  x -> %d\n", x);
    printf("Value at ip -> %d\n", *ip);

    // Increment one in the "value at" (*) pointer ip
    printf("*ip + 1 -> %d\n", *ip + 1);

    // Increment value at pointer ip 
    // Use prefix increment operator for operation

    // *ip -> x -> 0
    // ++*ip -> ++(*ip) -> *ip = *ip + 1
    printf("++*ip -> %d\n", ++(*ip));
    // Increment in *ip means increment in x.
    printf("Value of x -> %d\n", x);
    printf("Value at ip -> %d\n", *ip);
    printf("Address of x -> %d\n", ip);

    // Increment value of pointer ip using
    // postfix increment operator
    
    // *ip++ -> *(ip++) -> *(&x++) = *(ip + 1)
    // *ip is never incremented, 
    // only ip is incremented.
    printf("*ip++ -> %d\n", *ip++);
    // There is no change in value of x. However,
    // the memory location that ip points to is now
    // incremented and ip is now pointing to memory
    // location present after x.
    // *ip -> Uninitialized garbage value
    // ip -> &x + 4
    printf("Value of  x -> %d\n", x);
    printf("Value at ip -> %d\n", *ip);
    printf("Address -> %d\n", ip);


    // Increment value of pointer in arrays
    printf("Increment value of pointer in an array\n");

    // ip points to first element of the
    // integer array z
    ip = &z[0];

    z[0] = 100;
    z[1] = 120;

    printf("Value of ip -> %d\n", ip);
    printf("Value at ip -> %d\n", *ip); // 100

    // increment value of pointer
    ++ip;

    // What happens when we increment the pointer?
    // When you increment a pointer, the address is 
    // incremented by the number of bytes used to store 
    // that type of variable.

    // As ip is pointer, ++ip works as
    // ip = ip + sizeof(variable)
    // After increment ip now points to sequentially next 
    // integer in the memory.
    // In this case ip now points to &z[1].
    printf("Value of ip -> %d\n", ip);
    printf("Value at ip -> %d\n", *ip); // 120

    // ip -> z[0]
    // ip + 1 -> z[1]
    // ip + 2 -> z[2]
    // ...
    // ip + m -> z[m] 

    // This is easily visible in array as when we increment
    // pointer pointing to an array, the pointer then points
    // to next element in the array

    // If we know length of array then we can access all
    // elements of array using pointer.
    
    return 0;
}