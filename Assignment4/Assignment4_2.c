//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char data;
    struct stack *next;
}stacks;

void push(stacks **stack, char data){
    stacks *new_stacks = (stacks*)malloc(sizeof(stacks));

    new_stacks->data = data;
    new_stacks->next = *stack;
    *stack = new_stacks;
}

void reverse(stacks **stack){
    stacks *prev = NULL;
    stacks *current = *stack;
    stacks *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *stack = prev;
}

void display(stacks *stack){
    while(stack != NULL){
        printf("%c ", stack->data);
        stack = stack->next;
    }
}

void Palindrome(stacks **stack){
    stacks *temp = *stack;
    stacks *rev = *stack;
    reverse(&rev);
    while(temp != NULL){
        if(temp->data != rev->data){
            printf("no");
            return;
        }
        temp = temp->next;
        rev = rev->next;
    }
    printf("yes");
}


int main(){
    stacks *stack = NULL;
    char str[100];
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++){
        push(&stack, str[i]);
    }
    Palindrome(&stack);
    return 0;
}