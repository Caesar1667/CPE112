//Pansa Intawong 66070503474
//Before or After Insertion
#include <stdio.h>
#include <stdlib.h>

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

void insertBefore(node_t **head, int ref_val, int ins_val){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = ins_val;

    node_t *temp = *head;
    node_t *temp2 = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(temp->data != ref_val && temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }

    new_node->next = temp;
    temp->next = new_node;
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
    // printList(head);
    char mode[1];
    int ref_val = 2, ins_val = 4;
    // scanf("%c %d %d", mode, ref_val, ins_val);
    insertBefore(&head, ref_val, ins_val);
    // printf("\n");
    // do{
    //     scanf("%c", mode);
    //     if(mode[0] == 'E'){
    //         break;
    //     }
    //     scanf("%d %d", &ref_val, &ins_val);

    //     switch (mode[0])
    //     {
    //     case 'A':
    //         insertAfter(&head, ref_val, ins_val);
    //         break;
    //     case 'B':
    //         insertBefore(&head, ref_val, ins_val);
    //         break;
    //     case 'E':
    //         break;
    //     default:
    //         break;
    //     }
    // }while(mode[0] != 'E');
    printList(head);
    return 0;
}