/*  ========== H03 - Personal Queue Implementation ============
 *
 *   Student: Marian Padron
 *   Semester: Fall 2023
 *
 * A simple queue unit-tst implementation
 *
 */

#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// Tests the capacity of a stack
int unitTest1(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    if (MAX_DEPTH == test_s->capacity)
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Enqueu several items into a stack and test the size
int unitTest2(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    stack_enqueue(test_s, 3);
    stack_enqueue(test_s, 4);
    stack_enqueue(test_s, 5);
    stack_enqueue(test_s, 6);
    stack_enqueue(test_s, 7);
    stack_enqueue(test_s, 8);
    stack_enqueue(test_s, 9);
    stack_enqueue(test_s, 10);

    if (10 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack
int unitTest3(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }

    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack multiple times
int unitTest4(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Simple enqueu and deque stack test
// Also confirms that a stack is full
int unitTest5(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(1);
    stack_enqueue(test_s, 1);
    if (1 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        return 0;
    }

    stack_dequeue(test_s);
    if (0 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_stack(test_s);

    return passed;
}

// Tests stack_empty.
int unitTest6() {
    int passed = 0;
    stack_t *s = create_stack(MAX_DEPTH);

    // Test empty
    if (stack_empty(s) == 1) {
        passed++;
    }

    // Test not empty
    stack_enqueue(s, 1);
    if (stack_empty(s) == 0) {
        passed++;
    }

    free_stack(s);

    if (passed == 2) {
        return 1;
    }
    return 0;
}

// Tests stack_full.
int unitTest7() {
    int passed = 0;
    stack_t* s = create_stack(2);

    // Test not full
    stack_enqueue(s, 1);
    if (stack_full(s) == 0) {
        passed++;
    }

    // Test full
    stack_enqueue(s, 2);
    if (stack_full(s) == 1) {
        passed++;
    }

    free_stack(s);

    if (passed == 2) {
        return 1;
    }
    return 0;

}

// Tests stack_size.
int unitTest8() {
    int passed = 0;
    stack_t* s = NULL;

    // Test error message failed stack creation
    if (stack_size(s) == -1) {
        passed++;
    }

    // Test size return
    s = create_stack(1);
    stack_enqueue(s, 1);
    if (stack_size(s) == 1) {
        passed++;
    }

    free_stack(s);

    if (passed == 2) {
        return 1;
    }
    return 0;

}

// add your own, and uncomment the provided tests as
// things are implemented
int (*unitTests[])(int) = {
   unitTest1,
   unitTest2,
   unitTest3,
   unitTest4,
   unitTest5,
   unitTest6,
   unitTest7,
   unitTest8,
    NULL};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}