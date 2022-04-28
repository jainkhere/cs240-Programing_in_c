/**
 * @file binary_search_tree.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to implement Binary Search Tree
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

struct TREENODE {
    int value;
    struct TREENODE * left;
    struct TREENODE * right;
    struct TREENODE * parent;
};

typedef struct TREENODE NODE;

void add_value_to_tree(NODE ** addr_of_root, int character) {
    // Return if addr_of_root is null
    if (addr_of_root == NULL) {
        return;
    }
    
    // Create root node and set its value as 
    // value at address of root
    NODE * root = *addr_of_root;

    // Create new_node using malloc
    // Set value of new_node equal to the character
    // Set left, right and parent of new_node as NULL
    NODE * new_node = malloc(sizeof(NODE));
    (*new_node).value = character;
    (*new_node).left = NULL;
    (*new_node).right = NULL;
    (*new_node).parent = NULL;


    // If root is NULL
    if (root == NULL) {
        // Tree is empty
        // Set value at addr_of_root equal to newly created node
        *addr_of_root = new_node;
        return;
    }

    // If character is greater than or equal to value of root
    if (character >= (*root).value) {
        // Add new node to the right sub tree
        // Call add_value_to_tree with root.right as root node
        add_value_to_tree(&(*root).right, character);

        // Set root.right.parent as root node
        (*(*root).right).parent = root;
    }


    // If character is less than value of root
    if (character < (*root).value) {
        // Add new node to the left sub tree
        // Call add_value_to_tree with root.left as root node
        add_value_to_tree(&(*root).left, character);

        // Set root.left.parent as root node
        (*(*root).left).parent = root;
    }
}

// Inorder traverdal of tree
void print_in_order (NODE * node) {
    // In order traversal - Left Root Right

    // return if node is null
    if (node == NULL) {
        return;
    }

    // call print_in_order function on left subtree
    print_in_order((*node).left);
    // print the value of root
    printf("%d ", (*node).value);
    // call print_in_order function on right subtree
    print_in_order((*node).right);
}

int main(void) {
    NODE * root = NULL;

    int character;
    while((scanf("%d", &character)) != EOF) {
        // add value to tree
        add_value_to_tree(&root, character);
    }
    print_in_order(root);

    return 0;
}