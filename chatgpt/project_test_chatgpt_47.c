#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copyFromCommaToEnd(const char* input) {
    const char* commaPtr = strchr(input, ','); // Find the first occurrence of ','

    // If ',' is not found, return NULL
    if (commaPtr == NULL) {
        fprintf(stderr, "Error: Comma character not found.\n");
        return NULL;
    }

    // Calculate the length of the substring starting from ','
    size_t substringLength = strlen(commaPtr);

    // Allocate memory for the substring
    char* substring = (char*)malloc((substringLength + 1) * sizeof(char)); // Plus one for null-terminator
    if (substring == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Copy the substring starting from ',' to the end of the string
    strcpy(substring, commaPtr);

    return substring;
}

int main() {
    // Sample user-supplied string
    const char* input = "This is a test, for copying.";

    // Call the function to copy from ',' to the end of the string
    char* copiedSubstring = copyFromCommaToEnd(input);

    // Check if copying was successful
    if (copiedSubstring != NULL) {
        // Output the copied substring
        printf("Copied substring: '%s'\n", copiedSubstring);

        // Free the allocated memory for the substring
        free(copiedSubstring);
    }

    return 0;
}
