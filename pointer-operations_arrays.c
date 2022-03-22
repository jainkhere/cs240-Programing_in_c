/**
 * @file pointer-operations_arrays.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief This programs shows how to represent array using
 *        pointers
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

void test_illegal_pointer_assignment() {
    int* p;
    // Without initializing pointer with a null value,
    // below assignment - *p = 100, could be dangerous 
    // as we are trying access and alter the value present
    // at an address that we know nothing about.
    
    // A pointer should always be set to null before we assign
    // value to that pointer.
    // That prevents any dangerous alterations we might perform
    // on the memory space.
    p = NULL;


    printf("Address of p -> %d\n", &p);
    printf("Value of p -> %d\n", p);
    printf("Value at p -> %d\n", *p);

    printf("Before assignment\n");

    // On some compilers your code may crash here if you
    // don't assign a NULL value to pointer.
    *p = 100;
    
    printf("After assignment\n");

    printf("Address of p -> %d\n", &p);
    printf("Value of p -> %d\n", p);
    printf("Value at p -> %d\n", *p);
}

int main(void) {

    test_illegal_pointer_assignment();

    char a[] = "HelloWorld";
    char b[] = "HelloCS240";

    // print a[6] and b[5]
    printf("Value of a[6] -> %c\n", a[6]);
    printf("Value of b[5] -> %c\n", b[5]);

    // Print values without using array name
    // TYPE *pointer-name = array-name
    // TYPE -> type of element of array
    char* pa = a;
    // pa + k -> a[k]
    char* pb = b;

    // *pa -> a[0], *(pa + 0) -> a[0]
    // *(pa + i) -> a[i]
    printf("Value of a[6] -> %c\n", *(pa + 6));
    printf("Value of b[5] -> %c\n", *(pb + 5));

    char* c[2];
    c[0] = pa;
    c[1] = pb;

    // print values without pa and pb

    // *(pa + i) -> a[i]
    // *(c[0] + i) -> a[i]
    // *c[0] -> *(pa) -> *(&a[0]) -> Value at address of a[0] -> a[0]
    printf("Value of a[6] -> %c\n", *(c[0] + 6));
    printf("Value of b[5] -> %c\n", *(c[1] + 5));

    // Represent c using pointer
    // TYPE *pointer-name = array-name
    // TYPE -> type of element of array
    char**pc = c;


    return 0;
}