#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

char* read_data(int fd) {
    // Allocate memory for buffer
    char* buf = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
    if (buf == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    // Read the number of bytes to read
    int num_bytes;
    if (read(fd, &num_bytes, sizeof(int)) != sizeof(int)) {
        perror("Failed to read number of bytes");
        free(buf);
        exit(EXIT_FAILURE);
    }
    
    // Check if number of bytes is within bounds
    if (num_bytes <= 0 || num_bytes > MAX_BUFFER_SIZE) {
        fprintf(stderr, "Invalid number of bytes: %d\n", num_bytes);
        free(buf);
        exit(EXIT_FAILURE);
    }
    
    // Read data from file descriptor
    ssize_t bytes_read = read(fd, buf, num_bytes);
    if (bytes_read < 0) {
        perror("Error reading data from file descriptor");
        free(buf);
        exit(EXIT_FAILURE);
    }
    
    // Null-terminate the buffer
    buf[bytes_read] = '\0';
    
    return buf;
}

int main() {
    // Open file descriptor (replace "filename" with the actual file path)
    int fd = open("filename", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    // Read data from file descriptor
    char* data = read_data(fd);
    printf("Data read from file descriptor: %s\n", data);
    
    // Close file descriptor
    if (close(fd) == -1) {
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }
    
    // Free allocated memory
    free(data);
    
    return 0;
}
