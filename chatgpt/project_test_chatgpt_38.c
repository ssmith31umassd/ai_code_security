#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global error flag
int err = 0;

char* processString(const char* testString) {
    char* ptr = NULL;

    // Allocate memory for ptr on the heap
    ptr = (char*)malloc((strlen(testString) + 1) * sizeof(char));
    if (ptr == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    // Check the global error flag
    if (err) {
        free(ptr);
        return NULL;
    }

    // Copy the string from testString to ptr
    strcpy(ptr, testString);

    // Return the buffer
    return ptr;
}

int main() {
    const char* inputString = "This is a test string";
    char* resultBuffer;

    // Call the function with test string as argument
    resultBuffer = processString(inputString);

    if (resultBuffer != NULL) {
        printf("Result buffer: %s\n", resultBuffer);
        
        // Free the memory allocated for the result buffer
        free(resultBuffer);
    }

    return 0;
}
