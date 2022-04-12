/**
 * @file struct-arrays.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Structure array

// Create a structure array for a class of students,
// and then print the structure using function.
// 2 functions - simple print, print using pointers

#include<stdio.h>
#include<stdlib.h>

struct student {
    char* name;
    int age;
};

void printClassInfo(struct student class[], int no_of_students) {
    int i;
    for (i = 0; i < no_of_students; i++) {
        printf("Name of the student is -> %s\n", class[i].name);
        printf("Age of the student is -> %d\n", class[i].age);
    }
}

void printClassInfoUsingPointer(struct student* p, int no_of_students) {
    int i;
    for (i = 0; i < no_of_students; i++) {
        printf("Name of the student is -> %s\n", (*(p + i)).name);
        printf("Age of the student is -> %d\n", (*(p + i)).age);
    }
}



int main (void) {

    struct student class[10];

    struct student std;
    
    std.name = "john";
    std.age = 21;
    class[0] = std;

    std.name = "jane";
    std.age = 20;
    class[1] = std;

    printClassInfo(class, 2);
    
    struct student* p = malloc(2 * sizeof(struct student));

    (*(p)).name = "john";
    (*(p)).age = 21;

    (*(p + 1)).name = "jane";
    (*(p + 1)).age = 20;

    printClassInfoUsingPointer(&(p[0]), 2);

    return 0;
}