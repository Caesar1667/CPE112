#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    struct node *next;
    struct node *prev;
} nodes;

void push(nodes **head, char val){
    nodes *new_node;
    new_node = (nodes*)malloc(sizeof(nodes));

    strcpy(new_node->data, val);
    new_node->next = *head;
    *head = new_node;
}

