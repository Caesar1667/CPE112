//Pansa Intawong 66070503474
//Circular Table
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} nodes;

void append(struct node **head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node *last = *head;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void deleteNode(struct node **head, int pos){
    if((*head)->next == NULL){
        *head = NULL;
        return;
    }
    struct node *temp = *head;
    
    if(pos == 0){
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
    }else{
        for(int i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        struct node *new_node = temp->next;
        temp->next = temp->next->next;
        new_node->next = NULL;
        free(new_node);
    }
    return;
}

void circular(struct node **head, int start, int step, int size){
    if((*head)->next == NULL || size == 1){
        return; //one node left
    }
    start = (start + step - 1) % size;
    deleteNode(head, start);
    circular(head, start, step, size-1);
}

int main(){
    int size, step;
    scanf("%d %d", &size, &step);
    struct node *head = NULL;
    for(int i = 0; i < size; i++){
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }
    circular(&head, 0, step, size);
    // deleteNode(&head, step);
    printList(head);
    return 0;
}