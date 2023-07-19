
// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node
{
    int data;
    struct node *next;  
    struct node *previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL
{
    int count;    // count keeps track of how many items are in the DLL.
    node_t *head; // head points to the first node in our DLL.
    node_t *tail; // tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t *create_dll()
{
    // Modify the body of this function as needed.
    dll_t *myDLL = (dll_t*)malloc(sizeof(dll_t));

    if (myDLL == NULL){
        return NULL;
    }
    myDLL -> head = NULL;
    myDLL -> tail = NULL;
    myDLL -> count = 0;

    return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t *l)
{
    if (l == NULL){
        return -1;
    }
    if (l -> count == 0) {
        return 1;
    }
    return 0;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t *l, int item)
{
    // Check for valid DLL
    if (dll_empty(l) == -1) {
        return -1;
    }
    // Create new mode
     node_t* new_node = (node_t*)malloc(sizeof(node_t));
     new_node -> data = item;
     l -> count++;

     // Check correct memory allocation
     if (new_node == NULL) {
        return 0;
     }

    // Check if DLL empty, create head and tail
    if (l -> head == NULL) {
        l -> head = new_node;
        l -> tail = new_node;

    // If not empty, push to front
    } else {

        new_node -> next = l -> head;
        l -> head -> previous = new_node;
        l -> head = new_node;
    }

    return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t *l, int item)
{
    // Check valid DLL
    if (dll_empty(l) == -1) {
        return -1;
    }

    // Create new mode
     node_t* new_node = (node_t*)malloc(sizeof(node_t));
     new_node -> data = item;
     l -> count++;

     // Check correct memory allocation
     if (new_node == NULL) {
        return 0;
     }

    // Check if DLL empty, create head and tail
    if (l -> tail == NULL) {
        l -> head = new_node;
        l -> tail = new_node;

    // If not empty push to back
    } else {

        l -> tail -> next = new_node;
        new_node -> previous = l -> tail;
        l -> tail = new_node;
    }

    return 1;

}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t *t)
{
    // Check valid DLL
    if (dll_empty(t) == -1) {
        return -1;
    }

    // Check nothing to pop
    if (t -> head == NULL) {
        return 0;

    }
    // hold item to pop
    int popped = t -> head -> data;

    // check if on last node
    if(t -> head -> next == NULL) {
        //free(t -> head);
        t -> count--;
        return popped;
    }

    node_t* new_head = t -> head -> next;
    t -> head -> next -> previous = NULL;
    //free(t -> head);

    // make head -> next the new head
    t -> head = new_head;
    t -> count--;

    return popped;

}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t *t)
{
    // Check valid DLL
    if (dll_empty(t) == -1) {
        return -1;
    }

    // Check nothing to pop
    if (t -> tail == NULL) {
        return 0;

    }
    // hold popped item
    int popped = t -> tail -> data;

    // check if on last node
    if(t -> tail -> previous == NULL) {
        //free(t -> tail);
        t -> count--;
        return popped;
    }

    node_t *new_tail = t -> tail -> previous;
    t -> tail -> previous -> next = NULL;
    //free(t -> tail);

    // make tail -> previous new head
    t -> tail = new_tail;
    t -> count--;

    return popped;

}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t *l, int pos, int item)
{
    // Check valid DLL
    if (dll_empty(l) == -1) {
        return -1;
    }

     if (dll_empty(l) == 1 || pos < 0 || pos > l -> count) {
        return 0;
    } 
    
    // inserting at front or back
    if (pos == 0) {
        return dll_push_front(l, item);
    }
    if (pos == l -> count) {
        return dll_push_back(l, item);
    }

    // Create new mode
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node -> data = item;
    if (new_node == NULL) { return 0; }
    
    // inserting at other positions
    node_t* position = l -> head;
    for (int i = 0; i < pos; i++) {
        position = position -> next;
    }

    new_node -> previous = position -> previous;
    new_node -> next = position;
    position -> previous -> next = new_node;
    position -> previous = new_node;

    l -> count++;

    return 1;

}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t *l, int pos)
{
    // Check valid DLL and pos
    if (dll_empty(l) == -1) {
        return -1;
    }
    if (dll_empty(l) == 1 || pos < 0 || pos > l -> count - 1) {
        return 0;

    }
    // Move position to location
    node_t* position = l -> head;
    for (int i = 0; i < pos; i++) {
        position = position -> next;
    }
    return position -> data;

}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the value of the node removed.
int dll_remove(dll_t *l, int pos)
{
    // Check valid DLL and pos
    if (dll_empty(l) == -1) {
        return -1;
    }
    if (dll_empty(l) == 1 || pos < 0 || pos > l -> count - 1) {
        return 0;

    } 

    // Use pop front, pop back
    if (pos == 0) {
        return dll_pop_front(l);
    }
    if (pos == l -> count - 1) {
        return dll_pop_back(l);
    }

    // Move position to location
    node_t* position = l -> head;
    for (int i = 0; i <= pos - 1 ; i++) {
        position = position -> next;
    }
    // hold value of node
    int removed = position -> data;

    position -> next -> previous = position -> previous;
    position -> previous -> next = position -> next;
    //free(position);
    l -> count--;

    return removed; 

}

// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t *t)
{
    // Check valid DLL
    if (dll_empty(t) == -1) {
        return -1;
    }

    return t -> count;
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the program terminates.
void free_dll(dll_t *t)
{
    if (dll_size(t) != 0) {
        node_t* next = t -> head;
        for (int i = 0; i < t -> count; i++) {
            free(next);
            next = next -> next;
        }
    }
    free(t);
}

#endif