#include <stdlib.h>
#include <string.h>

char* allocateAndCopyString(const char* testString) {
    char* ptr = NULL;

    // Allocate memory for the buffer
    ptr = (char*)malloc(strlen(testString) + 1);

    // Check if memory allocation was successful
    if (ptr != NULL) {
        // Copy the string to the buffer
        strcpy(ptr, testString);
    }

    // Check the error flag
    if (err) {
        // Free the buffer if the error flag is true
        free(ptr);
        ptr = NULL;
    }

    return ptr;
}