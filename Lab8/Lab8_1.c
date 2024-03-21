//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap{
    int *arr;
    int capacity;
    int size;
} heap;

heap *createHeap(int capacity){
    heap *h = (heap*)malloc(sizeof(heap));
    h->arr = (int*)malloc(capacity * sizeof(int));
    h->capacity = capacity;
    h->size = 0;
    return h;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int index){
    int smallest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if(l < h->size && h->arr[l] < h->arr[smallest])
        smallest = l;
    if(r < h->size && h->arr[r] < h->arr[smallest])
        smallest = r;

    if(smallest != index){
        swap(&h->arr[index], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void insert(heap *h, int value){
    if(h->size == h->capacity){
        //full
        return;
    }

    int i = h->size++;
    h->arr[i] = value;

    while(i != 0 && h->arr[(i - 1) / 2] > h->arr[i]){
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

int extractMin(heap *h){
    if(h->size == 0){
        //empty
        return -1;
    }

    int min = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min;
}

void delete(heap *h, int value){
    if(h->size == 0){
        return;
    }

    int i = 0;
    while(h->arr[i] != value){
        i++;
    }
    swap(&h->arr[i], &h->arr[h->size - 1]);
    h->size--;

    for(int i = (h->size / 2) - 1; i >= 0; i--){
        heapify(h, i);
    }
}

void printHeap(heap *h){
    for(int i = 0; i < h->size; i++){
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main(){
    heap *h = createHeap(100);
    int temp;
    char option[7];
    do{
        scanf("%s", option);
        if(strcmp(option, "INSERT") == 0){
            while(scanf("%d", &temp) == 1){
                insert(h, temp);
            }
        }else if(strcmp(option, "DELETE") == 0){
            while(scanf("%d", &temp) == 1){
                delete(h, temp);
            }
        }else if(strcmp(option, "PRINT") == 0){
            printHeap(h);
        }else if(strcmp(option, "EXIT") == 0){
            free(h);
            break;
        }else{
            printf("Invalid command.\n");
            continue;
        }
    }while(strcmp(option, "EXIT") != 0);

    return 0;
}

// 1 3 9 0
// -1 -4 -6
// del 1
// print -6 -1 -4 3 0 9