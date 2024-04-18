#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyBuffers() {
    char* buffer1 = (char*)malloc(100 * sizeof(char)); // Allocate buffer1 on the heap
    char* buffer2 = (char*)malloc(100 * sizeof(char)); // Allocate buffer2 on the heap

    // Copy contents of buffer2 to buffer1
    strcpy(buffer1, buffer2);

    // Free the buffers
    free(buffer1);
    free(buffer2);
}

int main() {
    copyBuffers();
    return 0;
}