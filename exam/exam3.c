//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define P_MAX 4

typedef struct Queue{
    int *people;
    int size;
    int front, rear;
} Q;

typedef struct PriorityQueue{
    int indf, indr;
    int priorty;
    struct PriorityQueue* next;
} PQ;

PQ *pq = NULL;

void initQ(Q *q, int size){
    q->size = size;
    q->people = (int*)malloc(size * sizeof(int));
    q->front = q->rear = -1;
}

PQ* newNode(int indf, int indr, int pri){
    PQ *temp = (PQ*)malloc(sizeof(PQ));
    temp->indf = indf;
    temp->indr = indr;
    temp->priorty = pri;
    temp->next = NULL;

    return temp;
}


bool isEmpty(Q *q){
    if(q->front == -1 && q->rear == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(Q *q){
    if((q->rear + 1) % q->size == q->front){
        return true;
    }else{
        return false;
    }
}

void Enqueue(Q *q, int data){ //O(1)
    if(isFull(q)){
        return;
    }else if(isEmpty(q)){
        q->front = q->rear = 0;
    }else{
        q->rear = (q->rear + 1) % q->size;
    }
    q->people[q->rear] = data;
}

void EnqueuePQ(PQ **pq, int indf, int indr, int pri){ // O(n)
    PQ* start = (*pq);
    PQ* temp = newNode(indf, indr, pri);
    if(*pq == NULL){
        *pq = temp;
        return;
    }

    if((*pq)->priorty < pri){
        temp->next = *pq;
        *pq = temp;
    }else{
        while(start->next != NULL && start->next->priorty > pri){
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

void display(Q *q){
    if(isEmpty(q)){
        return;
    }
    int i = q->front;
    do{
        printf("%d ", q->people[i]);
        i = (i + 1) % q->size;
    }while(i != (q->rear + 1) % q->size);
}

void printList(Q *q, PQ *pq){ // O(n)
    while(pq != NULL){
        int i = pq->indf;
        do{
            printf("%d ", q->people[i]);
            i++;
        }while(i < pq->indr);
        pq = pq->next;
        printf("\n");
    }
}

void printPQ(){ // O(n)
    while(pq != NULL){
        printf("%d ", pq->priorty);
        pq = pq->next;
    }
}

void prioritise(Q *q){ // O(n^2)
    int i = q->front;
    int flag = 0;
    while(i <= q->size){
           if(q->people[i] < P_MAX){
            int j = i + 1;
            int temp = q->people[i];
            while(temp + q->people[j] <= 4 && j < q->size){
                flag = 1;
                temp = temp + q->people[j];
                j++;
            }
            if(flag){
                EnqueuePQ(&pq, i, j, temp);
                i = i + j;
            }else{
                EnqueuePQ(&pq, i, i, temp);
            }
        }else if(q->people[i] == P_MAX){
            EnqueuePQ(&pq, i, i, P_MAX);
            i++;
        }
    }
    printList(q, pq);
}


int main(){
    Q q;
    int size;
    scanf("%d", &size);
    initQ(&q, size);
    for(int i = 0; i < size; i++){
        int temp;
        scanf("%d", &temp);
        // scanf("%d%d%d", &temp, &tymp, &pri);
        Enqueue(&q, temp);
        // EnqueuePQ(&pq, temp, tymp, pri);
    }
    // printPQ();
    prioritise(&q);
    // display(&q);
    return 0;
}