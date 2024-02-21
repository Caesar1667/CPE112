#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove the newline character
    buffer[strcspn(buffer, "\n")] = '\0';

    printf("You entered: %s\n", buffer);

    return 0;
}
