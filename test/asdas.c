// 66070503421 Nutthawut Jaroenchokwittaya
// Insert before or after the given node
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to insert a node at the end of the linked list
void insert_back(node** start, int data) {
    node* newnode, *ptr;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (*start == NULL) {
        // If the list is empty, the new node becomes the start
        *start = newnode;
    } else {
        // Traverse to the end of the list and add the new node
        ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

// Function to insert a node before a given key in the linked list
void insert_before(node** start, int key, int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    node* ptr = *start;
    node* preptr = NULL;

    // Traverse the list to find the key or the end of the list
    while (ptr != NULL && ptr->data != key) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (preptr == NULL) {
        // If the key is not found or it's the first element, insert at the beginning
        newnode->next = *start;
        *start = newnode;
    } else {
        // Insert the new node before the key
        newnode->next = ptr;
        preptr->next = newnode;
    }
}

// Function to insert a node after a given key in the linked list
void insert_after(struct node** start, int key, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node* ptr = *start;
    struct node* preptr = NULL;

    while (ptr != NULL && ptr->data != key) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        // The given key is not present in the list
        free(newnode);
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}


int main(void) {
    node* start = NULL;
    int numofnode, data, data2, key;
    char choice;

    // Read the number of nodes and their values
    scanf(" %d", &numofnode);
    for (int i = 0; i < numofnode; i++) {
        scanf(" %d", &data);
        insert_back(&start, data);
    }

    // Process user commands
    while (1) {
        scanf(" %c", &choice);
        if (choice == 'A' || choice == 'B') {
            scanf(" %d %d", &key, &data2);
            if (choice == 'A') {
                // Insert after the given key
                insert_after(&start, key, data2);
            } else if (choice == 'B') {
                // Insert before the given key
                insert_before(&start, key, data2);
            }
        } else if (choice == 'E') {
            // Exit the loop if 'E' is entered
            break;
        }
    }

    // Print the final list
    node* current = start;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free memory by deallocating each node
    while (start != NULL) {
        node* temp = start;
        start = start->next;
        free(temp);
    }

    start = NULL;
    return 0;
}