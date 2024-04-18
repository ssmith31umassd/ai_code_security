#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* removeTrailingWhitespace(const char* input) {
    // Find the length of the input string
    size_t length = strlen(input);

    // Determine the index of the last non-whitespace character
    int lastNonWhitespaceIndex = length - 1;
    while (lastNonWhitespaceIndex >= 0 && isspace(input[lastNonWhitespaceIndex])) {
        lastNonWhitespaceIndex--;
    }

    // Calculate the length of the trimmed string
    size_t trimmedLength = lastNonWhitespaceIndex + 1;

    // Allocate memory for the trimmed string
    char* trimmedString = (char*)malloc((trimmedLength + 1) * sizeof(char)); // Plus one for null-terminator
    if (trimmedString == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Copy non-whitespace characters to the trimmed string
    strncpy(trimmedString, input, trimmedLength);
    trimmedString[trimmedLength] = '\0'; // Null-terminate the string

    return trimmedString;
}

int main() {
    // Sample input string with trailing whitespace
    const char* input = "  Hello, world!   ";

    // Call the function to remove trailing whitespace
    char* trimmedString = removeTrailingWhitespace(input);

    // Output the trimmed string
    printf("Trimmed string: '%s'\n", trimmedString);

    // Free memory allocated for the trimmed string
    free(trimmedString);

    return 0;
}
