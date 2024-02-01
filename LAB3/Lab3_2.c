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
        *head = new_node;
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
void insertAfter(node_t **head, int ref_val, int ins_val){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = ins_val;

    node_t *last = *head;

    // new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->data != ref_val && last->next != NULL)
    {
        last = last->next;
    }
    new_node->next = last->next;
    last->next = new_node;
}

void printList(node_t *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
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
    char mode[1];
    int ref_val = 2, ins_val = 4;
    // scanf("%c %d %d", mode, ref_val, ins_val);
    insertAfter(&head, ref_val, ins_val);
    printList(head);
    // do{
    //     scanf("%c %d %d", mode, ref_val, ins_val);
    //     if(mode[0] == 'A'){
    //         insertAfter(&head, ref_val, ins_val);
    //     }
    // }while(mode != 'E');
    return 0;
}