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

int main(void) {

    // This is driver function. We call all function
    // from this driver function.
    
    // Uncomment the function that you want to run
    // and check the output for.

    // test_switch();
    // test_break_continue();

    return 0;

}