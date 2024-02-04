//Pansa Intawong 66070503474
//Deletion
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} nodes;

void deleteFirst(nodes **head){
    if(*head == NULL){
        return;
    }
    nodes *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(nodes **head){
    if(*head == NULL){
        return;
    }
    nodes *end = *head;
    nodes *prev = NULL;

    while(end->next != NULL){
        prev = end;
        end = end->next;
    }
    if(prev != NULL){
        prev->next = NULL;
    }else{
        free(*head);
        *head = NULL;
    }
}

void deleteSelected(nodes **head, int val){
    if(*head == NULL){
        return;
    }

    nodes *temp = *head;
    nodes *start = NULL;

    while(temp != NULL && temp->data != val){
        start = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    if(start == NULL){
        *head = temp->next;
    }else{
        start->next = temp->next;
    }
    free(temp);
}

void append(nodes **head, int data){
    nodes *new_node = (nodes*)malloc(sizeof(nodes));

    new_node->data = data;

    nodes *last = *head;

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

void printList(nodes *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}
int main(){
    int size;
    scanf("%d", &size);

    nodes *head = NULL;
    for(int i = 0; i < size; i++){
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }

    char mode[1];
    int val;
    // deleteSelected(&head, 3);

    do
    {
        scanf("%c", mode);
        switch (mode[0])
        {
            case 'F':
                deleteFirst(&head);
                break;
            case 'L':
                deleteLast(&head);
                break;
            case 'N':
                scanf("%d", &val);
                deleteSelected(&head, val);
                break;
            case 'E':
                break;
        }
    } while (mode[0] != 'E');
    if(head == NULL){
        printf("none");
    }else{
        printList(head);
    }
    return 0;
}