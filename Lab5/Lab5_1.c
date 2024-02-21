    //Pansa Intawong 66070503474
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>

    #define MAX 50 


    typedef struct queue{
        char name[MAX][MAX];
        char artist[MAX][MAX];
        int time[MAX];
        int front, rear;
    } Queue;

    void initQ(Queue *queue){
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
        if((queue->rear + 1) % MAX == queue->front){
            return true;
        }else{
            return false;
        }
    }

    void Enqueue(Queue *queue, char name[], char artist[], int time){
        if((queue->rear+1)% MAX == queue->front){
            // printf("Queue is full. Please dequeue when possible.\n");
            return;
        }else if(isEmpty(queue)){
            queue->front = queue->rear = 0;
        }else{
            queue->rear = (queue->rear+1) % MAX;
        }
        strcpy(queue->name[queue->rear], name);
        strcpy(queue->artist[queue->rear], artist);
        queue->time[queue->rear] = time;
    }

    void Dequeue(Queue *queue){
        if(isEmpty(queue)){
            printf("No songs in the playlist\n");
            return;
        }else if(queue->front == queue->rear){
            printf("Now playing: %s by %s\n", queue->name[queue->front], queue->artist[queue->front]);
            queue->front = queue->rear = -1;
        }else{
            printf("Now playing: %s by %s\n", queue->name[queue->front], queue->artist[queue->front]);
            queue->front = (queue->front + 1) % MAX;
        }
    }

    int Front(Queue *queue){
        if(!isEmpty(queue)){
            int i = queue->front;
            int cumulative_time = 0;
            printf("Songs in the playlist:\n");
            do{
                printf("%s by %s %d\n", queue->name[i], queue->artist[i], queue->time[i]);
                cumulative_time += queue->time[i];
                i = (i + 1) % MAX;
            }while(i != (queue->rear + 1) % MAX);
            printf("Remaining Time: %d\n", cumulative_time);
        }else{
            printf("No songs in the playlist\n");
        }
    }

    void displayQ(Queue *queue){
        if(isEmpty(queue)){
            return;
        }
        int i = queue->front;

        do{
            printf("%s\n%s\n%d ", queue->name[i], queue->artist[i], queue->time[i]);
            i = (i + 1) % MAX;
        }while(i != (queue->rear + 1) % MAX);

        printf("\n");
    }

    int main(){
        Queue queue;
        initQ(&queue);
        char op[5];

        // char temp_name[MAX], temp_art[MAX];
        //         int temp_time;
        //         printf("Input song name : ");
        //         fgets(temp_name, MAX, stdin);
        //         temp_name[strcspn(temp_name, "\n")] = '\0';
        //         printf("Input artist name : ");
        //         fgets(temp_art, MAX, stdin);
        //         temp_art[strcspn(temp_art, "\n")] = '\0';            
        //         printf("Input time : ");
        //         scanf("%d", &temp_time);
        //         getchar();
        //         Enqueue(&queue, temp_name, temp_art, temp_time);

        //         printf("Input song name : ");
        //         fgets(temp_name, MAX, stdin);
        //         temp_name[strcspn(temp_name, "\n")] = '\0';
        //         printf("Input artist name : ");
        //         fgets(temp_art, MAX, stdin);
        //         temp_art[strcspn(temp_art, "\n")] = '\0';            
        //         printf("Input time : ");
        //         scanf("%d", &temp_time);
        //         getchar();
        //         Enqueue(&queue, temp_name, temp_art, temp_time);
        //     // displayQ(&queue);
        //     Dequeue(&queue);
        while(1){
        // printf("Enter options : ");
        fgets(op, 5, stdin);
        op[strcspn(op, "\n")] = '\0';
            if(strcmp(op, "add") == 0){
                char temp_name[MAX], temp_art[MAX];
                int temp_time;
                // printf("Input song name : ");
                fgets(temp_name, MAX, stdin); //recieve input from input buffer
                temp_name[strcspn(temp_name, "\n")] = '\0'; //fgets will also count '\n' into the input so strcspn is use to find the inde where '\n' is located then assign it as '\0'
                // printf("Input artist name : ");
                fgets(temp_art, MAX, stdin);
                temp_art[strcspn(temp_art, "\n")] = '\0';            
                // printf("Input time : ");
                scanf("%d", &temp_time);
                // getchar(); //works similar to strcspn.
                Enqueue(&queue, temp_name, temp_art, temp_time);
            }else if(strcmp(op, "play") == 0){
                Dequeue(&queue);
            }else if(strcmp(op, "sum") == 0){
                Front(&queue);
                break;
            }
        }
        return 0;
    }
        