#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

void readFromSocketToTempFile(int sock) {
    FILE *tempFile = tmpfile(); // create a temporary file
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(sock, buffer, MAX_BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytesRead, tempFile);
    }

    fclose(tempFile);

    if (bytesRead < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Assume sock is the socket descriptor
    readFromSocketToTempFile(sock);

    return 0;
}