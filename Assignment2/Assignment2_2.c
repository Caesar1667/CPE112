//Pansa Intawong 66070503474
//Jumping Jacks
#include <stdio.h>
#include <stdlib.h>

int minJump(int start, int end, int arr[]){
    if(end == start){
        return 0;
    }
    if(arr[start] == 0){
        return 1000;
    }
    int minjump = 1000;
    for(int i = start + 1, j = start + arr[start]; i <= end && i <= j; i++){
        int jump = minJump(i, end, arr);
        if(jump != 1000 && jump + 1 < minjump){
            minjump = jump + 1;
        }
    }
    return minjump;
}

int main(){
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    int a = minJump(0, size - 1, arr);
    if(a == 1000){
        printf("Not Possible");
    }else{
        printf("%d", a);
    }
    free(arr);
    return 0;
}