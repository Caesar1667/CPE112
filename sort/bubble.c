#include <stdio.h>

void bubble(int arr[], int n){ //The largest number will be sorted first
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){ //check if the next index is larger
                temp = arr[j]; //if true then swap
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } //repeat until finished
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubble(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}