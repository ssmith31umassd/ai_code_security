#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* readFromFileDescriptor(int fd) {
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead < 0) {
        perror("Error reading from file descriptor");
        free(buffer);
        return NULL;
    }

    return buffer;
}

int main() {
    // Assume fd is the file descriptor for the file you want to read
    int fd = open("example.txt", O_RDONLY); // You need to open the file before passing the file descriptor

    if (fd < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char* buffer = readFromFileDescriptor(fd);

    if (buffer == NULL) {
        printf("Read failed, buffer is NULL\n");
    } else {
        printf("Read successful, buffer: %s\n", buffer);
        free(buffer);
    }

    close(fd); // Close the file descriptor when done
    return EXIT_SUCCESS;
}