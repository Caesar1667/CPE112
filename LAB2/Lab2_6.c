//Pansa Intawong 66070503474
//Sum of Diagonal Matrix
#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX{
    int row;
    int col;
    int **arr;
} MATRIX_X;

MATRIX_X *initMatrix(int row, int col){
    MATRIX_X *matrix = (MATRIX_X*)malloc(sizeof(MATRIX_X));
    matrix->row = row;
    matrix->col = col;
    matrix->arr = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        matrix->arr[i] = (int*)malloc(col * sizeof(int));
    }
    return matrix;
}

int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    if(row != col){
        printf("ERROR");
        return 0;
    }

    MATRIX_X *matrix = initMatrix(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int temp;
            scanf("%d", &temp);
            matrix->arr[i][j] = temp;
        }
    }

    int pri = 0, sec = 0;
    for(int i = 0; i < row; i++){
        pri += matrix->arr[i][i];
        sec += matrix->arr[i][row - i - 1];
    }

    printf("Primary: %d\nSecondary: %d", pri, sec);
    for(int i = 0; i < matrix->row; i++){
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
    return 0;
}