/**
 * @file linked_list.c
 * @author Add and print characters using a linked list
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

// Create a structure for node of linked list
// Each node contains 2 attributes/members
//      1. Value -> Value of the node
//      2. Next -> Pointer to the next node
struct NODE {
    char value;
    struct NODE * next;
};

void printLinkedList (struct NODE* first) {
    // To print, create a pointer to a NODE and initialize if with null
    // This code keeps track of current element of the linked list 
    struct NODE * current = NULL;
    
    // Start with current = first
    current = first;
    
    // print till last character.
    while(current != NULL) {
        printf("%c", (*current).value);

        // set current to current.next in each iteration
        current = (*current).next;
    }
}

struct NODE * addNewNodeFront (struct NODE* first, int character) {
    // create a new_node
    // allocate memory using malloc
    // new_node.value = character
    // new_node.next = null
    struct NODE * new_node = malloc(sizeof(struct NODE));
    (*new_node).value = character;
    (*new_node).next = NULL;

    // If first = null, that means list is empty
    if (first == NULL) {
        // add new_node at starting position
        // first = new_node
        first = new_node;
    }

    // If first != null
    else {
        // Add new element to the front of the list
        
        // To add new_node at the front, 
        // set new_node.next = first
        (*new_node).next = first;

        // update first to new_node, as new_node is now the starting node
        first = new_node;
    }

    return first;
}

struct NODE* appendNewNode (struct NODE* first, int character) {
    // create a new_node
    // allocate memory using malloc
    // new_node.value = character
    // new_node.next = null
    struct NODE * new_node = malloc(sizeof(struct NODE));
    (*new_node).value = character;
    (*new_node).next = NULL;

    // If first = null, that means list is empty
    if (first == NULL) {
        // add new_node at starting position
        // first = new_node
        first = new_node;
    }

    // If first != null
    else {
        // Go to the end of the linked list, 
        // and add a new node

        // Create a pointer to a node and initialize it with null
        // This node keeps track of last element of linked list.
        struct NODE * last = NULL;
        
        // After initialization, set last = first.
        last = first;
        
        // Go to the end of linked list
        // through next member of last NODE
        while((*last).next != NULL) {
            // last = last.next
            last = (*last).next;
        }
        
        // Once reached to the end, set last.next to new_node
        (*last).next = new_node;
    }

    return first;                       
}

// Will implement following function in next class.

// Append new node in a linked list in much less time and computation.
// Instead of going to the first element and then going through
// all the elements using node.next to reach last element, 
// keep track of last node and append new element to this last node.
appendNewNodeFaster (struct NODE * first, struct NODE * last, int character) {
    // TODO
}

int main(void) {
    
    int character;
    // Create pointer to NODE and initialize it with null value
    // This is first NODE in the linked list
    struct NODE * first = NULL;
    
    // Read input characters
    while((character = getchar()) != EOF) {
        // Append character if not EOF

        // Append a character at the end of a linked list
        // first = appendNewNode(first, character);

        // Append a character at the front of a linked list
        // first = addNewNodeFront(first, character);
    }
    // print all characters that we just read.
    // start printing from first character
    printLinkedList(first);

    return 0;

}