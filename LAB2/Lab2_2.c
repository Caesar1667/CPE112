//Pansa Intawong 66070503474
//No Bracket No Printf
#include <stdio.h>
#include <stdlib.h>

struct fakeArray{
    int n;
    int *content;
} fakeArray;

void NotMain(int *ptr, int n){
    int Max = -9999, indMax = 0;
    int Min = 9999, indMin = 0;
    for(int i = 0; i < n; i++){
        if(*(ptr + i) > Max){
            Max = *(ptr + i);
            indMax = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(*(ptr + i) < Min && *(ptr + i) != Min){
            Min = *(ptr + i);
            indMin = i;
        }
    }
    printf("%d %d\n%d %d", Max, indMax, Min, indMin);
}
int main(){
    scanf("%d", &fakeArray.n);

    fakeArray.content = (int *)malloc(fakeArray.n * sizeof(int));
    for(int i = 0; i < fakeArray.n; i++){
        scanf("%d", (fakeArray.content + i));
    }
    // for(int i = 0; i < fakeArray.n; i++){
    //     printf("%d ", *(fakeArray.content + i));
    // }
    NotMain(fakeArray.content, fakeArray.n);
}