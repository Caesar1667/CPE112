// Phuwasin Kriangdechachai 66070503478
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

void Forward(node *head) {
    node *new_node = head;
    while (new_node != NULL) {
        printf("%d ", new_node->data);
        new_node = new_node->next;
    }
}

void Backward(node *tail) {
  node *new_node = tail;
  while (new_node != NULL) {
      printf("%d ", new_node->data);
      new_node = new_node->prev;
  }
}

node *New_Node(int val){
    node *New_Node = (node *)malloc(sizeof(node));
    New_Node->data = val;
    New_Node->next = NULL;
    New_Node->prev = NULL;
    return New_Node;
}

void ADD(node **head){
    int num;
    scanf("%d", &num);
    node *new_node = New_Node(num);

    if(*head == NULL){
        *head = new_node;
        return;
    }

    node *new_node = *head;
    while(new_node->next != NULL){
        new_node = new_node->next;
    }
    new_node->next = new_node;
    new_node->prev = new_node;
}

void SCH(node** head) {
    node* new_node = *head;
    int num;
    scanf("%d", &num);

    if (*head == NULL) {
        printf("none\n");
        return;
    }

    while (new_node->next != NULL && new_node->data != num) {
        new_node = new_node->next;
    }

    if (new_node->data == num) {
        if (new_node->next == NULL && new_node->prev ==NULL) {
            printf("NULL NULL\n");
        } else if(new_node->next == NULL){
            printf("%d NULL\n", new_node->prev->data);
        } else if(new_node->prev == NULL){
            printf("NULL %d\n", new_node->next->data);
        } else{
            printf("%d %d\n", new_node->prev->data, new_node->next->data);
        }
    } else {
        printf("none\n");
    }
}

void DEL(node **head) {
    node *new_node = *head;
    node *temp = NULL;
    int num;
    scanf("%d", &num);

    if (new_node == NULL) {
        return;
    }

    if (new_node->data == num) {
        *head = new_node->next;
        if (new_node->next != NULL) {
            new_node->next->prev = NULL;
        }
        return;
    }

    while (new_node != NULL && new_node->data != num) {
        temp = new_node;
        new_node = new_node->next;
    }

    if (new_node != NULL) {
        temp->next = new_node->next;
        if (new_node->next != NULL) {
            new_node->next->prev = temp;
        }
    }
}



int main (void){
  node *head = NULL;
  node *tail = NULL;
  char options [10];
  do {
    scanf("%s", options);
    if(strcmp(options, "ADD") == 0) {
      ADD(&head);
    } else if (strcmp(options, "SCH") == 0){
      SCH(&head);
    } else if (strcmp(options, "DEL") == 0){
      DEL(&head);
    }else{
      break;
    }
  } while ( strcmp(options,"ADD") == 0 || strcmp(options,"SCH") == 0 || strcmp(options,"DEL") == 0);

    if(head == NULL){
            printf("none\nnone");
        }else{
            node *new_node = head;
            while(new_node->next != NULL){
                new_node = new_node->next;
            }
            tail = new_node;
            Forward(head);
            printf("\n");
            Backward(tail);
        }
        return 0;
    }
