/**
 * @file struct.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to demonstrate structs and their use in C
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

// Create a function that will tell us if a point is in a rectangle or not
int isPointInsideBox(struct rect box, struct point p) {
    return p.x >= box.pt1.x && p.x <= box.pt2.x && p.y >= box.pt1.y && p.x <= box.pt2.y;
}

int main (void) {

    struct rect box;

    // Declaration of Structure
    // Here point is a structure which has
    // variables x and y as its members.
    box.pt1.x = 300;
    box.pt1.y = 200;
    
    box.pt2.x = 400;
    box.pt2.y = 400;
    
    struct point p = {350, 250};

    printf("Is point inside rectangle -> %s", isPointInsideBox(box, p) == 1 ? "yes" : "no");
    // isPointInsideBox(box, p);

    // printf("p1.x -> %d\n", p1.x);
    // printf("p1.y -> %d\n", p1.y);

    // printf("p2.x -> %d\n", p2.x);
    // printf("p2.y -> %d\n", p2.y);

    // p2 = p1;

    // printf("After assignment\n");
    // printf("p2.x -> %d\n", p2.x);
    // printf("p2.y -> %d\n", p2.y);
}