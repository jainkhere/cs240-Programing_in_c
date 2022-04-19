/**
 * @file linked_list_more.c
 * @author Add, remove and print characters in a double linked list
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
//      3. Prev -> Pointer to the previous node
struct NODE {
    char value;
    struct NODE * next;
    struct NODE * prev;
};

void printLinkedList (struct NODE* first) {
    // To print, create a pointer to a NODE and initialize it with null
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

void printLinkedListReverse (struct NODE* last) {
    // To print, create a pointer to a NODE and initialize it with null
    // This code keeps track of current element of the linked list 
    struct NODE * current = NULL;
    
    // Start with current = last
    current = last;
    
    // print till first node.
    while(current != NULL) {
        printf("%c", (*current).value);

        // set current to current.prev in each iteration
        current = (*current).prev;
    }
}

void removeNode(struct NODE ** addr_of_first, int position) {
    struct NODE * node_to_remove = NULL;

    node_to_remove = *addr_of_first;
    int i;
    for (i  = 1; i < position; i++) {
        node_to_remove = (*node_to_remove).next;
    }
    struct NODE * prev_node = (*node_to_remove).prev;
    struct NODE * next_node = (*node_to_remove).next;

    (*prev_node).next = next_node;
    (*next_node).prev = prev_node;

    free(node_to_remove);
}


// Append new node in a linked list in much less time and computation.
// Instead of going to the first element and then going through
// all the elements using node.next to reach last element, 
// keep track of last node and append new element to this last node.
void appendNewNodeFaster (struct NODE ** addr_of_first, struct NODE ** addr_of_last, int character) {
    // Create first and last node to hold value at address of first and last node
    struct NODE * first = NULL;
    struct NODE * last = NULL;

    first = *addr_of_first;
    last = *addr_of_last;

    // create a new_node
    // allocate memory using malloc
    // new_node.value = character
    // new_node.next = null
    // new_node.prev = null
    struct NODE * new_node = malloc(sizeof(struct NODE));
    (*new_node).value = character;
    (*new_node).next = NULL;
    (*new_node).prev = NULL;

    // If first = null, that means list is empty
    if (first == NULL) {
        // add new_node at starting position
        // first = new_node and last = new_node
        first = new_node;
        last = new_node;

        // update the value at address of first and last
        *addr_of_first = first;
        *addr_of_last = last;
    }

    // If first != null
    else {
        // As we already have a track of last node linked list, 
        // just add a new node next to it

        // set last.next to new_node. 
        // This corresponds to the forward link in the node.
        // set new_node.prev to last. 
        // This corresponds to the backward link in the node.
        (*last).next = new_node; // forward link
        (*new_node).prev = last; // backward link

        // update value at address of last
        *addr_of_last = new_node;
    }

}

int main(void) {
    
    int character;
    // Create pointer to NODE and initialize it with null value
    // This is first NODE in the linked list
    struct NODE * first = NULL;
    struct NODE * last = NULL;
    
    // Read input characters
    while((character = getchar()) != EOF) {
        // Append character if not EOF

        // Append a character faster in linked list
        appendNewNodeFaster(&first, &last, character);
    }
    // print all characters that we just read.
    // start printing from first character
    printLinkedList(first);

    printf("\n");

    removeNode(&first, 2);

    printLinkedList(first);
    printf("\n");

    printLinkedListReverse(last);

    return 0;

}