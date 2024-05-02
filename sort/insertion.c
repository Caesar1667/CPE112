#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quick(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], M[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        M[j] = arr[m + 1 + j];
    }

    int i, j, k;
    i = 0; j = 0; k = l;

    while(i < n1 && j < n2){
        if(L[i] <= M[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    while(j < n2){
        arr[k] = M[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void print(int arr[], int n){
    printf("After : ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        arr[i] = n - i;
    }
}

int main(){
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;

    printf("Quick Sort\nBefore : ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick(arr, 0, n - 1);
    print(arr, n);

    printf("Merge Sort\nBefore : ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}