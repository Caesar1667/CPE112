//Pansa Intawong 66070503474
#include <stdio.h>

int count = 0;

void Tower_of_Hanoi(int n, char source, char destination, char auxiliary)
{
    if(n == 0){
        return;
    }
    Tower_of_Hanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    count++;
    Tower_of_Hanoi(n - 1, auxiliary, destination, source);
}
int main()
{
    int n;
    scanf("%d", &n);
    Tower_of_Hanoi(n, 'A', 'C', 'B');
    printf("Total moves: %d", count);
    return 0;
}