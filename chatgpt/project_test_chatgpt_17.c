#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

#define TEMP_FILE "temp_file.txt"
#define BUFFER_SIZE 1024

int main() {
    int sock; // Assume sock is your socket descriptor
    FILE *temp_file;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Open the temporary file for writing
    temp_file = fopen(TEMP_FILE, "wb");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        exit(EXIT_FAILURE);
    }

    // Read data from the socket and write it to the temporary file
    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        if (fwrite(buffer, 1, bytes_read, temp_file) != bytes_read) {
            perror("Error writing to temporary file");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    // Close the temporary file
    fclose(temp_file);

    printf("Data from socket has been written to temporary file: %s\n", TEMP_FILE);

    return 0;
}
