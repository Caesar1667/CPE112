#include <stdio.h>

int partition(int arr[], int high, int low){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < low; j++){
        if(arr[j] <= pivot){
            i++;

            int temp = arr[j];
            arr[j] = arr[high];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quick(int arr[], int high, int low){
    if(low < high){
        int pi = partition(arr, high, low);

        quick(arr, pi - 1, low);
        quick(arr, high, pi - 1);
    }
}

int main(){
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;

    quick(arr, n - 1, 0);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
