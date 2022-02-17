/**
 * @file data-types-variables.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Simple functions to test data types, 
 *        constants and ternary operator.
 * @version 0.1
 * @date 2022-02-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

// Function to show overflow of char datatype
// When you declare a variable in C, by default
// it is a signed data type.
void test_datatype_overflow() {
    // signed char - 8 bits
    char c = 127;
    printf("Value of c -> %d\n", c);
    
    // overflows at 127
    // Value goes to negetive extreme 
    // after overflow
    c = 128;
    printf("Value of c -> %d\n", c);

    // underflows at -128
    // Value goes to positive extreme 
    // after underflow
    c = -129;
    printf("Value of C -> %d\n", c);
}

// Function to show sizeof()
// sizeof(data-type) -> Function returns size of 
//                      data type in bytes.
// sizeof() Argument -> variable name or data type
void test_datatype_size() {
    // sizeof() with explicit data type as argument
    printf("Size of char -> %d\n", sizeof(char));
    printf("Size of integer -> %d\n", sizeof(int));

    // sizeof() with variable name as argument
    short int i = 0;
    printf("Size of i -> %d\n", sizeof(i));
}

// This function shows how to define octal and 
// hexadecimal integer constants.
void test_var_octal_hexa() {
    // Leading 0 -> Octal value
    int octal = 0123;
    // Leading 0x -> hexadecimal value
    int hexa = 0x123;
    printf("Octal value in decimal -> %d\n", octal);
    printf("Hexadecimal value in decimal -> %d\n", hexa);
}

// Enumeration constants
// Value of Sunday -> 0
//          Monday -> 1 ... and so on
enum week { Sunday, Monday, Tuesday, Wednesday };

// Values of Enum start from 0, unless explicitly defined.

// Value of JAN -> 1 Explicitly defined
//          FEB -> 2
//          MAR -> 3 ... and so on
enum months { JAN = 1, FEB, MAR, APR, JUN };

// This function prints enum values.
void test_enum() {
    // Access enum value by declaring a variable 
    // of enum type. Here day is of type enum week
    enum week day;
    day = Wednesday;
    printf("Day -> %d\n", day);

    // Access enum value directly using 
    // name of enum element.
    printf("Value of Jan -> %d\n", JAN);
}

// This function prints initial value of local
// and static integer.
void test_var_initialization() {
    // Local int initializes with a garbage value
    int local_var;
    // Static int initializes with zero value
    static int static_var;

    printf("Value of local variable is -> %d\n", local_var);
    printf("Value of static variable is -> %d\n", static_var);

    // Remember to explicitly define local variables
    // as they initialize with a garbage value.
}

// Function to show how ternary operator works
void test_ternary_operator() {
    int z, a = 5, b = 7;
    
    // if (expr1) {
    //     expr2;
    // } else {
    //     expr3;
    // }

    // If else way to evaluate max(a,b)
    //
    // if (a > b) {
    //     z = a;
    // } else {
    //     z = b;
    // }

    // Ternary operator -> More concise if else
    // expr1 ? expr2 : expr3
    // If expr1 is true,
    //      evaluate expr2
    // else evaluate expr3

    // Ternary operator way to
    // evaluate max(a,b)
    z = (a > b) ? a : b;
    printf("Value of z -> %d\n", z);
}

int main(void) {

    // This is driver function. We call all function
    // from this driver function.
    
    // Uncomment the function that you want to run
    // and check the output for.

    // test_datatype_overflow();
    // test_datatype_size();
    // test_enum();
    // test_var_octal_hexa();
    // test_var_initialization();
    // test_ternary_operator();

    return 0;
}