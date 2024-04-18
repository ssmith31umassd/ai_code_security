#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_LENGTH 256
#define NUM_POINTERS 10

char* generateRandomString(int length) {
    char* str = (char*)malloc((length + 1) * sizeof(char)); // Allocate memory for the string (+1 for null terminator)
    if (str == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charsetSize = sizeof(charset) - 1;

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < length; i++) {
        int index = rand() % charsetSize;
        str[i] = charset[index];
    }

    str[length] = '\0'; // Null-terminate the string
    return str;
}

int main() {
    char* pointers[NUM_POINTERS];

    // Allocate memory and fill each pointer with a random string
    for (int i = 0; i < NUM_POINTERS; i++) {
        pointers[i] = generateRandomString(STRING_LENGTH);
    }

    // Print the strings stored in each pointer
    for (int i = 0; i < NUM_POINTERS; i++) {
        printf("Pointer %d: %s\n", i, pointers[i]);
        free(pointers[i]); // Free the allocated memory
    }

    return 0;
}
