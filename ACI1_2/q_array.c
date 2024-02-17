#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{
    int front, rear, size;
    unsigned cap;
    int* array;
};

struct Queue* initQueue(unsigned cap){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->cap = cap;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->array = (int*)malloc(queue->cap * sizeof(int));
    return queue;
}   

int isFull(struct Queue *queue){
    return (queue->size == queue->cap);
}

int isEmpty(struct Queue *queue){
    return (queue->size == 0);
}

void size(struct Queue *queue){
    printf("%d\n", queue->size);
}

int front(struct Queue *queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(struct Queue *queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

void enqueue(struct Queue *queue, int data){
    if(isFull(queue)){
        printf("Stack Overflow.\n");
    }
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->array[queue->rear] = data;
    queue->size = queue->size + 1;
    printf("%d\n", queue->array[queue->rear]);
}

int dequeue(struct Queue *queue){
    if(isEmpty(queue)){
        printf("Stack Underflow.\n");
        return INT_MIN;
    }

    int temp = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size = queue->size - 1;
    return temp;
}

void displayQueue(struct Queue *queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue are : ");
    if(queue->front == )
    for(int i = queue->front; i <= queue->rear; i = (i + 1) % queue->cap){
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main(){
    struct Queue *queue = initQueue(3);
    int op;
    do{
        printf("Option 1 : Enqueue\n");
        printf("Option 2 : Dequeue\n");
        printf("Option 3 : Show size\n");
        printf("Option 4 : Show front\n");
        printf("Option 5 : Show rear\n");
        printf("Option 6 : Display queue\n");
        printf("Option 7 : Exit\n");
        printf("Input your option : ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                int temp;
                printf("Input num : ");
                scanf("%d", &temp);
                enqueue(queue, temp);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                size(queue);
                break;
            case 4:
                printf("front : %d\n", front(queue));
                break;
            case 5:
                printf("rear : %d\n", rear(queue));
                break;
            case 6:
                displayQueue(queue);
                break;
            case 7:
                printf("Exiting...");
                break;
            default:
                break;
        }
    }while(op != 7);
    return 0;
}