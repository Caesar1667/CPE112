#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack{
    char data;
    struct stack *next;
}stacks;

void push(stacks **stack, char val){
    stacks *new_stack = (stacks*)malloc(sizeof(stacks));

    new_stack->data = val;
    new_stack->next = *stack;
    *stack = new_stack;
}

void pop(stacks **stack){
    if(*stack == NULL){
        return;
    }
    stacks *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

void display(stacks *stack){
    while(stack != NULL){
        printf("%c", stack->data);
        stack = stack->next;
    }
}

void displayTop(stacks *stack){
    if(stack == NULL){
        printf("empty\n");
    }else{
        printf("%c\n", stack->data);
    }
}

bool balanceCheck(stacks **stack){
    stacks *current = *stack;

    while (current != NULL) {
        if (current->data == ')' || current->data == ']' || current->data == '}') {
            switch (current->data) {
                case ')':
                    if (*stack != NULL && (*stack)->data == '(') {
                        (*stack) = (*stack)->next;
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (*stack != NULL && (*stack)->data == '{') {
                        (*stack) = (*stack)->next;
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (*stack != NULL && (*stack)->data == '[') {
                        (*stack) = (*stack)->next;
                    } else {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        current = current->next;
    }

    return true;
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

void parenthesis(stacks **stack){
    stacks *current = *stack, *prev = NULL, *topStack = NULL;
    while(current != NULL){
        if(current->data == ']' || current->data == '}' || current->data == ')'){
                if(prev != NULL){
                    prev->next = current->next;
                }else{
                    *stack = current->next;
                }
                current->next = topStack;
                topStack = current;
                current = (prev != NULL) ? prev->next : *stack;
        }else{
            prev = current;
            current = current->next;
        }
    }
    if(prev != NULL){
        prev->next = topStack;
    }else{
        *stack = topStack;
    }
}


int main(){
    stacks *stack = NULL;
    char INPUT;
    while((INPUT = getchar()) != '\n' && INPUT != EOF){
        push(&stack, INPUT);
    }
    display(stack);
    printf("\n");
    displayTop(stack);
    reverse(&stack);
    display(stack);
    printf("\n");
    displayTop(stack);
    parenthesis(&stack);
    display(stack);
    printf("\n");
    displayTop(stack);
    if(balanceCheck(&stack)){
        printf("The string is balanced");
    }else{
        printf("The string is not balanced");
    }
    return 0;
}