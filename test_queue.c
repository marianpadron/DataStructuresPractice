/*  ========== H03 - Personal Queue Implementation ============
 *
 *   Student: Marian Padron
 *   Semester: Fall 2023
 *
 * A simple queue unit-tst implementation 
 *
 */

//
// Compile this assignment with: gcc -g -Wall queue_test.c -o queue_test
//
// Run with: ./queue_test
//

#include "myqueue.h"

#include <stdio.h> // For IO operations


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.

// Tests that a new queue was created and the capacity
// was properly set.
int unitTest1(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(30);
    if (30 == testq->capacity)
    {
        passed = 1;
    }
    free_queue(testq);

    return passed;
}

// Tests adding multiple items to a queue
int unitTest2(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(10);
    queue_enqueue(testq, 1);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 3);
    queue_enqueue(testq, 4);
    queue_enqueue(testq, 5);
    queue_enqueue(testq, 6);
    queue_enqueue(testq, 7);
    queue_enqueue(testq, 8);
    queue_enqueue(testq, 9);
    queue_enqueue(testq, 10);
    if (10 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing
int unitTest3(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing multiple times
int unitTest4(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

int unitTest5(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(1);
    queue_enqueue(testq, 1);
    if (1 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        free_queue(testq);
        return 0;
    }

    queue_dequeue(testq);
    if (0 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_queue(testq);

    return passed;
}

// Tests correct error message received when dequeueing an empty queue.
int unitTest6(int status){
    int passed = 0;

    queue_t *q = create_queue(3);
    int exit_failure = queue_dequeue(q);

    if (exit_failure == 1){
        passed++;
    }
    
    free_queue(q);
    return passed;
    
}

// Tests queue_empty fuction.
int unitTest7(){
    int passed = 0;

    // Test empty queue.
    queue_t *empty_q = create_queue(2);
    if (queue_empty(empty_q) == 1){
        passed++;
    }

    // Test non-empty queue.
    queue_t *q = create_queue(2);
    queue_enqueue(q, 1);
    if (queue_empty(q) == 0){
        passed++;
    }
    
    free_queue(q);
    free_queue(empty_q);

    // Return 1 if passed both 
    if(passed == 2){
        return 1;
    }
    return 0;
 
}

// Tests queue_full.
int unitTest8(){
    int passed = 0;

    // Test full queue
    queue_t *q = create_queue(2);
    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    passed += queue_full(q);

    //Test empty queue
    queue_t *q2 = create_queue(2);
    if (queue_full(q2) == 0) {
        passed += 1;
        
    }

    free_queue(q);
    free_queue(q2);

    if (passed == 2) {
        return 1;
    }
    return 0;

}

// Tests queue_size.
int unitTest9(){
    int passed = 0;
    queue_t *q = NULL;
    
    // Check queue not created error
    if (queue_size(q) == -1) {
        passed++;
    }

    // Check return queue size
    q = create_queue(2);
    queue_enqueue(q, 1);
    if (queue_size(q) == 1) {
        passed++;
    }

    free_queue(q);

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
    unitTest9,
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