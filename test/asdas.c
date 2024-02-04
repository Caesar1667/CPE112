// 66070503421 Nutthawut Jaroenchokwittaya
// Delete first last or same value node and print remaining
#include <stdio.h>
#include<stdlib.h>
// Define the structure for a linked list node
typedef struct node {
    int data;
    struct node* next;
} node;
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
void deletefirst(node** start){
  node* ptr;
  if(*start==NULL){
    return;
  }
  ptr=*start;
  *start=(*start)->next;
  free(ptr);
}
void deletelast(node** start){
  node* ptr,*pre;
  if(*start == NULL){
    return;
  }
  ptr = *start;
  while(ptr->next != NULL){
    pre = ptr;
    ptr = ptr->next;
  }
  if(pre == NULL){ //prev has one node
      *start = NULL;
  }else{ //prev has more than one
      pre->next = NULL;
  }
}
void deletenode(node** start, int value) {
    if (*start == NULL) {
        return; // Empty list, nothing to delete
    }

    node* ptr, *preptr;
    ptr = *start;
    preptr = NULL;

    // Search for the node with the specified value
    while (ptr != NULL && ptr->data != value) {
        preptr = ptr;
        ptr = ptr->next;
    }

    // If the value is not found, do nothing
    if (ptr == NULL) {
        return;
    }

    // If the node to be deleted is the first node
    if (preptr == NULL) {
        *start = ptr->next;
    } else {
        preptr->next = ptr->next;
    }

    free(ptr);
}


void freelist(node* start){
  node* ptr = start;
  node* tmp;
  while(ptr != NULL){
    tmp = ptr->next;
    free(ptr);
    ptr = tmp;
  }
}
int main(void) {
  node* start = NULL;
  int numofnode, data, value;
  char choice;

  // Read the number of nodes and their values
  scanf(" %d", &numofnode);
  for (int i = 0; i < numofnode; i++) {
      scanf(" %d", &data);
      insert_back(&start, data);
  }
  scanf(" %c", &choice);
// ...

while (1) {
    if (choice == 'F') {
        deletefirst(&start);
    } else if (choice == 'L') {
        deletelast(&start);
    } else if (choice == 'N') {
        scanf(" %d", &value);
        if (value >= 1) {
            deletenode(&start, value);
        }
    } else if (choice == 'E') {
        break;
    } else {
        continue;
    }

    // Read the next choice after performing the current operation
    scanf(" %c", &choice);
}


    // Print the remaining nodes
    node* last = start;
  if(start != NULL){
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->next;

    }
  }else{
    printf("none");
  }

freelist(start);
return 0;
}