//Pansa Intawong 66070503474
//No Bracket
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, mode;
    scanf("%d", &n);
    int *content; 
    content = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < (n); i++){
        scanf("%d ", (content + i));
    }
    // for(int i = 0; i < n; i++){
    //     printf("%d ", *(content + i));
    // }
    scanf("%d", &mode);
    int count = 0;
    switch(mode){
        case 0:
            for(int i = 0; i < n; i = i + 2){
                printf("%d ", *(content + i));
                count++;
            }
            break;
        case 1:
            for(int i = 1; i < n; i = i + 2){
                printf("%d " ,*(content + i));
                count++;
            }
            break;
        // default:
        //     printf("ERROR");
        //     break;
    }
    if(count == 0){
        printf("none");
    }
    free(content);

    return 0;
}