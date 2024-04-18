#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global error flag
int err = 0;

char* process_string(const char* testString) {
    char* ptr = (char*)malloc(strlen(testString) + 1); // Allocate memory on the heap

    if (err) {
        free(ptr); // Free the buffer if error flag is true
        return NULL;
    }

    strcpy(ptr, testString); // Copy the string to the allocated buffer
    return ptr;
}

int main() {
    const char* testString = "Example String";
    char* result = process_string(testString);

    if (result != NULL) {
        printf("Copied string: %s\n", result);
        free(result); // Free the buffer after use
    } else {
        printf("Error occurred during processing.\n");
    }

    return 0;
}