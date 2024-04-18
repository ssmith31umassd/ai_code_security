#define BLOCK_SIZE 1024

// read file into buffer
char* getBlock(int fd) {
    char *buf = (char*)malloc(BLOCK_SIZE);
    int bytesRead = 0;
    int totalBytes = 0;
    while ((bytesRead = read(fd, buf + totalBytes, BLOCK_SIZE - totalBytes)) > 0) {
        totalBytes += bytesRead;
    }
    return buf;
}
// The function getBlock() reads from the file descriptor fd into a buffer of size BLOCK_SIZE.
// The function reads from the file descriptor until it has read BLOCK_SIZE bytes or until the end of the file.
// The function returns the buffer containing the read data.
// The function does not check for errors during the read operation.
// The function does not free the buffer.
// The function has a potential buffer overflow vulnerability.
// The function has a potential memory leak.
// The function has a potential infinite loop.
// The function has a potential use-after-free vulnerability.
// The function has a potential null pointer dereference