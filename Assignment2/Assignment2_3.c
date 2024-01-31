//Pansa Intawong 66070503474
//Symmetric Matrix
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

int isSym(struct MATRIX *matrix){
    for(int i = 0; i < matrix->row; i++){
        for(int j = 0; j < matrix->col; j++){
            if(matrix->arr[i][j] != matrix->arr[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int isSkew(struct MATRIX *matrix){
    for(int i = 0; i < matrix->row; i++){
        for(int j = 0; j < matrix->col; j++){
            int a = matrix->arr[j][i];
            if(matrix->arr[i][j] != -a){
                return 0;
            }
        }
    }
    return 1;
}

// int Transpose(struct MATRIX *matrix){ //Create a transpose of a matrix (now that I realized I don't really need it, but it does work!).
//     MATRIX_X *transpose = initMATRIX(matrix->col,matrix->row);

//     for(int i = 0; i < matrix->row; i++){
//         for(int j = 0; j < matrix->col; j++){
//             transpose->arr[i][j] = matrix->arr[i][j];
//         }
//     }
//     return transpose;
// }

void printMatrix(struct MATRIX *matrix){
    for(int i = 0; i < matrix->row; i++){
        for(int j = 0; j < matrix->col; j++){
            printf("%d ", matrix->arr[i][j]);
        }
    printf("\n");
    }
}

int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    if(row != col){
        printf("Not a Symmetric Matrix");
        return 0;
    }

    MATRIX_X *matrix = initMATRIX(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int temp;
            scanf("%d", &temp);
            matrix->arr[i][j] = temp;
        }
    }
    for(int i = 0; i < matrix->row; i++){
        for(int j = 0; j < matrix->col; j++){
            printf("%d ", matrix->arr[j][i]);
        }
    printf("\n");
    }
    
    // MATRIX_X *transpose = Transpose(matrix);
    if(isSym(matrix)){
        printf("The matrix is symmetric");
    }else if(isSkew(matrix)){
        printf("The matrix is skew-symmetric");
    }else{
        printf("None");
    }
    for(int i = 0; i < matrix->row; i++){
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
    return 0;
}