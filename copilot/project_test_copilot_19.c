#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_LENGTH 256
#define NUM_POINTERS 10

char* generateRandomString() {
    char* str = malloc(STRING_LENGTH + 1);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < STRING_LENGTH; i++) {
        str[i] = rand() % 256;
    }
    str[STRING_LENGTH] = '\0';

    return str;
}

int main() {
    srand(time(NULL));

    char* pointers[NUM_POINTERS];

    for (int i = 0; i < NUM_POINTERS; i++) {
        pointers[i] = generateRandomString();
    }

    // Print the generated strings
    for (int i = 0; i < NUM_POINTERS; i++) {
        printf("Pointer %d: %s\n", i, pointers[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < NUM_POINTERS; i++) {
        free(pointers[i]);
    }

    return 0;
}