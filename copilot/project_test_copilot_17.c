#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Replace with the actual port number
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with the actual IP address

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Open a temporary file for writing
    FILE* temp_file = tmpfile();
    if (temp_file == NULL) {
        perror("Failed to create temporary file");
        return 1;
    }

    // Read data from the socket and write it to the temporary file
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(sock, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, temp_file);
    }

    if (bytes_read < 0) {
        perror("Read error");
        return 1;
    }

    // Close the socket and the temporary file
    close(sock);
    fclose(temp_file);

    return 0;
}