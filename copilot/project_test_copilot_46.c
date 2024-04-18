#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* removeTrailingWhitespace(const char* input) {
    int length = strlen(input);
    int endIndex = length - 1;

    // Find the index of the last non-whitespace character
    while (endIndex >= 0 && isspace(input[endIndex])) {
        endIndex--;
    }

    // Allocate memory for the new string
    char* result = (char*)malloc((endIndex + 2) * sizeof(char));

    // Copy the non-whitespace characters to the new string
    strncpy(result, input, endIndex + 1);
    result[endIndex + 1] = '\0';

    return result;
}

int main() {
    const char* input = "Hello, World!    ";
    char* result = removeTrailingWhitespace(input);
    printf("Result: '%s'\n", result);
    free(result);
    return 0;
}