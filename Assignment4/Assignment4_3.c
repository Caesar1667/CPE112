//Pansa Intawong 66070503474
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char *stack,char val, int top){
    if(top == MAX - 1){
        printf("Stack Overflow.");
        return;
    }

    stack[++top] = val;
}

int empty(){
    return top == -1;
}

char pop(char *stack, int top){
    if(top == -1){
        printf("Stack Underflow.");
        return '\0';
    }else{
        return stack[top--];
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty.");
        return;
    }

    for(int i = top; i > -1; i--){
        printf("%c", stack[i]);
    }
}

void reverse(){
    int i = top;
    int last = 0;
    while(last < i){
        char temp = stack[last];
        stack[last] = stack[i];
        stack[i] = temp;
        last++;
        i--;
    }
}

int ParenthesesCheck(char * stack){
    int temptop = -1;
    char tempstack[MAX];
    for(int i = 0; i < top; ++i){
        if(stack[i] == '(' || stack[i] == '{' || stack[i] == '['){
            push(tempstack, stack[i], temptop);
        }else if(stack[i] == ')' || stack[i] == '}' || stack[i] == ']'){
            if(temptop == -1){
                return 0;
            }

            char topStack = pop(tempstack, temptop);

            if ((topStack == '(' && stack[i] != ')') ||
                (topStack == '{' && stack[i] != '}') ||
                (topStack == '[' && stack[i] != ']')) {
                return 0;
            }
        }
    }
    return (temptop == -1);
}

int main(){
    char INPUT;
    while((INPUT = getchar()) != '\n' && INPUT != EOF){
        push(stack, INPUT, top);
    }

    if(ParenthesesCheck(stack)){
        printf("The string is balanced");
    }else{
        printf("The string is not balanced");
    }
    
    return 0;
}
