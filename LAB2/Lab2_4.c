//Pansa Intawong 66070503474
//Array Manipulation
#include <stdio.h>
#include <stdlib.h>

struct array{
    int size;
    int *content;
};

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertArray(int* arr, int *size, int indexInsert, int Value){
    arr = (int*)realloc(arr, (*size+1) * sizeof(int));
    for(int i = *size + 1; i >= indexInsert; i--){
        *(arr + i + 1) = *(arr + i);
    }
    *(arr + indexInsert) = Value;
    *size += 1;
    printArray(arr, *size);
}

int deleteArray(int* arr, int *size, int indexDelete){
    if(indexDelete+1 > *size){
        printf("Index out of bounds\n");
        return 0;
    }else{
        for(int i = indexDelete; i < *size; i++){
        *(arr + i) = *(arr + i + 1);
    }
    *size -= 1;
    printArray(arr, *size);
    }
}

int mergeArray(int* arr1, int size1, int* arr2, int size2){
    int *arr3, size3;
    size3 = size1 + size2;
    arr3 = (int*)malloc(size3 * sizeof(int));
    for(int i = 0; i < size1; i++){
        *(arr3 + i) = *(arr1 + i);
    }
    int in = 0;
    for(int i = size1; i < size3; i++){
        *(arr3 + i) = *(arr2 + in);
        in++;
    }
    printArray(arr3, size3);
}


int main(){
    int i;
    struct array arr1;
    scanf("%d", &arr1.size);
    arr1.content = (int*)malloc(arr1.size * sizeof(int));
    for(i = 0; i < arr1.size; i++){
        scanf("%d", (arr1.content + i));
    }
    struct array arr2;
    scanf("%d", &arr2.size);
    arr2.content = (int*)malloc(arr2.size * sizeof(int));
    for(i = 0; i < arr2.size; i++){
        scanf("%d", (arr2.content + i));
    }

    int indexIns, indexVal, indexDel;
    scanf("%d\n%d\n%d", &indexIns, &indexVal, &indexDel);
    insertArray(arr1.content, &arr1.size, indexIns, indexVal);
    deleteArray(arr1.content, &arr1.size, indexDel);
    mergeArray(arr1.content, arr1.size, arr2.content, arr2.size);

    return 0;
}