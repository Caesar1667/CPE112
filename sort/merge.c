#include <stdio.h>

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
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 10;
    int arr[n];
    for(int i = 1; i <= n; i++){
        arr[i - 1] = i;
    }

    mergeSort(arr, 0, n - 1); // 0 is the first index and n - 1 is the last index.
    print(arr, n);

    return 0;
}