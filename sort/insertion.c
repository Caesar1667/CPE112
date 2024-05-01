#include <stdio.h>

void insertion(int arr[], int n){ //key is the number that wiil be picked out
    int key;
    for(int i = 1; i < n; i++){ // 5 9 1 4 3. say key is 9
        key = arr[i];

        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j]; //then move the array until there's place for the key. -> 5 1 4 3 3
            j--;
        }
        arr[j + 1] = key; // put key in the appropriate place.
    }                     // 5 1 4 3 9
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    insertion(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}