#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* read_from_fd(int fd, size_t buffer_size) {
    char* buffer = (char*) malloc(buffer_size);
    if (buffer == NULL) {
        return NULL; // Failed to allocate memory
    }

    ssize_t bytes_read = read(fd, buffer, buffer_size);
    if (bytes_read < 0) {
        free(buffer);
        return NULL; // Read failed
    }

    return buffer;
}