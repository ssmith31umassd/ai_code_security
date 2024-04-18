#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* toLower(const char* input) {
    // Calculate the length of the input string
    size_t len = strlen(input);

    // Allocate memory for the output string
    char* output = (char*)malloc(len + 1); // +1 for the null terminator

    if (output == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Iterate through the input string, converting characters to lowercase
    for (size_t i = 0; i < len; i++) {
        output[i] = tolower(input[i]);
    }

    // Add null terminator to the output string
    output[len] = '\0';

    return output;
}

int main() {
    const char* input = "Hello, World!";
    char* lowercased = toLower(input);
    if (lowercased != NULL) {
        printf("Lowercased string: %s\n", lowercased);
        free(lowercased); // Free the heap-allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
