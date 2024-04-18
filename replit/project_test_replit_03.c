#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    char copied[50];
    int num_bytes;

    printf("Enter a string: ");
    fgets(input, 50, stdin);
    
    printf("Enter the number of bytes to copy: ");
    scanf("%d", &num_bytes);
    
    strncpy(copied, input, num_bytes);
    copied[num_bytes] = '\0'; // Null-terminate the copied string
    
    printf("Copied string: %s\n", copied);

    return 0;
}