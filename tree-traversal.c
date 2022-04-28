/**
 * @file tree-traversal.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Program to show preorder, postorder and inorder tree traversal
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

// Create TREENODE structure
// Members -
// int value - value of node
// struct pointer left - pointer to left node
// struct pointer right - pointer to right node
struct TREENODE {
    int value;
    struct TREENODE * left;
    struct TREENODE * right;
};

// Create short hand for struct TREENODE
typedef struct TREENODE NODE;

// Create a node with a given value and return it
NODE * create_node(int value) {
    NODE * node = malloc(sizeof(NODE));
    (*node).value = value;
    (*node).left = NULL;
    (*node).right = NULL;

    return node;
}

// Postorder traverdal of tree
void print_post_order (NODE * node) {
    // Post order traversal - Left Right Root

    // Return if node is null
    if (node == NULL) {
        return;
    }

    // call print_post_order function on left subtree
    print_post_order((*node).left);
    // call print_post_order function on right subtree
    print_post_order((*node).right);
    // print the value of root
    printf("%d ", (*node).value);
}

// Preorder traverdal of tree
void print_pre_order (NODE * node) {
    // Pre order traversal - Root Left Right

    // Return if node is null
    if (node == NULL) {
        return;
    }

    // print the value of root
    printf("%d ", (*node).value);
    // call print_pre_order function on left subtree
    print_pre_order((*node).left);
    // call print_pre_order function on right subtree
    print_pre_order((*node).right);
}

// Inorder traverdal of tree
void print_in_order (NODE * node) {
    // In order traversal - Left Root Right

    // Return if node is null
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
    // Create tree by adding node
    NODE * root = create_node(1);
    (*root).left = create_node(2);
    (*root).right = create_node(3);
    (*(*root).left).left = create_node(4);
    (*(*root).left).right = create_node(5);

    // Print tree using in order traversal
    printf("Inorder traversal -> ");
    print_in_order(root);

    printf("\n");
    
    // print tree using pre order traversal
    printf("Preorder traversal -> ");
    print_pre_order(root);

    printf("\n");

    // print tree using post order traversal
    printf("Postorder traversal -> ");
    print_post_order(root);

    printf("\n");

    return 0;
}