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

// Function to know if node is right most node or not
// Return 1 if node is right most node
// Return 0 otherwise
int is_right_most_node(NODE * node) {
    // Keep going up following right-child
    // if we can reach the root, then node is right most node
    // if we cannot reach the root, it is not the right most node

    // return 0 if node is null
    if (node == NULL) 
        return 0;

    // return 0 if right child of node is not null
    if ((*node).right != NULL)
        return 0;

    
    while(1) {
        NODE * parent = (*node).parent;
        if (parent == NULL) {
            // we have reached the root
            return 1;
        }
        if ((*parent).right == node)
            node = (*node).parent;
        // if node is not right child then it is left child,
        // and therefore it cannot be right most node
        else
            return 0;
    }
}

// Function to get right most node
// In binary search tree, right most node is
// same as max value in the tree
NODE * get_right_most_node(NODE * root) {
    // return if root is null
    if (root == NULL) {
        return NULL;
    }
    
    // create a temp node. initialize it with root
    // keep on traversing temp.right until temp.right is null
    // you will reach right most node
    NODE * temp = root;
    while((*temp).right != NULL) {
        temp = (*temp).right;
    }
    return temp;
}

// Function to get left most node
// In binary search tree, left most node is
// same as min value in the tree
NODE * get_left_most_node(NODE * root) {
    // return if root is null
    if (root == NULL) {
        return NULL;
    }

    // create a temp node. initialize it with root
    // keep on traversing temp.left until temp.left is null
    // you will reach left most node
    NODE * temp = root;
    while((*temp).left != NULL) {
        temp = (*temp).left;
    }
    return temp;
}

void print_tree_increasing_order (NODE * root) {
    if (root == NULL)
        return;
    
    // print all values on left subtree
    print_tree_increasing_order((*root).left);

    // print root
    if (is_right_most_node(root) == 1)
        printf("%d", (*root).value);
    else
        printf("%d, ", (*root).value);
    
    // print all values on right subtree
    print_tree_increasing_order((*root).right);
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

    // stdin: 1 10 3 2 20 30 4 18 11

    int character;
    while((scanf("%d", &character)) != EOF) {
        // add value to tree
        add_value_to_tree(&root, character);
        // printf("%d\n", (*root).value);
    }
    print_in_order(root);
    printf("\n");
    print_tree_increasing_order(root);

    return 0;
}