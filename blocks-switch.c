/**
 * @file blocks-switch.c
 * @author kunal jain (kunal.jain051@umb.edu)
 * @brief Program to demonstrate switch block
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include<stdio.h>

#define STATE 1

// Macros may not work as expected when
// defined without brackets.
#define SQUARENB(A) (A*A)      // Macro without brackets around expression
#define SQUARE(A) ((A)*(A))    // Macro with brackets around expression 

// Use backslash (\) to write macro definition in two line.
// Following macro swaps value of x and y. t is data type int.
#define EXCHG(t, x, y) { t d; d = x; x = y;\
         y = d;}

// This function shows how switch statement works.
void test_switch() {
    enum weekdays { ERR, SUN, MON, TUE, WED, THUR, FRI, SAT };
    // ERR -> 0
    // SUN -> 1
    // MON -> 2 ... and so on

    // Scan input using scanf()
    // syntax -> scanf("<format-specifier>", <address-of-variable>)
    int num;
    printf("Please enter a weekday number : ");
    scanf("%d", &num); 

    // 1. Switch compares value of variable with all cases.
    // 2. If a case is statisfied then statements inside that
    //    case are executed.
    // 3. Default case runs in case no case is satisfied.
    // 4. End all cases using break statement.
    switch(num) {
        case 0:
            printf("Invalid weekday\n");
            break;
        case SUN:
            printf("Day is Sunday\n");
            break;
        case MON:
            printf("Day is Monday\n");
            break;
        default:
            printf("Day is between Tuesday and Sat\n");
            // break;
    }
}

// This function is an example of 
// break and continue statements.
void test_break_continue() {
    int i;
    for (i = 1; i <= 7; i++) {

        // Break -> Brings control to end of 
        //          current loop or switch case.
        // For eg, this loop ends when i = 5
        if (i == 5)
            break;
        
        // Continue -> Cases next iteration of 
        //             enclosing loop to begin.
        // For eg, when i = 2, control goes
        // to next iternation of the loop.
        if (i == 2)
            continue;
        
        printf("The value of i is %d\n", i);
    }
}

// This function shows how to
// use macros without arguments.
void test_macro_no_arg() {
    if (STATE) {
        printf("Macro substitution works!");
    }
}

// This function shows how to 
// using macro with arguments.
void test_macro_arg() {
    int n = 9;
    n = SQUARENB(n + 1);    // Substitution -> (n + 1*n + 1)
    printf("Value of n when no brackets in Macro definition -> %d\n", n);
    n = 9;
    n = SQUARE(n + 1);      // Substitution -> ((n + 1)*(n + 1))
    printf("Value of n brackets in Macro definition -> %d\n", n);
}

// Using EXCHG macro to swap
// values of two variables.
void test_macro_exchg() {
    int a = 5, b = 7;
    printf("Value of a and be is %d and %d respectively\n", a, b);
    EXCHG(int, a, b);
    // Above macro expands as follows
    // Shown in multiple lines for clarity
    // {
    //     int d;
    //     d = u;
    //     u = v;
    //     v = d;    
    // }
    // In above expansion, d is defined locally within block.
    printf("Value of a and be is %d and %d respectively\n", a, b);
}

int main(void) {

    // This is driver function. We call all function
    // from this driver function.
    
    // Uncomment the function that you want to run
    // and check the output for.

    // test_switch();
    // test_break_continue();
    // test_macro_no_arg();
    // test_macro_arg(); 
    // test_macro_exchg();

}