//Pansa Intawong 66070503474
//Matrix Multiplication
#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX{
    int row;
    int col;
    int **arr;
} MATRIX_X;

MATRIX_X *initMATRIX(int row, int col){
    MATRIX_X *matrix = (MATRIX_X*)malloc(sizeof(MATRIX_X));
    matrix->row = row;
    matrix->col = col;
    matrix->arr = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        matrix->arr[i] = (int*)malloc(col * sizeof(int*));
    }
    return matrix;
}

void printMatrix(struct MATRIX *matrix){
    for(int i = 0; i < matrix->row; i++){
        for(int j = 0; j < matrix->col; j++){
            printf("%d ", matrix->arr[i][j]);
        }
    printf("\n");
    }
}

void FREEMEM(struct MATRIX *matrix){
    for(int i = 0; i < matrix->row; i++){
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}

int main(){
    int row, col;
    scanf("%d%d", &row, &col);

    MATRIX_X *matrix1 = initMATRIX(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int temp;
            scanf("%d", &temp);
            matrix1->arr[i][j] = temp;
        }
    }
    scanf("%d%d", &row, &col);
    MATRIX_X *matrix2 = initMATRIX(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int temp;
            scanf("%d", &temp);
            matrix2->arr[i][j] = temp;
        }
    }
    if(matrix1->col != matrix2->row){
        printf("Not Compatible");
        return 0;
    }

    MATRIX_X *matrix3 = initMATRIX(matrix1->row, matrix2->col);
    for(int i = 0; i < matrix3->row; i++){
        for(int j = 0; j < matrix3->col; j++){
            matrix3->arr[i][j] = 0;
            for(int k = 0; k < matrix1->col; k++){
                matrix3->arr[i][j] += matrix1->arr[i][k] * matrix2->arr[k][j];
            }
            printf("%d ", matrix3->arr[i][j]);
        }
        printf("\n");
    }

    FREEMEM(matrix1);
    FREEMEM(matrix2);
    FREEMEM(matrix3);
    return 0;
}