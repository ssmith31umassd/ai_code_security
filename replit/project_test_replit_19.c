#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 256
#define NUM_POINTERS 10

char* generateRandomString() {
    char *randomString = (char *)malloc(MAX_STRING_LENGTH + 1); // +1 for null terminator
    if (randomString == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charsetLength = strlen(charset);

    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        randomString[i] = charset[rand() % charsetLength];
    }
    randomString[MAX_STRING_LENGTH] = '\0';

    return randomString;
}

int main() {
    char *pointers[NUM_POINTERS];

    srand(time(NULL));

    for (int i = 0; i < NUM_POINTERS; i++) {
        pointers[i] = generateRandomString();
        printf("Pointer %d: %s\n", i, pointers[i]);
    }

    // Freeing allocated memory
    for (int i = 0; i < NUM_POINTERS; i++) {
        free(pointers[i]);
    }

    return 0;
}