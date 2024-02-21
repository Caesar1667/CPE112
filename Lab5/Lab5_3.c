//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

const char vowel[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

typedef struct PriorityQueue{
    char arr[MAX];
    char Prioritised[3][MAX];
} PQ;

int main(){
    PQ pq;
    fgets(pq.arr, 1000, stdin);
    pq.arr[strcspn(pq.arr, "\n")] = '\0';
    int length = strlen(pq.arr);
    int i = 0, j = 0, low = 0, mid = 0, high = 0;
    for(i = 0; i < length; i++){
        if (((pq.arr[i] >= 'B' && pq.arr[i] <= 'Z') && pq.arr[i] != 'E' && pq.arr[i] != 'I' && pq.arr[i] != 'O' && pq.arr[i] != 'U') || 
            ((pq.arr[i] >= 'b' && pq.arr[i] <= 'z') && pq.arr[i] != 'e' && pq.arr[i] != 'i' && pq.arr[i] != 'o' && pq.arr[i] != 'u')){
                pq.Prioritised[0][low] = pq.arr[i];
                low++;
        }else if ((pq.arr[i] == 'A' || pq.arr[i] == 'E' || pq.arr[i] == 'I' || pq.arr[i] == 'O' || pq.arr[i] == 'U') || 
                  (pq.arr[i] == 'a' || pq.arr[i] == 'e' || pq.arr[i] == 'i' || pq.arr[i] == 'o' || pq.arr[i] == 'u')){
                pq.Prioritised[2][high] = pq.arr[i];
                high++;
        }else{
                pq.Prioritised[1][mid] = pq.arr[i];
                mid++;
        }
    }
    // printf("%c ", pq.Prioritised[0][1]);
    for (int i = 0; i < high; i++) {
        printf("%c", pq.Prioritised[2][i]);
    }

    for (int i = 0; i < mid; i++) {
        printf("%c", pq.Prioritised[1][i]);
    }

    for (int i = 0; i < low; i++) {
        printf("%c", pq.Prioritised[0][i]);
    }
    return 0;
}


// char vowel[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
// arr[100];
// fgets(arr, 100, stdin);
// arr[strcspn(arr, "\n")] == '\0';
// int len = strlen(arr);
// int i = 0;
// while(i < len){
//     if(arr[i] == vowel){
//         printf("%s ", arr[i]);
//     }
// }

// IiouaaoouoeiEAIAIOo           ^^wshyllgdlcknthFrstXMNTN