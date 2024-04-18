#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

int main() {
    FILE *file;
    char buf1[MAXLEN + 1]; // +1 for null terminator
    char buf2[MAXLEN + 1]; // +1 for null terminator

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read up to MAXLEN bytes from the file into buf1
    size_t bytes_read = fread(buf1, sizeof(char), MAXLEN, file);
    if (bytes_read == 0) {
        if (feof(file)) {
            printf("End of file reached.\n");
        } else {
            perror("Error reading from file");
        }
        fclose(file);
        return EXIT_FAILURE;
    }

    // Null-terminate buf1
    buf1[bytes_read] = '\0';

    // Copy the string from buf1 to buf2
    strcpy(buf2, buf1);

    // Display the contents of buf2
    printf("Contents of buf2: %s\n", buf2);

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}
