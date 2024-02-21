//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void display(stacks *stack){
    while(stack != NULL){
        printf("%c", stack->data);
        stack = stack->next;
    }
}

void convert(stacks **stack, int num, int base){
    while(num != 0){
        char temp = num % base;
        if(temp > 9 && base > 9){
            temp = temp - 10 + 'A';
        }else{
            temp = temp + '0';
        }
        push(stack, temp);
        num /= base;
    }
}

int main(){
    stacks *converted = NULL;
    int num, base;
    scanf("%d\n%d", &num, &base);
    if(num < 0 || base < 2 || base > 36){
        printf("invalid");
        return 0;
    }
    if(num == 0){
        printf("0");
        return 0;
    }
    convert(&converted, num, base);
    display(converted);
    return 0;
}