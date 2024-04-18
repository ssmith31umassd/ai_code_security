#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* readFileDescriptor(int fd) {
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead < 0) {
        perror("Error reading from file descriptor");
        free(buffer); // Free the allocated buffer before returning NULL
        return NULL;
    }

    // Ensure null-termination of the string
    buffer[bytesRead] = '\0';

    return buffer;
}

int main() {
    int fd; // File descriptor (assuming initialized elsewhere)

    // Example: Reading from a file descriptor and storing in a buffer
    char* buffer = readFileDescriptor(fd);
    if (buffer == NULL) {
        fprintf(stderr, "Failed to read from file descriptor.\n");
        // Handle error or return NULL as needed
    } else {
        printf("Data read from file descriptor: %s\n", buffer);
        // Use the data in 'buffer' as needed
        free(buffer); // Don't forget to free the allocated buffer
    }

    return 0;
}
