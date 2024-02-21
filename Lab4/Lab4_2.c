//Pansa Intawong 66070503474
//Stack Linked List
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack{
    int data;
    struct stack *next;
} stacks;

void push(stacks **stack, int val){
    if(val > INT_MAX || val < INT_MIN){
        return; //input value above or below interger limits
    }
    stacks *new_stacks = (stacks*)malloc(sizeof(stacks));

    new_stacks->data = val; 
    new_stacks->next = *stack;
    *stack = new_stacks;
}

void pop(stacks **stack){
    if(*stack == NULL){
        printf("empty\n");
        return;
    }

    stacks *temp = *stack;
    printf("%d\n", (*stack)->data);
    *stack = (*stack)->next;
    free(temp);
}

void displayTop(stacks *stack){
    if(stack == NULL){
        printf("empty\n");
    }else{
        printf("%d\n", stack->data);
    }
}

int isEmpty(stacks *stack){
    if(stack == NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    stacks *stack = NULL;
    char command[1];
    do
    {
        scanf("%c", command);
        if(command[0] != 'q'){
            switch (command[0])
            {
                case 'p':
                    int val;
                    scanf("%d", &val);
                    push(&stack, val);
                    break;
                case 'o':
                    pop(&stack);
                    break;
                case 't':
                    displayTop(stack);
                    break;
                case 'e':
                    val = isEmpty(stack);
                    printf("%d\n", val);
                    break;
            }
        }
    } while (command[0] != 'q');
    
}