/** Implementation of BST utility functions
 *
 *  @author Marian Padron
 * Semester Spring 2023
 *
*/


#include "my_bst_util.h"

/**
* Recursive helper for sum.
*/
void sum_helper(Node* root, int* sum) {
    if (root == NULL) return;
    sum_helper(root -> left, sum);
    *sum += root -> data;
    sum_helper(root -> right, sum);

}

/**
 * Returns the sum of all the values in the tree.
*/
int sum(BST *tree) {
    int sum = 0;
    sum_helper(tree -> root, &sum);
    return sum; 
}

/**
* Recursive helper for min.
*/
void min_helper(Node* root, int* min) {
    if (root == NULL) return;
    if (root -> data < *min) *min = root -> data;
    min_helper(root -> left, min);
    min_helper(root -> right, min);
}

/**
 * Returns the minimum value in the tree. 
*/
int min(BST *tree) {
    int min = tree -> root -> data;
    min_helper(tree -> root, &min);
    return min;
}

/**
* Recursive helper for max.
*/
void max_helper(Node* root, int* max) {
    if (root == NULL) return;
    if (root -> data > *max) *max = root -> data;
    max_helper(root -> left, max);
    max_helper(root -> right, max);
}

/**
 * Returns the maximum value in the tree.
*/
int max(BST *tree) {
    int max = tree -> root -> data;
    max_helper(tree -> root, &max);
    return max;
}
