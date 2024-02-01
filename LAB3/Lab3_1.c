#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;

void insertBegin(node_t **head, int val){
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));

    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void insertEnd(node_t **head, int val){
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    node_t *last = *head;

    new_node->data = val;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

int main(){
    int size;
    scanf("%d", &size);
    node_t *head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if(head == NULL){
        return 1;
    }
    for(int i = 0; i < size; i++){
        int temp;
        scanf("%d", &temp);
        // insertBegin(&head, temp);
        insertEnd(&head, temp);
    }
    node_t *current = head;

    for(int i = 0; i < size; i++){
        printf("%d ", current->data);
        current = current->next;
    }

}