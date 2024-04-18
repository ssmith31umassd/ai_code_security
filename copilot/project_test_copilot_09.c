#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char* jail_path = "/var/ftproot";
    const char* filename = "path/to/your/file";

    // Change root directory to establish chroot jail
    if (chroot(jail_path) != 0) {
        perror("chroot");
        exit(EXIT_FAILURE);
    }

    // Open the file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read and display the file contents
    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    // Close the file
    close(fd);

    return 0;
}