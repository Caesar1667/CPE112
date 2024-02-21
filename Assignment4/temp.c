#include <stdio.h>
#include <stdlib.h>

int count = 0; //use for parenthesis count;

typedef struct stack{
    char data;
    struct stack *next;
}stacks;

void push(stacks **stack, char key){
    stacks *new_stack = (stacks*)malloc(sizeof(stacks));

    new_stack->data = key;
    new_stack->next = *stack;
    *stack = new_stack;
}

void push2top(stacks **stack, char key){
    int i = 1;
    stacks *current = *stack;
    stacks *prev = NULL;
    while(current != NULL && current->data != key){
        prev = current;
        current = current->next;
        if(current->data == key && i == count){
            break;
        }else if(current != NULL){
            current = current->next;
            i++;
        }
    }

    if(current == NULL){
        return; //key not found.
    }
    if(prev == NULL){
        return; //the key is already at the top;
    }
    prev->next = current->next;
    current->next = *stack;
    *stack = current;
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
    if(stack == NULL){
        return;
    }
    while(stack != NULL){
        printf("%c ", stack->data);
        stack = stack->next;
    }
}

void parentheses(stacks **stack){
    if(*stack == NULL){
        return; //stack is empty.
    }
    stacks *current = *stack;
    while(current != NULL){
        if(current->data == '(' || current->data == '{' || current->data == '['){
            count++;
            push2top(stack, current->data);
        }
        current = current->next;
    }
}

int main(){
    stacks *stack = NULL;
    char INPUT;
    while((INPUT = getchar()) != '\n' && INPUT != EOF){
        push(&stack, INPUT);
    }
    reverse(&stack);
    // push2top(&stack, 'b');
    parentheses(&stack);
    display(stack);
    return 0;
}