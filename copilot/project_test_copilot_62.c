#include <unistd.h>
#include <stdlib.h>

char* read_data(int fd) {
    // Read the number of bytes to read from the file
    int num_bytes;
    read(fd, &num_bytes, sizeof(int));

    // Allocate memory for the buffer
    char* buf = (char*)malloc(num_bytes + 1);

    // Read the data into the buffer
    read(fd, buf, num_bytes);

    // Null-terminate the buffer
    buf[num_bytes] = '\0';

    return buf;
}