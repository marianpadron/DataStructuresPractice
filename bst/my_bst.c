/** Implementation of the BST data structure 
 * 
 * @author Marian Padron
 * Semester Spring 2023
*/

#include "my_bst.h"

/**
 * Checks to see if the tree is empty
 * by looking at the tree size.
 * returns true if the tree is empty.
 * False otherwise.
*/
bool bst_is_empty(BST *tree) {
    if (tree == NULL) return false;
    if(tree -> size == 0) return true;
    return false;
}

/**
* Helper function for bst_exists.
*/
bool exists_helper(Node* root, int value) {
    if(root == NULL) return false;
    if(root -> data == value) return true;
    bool left = exists_helper(root -> left, value);
    bool right = exists_helper(root -> right, value);
    return left || right;
}

/**
 * Checks to see if the value exists in the tree.
 * returns true if the value exists in the tree.
 * False otherwise.
*/
bool bst_exists(BST *tree, int value)
{
    if (tree == NULL) return false;
    return exists_helper(tree -> root, value);
}

/**
 * Returns the size of the tree.
*/
unsigned int bst_size(BST *tree) {
    if (tree == NULL) return 0;
    return tree -> size;
}

/**
* Creates a tree node to add to tree.
*/
Node* create_node(int value) {
    // Create tree node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

/**
* Add node helper.
*/
Node* add_helper(Node* root, int value) {
    // If on last leaf return newNode to previous left or right
    if (root == NULL) return create_node(value);

    // Iterate through left until find last leaf
    if (value < root -> data) {
        root -> left = add_helper(root -> left, value);
    } else if (value > root -> data) {
        root -> right = add_helper(root -> right, value);
    }

    return root;
}

/**
 * Adds a value to the tree.
 * returns 1 if the value was added successfully.
 * returns 0 if the value already exists in the tree.
 * returns -1 if the value could not be added due to errors. (malloc failed)
*/
int bst_add(BST *tree, int value) {
    // Check if value exists and tree exists
    if (bst_exists(tree, value)) return 0;
    if (tree == NULL) return -1;

    // Add node to root if empty
    if (tree -> root == NULL) {
        Node* prev_root = create_node(value);
        tree -> root = prev_root;
        tree -> size += 1;
        if (prev_root) return 1; // check creation
    } else {
        // Add node to tree
        Node* prev_root = add_helper(tree -> root, value);
        tree -> size += 1;
        if (prev_root -> right == NULL && prev_root -> left == NULL) return -1; // check creation
    }
    
    return 1;

}

/**
* Frees the tree's nodes inorder traversal
*/
void free_nodes(Node* root) {
    // Check if reached last leaf
    if (root == NULL) return;

    // Traverse tree inorder
    free_nodes(root -> left);
    free(root);
    free_nodes(root -> right);

}

/**
 * Frees the memory allocated for the tree.
 * hint: Think about which order works for traversal (pre, in, post) and how that
 * can help you free the memory
*/
void bst_free(BST *tree) {
    if (tree == NULL) return;
    free_nodes(tree -> root);
    free(tree);
}

/**
 * Creates a new BST.
 * returns a pointer to the new BST.
 * The root node will still be NULL until the first bst_add is called
*/
BST *create_bst() {
    BST* newBst = (BST*)malloc(sizeof(BST));
    newBst -> root = NULL;
    newBst -> size = 0;
    return newBst;
}

