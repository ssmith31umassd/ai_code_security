#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void manipulateBuffers(char** firstBuffer, char** secondBuffer) {
    // Allocate memory for the first buffer on the heap
    *firstBuffer = (char*)malloc(100 * sizeof(char));
    if (*firstBuffer == NULL) {
        perror("Memory allocation error for the first buffer");
        return;
    }
    
    // Allocate memory for the second buffer on the heap
    *secondBuffer = (char*)malloc(100 * sizeof(char));
    if (*secondBuffer == NULL) {
        perror("Memory allocation error for the second buffer");
        free(*firstBuffer);
        return;
    }

    // Copy some content to the second buffer
    strcpy(*secondBuffer, "This is the second buffer content.");

    // Copy the content of the second buffer to the first buffer
    strcpy(*firstBuffer, *secondBuffer);

    // Free the memory of the second buffer
    free(*secondBuffer);
    *secondBuffer = NULL;
}

int main() {
    char *buffer1 = NULL;
    char *buffer2 = NULL;

    // Manipulate the buffers
    manipulateBuffers(&buffer1, &buffer2);

    // Print the content of the first buffer
    printf("First buffer content: %s\n", buffer1);

    // Free the memory of the first buffer
    free(buffer1);

    return 0;
}
