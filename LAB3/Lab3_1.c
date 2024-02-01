//Pansa Intawong 66070503474
//Insert Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

struct Node {
	int data;
	struct Node* next;
};

void insertBegin(node_t **head, int val)
{
    node_t *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));

    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void insertEnd(node_t **head, int val)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = val;

    node_t *last = *head;

    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

int main()
{
    int size, option;
    scanf("%d\n%d", &size, &option);
    node_t *head = NULL;
        for (int i = 0; i < size; i++)
        {
            int temp;
            scanf("%d", &temp);
            insertEnd(&head, temp);
            // if(option == 1){
            //     insertBegin(&head, temp);
            // }else if(option == 2){
            //     insertEnd(&head, temp);
            // }else{
            //     printf("Invalid");
            //     return 0;
            // }
        }
    
    if(size == 0){
        printf("Invalid");
        return 0;
    }
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}