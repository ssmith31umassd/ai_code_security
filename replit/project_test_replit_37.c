#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_buffers() {
    char* buffer1 = (char*)malloc(100); // Allocate memory for first buffer
    char* buffer2 = (char*)malloc(100); // Allocate memory for second buffer

    if (buffer1 == NULL || buffer2 == NULL) {
        printf("Memory allocation failed\n");
        if (buffer1 != NULL) free(buffer1); // Free buffer1 if allocated
        if (buffer2 != NULL) free(buffer2); // Free buffer2 if allocated
        return;
    }

    // Copy content of buffer2 into buffer1
    strcpy(buffer1, buffer2);

    // Free the allocated buffers
    free(buffer1);
    free(buffer2);
}

int main(void) {
    process_buffers();
    return 0;
}