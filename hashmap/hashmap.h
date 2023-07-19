/** 
 * CS 5008 - Homework 09
 * Student: Marian Padron
 * Semester: Spring 2023
*/
#ifndef HASHMAP
#define HASHMAP

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node
{
    char *key;
    float value;
    struct node *next;
} h_node;

typedef struct ht {
    int size;
    h_node **contents;

} *hashmap;

typedef unsigned long ul;
typedef h_node **hashTable;

/**
 * A hashing algorithm. Students may pick their own
 * but it is recommended they use one of the ones 
 * from the lab. 
*/
ul get_hash(char *str) {
    // Use DJB2 hashign method
    ul hash = 5381;
    int c;
    while((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

/**
 * Creates with the specified size.
*/
hashmap map_create(int size) {
    // Intialize map
   hashmap map = malloc(sizeof(hashmap));
   map -> size = size;

   // Malloc size of nodes
   //map -> contents = malloc(sizeof(h_node*) * size);
   map -> contents = calloc(size, sizeof(h_node*));
   return map;

}

/**
* Counts how many items are in the hashmap.
*/
int count_map(hashmap map) {
    int count = 0;
    // Iterate through hashmap
    for (int i = 0; i < map -> size; i++) {
        h_node *node = map -> contents[i]; // go through all indexes
        while (node != NULL) { // iterate until the end of chain
            count++;
            node = node -> next;
        }
    }
    return count;
}

/**
 * Gets a value from the hashmap. 
 * If a value is not found, return -1.0F
*/
float map_get(hashmap map, char *key) {
    // Get index
    unsigned int index = get_hash(key) % map -> size;

    if (map -> contents[index] == NULL) {
        return -1.0; // key not found
    } else {
        h_node *cur = map -> contents[index];
        while (cur != NULL) {
            if (strcmp(cur -> key, key) == 0) { // if find matching key, return value
                return cur -> value;
            }
            cur = cur -> next; // keep looping to find key
        }
    }

    return -1.0;

}

/**
 * Removes an item from the hashmap, returning
 * the value of the item. If an item
 * is not found to remove, return -1.0F
*/
float map_del(hashmap map, char *key) {
    // Get index
    unsigned int index = get_hash(key) % map -> size;
    // Get first node at index
    h_node *node = map -> contents[index];
    // Place holder for prevous node before node that will be deleted
    h_node *previous_node = NULL;
    // Iterate until find correct key
    while(node != NULL) {
        if (strcmp(node -> key, key) == 0) {
            // Node found is first in linked list
            if (previous_node == NULL) {
                map -> contents[index] = node -> next;
            } else {
                previous_node -> next = node -> next;
            }
            float value = node -> value;
            // Free node
            free(node);
            return value;
        }
        // Keep iterating through nodes
        previous_node = node;
        node = node -> next;
    }
    return -1.0;
}

/**
 * Stores a value into the hashmap. 
 * 1. if a key is already in the map, overwrites it with the new value
 * 2. if the key is not in the map, adds the key/value (node) pair.
*/
void map_put(hashmap map, char *key, float value) {
    // Get index
    unsigned int index = get_hash(key) % map -> size;

    // Create new node and add data
    h_node *new_node = malloc(sizeof(h_node));
    new_node -> key = key;
    new_node -> value = value;
    new_node -> next = NULL;

    // Store in table if no node current location
    if (map -> contents[index] == NULL) {
        map -> contents[index] = new_node;

    } else {
        // If collision, get to end of chain to add new node
        h_node *cur = map -> contents[index];

        // Check for override on first node
        if (strcmp(cur -> key, key) == 0) {
            cur -> value = value;
        }

        while (cur -> next != NULL) {
            if (strcmp(cur -> key, key) == 0) { // if same node key override
                cur -> value = value;
            }
            cur = cur -> next;
        }
        cur -> next = new_node; // Set new node at empty location of linked list
    }

}

/**
 * Prints the map in the specified format of
 * {key : value, key : value}
*/
void map_print(hashmap map) {
    printf("{");
    int print = 1;
    int count = count_map(map);

    for(int i = 0; i < map -> size; i ++) {
        h_node *node = map -> contents[i];
        while (node != NULL) {
            if (count > 1 && print < count) {
                 printf("%s : %.2f, ", node -> key, node -> value);
            } else { 
                printf("%s : %.2f", node -> key, node -> value); 
                }
            print++;
            node = node -> next;
        }
    }
    printf("}\n");
   
}

/**
 * Frees the map in memory. Make sure
 * to free all the individual nodes. 
*/
void map_free(hashmap map) {
    if (map == NULL) {
        return;
    }
    for (int i = 0; i < map -> size; i++) {
        h_node *cur = map -> contents[i];
        while (cur != NULL) {
            h_node *tmp = cur -> next;
            free(cur);
            cur = tmp;
        }
    }
    free(map -> contents);
    free(map);
}


#endif
