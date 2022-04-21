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

// Insert node at a given position in linked list
void insertNode(struct NODE ** addr_of_first, struct NODE ** addr_of_last, int position, char value) {
    // addr_of_first: address of the pointer to 1st node in the list
    // position: position to insert the node
    // value: value to insert

    // Create node to insert using malloc
    struct NODE * node_to_insert = malloc(sizeof(struct NODE));
    (*node_to_insert).value = value;
    (*node_to_insert).next = NULL;
    (*node_to_insert).prev = NULL;

    // Create node first, to hold value at address of first node
    struct NODE * first = NULL;
    first = *addr_of_first;
    
    // Create node current to keep track of node at current position
    // Initialize current node with first node.
    struct NODE * current = NULL;
    current = first;

    // Create node target to keep track of node at position - 1.
    // Insert node next to the target node
    // Initialize target with current.prev 
    struct NODE * target = NULL;
    target = (*current).prev;

    int i;
    // Run a loop to reach the position where we want to insert
    for (i = 1; i < position; i++) {
        // Set target = current and
        // current = current.next, until we reach insertion position
        target = current;
        current = (*current).next;
    }

    // If target == NULL 
    if (target == NULL) {
        // insert node at the first position
        // set node_to_insert.next = current
        (*node_to_insert).next = current;
        (*current).prev = node_to_insert;

        // update value at address of first node
        *addr_of_first = node_to_insert;
    }
    
    // If current == NULL
    else if (current == NULL) {
        // insert node at last position
        // set target.next = node_to_insert
        (*target).next = node_to_insert;
        (*node_to_insert).prev = target;

        // update value at address of last node
        *addr_of_last = node_to_insert;
    }
    
    // else
    else {
        // insert node between target and current node.
        // set forward and backward link between 
        // target and node_to_insert
        (*target).next = node_to_insert;
        (*node_to_insert).prev = target;
        // similarly set forward and backward link between 
        // node_to_insert and current
        (*node_to_insert).next = current;
        (*current).prev = node_to_insert;
    }
    
}

void removeNode(struct NODE ** addr_of_first, struct NODE ** addr_of_last, int position) {
    // Create a struct node. We will delete this node.
    struct NODE * node_to_remove = NULL;

    // Initialize node_to_remove with value at address of first node
    node_to_remove = *addr_of_first;

    // Run a loop to reach to the position that we need to remove
    int i;
    for (i  = 1; i < position; i++) {
        // Reach node_to_remove position and
        // set node_to_remove to node_to_remove.next
        node_to_remove = (*node_to_remove).next;
    }

    // get previous and next node of node_to_remove
    struct NODE * prev_node = (*node_to_remove).prev;
    struct NODE * next_node = (*node_to_remove).next;

    // Unlink node_to_remove.
    // Reset next value of prev_node and 
    // prev value of next_node.
    if (prev_node == NULL) {
        // Reset prev value of next_node
        (*next_node).prev = NULL;

        // Update value at address of first node
        *addr_of_first = next_node;
    }
    else if (next_node == NULL) {
        // Reset next value of prev_node
        (*prev_node).next = next_node;

        // Update value at address of last node
        *addr_of_last = prev_node;
    }
    else {
        // Reset next value of prev_node
        (*prev_node).next = next_node;
        // Reset prev value of next_node
        (*next_node).prev = prev_node;
    }

    // Release memory using free function
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

    removeNode(&first, &last, 5);

    printLinkedList(first);
    printf("\n");

    insertNode(&first, &last, 5, '7');

    printLinkedList(first);
    printf("\n");

    printLinkedListReverse(last);

    return 0;

}