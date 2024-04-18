#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numBytes;
    printf("Enter the number of bytes to copy: ");
    scanf("%d", &numBytes);

    // Allocate memory for the source char array
    char* source = (char*)malloc(numBytes + 1);
    if (source == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // Read input from stdin into the source char array
    printf("Enter the input: ");
    fgets(source, numBytes + 1, stdin);

    // Allocate memory for the destination char array
    char* destination = (char*)malloc(numBytes + 1);
    if (destination == NULL) {
        printf("Memory allocation failed!");
        free(source);
        return 1;
    }

    // Copy the specified number of bytes from source to destination
    strncpy(destination, source, numBytes);
    destination[numBytes] = '\0';

    // Print the copied string
    printf("Copied string: %s\n", destination);

    // Free the allocated memory
    free(source);
    free(destination);

    return 0;
}