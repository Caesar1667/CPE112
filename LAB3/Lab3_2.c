#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;

void append(node_t **head, int val){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = val;

    node_t *last = *head;

    new_node->next = NULL;

    if(*head == NULL){
        head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}
bool search(node_t *head, int val){
    if(head == NULL){
        return false;
    }

    if(head->data == val){
        return true;
    }
    return search(head->next, val);
}
int insertAfter(node_t **head, int val){
    node_t new_node = (node_t*)malloc(sizeof(node_t))
    if(search(head, val)){
        
    }
}

int main(){
    int size;
    scanf("%d", &size);
    node_t *head = NULL;
    for(int i = 0; i < size; i++){
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }
    char mode;
    do{
        if(mode == 'A'){

        }
    }while(mode != 'E');
}