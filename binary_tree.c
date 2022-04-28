/**
 * @file binary_tree.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief Construct a binary tree. 
 *        Parent node is less than both child
 * @version 0.1
 * @date 2022-04-28
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
// struct pointer parent - pointer to parent node
struct TREENODE {
    int value;
    struct TREENODE * left;
    struct TREENODE * right;
    struct TREENODE * parent;
};

// Create short hand for struct TREENODE
typedef struct TREENODE NODE;

void add_value_to_node (NODE ** addr_of_root, int insert_value) {
    // Create a root node to hold value at address of root
    NODE * root = *addr_of_root;

    // Create a new node that we will add in tree
    // Use malloc to create new node. Set value of 
    // new node equal to the value passed in function arguments
    NODE * new_node = malloc(sizeof(NODE));
    (*new_node).value = insert_value;
    (*new_node).left = NULL;
    (*new_node).right = NULL;
    (*new_node).parent = NULL;
 
    // If root is null, tree is empty.
    // Set value at address of root equal to 
    // new_node
    if (root == NULL) {
        *addr_of_root = new_node;
        return;
    }

    // Else tree is not empty.

    // Compare value of root with insert_value
    // If root value greater than insert_value then 
    // 1. set current root as left child of new_node
    // 2. set new_node as current root parent
    // 3. make new_node the root of the tree
    if ((*root).value > insert_value) {
        (*new_node).left = root;
        (*root).parent = new_node;
        *addr_of_root = new_node;
        return;
    }
    
    // If left child of root does not exist then
    // 1. make new_node the left child of root
    if ((*root).left == NULL) {
        (*root).left = new_node;
        (*new_node).parent = root;
        return;
    }

    // If right child of root does not exist then
    // 1. make new_node the right child of root
    if ((*root).right == NULL) {
        (*root).right = new_node;
        (*new_node).parent = root;
        return;
    }

    // Create node for left and right child of root
    NODE * left_child = (*root).left;
    NODE * right_child = (*root).right;

    // If left child of root exist but it's value is 
    // less than or equal to insert_value then
    // 1. Call add_value_to_node on left subtree.
    // 2. make root the parent of left child
    // 3. set left_child node as left child of root
    if ((*left_child).value <= insert_value) {
        add_value_to_node(&left_child, insert_value);
        (*left_child).parent = root;
        (*root).left = left_child;
        return;
    }

    // If right child of root exist but it's value is 
    // less than or equal to insert_value then
    // 1. Call add_value_to_node on right subtree.
    // 2. make root the parent of right child
    // 3. set right_child node as right child of root
    if ((*right_child).value <= insert_value) {
        add_value_to_node(&right_child, insert_value);
        (*right_child).parent = root;
        (*root).right = right_child;
        return;
    }

    // If left and right child of root, both exist but
    // their values are greater than insert_value then
    // 1. set right child of root as left child of new_node
    // 2. set parent of right child as new_node
    // 3. make new_node, a right child of root
    // 4. make root parent of new_node
    (*new_node).left = right_child;
    (*right_child).parent = new_node;
    right_child = new_node;
    (*new_node).parent = root;
    return;

}

// Find node on tree whose value is equal to node_to_find
// root - pointer to root node
// node_to_find - value of node to find
NODE * find_node (NODE * root, int node_to_find) {
    // if root is null then return null

    // if value of root is equal to node_to_find
    // then return root

    // recursively call find_node on left subtree
    // if node found then return it.

    // recursively call find_node on right subtree
    // return this node
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

    NODE * root = NULL;

    // stdin: 50 10 20 100 30 35 70 15 40

    // Create tree by adding node
    int character;
    while(scanf("%d", &character) != EOF) {
        add_value_to_node(&root, character);
    }

    // Print tree using in order traversal
    printf("Inorder traversal -> ");
    print_in_order(root);

    printf("\n");

    NODE * node = find_node(root, 40);
    printf("Value of found node -> %d\n", (*node).value);

    return 0;
}