//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int row, int matrix[][row]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall( int row, int mat[][row]){
    int i, j, k;

    for(int k = 0; k < row; k++){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < row; j++){
                    if(mat[i][k] + mat[k][j] < mat[i][j]){
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }

    printMatrix(row, mat);
}


int main(){
    int row;
    scanf("%d", &row);
    int mat[row][row];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    floyd_warshall(row, mat);
    return 0;
}