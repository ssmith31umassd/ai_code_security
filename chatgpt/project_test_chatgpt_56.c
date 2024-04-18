#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // Assuming input will not exceed 100 characters

    // Read input from the console
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline if exists
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Print the result
    printf("Input with trailing newline removed: %s\n", input);

    return 0;
}
