#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Function to read data from file descriptor fd
void read_data_from_fd(int fd, char* buf) {
    // Read the size of the data to be read
    int size;
    read(fd, &size, sizeof(int));

    // Read the actual data into buf
    read(fd, buf, size);
}

int main(void) {
    // Assume fd is already opened and points to the file
    int fd; // File descriptor
    char buf[100]; // Initialize buf with enough space

    // Call the function to read data from the file descriptor
    read_data_from_fd(fd, buf);

    // Assuming buf now contains the data that was read
    printf("Data read: %s\n", buf);

    return 0;
}