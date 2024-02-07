//Pansa Intawong 66070503474
//Reverse portion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

void append(ListNode **head, int val){
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;

    ListNode *last = *head;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void printList(ListNode *head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
}

void Reverse(ListNode **head, int start, int end){
    ListNode *emp = (ListNode*)malloc(sizeof(ListNode));
    emp->next = *head;
    *head = emp;
    
    ListNode *current = *head;
    ListNode *temp = NULL;
    ListNode *prev = NULL;
    
        for(int i = 0; i < start; i++){
            current = current->next;
        }
            prev = current;
            current = current->next;
        for(int i = start; i < end; i++){
            temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

    *head = (*head)->next;
}

int main(){
    char put[7];
    ListNode *list = NULL;
    do{
        scanf("%6s", put);
        if(strcmp(put, "END") == 0){
            break;
        }else{
            int temp;
            temp = atoi(put);
            append(&list, temp);
        }
    }while(strcmp(put, "END") != 0);
    int start, end;
    scanf("%d %d", &start, &end);
    Reverse(&list, start-1, end-1);
    printList(list);
    return 0;
}