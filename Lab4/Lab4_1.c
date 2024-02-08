//Pansa Intawong 66070503474
//Stack Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size;
int top = -1;

int push(int stack[], int val){
    if(top == size-1){
        printf("Stack Overflow.");
        return 0;
    }
    top++;
    stack[top] = val;
    return 1;
}

int pop(int stack[]){
    if(top == -1){
        printf("Stack Underflow.");
        return 0;
    }
    top--;
    return 1;
}

void show(int stack[]){
    if(top == -1){
        printf("Stack is empty.");
    }
    while(top >= 0){
        printf("%d\n", stack[top]);
        top--;
    }
}

void leave(){
    printf("Exiting...");
}

int main(){
    scanf("%d", &size);
    if(size <= 0){
        printf("Please enter a positive number.");
        return 0;
    }
    int *stack = (int*)malloc(size * sizeof(int));
    int top = 0;
    int option, num;
    while(1){
        scanf("%d", &option);
        if(option == 1){
            scanf("%d", &num);
            if(!push(stack, num)){
                break;
            }
        }else if(option == 2){
            if(!pop(stack)){
                break;
            }
        }else if(option == 3){
            show(stack);
            break;
        }else if(option == 4){
            leave();
            break;
        }else{
            printf("Invalid choice.");
            return 0;
        }
    }
    return 0;
}