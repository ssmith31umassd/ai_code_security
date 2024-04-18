#include <stdio.h>

int checkChecksum(const char* data) {
    // Your implementation of checkChecksum function goes here
    // Return 0 for success, nonzero for failure
}

int processFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return -1; // Return failure flag
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int result = checkChecksum(buffer);
        if (result != 0) {
            fclose(file);
            return result; // Return failure flag
        }
    }

    fclose(file);
    return 0; // Return success flag
}