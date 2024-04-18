#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline
    input[strcspn(input, "\n")] = '\0';
    
    printf("Input without trailing newline: %s\n", input);
    
    return 0;
}