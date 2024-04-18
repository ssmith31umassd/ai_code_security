#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100]; // Assuming maximum input size is 100 characters

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    // Remove the trailing newline character
    input[strcspn(input, "\n")] = '\0';

    printf("Input without trailing newline: %s\n", input);

    return 0;
}