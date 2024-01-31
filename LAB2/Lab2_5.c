//Pansa Intawong 66070503474
//List Slicing
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST
{
   int *arr;
   int size;

} LIST_T;

LIST_T *initList()
{
    LIST_T *list = (LIST_T*)malloc(sizeof(LIST_T));
    list->size = 0;
    list->arr = NULL;
    return list;
}

void append(LIST_T *list, int val)
{
    list->size++;
    list->arr = (int*)realloc(list->arr, list->size * sizeof(int*));
        list->arr[list->size - 1] = val;
}

void printList(LIST_T *list)
{
    if (list->size == 0)
    {
        printf("empty\n");
        return;
    }

    for(int i = 0; i < list->size; i++){
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int assignStartEnd(int idx, int size)
{
    if(idx < 0){
        idx += size;
    }
    if(idx < 0){
        idx = 0;
    }else if(idx > size){
        idx = size;
    }
    return idx;
}

LIST_T *slice(LIST_T *list, int start, int end, int step)
{
    LIST_T *sliced = initList();

    start = assignStartEnd(start, list->size);
    end = assignStartEnd(end, list->size);

    if(start == list->size && step < 0){
        start--;
    }

    if(step == 0){
        return sliced;
    }

    if(step > 0){
        for(int i = start; i < end; i += step){
            append(sliced, list->arr[i]);
        }
    }else{
        for(int i = start; i > end; i += step){
            append(sliced, list->arr[i]);
        }
    }
    return sliced;
}

int main()
{
    LIST_T *list = initList();
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        append(list, temp);
    }
    // printList(list);

    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

    LIST_T *sliced = slice(list, start, end, step);
    printList(sliced);

    /*
    add code to prevent memory leak
    */
   free(list);
   free(sliced);
    return 0;
}