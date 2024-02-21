//Pansa Intawong 66070503474
//Mom said it's my turn.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue{
    int *data;
    int front, rear;
    int size;
} Queue;

void initQ(Queue *queue, int size){
    queue->size = size;
    queue->data = (int*)malloc(size * sizeof(int));
    queue->front = queue->rear = -1;
}

bool isEmpty(Queue *queue){
    if(queue->front == -1 && queue->rear == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(Queue *queue){
    if((queue->rear + 1) % queue->size == queue->front){
        return true;
    }else{
        return false;
    }
}

void Enqueue(Queue *queue, int data){
    if(isFull(queue)){
        printf("Queue is full!!\n");
        return;
    }else if(isEmpty(queue)){
        queue->front = queue->rear = 0;
    }else{
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->data[queue->rear] = data;
}

void Dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty!!\n");
        return;
    }else if(queue->front == queue->rear){
        printf("%d \n", queue->data[queue->front]);
        queue->front = queue->rear = -1;
    }else{
        printf("%d \n", queue->data[queue->front]);
        queue->front = (queue->front + 1) % queue->size;
    }
}

// void top(Queue *queue){
//     if(!isEmpty(queue)){
//         printf("Front: %d \n", queue->data[queue->front]);
//     }else{
//         printf("Queue is empty!!\n");
//     }
// }

void Display(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d \n", queue->front);
    int i = queue->front;
    printf("Items: ");
    do{
        printf("%d ", queue->data[i]);
        i = (i + 1) % queue->size;
    }while(i != (queue->rear + 1) % queue->size);
    printf("\n");
    printf("Rear: %d \n", queue->rear);
}

int main(){
    Queue queue;
    int size;
    scanf("%d", &size);
    initQ(&queue, size);
    char op[2];
    // do{
        
    // }while(op[0] != 'E');
    while(1){
        scanf("%s", op);
        switch (op[0])
        {
        case 'I':
            int temp;
            scanf(" %d", &temp);
            Enqueue(&queue, temp);
            break;
        case 'D':
            Dequeue(&queue);
            break;
        case 'E':
            break;
        case 'S':
            Display(&queue);
            break;
        }
        if(op[0] == 'E'){
            break;
        }
    }

    free(queue.data);
    return 0;
}