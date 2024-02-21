#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front, *rear;
};

struct Node *initNode(int val){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    node->data = val;
    node->next = NULL;
    return node;
}

struct Queue *initQueue(){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));

    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int val){
    struct Node *temp = initNode(val);

    if(queue->rear == NULL){
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

void dequeue(struct Queue *queue){
    if(queue->front == NULL){
        printf("Underflow.\n");
        return;
    }

    struct Node *temp = queue->front;

    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }
    free(temp);
}

void displayQueue(struct Queue *queue){
    if(queue->front == NULL){
        printf("Empty.\n");
        return;
    }

    struct  Node *node = queue->front;
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Queue *queue = initQueue();
    int option;
    do{
        printf("Option 1 : Enqueue\n");
        printf("Option 2 : Dequeue\n");
        printf("Option 3 : Display Queue\n");
        printf("Option 4 : Exit\n");
        printf("Select an option : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Input num : ");
                int temp;
                scanf("%d", &temp);
                enqueue(queue, temp);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Item in queue : ");
                displayQueue(queue);
                break;
            case 4:
                printf("exiting...");
                return 0;
            default:
                break;
        }
    }while(option != 4);
    return 0;
}