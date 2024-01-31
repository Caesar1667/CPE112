//Pansa Intawong 66070503474
//Spiral Array Printer
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

int Spiral(struct MATRIX *matrix, int startrow, int endrow, int startcol, int endcol){
    if(startrow > endrow || startcol > endcol){
        return 0;
    }

    for(int i = startcol; i <= endcol; i++){
        printf("%d ", matrix->arr[startrow][i]);
    }

    for(int i = startrow + 1; i <= endrow; i++){
        printf("%d ", matrix->arr[i][endcol]);
    }

    if(startrow < endrow){
        for(int i = endcol - 1; i >= startcol; i--){
           printf("%d ", matrix->arr[endrow][i]);
        }
    }

    if(startcol < endcol){
        for(int i = endrow - 1; i > startrow; i--){
            printf("%d ", matrix->arr[i][startcol]);
        }
    }

    Spiral(matrix, startrow + 1, endrow - 1, startcol + 1, endcol - 1);
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

    MATRIX_X *matrix = initMATRIX(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int temp;
            scanf("%d", &temp);
            matrix->arr[i][j] = temp;
        }
    }
    Spiral(matrix, 0, row - 1, 0, col - 1);

    return 0;
}