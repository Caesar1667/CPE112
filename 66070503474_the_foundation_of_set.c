#include <stdio.h>

//Pansa Intawong 66070503474
// The foundation of set

int sort(int x[], int y){
  int temp;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < i; j++){
            if(x[i] < x[j]){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}
int set(int x[], int m, int n, int size){
  int count = 0;
  
    for (int i = 0; i < size; i++) {
      if ((x[i] >= m && x[i] <= n) && x[i] != x[i + 1]) {
        printf("%d ", x[i]);
        count++;
      }
    }
    if(count == 0){
      printf("empty");
    }    
    printf("\n");
}
void createUniverse(int m, int n, int *u){
  for(int i = 0; i <= n-m; i++){
    *(u + i) = m + i;
  }
  // for(int i = 0; i < (n-m) + 1; i++){
  //   printf("%d ", *(u + i));
  // }
}

int Union(int sizeA, int sizeB, int A[], int B[], int m, int n){
  int tempU[sizeA+sizeB];
  for(int i = 0; i < sizeA; i++){
    tempU[i] = A[i];
  }
  int tempCount = 0;
  for(int i = sizeA; i < sizeA+sizeB; i++){
    tempU[i] = B[tempCount];
    tempCount++;
  }

  sort(tempU, sizeA+sizeB);

  set(tempU, m, n, sizeA+sizeB);
}

void Intersection(int sizeA, int sizeB, int A[], int B[], int m, int n){
  int tempS[sizeA+sizeB], size = 0;
    for(int i = 0; i < sizeA; i++){
      for(int j = 0; j < sizeB; j++){
        if(A[i] == B[j]){
          tempS[size] = A[i];
          size++;
        }
      }
    }
  int S[size];
  for(int i = 0; i < size; i++){
    S[i] = tempS[i];
  }
  set(S, m, n, size); 
}

void Difference(int sizeA, int sizeB, int A[], int B[], int m, int n){
  int k = 0, C[sizeA+sizeB];
  for(int i = 0; i < sizeA; i++){
    int count = 0;
    for(int j = 0; j < sizeB; j++){
      if(A[i] == B[j]){
        count++;
      }
    }
    if(count == 0){
      C[k] = A[i];
      k++;
    }
  }
  set(C, m, n, k);
}

void Complement(int sizeA, int sizeU, int A[], int U[], int m, int n){
  createUniverse(m, n, U);
  Difference(sizeU+1, sizeA, U, A, m, n);
}

int main() {
  int m, n; // Range of the Universe
  int p, q; // number of elements
  scanf("%d %d\n%d", &m, &n, &p);
  int a[p], u[n-m+1];

  for (int i = 0; i < p; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  int b[q];
  for (int i = 0; i < q; i++) {
    scanf("%d", &b[i]);
  }
  

  // OUTPUT
  set(a,m,n,p);
  set(b,m,n,q);

  Union(p, q, a, b, m, n);
  Intersection(p, q, a, b, m, n);
  Difference(p, q, a, b, m, n);
  Difference(q, p, b, a, m, n);
  Complement(p, n-m, a, u, m, n);
  Complement(q, n-m, b, u, m, n);
  // createUniverse(m, n, u);
}