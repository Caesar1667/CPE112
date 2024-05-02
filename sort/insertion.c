#include <stdio.h>

void insertion(int arr[], int n){
    int key;
    for(int i = 1; i < n; i++){
        key = arr[i];
        int j = i - 1;

        while(i >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, n);
    print(arr, n);

    return 0;
}