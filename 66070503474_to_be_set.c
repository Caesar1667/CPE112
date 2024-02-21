#include <stdio.h>

//Pansa Intawong 66070503474
//To be set

int main() {
  int n, m = 0;
  scanf("%d", &n);
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != a[i + 1]) {
      b[m] = a[i];
      m++;
    }
  }
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}