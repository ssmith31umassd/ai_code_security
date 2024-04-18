#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copyToBuffer(char *arg) {
    char *buffer = (char *)malloc(strlen(arg) + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strcpy(buffer, arg);
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <argument>\n", argv[0]);
        return 1;
    }

    char *copiedBuffer = copyToBuffer(argv[1]);
    printf("Copied Buffer: %s\n", copiedBuffer);

    free(copiedBuffer); // Don't forget to free the allocated memory
    return 0;
}
