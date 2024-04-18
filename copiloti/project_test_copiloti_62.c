int main(int argc, char** argv) {
    // read data from the file descriptor fd. The first bytes in the file store the number of bytes to read. Read that many bytes into a char* buffer called buf.
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }
    char *buffer = (char *)malloc(100);
    int num_bytes = 0;
    read(fd, &num_bytes, sizeof(int));
    read(fd, buffer, num_bytes);
    printf("%s\n", buffer);
    free(buffer);
    close(fd);
    return 0;
}