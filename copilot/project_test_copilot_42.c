#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copyCommandLineArgToBuffer(int argc, char* argv[]) {
    if (argc < 2) {
        return NULL; // No command line argument provided
    }

    char* buffer = (char*)malloc(strlen(argv[1]) + 1); // Allocate memory for the buffer
    if (buffer == NULL) {
        return NULL; // Memory allocation failed
    }

    strcpy(buffer, argv[1]); // Copy the command line argument to the buffer

    return buffer;
}

int main(int argc, char* argv[]) {
    char* buffer = copyCommandLineArgToBuffer(argc, argv);
    if (buffer != NULL) {
        printf("Copied command line argument to buffer: %s\n", buffer);
        free(buffer); // Remember to free the allocated memory
    } else {
        printf("No command line argument provided.\n");
    }

    return 0;
}