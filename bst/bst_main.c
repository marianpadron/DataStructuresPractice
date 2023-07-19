/**
 * Use this file to add your own tests and run a mini BST program.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_bst.h"
#include "my_bst_util.h"
#include "my_bst.c"
#include "my_bst_printer.c"
#include "my_bst_util.c"


// a helper to get a range  of numbers
int *get_range_array(int start, int end) {
    int *arr = (int*) malloc(sizeof(int) * (end - start));
    int j = 0;
    for (int i = start; i < end; i++, j++) arr[j] = i;
    return arr;
}

// sample helper function to help you create random int arrays
int *get_random_array(int size) {
    int *arr = (int *)malloc(sizeof(int) * size);
    srand(time(NULL)); // seed the random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

/**
* Test create tree and free.
*/
int test1() {
    BST* tree = create_bst();
    bst_add(tree, 2);
    if (tree -> size != 1) return 1;
    if (tree -> root -> data != 2) return 1;
    //bst_print(tree, "inorder");
    bst_free(tree);
    return 0;
}

/**
* Tests bst_size.
*/
int test2() {
    BST* tree = create_bst();
    bst_add(tree, 2);
    if (bst_size(tree) != 1) return 1;
    bst_add(tree, 3);
    if (bst_size(tree) != 2) return 1;
    bst_free(tree);
    return 0;
}

/**
* Tests bst_is_empty.
*/
int test3() {
    BST* empty_tree = create_bst();
    BST* tree = create_bst();
    bst_add(tree, 2);

    if(bst_is_empty(empty_tree) && !bst_is_empty(tree)) {
        bst_free(tree);
        bst_free(empty_tree);
        return 0;
    }

    return 1;
}

/**
* Tests add serveral nodes.
*/
int test4() {
    BST* tree = create_bst();
    bst_add(tree, 2);
    bst_add(tree, 3);
    bst_add(tree, 1);
    bst_add(tree, 4);
    if (bst_size(tree) != 4) return 1;
    // Check correct order
    if (tree -> root -> right -> right -> data != 4) return 1;
    if (tree -> root -> right -> data != 3) return 1;
    if (tree -> root -> left -> data != 1) return 1;
    //bst_print(tree, "inorder");
    bst_free(tree);
    return 0;
}

/**
* Tests bst_exists.
*/
int test5() {
    BST* tree = create_bst();
    int results = 0;
    bst_add(tree, 2);
    bst_add(tree, 3);
    bst_add(tree, 1);
    if (bst_exists(tree, 1)) results++;
    if (bst_exists(tree, 3)) results++;
    if (bst_exists(tree, 2)) results++;
    if (!bst_exists(tree, 5)) results++; // test nonvalid value
    bst_free(tree);
    if (results == 4) return 0;
    return 1;
}

/**
* Test bst sum.
*/
int test6() {
    BST* tree = create_bst();
    bst_add(tree, 2);
    bst_add(tree, 3);
    bst_add(tree, 1);
    if (sum(tree) != 6) return 1;
    bst_free(tree);
    return 0;
}

/**
* Test bst min.
*/
int test7() {
    BST* tree = create_bst();
    bst_add(tree, 2);
    bst_add(tree, 3);
    bst_add(tree, 1);
    if (min(tree) != 1) return 1;
    bst_free(tree);
    return 0;
}

/**
* Test bst max.
*/
int test8() {
    BST* tree = create_bst();
    bst_add(tree, 2);
    bst_add(tree, 3);
    bst_add(tree, 1);
    if (max(tree) != 3) return 1;
    bst_free(tree);
    return 0;
}

/**
* Test for tree with values 1 - 100.
*/
int test9() {
    BST* tree = create_bst();
    for (int i = 0; i < 100; i++) {
        bst_add(tree, i);
    }
    if (bst_size(tree) != 100) return 1;
    if (sum(tree) != 4950) return 1;

    bst_free(tree);
    return 0;
}

int main(int argc, char const *argv[])
{
    int passed = 0;
    passed += test1();
    passed += test2();
    passed += test3();
    passed += test4();
    passed += test5();
    passed += test6();
    passed += test7();
    passed += test8();
    passed += test9();

    if (passed == 0) {
        return printf("All tests have passed.\n");
    } else {
        printf("At least one test has failed.\n");
    }

    return 0;
}
