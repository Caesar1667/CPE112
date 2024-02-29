//Pansa Intawong 66070503474
//sort and remove duplicate
//Overall time complexity O(n^2)
#include <stdio.h>
#include <stdlib.h>

typedef struct sortedset
{
    int *elements;
    int index; //will be use to keep track of index when doing insertion
    int size;
} Sortedset;

// Function prototypes
void init(Sortedset *s, int size);
void checkDuplicate(Sortedset *s);
void insertElement(Sortedset *s, int newNum);
void printArray(Sortedset *s);
void sort(Sortedset *s);

int main()
{
    Sortedset set;
    int size;
    scanf("%d", &size);
    init(&set, size);
    for(int i = 0; i < set.size; i++){
        int temp;
        scanf("%d", &temp);
        insertElement(&set, temp);
    }
    sort(&set);
    checkDuplicate(&set);
    printArray(&set);
}

//O(1)
void init(Sortedset *s, int size){ 
    s->size = size;
    s->index = 0;
    s->elements = (int*)malloc(size * sizeof(int)); //allocate memory to pointer
}

//O(n)
void checkDuplicate(Sortedset *s){
    Sortedset temp;
    init(&temp, s->size);
    int count = -1;
    for(int i = 0; i < s->size; i++){ 
/*check if current array at current index is the same as next index
    if not then store the data in temp array*/
        if(s->elements[i] != s->elements[i+1]){
            count++;
            temp.elements[count] = s->elements[i];
        }
    }
    if(count == -1){ //no dupe
        return;
    }
    s->size = count + 1; //change size according to how many duplicates have been removed
    for(int i = 0; i < s->size; i++){
        s->elements[i] = temp.elements[i];
    }
}

//Big O : O(1)
void insertElement(Sortedset *s, int data){
    s->elements[s->index] = data; //insert data at current index (starts at 0)
    s->index++;
}

//Big O : O(n^2)
void sort(Sortedset *s){
    int temp;
    for(int i = 0; i < s->size; i++){
        for(int j = 0; j < i; j++){
            if(s->elements[i] < s->elements[j]){ 
                /* compare the current index with every index after 
                in this case compare if current is lower
                    if true then move the elements in ascending order */
                temp = s->elements[i];
                s->elements[i] = s->elements[j];
                s->elements[j] = temp;
            }
        }
    }
}


//Big O : O(1)
void printArray(Sortedset *s){
    printf("%d\n", s->size);
    printf("{");
    for(int i = 0; i < s->size; i++){
        printf("%d", s->elements[i]);
        if(i != s->size - 1){ //if not at the end print comma and whitespace else do nothing.
            printf(", ");
        }
    }
    printf("}");
}