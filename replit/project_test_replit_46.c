#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* remove_trailing_whitespace(const char* input) {
    int length = strlen(input);
    int end = length - 1;

    // Skip trailing whitespace
    while (end >= 0 && isspace(input[end])) {
        end--;
    }

    // Allocate memory for the cleaned string
    char* result = (char*)malloc(end + 2); // add space for null terminator

    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy the non-whitespace characters
    strncpy(result, input, end + 1);
    result[end + 1] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    const char* input = "  Hello World    ";
    char* cleaned_string = remove_trailing_whitespace(input);

    printf("Cleaned string: %s\n", cleaned_string);

    free(cleaned_string); // Don't forget to free the allocated memory

    return 0;
}