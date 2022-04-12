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

int main(void) {
    
    int character;
    // Create pointer to NODE and initialize it with null value
    // This is first NODE in the linked list
    struct NODE * first = NULL;
    
    // Read input characters
    while(1) {
        character = getchar();

        // Break loop if character is EOF
        if (character == EOF) {
            break;
        }

        // Add character if not EOF
        else {
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
        }
    }
    // print all characters that we just read.
    // start printing from first character

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

    return 0;

}
