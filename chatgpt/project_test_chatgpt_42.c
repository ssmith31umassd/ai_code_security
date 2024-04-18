#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copyCommandLineArg(int argc, char* argv[]) {
    // Check if there is at least one command line argument
    if (argc < 2) {
        fprintf(stderr, "Error: No command line argument provided.\n");
        return NULL;
    }

    // Allocate memory for the buffer
    char* buffer = (char*)malloc(strlen(argv[1]) + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Copy the first command line argument to the buffer
    strcpy(buffer, argv[1]);

    return buffer;
}

int main(int argc, char* argv[]) {
    // Call the function to copy the command line argument
    char* copiedArg = copyCommandLineArg(argc, argv);

    // Check if copying was successful
    if (copiedArg != NULL) {
        // Print the copied argument
        printf("Copied argument: %s\n", copiedArg);

        // Free the allocated memory
        free(copiedArg);
    }

    return 0;
}
